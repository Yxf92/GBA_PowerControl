#ifndef __TIM_H__
#define __TIM_H__

#include "at32f423.h"

#define MainLoopTime TMR14

#define MainLoopTimeITClose tmr_interrupt_enable(MainLoopTime, TMR_OVF_INT | TMR_C1_INT , FALSE)
#define MainLoopTimeITOpen tmr_interrupt_enable(MainLoopTime, TMR_OVF_INT | TMR_C1_INT , TRUE)


extern volatile uint32_t SystemTimeMs;

void SystemTim_Configuration(void);
void MainLoopTime_Configuration(void);

uint32_t Get_ms(void);
uint32_t Get_us(void);

#endif
