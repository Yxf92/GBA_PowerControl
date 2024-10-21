#ifndef __MAIN_H__
#define __MAIN_H__

#include "at32f423_conf.h"
#include "at32f423.h"
#include "stdint.h"
#include "stdbool.h"
#include "target.h"
#include "ConctrolLed.h"
#include "../APP/version.h"

#include "usart.h"
#include "gpio.h"
#include "tim.h"
#include "flash.h"
#include "dac.h"
#include "adc.h"
#include "wdt.h"

typedef struct
{
    uint8_t Vin_mode;
    uint8_t Dc_state;
    uint8_t Error_flag;
} GBA_STATE;

typedef enum
{
    Bat_Vin = 0,
    Dc_Vin,
    NC_Vin = 255,
} GBA_STATE_FLAG;

typedef enum
{
    Vin_low = 0,
    Vin_hi,
    V3_hi,
    No_error = 255,
} GBA_ERROR_FLAG;

typedef enum
{
    Normal_v = 0,
    Low_v,
} TPS54302_MODE;

extern GBA_STATE GBA_State;

void MCU_Reboot(void);

#endif
