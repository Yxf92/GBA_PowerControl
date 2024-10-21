#include "stdio.h"
#include "main.h"
#include "delay.h"
#include "math.h"
#include "PCDataConvert.h"
#include "arm_math.h"
#include "ComTask.h"
#include "Tasksch.h"
#include "DebugData.h"
#include "Communication.h"
#include "Loop.h"
#include "McuDriveInit.h"
#include "Tasksch.h"
#include "target.h"
#include "protect.h"

extern uint32_t start_cnt;

uint16_t mainlooptime, mainlooptimebase;

volatile uint8_t Main_Loop_Start = 0;

uint8_t status_tx, status_rx;
uint8_t txbuf[32], rxbuf[32]; // 发送缓冲

void OpenControlLoop(void)
{
    Main_Loop_Start = 1;
}

volatile uint8_t IMUDATA[14];
void ControlLoop1(void)
{
    ReadVolData();
}

void ControlLoop2(void)
{
    mainlooptimebase = Get_us();
    TaskCount(); // 任务调度时间计数
    if (Main_Loop_Start)
    {
    }    mainlooptime = Get_us() - mainlooptimebase;
}
