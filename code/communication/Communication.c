#include "Communication.h"
#include "ComTask.h"
#include "ComPort.h"
#include "Tasksch.h"
#include "stdbool.h"
#include "CircleBuffer.h"
#include "target.h"

static bool _initialised0 = false;

void CommunicationInit(void)
{
    CircleBuffer_Init();
    Port0_Init();
}

void Port0_Init(void)
{
    if (_initialised0)
    {
        return;
    }
    CreateTask(UPDATEMAVLINK_TN, -1, 10, Port0_Update);
    _initialised0 = true;
}

void Port0_Update(void)
{
    if (_initialised0 == false)
    {
        return;
    }

    static Message_t msg;
    static uint8_t status;
    uint16_t nbytes = comm_get_available(0);
    for (uint16_t i = 0; i < nbytes; i++)
    {
        uint8_t c = comm_receive_ch(0);
        uint8_t ret = mavlink_parse_char(c, &msg, status);
        if (ret == MESSAGE_OK)
        {
            _handle_msg(&msg);
        }
    }
}
