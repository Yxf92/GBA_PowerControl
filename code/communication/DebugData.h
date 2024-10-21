#ifndef __DEBUGDATA_H__
#define __DEBUGDATA_H__

#include "at32f423.h"
#include "main.h"

#define MOTORGRY_PRY 0x00001000

#define PWM1_PWM2 0x00008000
#define Global_LowAcc 0x00000080
#define PLANE_GIMBAL 0x00000100
#define NONE_BUTTON1 0x00002000
#define POWER_AIRACC 0x00004000

typedef enum
{
    PITCH_PID_RX = 1,            // PITCH 轴PID
    ROLL_PID_RX = 2,             // ROLL 轴PID
    YAW_PID_RX = 3,              // YAW 轴PID
    PID12_RX = 4,                // PID12
    PID34_RX = 5,                // PID34
    PID_RESET_RX = 6,            // 读取存储在flash里面的PID数据
    PID_SAVE_RX = 7,             // 将PID数据存储在flash里面
    RESETPID_RX = 8,             // 恢复PID的出厂设置
    TEMPCALIB_RX = 9,            // 温度校准
    TEMPCALIB_ERA_RX = 10,       // 擦除温度校准数据
    READTEMPCALI_RX = 11,        // 读取温度校准数据
    ENCCALI_RX = 12,             // 编码器校准
    ENCCALIB_ERA_RX = 13,        // 编码器校准数据擦除
    READENCCALI_RX = 14,         // 读取编码器校准数据
    PREFRONTCALIB_RX = 15,       // 开始前向预校准
    ZEROCALIB_RX = 16,           // 零位校准
    ZERO_ERA_RX = 17,            // 擦除零位校准数据
    ACCCALIB_RX = 18,            // 加速度计球形校准
    ACCCALI_ERA_RX = 19,         // 擦除加速度计球形校准数据
    FRONT_CALIB_RX = 20,         // 前向校准
    FRONT_ZERO_RX = 21,          // 擦除前向校准数据
    POWEROFF_RX = 22,            // 关闭马达电源
    POWERON_RX = 23,             // 打开马达电源
    VERSION_RX = 24,             // 发送软件版本号
    RESTARTGB_RX = 25,           // 重启云台
    GRYACCHF_RX = 26,            // 开启发送1ms周期的加速度及陀螺仪数据
    HFPERIOD_RX = 27,            // 设置高频数据的周期
    SETPARA_RX = 28,             // 改写控制参数
    READPARA_RX = 29,            // 读取控制参数
    MOTORTEST_RX = 30,           // 开始马达测试
    MACHINE_TEST_RX = 32,        // 机械综合检测
    SOCKETTEST_RX = 33,          // 开始PCB检测
    MACHINEAGINGTEST_RX = 34,    // 开始機械老化测试
    IMUTEST_RX = 35,             // 开始IMU综合测试
    READUID_RX = 36,             // 读取UID数据
    GRYHF_RX = 37,               // 高频陀螺仪数据
    ACCHF_RX = 38,               // 高频加速度计数据
    CLOSEHF_RX = 39,             // 关闭高频数据
    GYRANGLEERRHF_RX = 40,       // 高频陀螺仪 角度数据
    READCALISTATE_RX = 41,       // 读取校准状态数据
    ACCSIXFACECALI = 43,         // 加速度计六面校准
    ACCSIXFACEERA = 44,          // 加速度计六面校准擦除
    MECHSTEPTEST_RX = 45,        // 机械阶跃测试
    MACHINERESONACETEST_RX = 47, // 机械共振检测
    MACHINESHAKETEST_RX = 48,    // 机械震动测试
    MAGCALIB_RX = 49,            // 开始地磁校准
    MAGCALI_ERA_RX = 50,         // 擦除地磁数据
    TASKCHANGE_RX = 51,          // 切换任务状态
    HEADCALI_RX = 52,            // 校准云台的前向
    MOTORFORCETEST_RX = 53,      // 马达力矩测试
} order_RX;

