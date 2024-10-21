#include "DebugData.h"
#include "main.h"
#include "PCDataConvert.h"
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

    if ((5 != 0) && (cnt % 200 == 0))
    {
        PacketDebugData0();
    }

    if ((200 != 0) && (cnt % 200 == 0))
    {
        PacketDebugData1();
    }

    if ((200 != 0) && (cnt % 200 == 0))
    {
        PacketDebugData2();
    }

    if ((200 != 0) && (cnt % 200 == 0))
    {
        PacketDebugData3();
    }

    if ((200 != 0) && (cnt % 200 == 0))
    {
        PacketDebugData4();
    }

    if ((200 != 0) && (cnt % 5 == 0))
    {
        PacketDebugData5();
    }

    if ((200 != 0) && (cnt % 200 == 0))
    {
        PacketAircraftData();
    }

    if ((200 != 0) && (cnt % 200 == 0))
    {
        PacketStandardData();
    }
}

#define DATA0REDUCE 30
#define DATA1REDUCE 1000
void PacketDebugData0(void)
{
    grypower_data valdata;
    valdata.systime = Get_ms();

    valdata.gryohope_x = 0 * DATA0REDUCE; // 马达角速度期望
    valdata.gryohope_y = 0 * DATA0REDUCE; // 马达角速度期望
    valdata.gryohope_z = 0 * DATA0REDUCE; // 马达角速度期望

    valdata.gryo_x = 0 * DATA0REDUCE; // 相机框角速度
    valdata.gryo_y = 0 * DATA0REDUCE; // 相机框角速度
    valdata.gryo_z = 0 * DATA0REDUCE; // 相机框角速度

    valdata.speedhope_pitch = 0 * DATA0REDUCE; // 马达角速度期望
    valdata.speedhope_roll = 0 * DATA0REDUCE;  // 马达角速度期望
    valdata.speedhope_yaw = 0 * DATA0REDUCE;   // 马达角速度期望

    valdata.speed_pitch = 0 * DATA0REDUCE; // 马达角速度
    valdata.speed_roll = 0 * DATA0REDUCE;  // 马达角速度
    valdata.speed_yaw = 0 * DATA0REDUCE;   // 马达角速度
    valdata.force_pitch = 0 * DATA1REDUCE; // 力矩期望值
    valdata.force_roll = 0 * DATA1REDUCE;  // 力矩期望值
    valdata.force_yaw = 0 * DATA1REDUCE;   // 力矩期望值

    SendOneTime(GRYPOWER_TX, (uint8_t *)(&valdata), 34);
}
#define DATA2REDUCE 100

void PacketDebugData1(void)
{
    angleeuler_data valdata;
    valdata.systime = Get_ms();
    valdata.anglehope_x = 0 * DATA2REDUCE; // 世界角期望
    valdata.anglehope_y = 0 * DATA2REDUCE;
    valdata.anglehope_z = 0 * DATA2REDUCE;
    valdata.angle_x = 0 * DATA2REDUCE; // 世界角
    valdata.angle_y = 0 * DATA2REDUCE;
    valdata.angle_z = 0 * DATA2REDUCE;
    valdata.eulerhope_pitch = 0 * DATA2REDUCE; // 欧拉角期望
    valdata.eulerhope_roll = 0 * DATA2REDUCE;
    valdata.eulerhope_yaw = 0 * DATA2REDUCE;
    valdata.euler_pitch = 0 * DATA2REDUCE; // 欧拉角
    valdata.euler_roll = 0 * DATA2REDUCE;
    valdata.euler_yaw = 0 * DATA2REDUCE;
    valdata.angleerr_x = 0 * 10000; // 世界角度误差
    valdata.angleerr_y = 0 * 10000;
    valdata.angleerr_z = 0 * 10000;
    SendOneTime(AGNLEEULER1_TX, (uint8_t *)(&valdata), 34);
}

void PacketDebugData2(void)
{
    acc_data valdata;
    valdata.systime = Get_ms();
    valdata.acclowpass_x = 0 * 1000; // 低通后的加速度值
    valdata.acclowpass_y = 0 * 1000;
    valdata.acclowpass_z = 0 * 1000;
    valdata.acclowpass = 0 * 1000;
    valdata.acc_x = 0 * 1000; // 低通前的加速度值
    valdata.acc_y = 0 * 1000;
    valdata.acc_z = 0 * 1000;
    valdata.acc = 0 * 1000;
    valdata.horizontalacc = 0 * 1000; // 加速度水平分量
    valdata.verticalacc = 0 * 1000;   // 加速度的垂直分量
    // valdata.verticalacc = 0 * 1000;                   // 飞机的水平加速度
    valdata.acckp = 0 * 1000; // 加速度计融合系数
    valdata.accki = 0 * 10000;
    valdata.acckd = 0 * 10000;
    valdata.horizontalaccchange_x = 0 * 100;
    valdata.horizontalaccchange_y = 0 * 100;
    SendOneTime(ACC_TX, (uint8_t *)(&valdata), 34);
}

