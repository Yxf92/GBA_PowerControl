#include "DebugData.h"
#include "main.h"
#include "string.h"
#include "ComPort.h"
#include "ComTask.h"
#include "Tasksch.h"
#include "math.h"
#include "stdio.h"
#include "ComPort.h"
#include "Communication.h"
#include "protect.h"

void SendDebugDataInit(void)
{
    CreateTask(SENDDEBUGDATA0_TN, -1, 1, SendDebugData);
    DefaultSendDebugData();
}

void DefaultSendDebugData(void)
{
    DefaultTask(SENDDEBUGDATA0_TN);
}

void RecoverySendDebugData(void)
{
    RecoveryTask(SENDDEBUGDATA0_TN);
}

void SendDebugData(void)
{
    static uint32_t cnt = 0;
    cnt++;
    if (cnt < 1000)
    {
        return;
    }

    if (cnt % 200 == 0)
    {
        PacketDebugData0();
    }
}

void PacketDebugData0(void)
{
    char phasearry[28];
    sprintf(phasearry, "channels:%f,%f,%f,%f,%f\n", Volbus, V3bus, GBA_State.Vin_mode, GBA_State.Dc_state, GBA_State.Error_flag);
    RF_ComData(phasearry);
}

void RF_ComData(char *SendArry) // 发送字符串
{
    SendOneTime((uint8_t *)SendArry, strlen(SendArry));
}

void SendOneTime(uint8_t *data, uint8_t lenth)
{
    uint8_t RFarry[128];
    if (lenth > 127)
    {
        lenth = 127;
    }
    memcpy(RFarry, data, lenth);
    comm_send_buffer(0, RFarry, lenth);
    DMA_USART1_SendMove();
}