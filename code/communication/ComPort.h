#ifndef __COMPORT_H__
#define __COMPORT_H__

#include <stdbool.h>
#include <stdint.h>


void comm_send_ch(uint8_t chan, uint8_t ch);
void comm_send_buffer(uint8_t chan, const uint8_t *buf, uint8_t len);
uint8_t comm_receive_ch(uint8_t chan);
uint16_t comm_get_available(uint8_t chan);
uint16_t comm_get_txspace(uint8_t chan);

#endif
