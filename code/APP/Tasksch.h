#ifndef __Tasksch_H__
#define __Tasksch_H__
#include "at32f423.h"

#define MAXTASKS 25
typedef enum
{
    SENDDEBUGDATA0_TN = 0, // 发送上位机数据
    MAVLINKHEART_TN,       // 发送mavlink0的心跳包
    UPDATEMAVLINK_TN,      // 接收mavlink0上的数据
    UI_UPDATE_TN,          // UI显示
    VOLPROTECT_TN,         // 过压保护
    LEDHANDLE,             // LED状态机
    CAPCHARGE_TN,
} TASKKIND;
typedef struct
{
    int16_t times;      // 执行次数
    int16_t period_cnt; // 时间计数器
    int16_t period;     // 周期
    void (*fp)(uint8_t i);
} TASK;

void HandleTask(uint8_t i);
void RunTasks(void);
void TaskCount(void);
void DefaultTask(uint8_t taskN);
uint8_t TaskTnq(uint8_t taskN);
uint8_t GetTaskBuzy(uint8_t taskN);
void RecoveryTask(uint8_t taskN);
void CreateTask(uint8_t taskN, int16_t time, int16_t td, void (*taskname)());
void SetTaskPeriod(uint8_t taskN, int16_t period);

#endif
