#include "ComPort.h"
#include "CircleBuffer.h"

uint8_t comm_receive_ch(uint8_t chan)
{
    if (chan >= 1)
    {
        return 0;
    }
    uint8_t ret = 0;
    switch (chan)
    {
    case 0:
        ret = CBUF1_GetByte();
        break;
    case 1:
        break;
    default:
        break;
    }
    return ret;
}

uint16_t comm_get_txspace(uint8_t chan)
{
    if (chan >= 1)
    {
        return 0;
    }
    switch (chan)
    {
    case 0:
        //
        break;
    case 1:
        break;
    default:
        break;
    }
    return 0;
}

uint16_t comm_get_available(uint8_t chan)
{
    if (chan >= 1)
    {
        return 0;
    }
    uint16_t bytes = 0;
    switch (chan)
    {
    case 0:
        bytes = CBUF1_Len();
        break;
    case 1:
        break;
    default:
        break;
    }
    return bytes;
}

void comm_send_ch(uint8_t chan, uint8_t ch)
{
    if (chan >= 1)
    {
        return;
    }
    switch (chan)
    {
    case 0:
        CBUF1_PutByte(ch);
        break;
    case 1:
        break;
    default:
        break;
    }
}

void comm_send_buffer(uint8_t chan, const uint8_t *buf, uint8_t len)
{
    if (chan >= 1)
    {
        return;
    }
    switch (chan)
    {
    case 0:
        CBUF1_PutStr(buf, len);
        break;
    case 1:
        break;
    default:
        break;
    }
}
