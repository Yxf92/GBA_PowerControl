#include "stdio.h"
#include "string.h"
#include "ComTask.h"
#include "ComPort.h"
#include "delay.h"
#include "main.h"
#include "math.h"
#include "UserIdentifier.h"
#include "Communication.h"
#include "DebugData.h"
#include "Tasksch.h"
#include "CircleBuffer.h"

void _handle_msg(Message_t *message)
{
    switch (message->msgid)
    {
    case 0:
        break;

    case 1:
        break;

    case 2:
        GREEN_LED_FLICKER;
        break;

    case 3:
        break;

    default:
        break;
    }
}

uint8_t mavlink_parse_char (uint8_t data, Message_t *msg, uint8_t status)
{
    if(data == 0xfe && status == MESSAGE_NONE)
    {
        memset(msg, 0, sizeof(Message_t));
        status = MESSAGE_HADE;
        return MESSAGE_HADE;
    }

    switch (status)
    {
    case MESSAGE_HADE:
        msg->msgid = data;
        status = MESSAGE_DATA;
        return MESSAGE_DATA;
        break;

    case MESSAGE_DATA:
        msg->data = data;
        status = MESSAGE_TELL;
        return MESSAGE_TELL;
        break;

    case MESSAGE_TELL:
        if (data == 0xee)
        {
            status = MESSAGE_NONE;
            return MESSAGE_OK;
        }
        else
        {
            status = MESSAGE_NONE;
            memset(msg, 0, sizeof(Message_t));
            return MESSAGE_NONE;
        }
        break;

    default:
        status = MESSAGE_NONE;
        memset(msg, 0, sizeof(Message_t));
        return MESSAGE_NONE;
        break;
    }

    status = MESSAGE_NONE;
    memset(msg, 0, sizeof(Message_t));
    return MESSAGE_NONE;
}
