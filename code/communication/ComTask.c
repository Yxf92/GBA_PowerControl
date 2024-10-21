#include "ComPort.h"
#include "stdio.h"
#include "ComTask.h"
#include "delay.h"
#include "main.h"
#include "math.h"
#include "UserIdentifier.h"
#include "Communication.h"
#include "DebugData.h"
#include "Tasksch.h"
#include "CircleBuffer.h"

extern float camerazoom;
extern uint32_t cameradzoom;

const uint16_t MESSAGE_NEED_RESEND[17] =
    {
        MAVLINK_MSG_ID_HEARTBEAT,
        MAVLINK_MSG_ID_ATTITUDE,
        MAVLINK_MSG_ID_COMMAND_ACK,
        MAVLINK_MSG_ID_CAMERA_TRIGGER,
        MAVLINK_MSG_ID_CAMERA_INFORMATION,
        MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED,
        MAVLINK_MSG_ID_PARAM_EXT_SET,
        MAVLINK_MSG_ID_PARAM_EXT_ACK,
        MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION,
        MAVLINK_MSG_ID_VIDEO_STREAM_STATUS,
        MAVLINK_MSG_ID_PARAM_EXT_REQUEST_READ,
        MAVLINK_MSG_ID_PARAM_EXT_REQUEST_LIST,
        MAVLINK_MSG_ID_PARAM_EXT_VALUE,
        MAVLINK_MSG_ID_CAMERA_SETTINGS,
        MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS,
        MAVLINK_MSG_ID_STORAGE_INFORMATION,
        MAVLINK_MSG_ID_GLOBAL_POSITION_INT};

uint8_t transmission_flag = 0;
uint8_t CAM_USE_USART_FLAG = 0;
float Angle_Offset_P = 0.0f;
float Angle_Offset_R = 0.0f;
uint8_t remote_control_version = 0;

static uint32_t Heartbeat_Time = 0;

// Note: Channel Number range should be: 0 or 1.
static mavlink_channel_t debugdatachan = MAVLINK_COMM_0;  // 调试数据接口
static mavlink_channel_t bootloaderchan = MAVLINK_COMM_0; // bootloader接口

// static void mavlink2_handle_msg(mavlink_message_t *message, mavlink_channel_t chan);
static void mavlink2_handle_command_long(mavlink_message_t *message, mavlink_channel_t chan);
static void send_command_ack(uint16_t cmd, unsigned char result, mavlink_channel_t chan, uint8_t type);
static void send_command_ack_in_progress(uint16_t cmd, mavlink_channel_t chan, uint8_t progress, uint8_t type);
static void send_autopilot_capabilities(mavlink_channel_t chan);

void PCSend_send_message_Mavlink(uint8_t *rfdata, uint8_t length) // 发送上位机调试数据
{
    _mav_finalize_message_chan_send(debugdatachan, MAVLINK_MSG_ID_GIMBAL_DEBUGDATA, (const char *)(rfdata), length, length, MAVLINK_MSG_ID_GIMBAL_DEBUGDATA_CRC);
}

void Bootload_send_message_Mavlink(uint8_t *arry, uint8_t length) // 发送bootload数据
{
    _mav_finalize_message_chan_send(bootloaderchan, MAVLINK_MSG_ID_BOOTLOAD_DATA, (const char *)(arry), length, length, MAVLINK_MSG_ID_BOOTLOAD_DATA_CRC);
}

void send_command_ack(uint16_t cmd, unsigned char result, mavlink_channel_t chan, uint8_t type)
{
    const uint8_t no_progress = 0;
    mavlink_msg_command_ack_send(chan, cmd, result, no_progress, type, 0, 0);
}

void send_command_ack_in_progress(uint16_t cmd, mavlink_channel_t chan, uint8_t progress, uint8_t type)
{
    mavlink_msg_command_ack_send(chan, cmd, MAV_RESULT_IN_PROGRESS, progress, type, 0, 0);
}

extern const char AppName[];
extern void send_autopilot_capabilities(mavlink_channel_t chan)
{
}

void mavlink2_calibration_feedback(int8_t progress, uint8_t type)
{
    //-1进度代表失败 MAV_RESULT_FAILED
    if (progress == -1)
    {
        send_command_ack(MAV_CMD_PREFLIGHT_CALIBRATION, MAV_RESULT_FAILED, MAVLINK_COMM_0, type);
        return;
    }

    // 当有100的进度时,不需要回应MAV_RESULT_ACCEPTED, accept refer to command accepted, need send when receive request
    if (progress == 100)
    {
        send_command_ack_in_progress(MAV_CMD_PREFLIGHT_CALIBRATION, MAVLINK_COMM_0, (uint8_t)progress, type);
    }
    else if (progress >= 0 && progress < 100)
    {
        send_command_ack_in_progress(MAV_CMD_PREFLIGHT_CALIBRATION, MAVLINK_COMM_0, (uint8_t)progress, type);
    }
}

/*****************************************************************************
 *处理接收到的mavlink数据
 *
 *
 ******************************************************************************/
// mavlink_attitude_t droneattitude;
mavlink_global_position_int_t aircraftglobal_position;
int16_t rece_cnt = 0;
mavlink_rc_channels_t rc_channels_packet;
mavlink_local_position_ned_t drone_position_ned_packet;
mavlink_highres_imu_t drone_highres_imu_packet;
mavlink_rc_channels_override_t rc_channels;

void _handle_msg(mavlink_message_t *message, mavlink_channel_t chan)
{
    switch (message->msgid)
    {
    case MAVLINK_MSG_ID_COMMAND_LONG:
        mavlink2_handle_command_long(message, chan);
        break;

    case MAVLINK_MSG_ID_BOOTLOAD_DATA:
        break;

    case MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE:
        mavlink_msg_rc_channels_override_decode(message, &rc_channels);
        GREEN_LED_FLICKER;
        break;

    case MAVLINK_MSG_ID_GIMBAL_DEBUGDATA:
        debugdatachan = chan;
        CarryoutOrder((uint8_t *)(message->payload64)); // 执行上位机数据
        break;

    default:
        Resend_Mavlink_Usart(1 - chan, message);
        break;
    }
}

void mavlink2_handle_command_long(mavlink_message_t *message, mavlink_channel_t chan)
{
    mavlink_command_long_t command_long;
    mavlink_msg_command_long_decode(message, &command_long);

    if (command_long.target_component == MAV_COMP_ID_ALL)
    {
        Resend_Mavlink_Usart(1 - chan, message);
    }
    if (command_long.target_system != 1 ||
        (command_long.target_component != MAV_COMP_ID_GIMBAL &&
         command_long.target_component != MAV_COMP_ID_ALL))
    {
        Resend_Mavlink_Usart(1 - chan, message);
        return;
    }
    switch (command_long.command)
    {

    default:
        send_command_ack(command_long.command, MAV_RESULT_UNSUPPORTED, chan, 0);
        break;
    }
}

void Resend_Mavlink_Usart(mavlink_channel_t chan, const mavlink_message_t *msg)
{
    if (((Get_ms() - Heartbeat_Time) > 3000) && CAM_USE_USART_FLAG == 1)
    {
        CAM_USE_USART_FLAG = 0;
    }

    if (CAM_USE_USART_FLAG == 1)
    {
        _mavlink_resend_uart(chan, msg);
    }
}