typedef enum
{
    GRYPOWER_TX = 1,        // 角速度环相关参数   数据包
    AGNLEEULER_TX = 2,      // 角速度环相关参数   数据包
    ACC_TX = 3,             // 加速度计以及姿态相关参数  数据包
    CHANNEL_TX = 4,         // 通道值  数据包
    TEMPDIFF_TX = 5,        // 陀螺仪校准以及恒温相关参数 数据包
    GBSTATE_TX = 6,         // 云台状态 数据包
    DATAHIGH_TX = 7,        // 高速数据包  数据包
    GRYACCHF_TX = 8,        // 1ms周期的加速度计以及陀螺仪数据
    PITCH_PID_TX = 9,       // PITCH轴PID数据
    ROLL_PID_TX = 10,       // ROLL轴PID数据
    YAW_PID_TX = 11,        // YAW轴PID数据
    PID12_TX = 12,          // PID12
    PID34_TX = 13,          // PID34
    READUINT32PARA_TX = 14, // uint32的控制参数
    READFLOATPARA_TX = 15,  // float型的控制参数
    TEMPCALIDATA_TX = 16,   // 温度校准数据
    TEMPCALILINE_TX = 17,   // 温度校准数据线性拟合公式
    UID_TX = 18,            // UID数据
    TEMPRATURELINE_TX = 19, // 温升曲线数据
    ENCCALILINE_TX = 20,    // 编码器校准曲线数据
    DRAGCALILINE_TX = 21,   // 阻力校准曲线数据
    ACCCALIDATA_TX = 22,    // 加速度校准数据
    GRYHF_TX = 23,          // 高频陀螺仪数据
    ACCHF_TX = 24,          // 高频加速度计数据
    GRYANGLEERRHF_TX = 25,  // 高频陀螺仪校准误差数据
    BASEDATA_TX = 26,       // 发给遥控器的一些数据
    airplaneData_TX = 27,   // 飞机上传输下来的一些GPS等速度加速度等信息
    AIRCRAFTDATA_TX = 28,   // 飞机的详细状态信息
    GIMBALMAGGPS_TX = 29,   // 云台的GPS，地磁等信息
    STANDARTDATA_TX = 30,   // 标准数据信息
    AGNLEEULER1_TX = 31,    // 新角度相关数据
} order_TX;

typedef struct // 32byte 发送PID控制数据结构体
{
    float aPID_kp;
    float aPID_ki;
    float aPID_kd;
    float sPID_kp;
    float sPID_ki;
    float sPID_kd;
    float POWER; // 4
    float PARA;  // 4
} RFPid_data;

typedef struct // 32byte 发送PID控制数据结构体
{
    uint16_t gimbalglag;
    uint8_t highvariable[6];
    float PID1_kp;
    float PID1_ki;
    float PID1_kd;
    float PID2_kp;
    float PID2_ki;
    float PID2_kd;
} PID12_data;

typedef struct // 16
{
    uint32_t systime;
    int16_t data0;
    int16_t data1;
    int16_t data2;
    int16_t data3;
    int16_t data4;
    int16_t data5;
} higespeeddata;

typedef struct // 34byte  //速度环相关数据
{
    uint32_t systime;
    int16_t gryohope_x;
    int16_t gryohope_y;
    int16_t gryohope_z;
    int16_t gryo_x;
    int16_t gryo_y;
    int16_t gryo_z;
    int16_t speedhope_pitch;
    int16_t speedhope_roll;
    int16_t speedhope_yaw;
    int16_t speed_pitch;
    int16_t speed_roll;
    int16_t speed_yaw;
    int16_t force_pitch;
    int16_t force_roll;
    int16_t force_yaw;
} grypower_data;

typedef struct // 34byte  //角度环相关数据
{
    uint32_t systime;
    int16_t anglehope_x;
    int16_t anglehope_y;
    int16_t anglehope_z;
    int16_t angle_x;
    int16_t angle_y;
    int16_t angle_z;
    int16_t eulerhope_pitch;
    int16_t eulerhope_roll;
    int16_t eulerhope_yaw;
    int16_t euler_pitch;
    int16_t euler_roll;
    int16_t euler_yaw;
    int16_t angleerr_x;
    int16_t angleerr_y;
    int16_t angleerr_z;
} angleeuler_data;

