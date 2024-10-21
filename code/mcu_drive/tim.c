#include "at32f423.h"
#include "tim.h"
#include <stdio.h>
#include "target.h"

volatile uint32_t SystemTimeMs = 0;

/* TIM6 init function */
void SystemTim_Configuration(void)
{
    /* ----------------------------------------------------------------------------
    TIMER Configuration:
    TIMER CLK = SystemCoreClock/240 = 1000KHz, the period is 1s(1000000/1000 = 1ms).
    ---------------------------------------------------------------------------- */
    /* enable tmr6 periph clock */
    crm_periph_clock_enable(CRM_TMR6_PERIPH_CLOCK, TRUE);

    /* tmr6 configuration */
    /* time base configuration */
    /* systemclock/24000/10000 = 1hz */
    tmr_base_init(TMR6, 999, 149);
    tmr_cnt_dir_set(TMR6, TMR_COUNT_UP);
    tmr_period_buffer_enable(TMR6, FALSE);

    /* overflow interrupt enable */
    tmr_interrupt_enable(TMR6, TMR_OVF_INT, TRUE);

    nvic_irq_enable(TMR6_DAC_GLOBAL_IRQn, 0, 1);

    /* configure primary mode settings */
    tmr_primary_mode_select(TMR6, TMR_PRIMARY_SEL_RESET);

    tmr_counter_enable(TMR6, TRUE);
}

uint32_t Get_ms(void)
{
    return SystemTimeMs;
}

uint32_t Get_us(void)
{
    return (SystemTimeMs * 1000 + TMR6->cval);
}

/* TIM14 init function */
void MainLoopTime_Configuration(void)
{
    tmr_output_config_type tmr_output_struct;
    tmr_brkdt_config_type tmr_brkdt_struct;

    /* enable tmr14 periph clock */
    crm_periph_clock_enable(CRM_TMR14_PERIPH_CLOCK, TRUE);

    tmr_base_init(TMR14, 999, 149);
    tmr_cnt_dir_set(TMR14, TMR_COUNT_UP);
    tmr_clock_source_div_set(TMR14, TMR_CLOCK_DIV1);
    tmr_repetition_counter_set(TMR14, 0);
    tmr_period_buffer_enable(TMR14, FALSE);

    /* configure channel 1 output settings */
    tmr_output_struct.oc_mode = TMR_OUTPUT_CONTROL_PWM_MODE_A;
    tmr_output_struct.oc_output_state = TRUE;
    tmr_output_struct.occ_output_state = FALSE;
    tmr_output_struct.oc_polarity = TMR_OUTPUT_ACTIVE_HIGH;
    tmr_output_struct.occ_polarity = TMR_OUTPUT_ACTIVE_HIGH;
    tmr_output_struct.oc_idle_state = FALSE;
    tmr_output_struct.occ_idle_state = FALSE;
    tmr_output_channel_config(TMR14, TMR_SELECT_CHANNEL_1, &tmr_output_struct);
    tmr_channel_value_set(TMR14, TMR_SELECT_CHANNEL_1, 699);
    tmr_output_channel_buffer_enable(TMR14, TMR_SELECT_CHANNEL_1, FALSE);

    tmr_output_channel_immediately_set(TMR14, TMR_SELECT_CHANNEL_1, FALSE);

    /* configure break and dead-time settings */
    tmr_brkdt_struct.brk_enable = FALSE;
    tmr_brkdt_struct.auto_output_enable = FALSE;
    tmr_brkdt_struct.brk_polarity = TMR_BRK_INPUT_ACTIVE_LOW;
    tmr_brkdt_struct.fcsoen_state = FALSE;
    tmr_brkdt_struct.fcsodis_state = FALSE;
    tmr_brkdt_struct.wp_level = TMR_WP_OFF;
    tmr_brkdt_struct.deadtime = 0;
    tmr_brkdt_config(TMR14, &tmr_brkdt_struct);

    tmr_interrupt_enable(TMR14, TMR_OVF_INT | TMR_C1_INT, TRUE);

    nvic_irq_enable(TMR14_GLOBAL_IRQn, 2, 2);

    tmr_output_enable(TMR14, TRUE);

    tmr_counter_enable(TMR14, TRUE);
}
