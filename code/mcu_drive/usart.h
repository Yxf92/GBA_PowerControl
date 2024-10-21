#ifndef USART_H
#define USART_H

#include "at32f423.h"

#define DMA_BYTE_LENGTH   12   //minimize mavlink msg size
#define DMA_TX_MAX_LEN    128
#define DMA_BUFF_MAX_LEN  128

extern volatile uint8_t USART1_DMA_GETBUFF[DMA_BUFF_MAX_LEN];
extern volatile uint8_t USART1_DMA_PUTBUFF[DMA_BUFF_MAX_LEN];

extern volatile uint8_t USART1_DMA_Put_Flag;
extern volatile uint8_t USART1_DMA_Get_Flag;

void USART1_Config_Cbuf(uint32_t baudrate);
void USART1_dma_configuration(void);
void DMA_USART1_SendMove(void);

#endif
