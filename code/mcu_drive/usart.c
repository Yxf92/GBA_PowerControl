#include "at32f423.h"
#include "usart.h"
#include <stdio.h>
#include "CircleBuffer.h"
#include "target.h"

volatile uint8_t USART1_DMA_GETBUFF[DMA_BUFF_MAX_LEN] = {0};
volatile uint8_t USART1_DMA_PUTBUFF[DMA_BUFF_MAX_LEN] = {0};
volatile uint8_t USART1_DMA_Put_Flag = 0, USART1_DMA_Get_Flag = 0;

/**
 * @brief  config usart3
 * @param  none
 * @retval none
 */
void USART1_Config_Cbuf(uint32_t baudrate)
{
    gpio_init_type gpio_init_struct;
    gpio_default_para_init(&gpio_init_struct);

    /* enable gpioa periph clock */
    crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);

    /* enable usart1 periph clock */
    crm_periph_clock_enable(USART1_RCC_Periph, TRUE);

    /* configure the TX pin */
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
    gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
    gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
    gpio_init_struct.gpio_pins = USART1_TX_PIN;
    gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
    gpio_init(USART1_TX_PORT, &gpio_init_struct);

    gpio_pin_mux_config(USART1_TX_PORT, GPIO_PINS_SOURCE9, GPIO_MUX_7);

    /* configure the RX pin */
    gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_MODERATE;
    gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
    gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
    gpio_init_struct.gpio_pins = USART1_RX_PIN;
    gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
    gpio_init(USART1_RX_PORT, &gpio_init_struct);

    gpio_pin_mux_config(USART1_RX_PORT, GPIO_PINS_SOURCE10, GPIO_MUX_7);

    /* configure param */
    usart_init(USART1, baudrate, USART_DATA_8BITS, USART_STOP_1_BIT);
    usart_transmitter_enable(USART1, TRUE);
    usart_receiver_enable(USART1, TRUE);
    usart_parity_selection_config(USART1, USART_PARITY_NONE);

    usart_dma_transmitter_enable(USART1, TRUE);

    usart_dma_receiver_enable(USART1, TRUE);

    usart_hardware_flow_control_set(USART1, USART_HARDWARE_FLOW_NONE);

    usart_enable(USART1, TRUE);

    USART1_dma_configuration();
}

/**
 * @brief  config dma for usart3
 * @param  none
 * @retval none
 */
void USART1_dma_configuration(void)
{
    dma_init_type dma_init_struct;

    /* enable dma1 periph clock */
    crm_periph_clock_enable(CRM_DMA1_PERIPH_CLOCK, TRUE);

    dma_reset(DMA1_CHANNEL1);
    dma_default_para_init(&dma_init_struct);
    dma_init_struct.buffer_size = DMA_BUFF_MAX_LEN;
    dma_init_struct.direction = DMA_DIR_PERIPHERAL_TO_MEMORY;
    dma_init_struct.memory_base_addr = (uint32_t)USART1_DMA_GETBUFF;
    dma_init_struct.memory_data_width = DMA_MEMORY_DATA_WIDTH_BYTE;
    dma_init_struct.memory_inc_enable = TRUE;
    dma_init_struct.peripheral_base_addr = (uint32_t)&USART1->dt;
    dma_init_struct.peripheral_data_width = DMA_PERIPHERAL_DATA_WIDTH_BYTE;
    dma_init_struct.peripheral_inc_enable = FALSE;
    dma_init_struct.priority = DMA_PRIORITY_MEDIUM;
    dma_init_struct.loop_mode_enable = FALSE;
    dma_init(DMA1_CHANNEL1, &dma_init_struct);

    /* enable transfer full data interrupt */
    dma_interrupt_enable(DMA1_CHANNEL1, DMA_FDT_INT, TRUE);

    /* dmamux function enable */
    dmamux_enable(DMA1, TRUE);
    dmamux_init(DMA1MUX_CHANNEL1, DMAMUX_DMAREQ_ID_USART1_RX);

    dma_reset(DMA1_CHANNEL2);
    dma_default_para_init(&dma_init_struct);
    dma_init_struct.buffer_size = DMA_BYTE_LENGTH;
    dma_init_struct.direction = DMA_DIR_MEMORY_TO_PERIPHERAL;
    dma_init_struct.memory_base_addr = (uint32_t)USART1_DMA_PUTBUFF;
    dma_init_struct.memory_data_width = DMA_MEMORY_DATA_WIDTH_BYTE;
    dma_init_struct.memory_inc_enable = TRUE;
    dma_init_struct.peripheral_base_addr = (uint32_t)&USART1->dt;
    dma_init_struct.peripheral_data_width = DMA_PERIPHERAL_DATA_WIDTH_BYTE;
    dma_init_struct.peripheral_inc_enable = FALSE;
    dma_init_struct.priority = DMA_PRIORITY_MEDIUM;
    dma_init_struct.loop_mode_enable = FALSE;
    dma_init(DMA1_CHANNEL2, &dma_init_struct);

    /* enable transfer full data intterrupt */
    dma_interrupt_enable(DMA1_CHANNEL2, DMA_FDT_INT, TRUE);

    /* dmamux function enable */
    dmamux_enable(DMA1, TRUE);
    dmamux_init(DMA1MUX_CHANNEL2, DMAMUX_DMAREQ_ID_USART1_TX);

    nvic_irq_enable(DMA1_Channel1_IRQn, 1, 2);
    nvic_irq_enable(DMA1_Channel2_IRQn, 1, 1);

    dma_channel_enable(DMA1_CHANNEL1, TRUE); /* usart1 rx begin dma receiving */
    // dma_channel_enable(DMA1_CHANNEL2, TRUE); /* usart1 tx begin dma transmitting */
}

void DMA_USART1_SendMove(void)
{
    uint16_t length = CBUF_Len(uart1_putbuf);
    if (USART1_DMA_Put_Flag == 0)
    {
        if (length > DMA_TX_MAX_LEN)
        {
            USART1_DMA_Put_Flag = 1;
            /* set the number of remaining data to be transferred by the DMA */
            dma_data_number_set(DMA1_CHANNEL2, DMA_TX_MAX_LEN);
            uint8_t i;
            for (i = 0; i < DMA_TX_MAX_LEN; i++)
            {
                USART1_DMA_PUTBUFF[i] = CBUF_Pop(uart1_putbuf);
            }
            dma_channel_enable(DMA1_CHANNEL2, TRUE);
        }
        else if (length > 0)
        {
            USART1_DMA_Put_Flag = 1;
            /* set the number of remaining data to be transferred by the DMA */
            dma_data_number_set(DMA1_CHANNEL2, length);
            uint8_t i;
            for (i = 0; i < length; i++)
            {
                USART1_DMA_PUTBUFF[i] = CBUF_Pop(uart1_putbuf);
            }
            dma_channel_enable(DMA1_CHANNEL2, TRUE);
        }
    }
}
