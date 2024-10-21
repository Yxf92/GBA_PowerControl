#include "main.h"
#include "target.h"
#include "protect.h"
#include "delay.h"
#include "ConctrolLed.h"
#include "Tasksch.h"

float Volbus, V3bus;
int16_t curr;

void TPS54302_Set_VBAT(uint8_t mode)
{
    switch (mode)
    {
    case 0:
        dac_1_data_set(DAC1_12BIT_RIGHT, 730);
        dac_software_trigger_generate(DAC1_SELECT);
        break;

    case 1:
        dac_1_data_set(DAC1_12BIT_RIGHT, 770);
        dac_software_trigger_generate(DAC1_SELECT);
        break;

    default:
        dac_1_data_set(DAC1_12BIT_RIGHT, 770);
        dac_software_trigger_generate(DAC1_SELECT);
        break;
    }
}

void ReadVolData(void)
{
    int32_t v3dat, voldat;
    float voltage_3v, voltage;

    v3dat = ADC_3V_ADC;
    voldat = VBAT_ADC;
    voltage_3v = (((float)v3dat + ADCOFFSET) * (ADCRANGE / ADCRESOLUTION));
    voltage = (((float)voldat + ADCOFFSET) * (ADCRANGE / ADCRESOLUTION)) / RES_DIV;// / (RES_UP / (RES_DOWN + RES_UP));

    V3bus = V3bus * 0.98f + voltage_3v * 0.02f;
    Volbus = Volbus * 0.9f + voltage * 0.1f;
}

void Voltage_monitor(void)
{
    static uint8_t state = 0;
    switch (state)
    {
    case 0:
        if (Volbus < 7.3)
        {
            SET_LedMod(YELLOWON, 50, -1);
            state = 1;
        }
        break;

    case 1:
        if (Volbus < 6.76)
        {
            TPS54302_Set_VBAT(Low_v);
            GBA_State.Error_flag = Vin_low;
            SET_LedMod(REDON, 50, -1);
            state = 2;
        }
        break;

    case 2:
        if (Volbus < 6.2)
        {
            TPS54302_Set_VBAT(Low_v);
            GBA_State.Error_flag = Vin_low;
            SET_LedMod(RED, 100, -1);
            state = 3;
        }
        break;

    default:
        break;
    }
}

void PROTECT_Loop(void)
{
    if (Volbus > 10.0)
    {
        EN_3V_RESET;
        GBA_State.Error_flag = Vin_hi;
        SET_LedMod(RED_BLUE, 300, -1);
        DefaultTask(VOLPROTECT_TN);
    }
    if (Volbus < 4.7)
    {
        EN_3V_RESET;
        GBA_State.Error_flag = Vin_low;
        SET_LedMod(RED, 300, -1);
        DefaultTask(VOLPROTECT_TN);
    }
    else if(V3bus > 3.2f)
    {
        EN_3V_RESET;
        GBA_State.Error_flag = V3_hi;
        SET_LedMod(RED_GREEN_BLUE, 300, -1);
        DefaultTask(VOLPROTECT_TN);
    }
    else if (Volbus > 8.8 && GBA_State.Dc_state == NC_Vin)
    {
        TPS54302_Set_VBAT(Normal_v);
        delay_ms(1);
        EN_3V_SET;
        GBA_State.Dc_state = Dc_Vin;
        GBA_State.Error_flag = No_error;
        SET_LedMod(PURPLEON, 50, -1);
    }
    else if (Volbus >= 6.0 && Volbus <= 8.3 && GBA_State.Dc_state == NC_Vin)
    {
        TPS54302_Set_VBAT(Normal_v);
        delay_ms(1);
        EN_3V_SET;
        GBA_State.Dc_state = Bat_Vin;
        GBA_State.Error_flag = No_error;
        SET_LedMod(GREENON, 50, -1);
    }

    Voltage_monitor();
}
