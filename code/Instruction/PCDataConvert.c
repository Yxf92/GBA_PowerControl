#include "at32f423.h"
#include "PCDataConvert.h"
#include "delay.h"
#include "main.h"
#include "math.h"
#include "string.h"
#include "DebugData.h"
#include "Tasksch.h"
#include "ComTask.h"
#include "stdio.h"
#include "Loop.h"
#include "UserIdentifier.h"

void CarryoutOrder(uint8_t *data)
{
    RecoverySendDebugData();

    switch (data[0])
    {
    case PITCH_PID_RX: //   接收新的PID数据
        break;

    case ROLL_PID_RX:
        break;

    case YAW_PID_RX:
        break;

    case PID12_RX:
        break;

    case PID34_RX:
        break;

    case PID_RESET_RX: // 读取flash里存储的PID参数
        break;

    case PID_SAVE_RX: // 保存现在的PID数据
        break;

    case RESETPID_RX: // 恢复出厂pid参数
        break;

    case ACCSIXFACECALI: // 做六面校准
        break;

    case ACCSIXFACEERA: // 擦除六面校准数据
        break;

    case TEMPCALIB_RX: // 加速度陀螺仪温度校准
        break;

    case TEMPCALIB_ERA_RX: // 擦除温度校准数据
        break;

    case READTEMPCALI_RX: // 读取温度校准数据
        break;

    case ENCCALI_RX: // 编码器校准
        break;

    case ENCCALIB_ERA_RX: // 擦除编码器校准数据
        break;

    case READENCCALI_RX: // 读取编码器校准数据
        break;

    case PREFRONTCALIB_RX: // 前向预校准
        break;

    case ZEROCALIB_RX: // 零位校准
        break;

    case ZERO_ERA_RX: // 擦除零位校准数据
        break;

    case ACCCALIB_RX: // 校准加速度计数据
        break;

    case ACCCALI_ERA_RX: // 擦除加速度计校准数据  同时需要清楚前向设置数据
        break;

    case FRONT_CALIB_RX: // 前向设置
        break;

    case FRONT_ZERO_RX: // 清除前向设置数据
        break;

    case POWEROFF_RX: // 关闭马达功率
        break;

    case POWERON_RX: // 打开马达功率
        break;

    case VERSION_RX:
        break;

    case RESTARTGB_RX: // 重启云台
        MCU_Reboot();
        break;

    case GRYACCHF_RX: // 高频加速度陀螺仪
        break;

    case SETPARA_RX: // 设置参数
        break;

    case READPARA_RX: // 读取参数
        break;

    case MOTORTEST_RX: // 马达测试
        break;

    case MACHINE_TEST_RX: // 震动检测
        break;

    case MACHINEAGINGTEST_RX:
        break;

    case IMUTEST_RX:
        break;

    case READUID_RX: // 读取UID数据
        break;

    case GRYHF_RX: // 读取高频陀螺仪数据
        break;

    case ACCHF_RX: // 读取高频加速度数据
        break;

    case CLOSEHF_RX: // 关闭发送高频数据
        break;

    case GYRANGLEERRHF_RX: // 读取高频陀螺仪角度误差数据
        break;

    case READCALISTATE_RX: // 读取校准校准状态
        break;

    case MECHSTEPTEST_RX: // 机械响应时间测试
        break;

    case MACHINERESONACETEST_RX: // 机械共振测试
        break;

    case MACHINESHAKETEST_RX:
        break;

    case MOTORFORCETEST_RX: // 马达力矩测试
        break;

    case HEADCALI_RX: // 校准云台的yaw前向
        break;
    }
}