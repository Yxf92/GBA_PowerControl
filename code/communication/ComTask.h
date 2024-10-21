#ifndef __COMTASK_H__
#define __COMTASK_H__

#include "at32f423.h"

#include "../MAVLINK2/mavlink_types.h"

extern volatile uint8_t debug_data_run_flag;

void mavlink2_calibration_feedback(int8_t progress, uint8_t type);
void _handle_msg(mavlink_message_t *message, mavlink_channel_t chan);
void PCSend_send_message_Mavlink(uint8_t *rfdata, uint8_t length); //发送上位机数据
//void Telecontroller_send_message_Mavlink(uint8_t* rfdata,uint8_t length);
void Bootload_send_message_Mavlink(uint8_t *arry, uint8_t length);
void Resend_Mavlink_Usart(mavlink_channel_t chan, const mavlink_message_t *msg);

extern uint8_t remote_control_version;

#endif
