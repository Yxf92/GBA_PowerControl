#ifndef __COMPORT_H__
#define __COMPORT_H__

#include <stdbool.h>

#define MAVLINK_SEPARATE_HELPERS
#define MAVLINK_SEND_UART_BYTES(chan, buf, len) comm_send_buffer(chan, buf, len)
#define MAVLINK_COMM_NUM_BUFFERS 1

#include "goertek/version.h"
#include "mavlink_types.h"

extern mavlink_system_t mavlink_system;

void comm_send_ch(mavlink_channel_t chan, uint8_t ch);
void comm_send_buffer(mavlink_channel_t chan, const uint8_t *buf, uint8_t len);
uint8_t comm_receive_ch(mavlink_channel_t chan);
uint16_t comm_get_available(mavlink_channel_t chan);
uint16_t comm_get_txspace(mavlink_channel_t chan);
bool comm_is_idle(mavlink_channel_t chan);

#define MAVLINK_USE_CONVENIENCE_FUNCTIONS
#include "goertek/mavlink.h"

#endif
