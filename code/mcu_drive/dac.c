#include "at32f423.h"
#include "target.h"
#include "adc.h"

void DAC_Init(void)
{
    gpio_init_type gpio_init_struct;
    gpio_default_para_init(&gpio_init_struct);

    crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
    crm_periph_clock_enable(CRM_DAC_PERIPH_CLOCK, TRUE);

    /*gpio------------------------------------------------------------------------------*/
    /* configure the OUT1 pin */
    gpio_init_struct.gpio_pins = V_CON_PIN;
    gpio_init_struct.gpio_mode = GPIO_MODE_ANALOG;
    gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
    gpio_init(V_CON_GPIO_PORT, &gpio_init_struct);

    /*dac OUT1 init--------------------------------------------------------------------*/
    dac_trigger_enable(DAC1_SELECT, TRUE);
    dac_trigger_select(DAC1_SELECT, DAC_SOFTWARE_TRIGGER);
    // dac_wave_generate(DAC1_SELECT, DAC_WAVE_GENERATE_NONE);
    dac_output_buffer_enable(DAC1_SELECT, TRUE);

    dac_enable(DAC1_SELECT, TRUE);

    /**
     * Users need to configure DAC interrupt functions according to the actual application.
     * 1. Call the below function to enable the corresponding DAC interrupt.
     *     --dac_udr_enable(...)
     * 2. Add the user's interrupt handler code into the below function in the at32f423_int.c file.
     *     --void TMR6_DAC_GLOBAL_IRQHandler(void)
     */
    /*dac_interrupt_config-------------------------------------------------------------*/
    // dac_udr_enable(DAC1_SELECT, TRUE);

    dac_1_data_set(DAC1_12BIT_RIGHT, 730);
    dac_software_trigger_generate(DAC1_SELECT);
}