typedef struct // 34byte  一些加速度计/姿态相关数据
{
    uint32_t systime;
    int16_t acclowpass_x;
    int16_t acclowpass_y;
    int16_t acclowpass_z;
    int16_t acclowpass;
    int16_t acc_x;
    int16_t acc_y;
    int16_t acc_z;
    int16_t acc;
    int16_t horizontalacc;
    int16_t verticalacc;
    int16_t acckp;
    int16_t accki;
    int16_t acckd;
    int16_t horizontalaccchange_x;
    int16_t horizontalaccchange_y;
} acc_data;

typedef struct // 20byte  一些通道值
{
    uint32_t systime;
    int16_t ch0;
    int16_t ch1;
    int16_t ch2;
    int16_t ch3;
    int16_t ch4;
    int16_t ch5;
    int16_t ch6;
    int16_t ch7;
} channel_data;

typedef struct // 30byte
{
    uint32_t systime;
    int16_t HistroyZroTolerance_x; // 陀螺仪静差历史数据
    int16_t HistroyZroTolerance_y;
    int16_t HistroyZroTolerance_z;
    int16_t ZroTolerance_x; // 陀螺仪本次静差数据
    int16_t ZroTolerance_y;
    int16_t ZroTolerance_z;
    int16_t ZroVariation_x; // 陀螺仪实时温漂
    int16_t ZroVariation_y;
    int16_t ZroVariation_z;
    int16_t TempHope;
    int16_t HeatPower;
    int16_t TempIntegral;
    int16_t IMUTemp;
} tempdiff_data;

typedef struct // 29byte 云台的一些状态值
{
    uint32_t systime;
    int16_t voltage;
    int16_t current;
    int16_t systime_s;
    int16_t encdata_p;
    int16_t encdata_r;
    int16_t encdata_y;
    int16_t stageangle_x;
    int16_t stageangle_y;
    int16_t aircraftangle_x;
    int16_t aircraftangle_y;
    int16_t aircraftangle_z;
    int8_t grystable_x;
    int8_t grystable_y;
    int8_t grystable_z;
} gimbalstate_data;

typedef struct // 22byte 云台发送给遥控器的一些状态值
{
    uint32_t systime;
    int16_t speed_pitch;
    int16_t speed_roll;
    int16_t speed_yaw;
    int16_t acc_x;
    int16_t acc_y;
    int16_t acc_z;
    int16_t angerror_x;
    int16_t angerror_y;
    int16_t angerror_z;
} base_data;

typedef struct // 18byte 飞机的一个GPS等速度数据
{
    uint32_t systime;
    int16_t raw_gps_vn;
    int16_t raw_gps_ve;
    int16_t fusion_vn;
    int16_t fusion_ve;
    int16_t reliability;
    int16_t Hacc;
    int16_t Hvel;
} autopilot_data;

typedef struct // 飞机的位置数据
{
    uint32_t systime;
    int16_t aircraft_angleX;    //*100
    int16_t aircraft_angleY;    //*100
    int16_t aircraft_angleZ;    //*100
    int16_t aircraft_latitude;  //*100
    int16_t aircraft_longitude; //*100
    int16_t aircraft_altitude;  //*100
    int16_t aircraft_speedX;    //*100
    int16_t aircraft_speedY;    //*100
    int16_t aircraft_speedZ;    //*100
    int16_t aircraft_accX;      //*1000
    int16_t aircraft_accY;      //*1000
    int16_t aircraft_accZ;      //*1000
    int16_t reliability;        //*1
} aircraft_data;

