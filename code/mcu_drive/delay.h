#ifndef __DELAY_H
#define __DELAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdio.h"
#include "at32f423.h"

/******************** functions ********************/
/* delay function */
void delay_s(uint8_t s);
void delay_ms(uint16_t ms);
void delay_us(uint32_t us);

#ifdef __cplusplus
}
#endif

#endif

