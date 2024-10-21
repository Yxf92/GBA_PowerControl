#include "at32f423.h"
#include "CircleBuffer.h"
#include "CBUF.h"
#include <stdarg.h>
#include "math.h"
#include "stdio.h"
#include "main.h"

USARTCBUF uart1_putbuf, uart1_getbuf;

void CircleBuffer_Init(void)
{
    CBUF_Init(uart1_getbuf);
    CBUF_Init(uart1_putbuf);
}

uint16_t CBUF1_Len(void)
{
    return CBUF_Len(uart1_getbuf);
}

uint8_t CBUF1_GetByte(void)
{
    return (CBUF_IsEmpty(uart1_getbuf) ? EOF : CBUF_Pop(uart1_getbuf));
}

void CBUF1_PutByte(char c)
{
    CBUF_Push(uart1_putbuf, c); // push the byte into circular buffer
}

void CBUF1_PutStr(const uint8_t *data, uint16_t size)
{
    while (size--)
    {
        CBUF_Push(uart1_putbuf, *data++);
    }
}