typedef struct // 云台的GPS数据
{
    uint32_t systime;
    int16_t gimbal_magnetX;   //*1000
    int16_t gimbal_magnetY;   //*1000
    int16_t gimbal_magnetZ;   //*1000
    int16_t gimbal_magnetLen; //*1000
    int16_t gimbal_latitude;  //*100
    int16_t gimbal_longitude; //*100
    int16_t gimbal_altitude;  //*100
    int16_t gimbal_speedX;    //*100
    int16_t gimbal_speedY;    //*100
    int16_t gimbal_speedZ;    //*100
    int16_t reliability;      //*1
} gimbal_mag_gps_data;

typedef struct // 标准数据
{
    uint32_t systime;
    int16_t DATA0;  //*1
    int16_t DATA1;  //*1
    int16_t DATA2;  //*1
    int16_t DATA3;  //*1
    int16_t DATA4;  //*1
    int16_t DATA5;  //*1
    int16_t DATA6;  //*1
    int16_t DATA7;  //*1
    int16_t DATA8;  //*1
    int16_t DATA9;  //*1
    int16_t DATA10; //*1
    int16_t DATA11; //*1
} standard_data;

typedef struct // 49byte  高速加速度计以及陀螺仪数据
{
    uint32_t systime;
    uint8_t highgryoacc[45];
} gryacchigh_data;

typedef struct // 49byte  高速加速度计以及陀螺仪数据
{
    uint32_t systime;
    uint8_t highgryoangleerr[45];
} gryangleerrhigh_data;

typedef struct // 34byte  高速加速度计以及陀螺仪数据
{
    uint32_t systime;
    int16_t highgryo[15];
} gryhigh_data;

typedef struct // 34byte  高速加速度计以及陀螺仪数据
{
    uint32_t systime;
    int16_t highacc[15];
} acchigh_data;

typedef struct // 18byte  温度校准遍历数据
{
    int16_t dataID;
    int16_t sum;
    int16_t gryo_x;
    int16_t gryo_y;
    int16_t gryo_z;
    int16_t acc_x;
    int16_t acc_y;
    int16_t acc_z;
    int16_t temperature;
} tempcali_data;

typedef struct // 24byte  温度校准遍历数据
{
    int16_t dataID;
    int16_t sum;
    int16_t temprature[10];
} templine_data;

typedef struct // 46byte  温度校准线性拟合数据
{
    float line_k;
    float line_b;
    float line_r;
    float line_hk;
    float line_hb;
    float line_hr;
    float line_lk;
    float line_lb;
    float line_lr;
    float tempstart;
    float tempend;
    int16_t dataID;
} templinecali_data;

typedef struct // 24byte  编码器校准数据
{
    int16_t dataID;
    int16_t sum;
    float enk;
    int16_t encdata[8];
} enccali_data;

typedef struct // 28byte  阻动比校准数据
{
    uint16_t dataID;
    uint16_t sum;
    int8_t dragdata1_x[4];
    int8_t dragdata1_y[4];
    int8_t dragdata1_z[4];

    int8_t dragdata2_x[4];
    int8_t dragdata2_y[4];
    int8_t dragdata2_z[4];
} Dragcali_data;

typedef struct // 22byte  加速度校准校准数据
{
    uint16_t dataID;
    uint16_t sum;
    int16_t temp;
    int16_t preaccdata_x;
    int16_t preaccdata_y;
    int16_t preaccdata_z;
    int16_t preaccdata_all;
    int16_t accdata_x;
    int16_t accdata_y;
    int16_t accdata_z;
    int16_t accdata_all;
} Acccali_data;

void SendDebugDataInit(void);
void DefaultSendDebugData(void);
void RecoverySendDebugData(void);
void PacketDebugData0(void);
void PacketDebugData1(void);
void PacketDebugData2(void);
void PacketDebugData3(void);
void PacketDebugData4(void);
void PacketDebugData5(void);
void PacketAircraftData(void);
void PacketStandardData(void);
void RF_ComData(char *SendArry);
void SendOneTime(uint8_t order, uint8_t *data, uint8_t lenth);
void SendOneTime1(uint8_t order, uint8_t *data, uint8_t lenth);
void PacketAircraftData(void);
void SendDebugData(void);
#endif
