#ifndef __CIRCLEBUFFER_H__
#define __CIRCLEBUFFER_H__

#include "at32f423.h"
#include "CBUF.h"

#define USARTBUFSIZE 1024

#define uart1_getbuf_SIZE USARTBUFSIZE
#define uart1_putbuf_SIZE USARTBUFSIZE

typedef struct
{
    uint16_t m_getIdx;
    uint16_t m_putIdx;
    uint8_t m_entry[USARTBUFSIZE];
} USARTCBUF;

extern USARTCBUF uart1_putbuf, uart1_getbuf;

void CircleBuffer_Init(void);
uint16_t CBUF1_Len(void);
uint8_t CBUF1_GetByte(void);
void CBUF1_PutByte(char c);
void CBUF1_PutStr(const uint8_t *data, uint16_t size);

#endif
