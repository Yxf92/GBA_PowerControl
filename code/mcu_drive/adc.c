#include "at32f423.h"
#include "target.h"
#include "dac.h"
__IO uint16_t adc_value[ADC_VALUE_LEN];

void ADC1_Init(void)
{
    gpio_init_type gpio_initstructure;
    adc_common_config_type adc_common_struct;
    adc_base_config_type adc_base_struct;
    dma_init_type dma_init_struct;

    /* enable gpioa periph clock */
    crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
    /* enable adc1 periph clock */
    crm_periph_clock_enable(CRM_ADC1_PERIPH_CLOCK, TRUE);
    /* enable dma1 periph clock */
    crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);

    dma_reset(DMA1_CHANNEL3);
    dma_default_para_init(&dma_init_struct);
    dma_init_struct.buffer_size = ADC_VALUE_LEN;
    dma_init_struct.direction = DMA_DIR_PERIPHERAL_TO_MEMORY;
    dma_init_struct.memory_base_addr = (uint32_t)adc_value;
    dma_init_struct.memory_data_width = DMA_MEMORY_DATA_WIDTH_HALFWORD;
    dma_init_struct.memory_inc_enable = TRUE;
    dma_init_struct.peripheral_base_addr = (uint32_t)&(ADC1->odt);
    dma_init_struct.peripheral_data_width = DMA_PERIPHERAL_DATA_WIDTH_HALFWORD;
    dma_init_struct.peripheral_inc_enable = FALSE;
    dma_init_struct.priority = DMA_PRIORITY_HIGH;
    dma_init_struct.loop_mode_enable = TRUE;
    dma_init(DMA1_CHANNEL3, &dma_init_struct);

    /* dmamux function enable */
    dmamux_enable(DMA1, TRUE);
    dmamux_init(DMA1MUX_CHANNEL3, DMAMUX_DMAREQ_ID_ADC1);

    dma_channel_enable(DMA1_CHANNEL3, TRUE);

    gpio_default_para_init(&gpio_initstructure);

    /* configure the IN0 pin */
    gpio_initstructure.gpio_mode = GPIO_MODE_ANALOG;
    gpio_initstructure.gpio_pins = VBAT_PIN;
    gpio_init(VBAT_PORT, &gpio_initstructure);

    /* configure the IN1 pin */
    gpio_initstructure.gpio_mode = GPIO_MODE_ANALOG;
    gpio_initstructure.gpio_pins = ADC_3V_PIN;
    gpio_init(ADC_3V_PORT, &gpio_initstructure);

    /* adc_common_settings--------------------------------------------------------------*/
    /* config adc clock source */
    crm_adc_clock_select(CRM_ADC_CLOCK_SOURCE_HCLK);

    adc_common_default_para_init(&adc_common_struct);
    /* config adc clock division */
    adc_common_struct.div = ADC_HCLK_DIV_2;
    /* config inner temperature sensor and vintrv */
    adc_common_struct.tempervintrv_state = FALSE;
    adc_common_config(&adc_common_struct);

    /* adc_settings------------------------------------------------------------------- */
    adc_base_default_para_init(&adc_base_struct);
    adc_base_struct.sequence_mode = TRUE;
    adc_base_struct.repeat_mode = TRUE;
    adc_base_struct.data_align = ADC_RIGHT_ALIGNMENT;
    adc_base_struct.ordinary_channel_length = ADC_VALUE_LEN;
    adc_base_config(ADC1, &adc_base_struct);
    adc_resolution_set(ADC1, ADC_RESOLUTION_12B);

    /* adc_ordinary_conversionmode---------------------------------------------------- */
    adc_ordinary_channel_set(ADC1, VBAT_ADC_CHANNEL, 1, ADC_SAMPLETIME_640_5);
    adc_ordinary_channel_set(ADC1, ADC_3V_ADC_CHANNEL, 2, ADC_SAMPLETIME_640_5);

    adc_ordinary_conversion_trigger_set(ADC1, ADC_ORDINARY_TRIG_SOFTWARE, ADC_ORDINARY_TRIG_EDGE_RISING_FALLING);

    adc_dma_mode_enable(ADC1, TRUE);
    adc_dma_request_repeat_enable(ADC1, TRUE);

    adc_enable(ADC1, TRUE);
    while(adc_flag_get(ADC1, ADC_RDY_FLAG) == RESET);

    /* adc calibration---------------------------------------------------------------- */
    adc_calibration_init(ADC1);
    while(adc_calibration_init_status_get(ADC1));
    adc_calibration_start(ADC1);
    while(adc_calibration_status_get(ADC1));

    adc_ordinary_software_trigger_enable(ADC1, TRUE);
}
