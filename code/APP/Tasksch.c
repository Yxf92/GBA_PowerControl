#include "at32f423.h"
#include "Tasksch.h"
#include "ComTask.h"
#include "DebugData.h"
/*******1号任务专门用来执行指令*****************/
TASK tasks[MAXTASKS];
void (*tasknum[MAXTASKS])();

void CreateTask(uint8_t taskN, int16_t time, int16_t period, void (*taskname)())
{
    tasknum[taskN] = taskname;                     // 指针函数
    tasks[taskN].times = time;                     // 该任务需要执行的次数
    tasks[taskN].period = period;                  // 周期
    tasks[taskN].period_cnt = tasks[taskN].period; // 周期计数器
    tasks[taskN].fp = HandleTask;                        //
}

uint8_t TaskTnq(uint8_t taskN) // 查询任务是否结束
{
    if (tasks[taskN].fp == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void DefaultTask(uint8_t taskN)
{
    tasks[taskN].fp = 0; // 解除任务
}

void RecoveryTask(uint8_t taskN)
{
    tasks[taskN].fp = HandleTask; // 恢复任务
}

uint8_t GetTaskBuzy(uint8_t taskN)
{
    if (tasks[taskN].fp == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void SetTaskPeriod(uint8_t taskN, int16_t period)
{
    tasks[taskN].period = period; // 更改任务的周期
    if (period == 0)              // 周期为0的话则将任务周期无限延长
    {
        tasks[taskN].period = 30000;
    }
}

void HandleTask(uint8_t i) // 处理任务
{
    if (tasks[i].times != 0)
    {
        tasks[i].period_cnt = tasks[i].period; // 更新任务周期计数器
        if (tasknum[i] != 0)                   // 指针不为空
        {
            tasknum[i](); // 最终调用
        }
    }
    if (tasks[i].times > 0) // 计算任务执行次数是否结束
    {
        tasks[i].times--;
        if (tasks[i].times == 0)
        {
            tasks[i].fp = 0; // 该任务完成之后，就清空该任务
        }
    }
}

void RunTasks(void)
{
    unsigned char i;
    for (i = 0; i < MAXTASKS; i++) // 轮询任务
    {
         if (tasks[i].fp != 0) // 根据优先级，依次判断函数指针是否为空
        {
            if (tasks[i].period_cnt == 0) // 如果任务时间到了
            {
                tasks[i].period_cnt = -1; // 则将任务时间改为-1
                tasks[i].fp(i);           // 调用任务处理函数，并给定任务ID i
            }
        }
    }
}

void TaskCount(void) // 任务计时器
{
    unsigned char i;
    for (i = 0; i < MAXTASKS; i++)
    {
        if (tasks[i].period_cnt > 0)
        {
            tasks[i].period_cnt--;
        }
    }
}
