#include "Communication.h"
#include "ComPort.h"
#include "ComTask.h"
#include "Tasksch.h"
#include "stdbool.h"
#include "CircleBuffer.h"
#include "target.h"

mavlink_rc_channels_override_t RAW_RC_CHAN;

static bool _initialised0 = false;
static bool _initialised1 = false;

extern uint8_t transmission_flag;

void CommunicationInit(void)
{
    CircleBuffer_Init();
    Port0_Init();
}

void Port0_Init(void)
{
    if (_initialised0)
    {
        return;
    }
    CreateTask(UPDATEMAVLINK_TN, -1, 10, Port0_Update);
    _initialised0 = true;
}

void Port0_Update(void)
{
    if (_initialised0 == false)
    {
        return;
    }

    mavlink_msg_heartbeat_send(MAVLINK_COMM_0,
                                   MAV_TYPE_GENERIC, MAV_AUTOPILOT_GENERIC, 0, 0, 0);

    // handle dma port move
    DMA_USART1_SendMove();

    static mavlink_message_t msg;
    static mavlink_status_t status;
    uint16_t nbytes = comm_get_available(MAVLINK_COMM_0);
    for (uint16_t i = 0; i < nbytes; i++)
    {
        uint8_t c = comm_receive_ch(MAVLINK_COMM_0);
        if (transmission_flag == 0)
        {
            uint8_t ret = mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status);
            if (ret == MAVLINK_FRAMING_OK)
            {
                _handle_msg(&msg, MAVLINK_COMM_0);
            }
            else if ((status.parse_state == MAVLINK_PARSE_STATE_IDLE) && (ret == MAVLINK_FRAMING_INCOMPLETE))
            {
                RED_LED_FLICKER;
            }
        }
    }
}