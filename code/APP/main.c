/**
 **************************************************************************
 * @file     main.c
 * @brief    main program
 **************************************************************************
 *                       Copyright notice & Disclaimer
 *
 * The software Board Support Package (BSP) that is made available to
 * download from Artery official website is the copyrighted work of Artery.
 * Artery authorizes customers to use, copy, and distribute the BSP
 * software and its related documentation for the purpose of design and
 * development in conjunction with Artery microcontrollers. Use of the
 * software is governed by this copyright notice and the following disclaimer.
 *
 * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
 * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
 * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
 * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
 * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
 *
 **************************************************************************
 */

#include "at32f423_clock.h"

#include "main.h"
#include "delay.h"

#include "stdio.h"
#include "string.h"
#include "Tasksch.h"
#include "DebugData.h"
#include "Communication.h"
#include "Loop.h"
#include "UserIdentifier.h"
#include "McuDriveInit.h"
#include "CircleBuffer.h"
#include "protect.h"

uint16_t whilelooptime, whilelooptimebase;

GBA_STATE GBA_State;

static void wk_wait_for_power_stable(void)
{
  volatile uint32_t delay = 0;
  for(delay = 0; delay < 50000; delay++);
}

/**
 * @brief  main function.
 * @param  none
 * @retval none
 */
int main(void)
{
    /* add a necessary delay to ensure that Vdd is higher than the operating
       voltage of battery powered domain (2.57V) when the battery powered
       domain is powered on for the first time and being operated. */
    wk_wait_for_power_stable();

    // flash_fap_enable(TRUE);

    nvic_priority_group_config(NVIC_PRIORITY_GROUP_2);
    system_clock_config();

    MCU_Drive_Init();

    // dac_1_data_set(DAC1_12BIT_RIGHT, 750);
    // dac_software_trigger_generate(DAC1_SELECT);

    CommunicationInit();
    SendDebugDataInit();

    GBA_State.Dc_state = NC_Vin;

    CreateTask(VOLPROTECT_TN, -1, 20, PROTECT_Loop);

    MainLoopOpen; // 开始1ms主中断
    // EN_3V_SET;
    delay_ms(500);

    uint8_t runflag = 0;
    while (1)
    {
        whilelooptimebase = Get_us();

        if (runflag == 0)
        {
            OpenControlLoop(); // 开始主循环

            runflag = 1;
        }

        RunTasks(); // 任务调度

        whilelooptime = Get_us() - whilelooptimebase;
    }
}

void MCU_Reboot(void)
{
    NVIC_SystemReset();
}

/**
 * @}
 */

/**
 * @}
 */