void PacketDebugData3(void)
{
    channel_data valdata;
    valdata.systime = Get_ms();
    // if (DeviceInq(FC_DEVICE))
    {
        valdata.ch0 = 0;
        valdata.ch1 = 0;
        valdata.ch2 = 0;
        valdata.ch3 = 0;
        valdata.ch4 = 0;
        valdata.ch5 = 0;
        valdata.ch6 = 0;
        valdata.ch7 = 0;
        SendOneTime(CHANNEL_TX, (uint8_t *)(&valdata), 20);
    }

    PacketAircraftData();
}

void PacketDebugData4(void)
{
    tempdiff_data valdata;
    valdata.systime = Get_ms();
    valdata.HistroyZroTolerance_x = 0 * 1000;
    valdata.HistroyZroTolerance_y = 0 * 1000;
    valdata.HistroyZroTolerance_z = 0 * 1000;
    valdata.ZroTolerance_x = 0 * 1000;
    valdata.ZroTolerance_y = 0 * 1000;
    valdata.ZroTolerance_z = 0 * 1000;
    valdata.ZroVariation_x = 0 * 1000;
    valdata.ZroVariation_y = 0 * 1000;
    valdata.ZroVariation_z = 0 * 1000;
    valdata.TempHope = 0 * 100;
    valdata.HeatPower = 0;
    valdata.TempIntegral = 0;
    valdata.IMUTemp = 0 * 100;
    SendOneTime(TEMPDIFF_TX, (uint8_t *)(&valdata), 30);
}

void PacketDebugData5(void)
{
    gimbalstate_data valdata;
    valdata.systime = Get_ms();
    valdata.voltage = Volbus * 100;
    valdata.current = V3bus * 100;
    valdata.systime_s = 0;
    valdata.encdata_p = 0;
    valdata.encdata_r = 0;
    valdata.encdata_y = 0;
    valdata.stageangle_x = 0 * 100;
    valdata.stageangle_y = 0 * 100;
    valdata.aircraftangle_x = 0 * 100;
    valdata.aircraftangle_y = 0 * 100;
    valdata.aircraftangle_z = 0 * 100;
    valdata.grystable_x = 0;
    valdata.grystable_y = 0;
    valdata.grystable_z = 0;
    SendOneTime(GBSTATE_TX, (uint8_t *)(&valdata), 29);
}

void PacketAircraftData(void)
{
    aircraft_data valdata;
    valdata.systime = Get_ms();
    valdata.aircraft_angleX = 0 * 100; //*100
    valdata.aircraft_angleY = 0 * 100; //*100
    valdata.aircraft_angleZ = 0 * 100; //*100
    valdata.aircraft_latitude = 0;     //*100
    valdata.aircraft_longitude = 0;    //*100
    valdata.aircraft_altitude = 0;     //*100

    valdata.aircraft_speedX = 0;
    valdata.aircraft_speedY = 0;
    valdata.aircraft_speedZ = 0;

    valdata.aircraft_accX = 0; //*1000
    valdata.aircraft_accY = 0; //*1000
    valdata.aircraft_accZ = 0; //*1000
    valdata.reliability = 0;  //*1
    valdata.reliability = 0;
    SendOneTime(AIRCRAFTDATA_TX, (uint8_t *)(&valdata), 30);
}

void PacketStandardData(void)
{
    standard_data valdata;
    valdata.systime = Get_ms();
    valdata.DATA0 = ADC_3V_ADC;  //*1
    valdata.DATA1 = GBA_State.Vin_mode;  //*1
    valdata.DATA2 = GBA_State.Dc_state;  //*1
    valdata.DATA3 = GBA_State.Error_flag;  //*1
    valdata.DATA4 = VBAT_ADC;  //*1
    valdata.DATA5 = 0;  //*1
    valdata.DATA6 = 0;  //*1
    valdata.DATA7 = 0;  //*1
    valdata.DATA8 = 0;  //*1
    valdata.DATA9 = 0;  //*1
    valdata.DATA10 = 0; //*1
    valdata.DATA11 = 0; //*1
    SendOneTime(STANDARTDATA_TX, (uint8_t *)(&valdata), 28);
}

void RF_ComData(char *SendArry) // 发送字符串
{
    SendOneTime(0xfe, (uint8_t *)SendArry, strlen(SendArry));
}

void SendOneTime(uint8_t order, uint8_t *data, uint8_t lenth)
{
    uint8_t RFarry[128];
    if (lenth > 127)
    {
        lenth = 127;
    }
    RFarry[0] = order;
    memcpy(RFarry + 1, data, lenth);
    PCSend_send_message_Mavlink(RFarry, lenth + 1);
    DMA_USART1_SendMove();
}

void SendOneTime1(uint8_t order, uint8_t *data, uint8_t lenth)
{
    uint8_t RFarry[128];
    if (lenth > 127)
    {
        lenth = 127;
    }
    RFarry[0] = order;
    memcpy(RFarry + 1, data, lenth);
}