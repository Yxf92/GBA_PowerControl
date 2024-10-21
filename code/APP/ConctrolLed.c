#include "at32f423.h"
#include "ConctrolLed.h"
#include "main.h"
#include "PCDataConvert.h"
#include "Tasksch.h"

static uint8_t ledflag = CLOSE_LED_MOD1;

void SET_LedMod(uint8_t ledmod, uint16_t period, int16_t times)
{
    if (times == 0)
    {
        times = -1;
    }
    if (period == 0)
    {
        period = 1000;
    }
    if (ledmod == CLOSE_LED_MOD && (ledflag == CLOSE_LED_MOD))
    {
        ledflag = CLOSE_LED_MOD1;
    }
    ledflag = ledmod;
    CreateTask(LEDHANDLE, times, period, LED_Handler);
}

extern TASK tasks[MAXTASKS];
void LED_Handler(void) // 500ms定时读取
{
    static uint32_t ledcnt = 0;
    if (tasks[LEDHANDLE].times == 1)
    {
        ledflag = CLOSE_LED_MOD;
    }
    ledcnt++;
    switch (ledflag)
    {
    case RED_GREEN_BLUE:
        if (ledcnt % 3 == 0)
        {
            RED_LED_ON;
            GREEN_LED_OFF;
            BLUE_LED_OFF;
        }
        else if (ledcnt % 3 == 1)
        {
            RED_LED_OFF;
            GREEN_LED_ON;
            BLUE_LED_OFF;
        }
        else if (ledcnt % 3 == 2)
        {
            RED_LED_OFF;
            GREEN_LED_OFF;
            BLUE_LED_ON;
        }
        break;
    case RED_GREEN:
        if (ledcnt % 2 == 0)
        {
            RED_LED_ON;
            GREEN_LED_OFF;
            BLUE_LED_OFF;
        }
        else if (ledcnt % 2 == 1)
        {
            RED_LED_OFF;
            GREEN_LED_ON;
            BLUE_LED_OFF;
        }
        break;
    case RED_BLUE:
        if (ledcnt % 2 == 0)
        {
            RED_LED_ON;
            GREEN_LED_OFF;
            BLUE_LED_OFF;
        }
        else if (ledcnt % 2 == 1)
        {
            RED_LED_OFF;
            GREEN_LED_OFF;
            BLUE_LED_ON;
        }
        break;
    case GREEN_BLUE:
        if (ledcnt % 2 == 0)
        {
            RED_LED_OFF;
            GREEN_LED_ON;
            BLUE_LED_OFF;
        }
        else if (ledcnt % 2 == 1)
        {
            RED_LED_OFF;
            GREEN_LED_OFF;
            BLUE_LED_ON;
        }
        break;
    case GREEN:
        RED_LED_OFF;
        GREEN_LED_FLICKER;
        BLUE_LED_OFF;
        break;
    case RED:
        RED_LED_FLICKER;
        GB_LED_FLICKER;//GB_LED
        GREEN_LED_OFF;
        BLUE_LED_OFF;
        break;
    case BLUE:
        RED_LED_OFF;
        GREEN_LED_OFF;
        BLUE_LED_FLICKER;
        break;
    case YELLOW:
        if (ledcnt % 2 == 0)
        {
            RED_LED_ON;
            GREEN_LED_ON;
            BLUE_LED_OFF;
        }
        else if (ledcnt % 2 == 1)
        {
            RED_LED_OFF;
            GREEN_LED_OFF;
            BLUE_LED_OFF;
        }
        break;
    case CYAN:
        if (ledcnt % 2 == 0)
        {
            RED_LED_OFF;
            GREEN_LED_ON;
            BLUE_LED_ON;
        }
        else if (ledcnt % 2 == 1)
        {
            RED_LED_OFF;
            GREEN_LED_OFF;
            BLUE_LED_OFF;
        }
        break;
    case PURPLE: //
        if (ledcnt % 2 == 0)
        {
            RED_LED_ON;
            GREEN_LED_OFF;
            BLUE_LED_ON;
        }
        else if (ledcnt % 2 == 1)
        {
            RED_LED_OFF;
            GREEN_LED_OFF;
            BLUE_LED_OFF;
        }
        break;
    case WHITE:
        if (ledcnt % 2 == 0)
        {
            RED_LED_OFF;
            GREEN_LED_OFF;
            BLUE_LED_OFF;
        }
        else if (ledcnt % 2 == 1)
        {
            RED_LED_ON;
            GREEN_LED_ON;
            BLUE_LED_ON;
        }
        break;
    case CYAN_RED:
        if (ledcnt % 2 == 0)
        {
            RED_LED_ON;
            GREEN_LED_OFF;
            BLUE_LED_OFF;
        }
        else if (ledcnt % 2 == 1)
        {
            RED_LED_OFF;
            GREEN_LED_ON;
            BLUE_LED_ON;
        }
        break;
    case YELLOW_BLUE:
        if (ledcnt % 2 == 0)
        {
            RED_LED_OFF;
            GREEN_LED_OFF;
            BLUE_LED_ON;
        }
        else if (ledcnt % 2 == 1)
        {
            RED_LED_ON;
            GREEN_LED_ON;
            BLUE_LED_OFF;
        }
        break;
    case PURPLE_GREEN:
        if (ledcnt % 2 == 0)
        {
            RED_LED_OFF;
            GREEN_LED_ON;
            BLUE_LED_OFF;
        }
        else if (ledcnt % 2 == 1)
        {
            RED_LED_ON;
            GREEN_LED_OFF;
            BLUE_LED_ON;
        }
        break;
    case GREENON:
        RED_LED_OFF;
        GREEN_LED_ON;
        BLUE_LED_OFF;
        break;
    case REDON:
        RED_LED_ON;
        GREEN_LED_OFF;
        BLUE_LED_OFF;
        break;
    case BLUEON:
        RED_LED_OFF;
        GREEN_LED_OFF;
        BLUE_LED_ON;
        break;
    case CYANON:
        RED_LED_OFF;
        GREEN_LED_ON;
        BLUE_LED_ON;
        break;
    case YELLOWON:
        RED_LED_ON;
        GREEN_LED_ON;
        BLUE_LED_OFF;
        break;
    case PURPLEON:
        RED_LED_ON;
        GREEN_LED_OFF;
        BLUE_LED_ON;
        GB_LED_ON;//GB_LED
        break;
    case WHITEON:
        RED_LED_ON;
        GREEN_LED_ON;
        BLUE_LED_ON;
        break;
    case CLOSE_LED_MOD:
        RED_LED_OFF;
        GREEN_LED_OFF;
        BLUE_LED_OFF;
        CreateTask(LEDHANDLE, 0, 0, 0);
        ledflag = CLOSE_LED_MOD1;
        break;
    }
    //  }
}
