#include "ComPort.h"
#include "CircleBuffer.h"

extern uint8_t transmission_flag;

#ifdef MAVLINK_SEPARATE_HELPERS
#include "../MAVLINK2/mavlink_helpers.h"
#endif

mavlink_system_t mavlink_system = {1, 154};

uint8_t comm_receive_ch(mavlink_channel_t chan)
{
    if (chan > MAVLINK_COMM_NUM_BUFFERS)
    {
        return 0;
    }
    uint8_t ret = 0;
    switch (chan)
    {
    case MAVLINK_COMM_0:
        ret = CBUF1_GetByte();
        break;
    case MAVLINK_COMM_1:
        break;
    case MAVLINK_COMM_2:
        break;
    case MAVLINK_COMM_3:
        break;
    default:
        break;
    }
    return ret;
}

uint16_t comm_get_txspace(mavlink_channel_t chan)
{
    if (chan >= MAVLINK_COMM_NUM_BUFFERS)
    {
        return 0;
    }
    switch (chan)
    {
    case MAVLINK_COMM_0:
        //
        break;
    case MAVLINK_COMM_1:
        break;
    case MAVLINK_COMM_2:
        break;
    case MAVLINK_COMM_3:
        break;
    default:
        break;
    }
    return 0;
}

uint16_t comm_get_available(mavlink_channel_t chan)
{
    if (chan >= MAVLINK_COMM_NUM_BUFFERS)
    {
        return 0;
    }
    uint16_t bytes = 0;
    switch (chan)
    {
    case MAVLINK_COMM_0:
        bytes = CBUF1_Len();
        break;
    case MAVLINK_COMM_1:
        break;
    case MAVLINK_COMM_2:
        break;
    case MAVLINK_COMM_3:
        break;
    default:
        break;
    }
    return bytes;
}

void comm_send_ch(mavlink_channel_t chan, uint8_t ch)
{
    if ((chan >= MAVLINK_COMM_NUM_BUFFERS) || (transmission_flag == 1))
    {
        return;
    }
    switch (chan)
    {
    case MAVLINK_COMM_0:
        CBUF1_PutByte(ch);
        break;
    case MAVLINK_COMM_1:
        break;
    case MAVLINK_COMM_2:
        break;
    case MAVLINK_COMM_3:
        break;
    default:
        break;
    }
}

void comm_send_buffer(mavlink_channel_t chan, const uint8_t *buf, uint8_t len)
{
    if ((chan >= MAVLINK_COMM_NUM_BUFFERS) || (transmission_flag == 1))
    {
        return;
    }
    switch (chan)
    {
    case MAVLINK_COMM_0:
        CBUF1_PutStr(buf, len);
        break;
    case MAVLINK_COMM_1:
        break;
    case MAVLINK_COMM_2:
        break;
    case MAVLINK_COMM_3:
        break;
    default:
        break;
    }
}

bool comm_is_idle(mavlink_channel_t chan)
{
    mavlink_status_t *status = mavlink_get_channel_status(chan);
    return status == NULL || status->parse_state <= MAVLINK_PARSE_STATE_IDLE;
}
