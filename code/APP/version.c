#include "at32f423.h"
#include "main.h"
#include "stdio.h"
#include "string.h"
#include "DebugData.h"
#include "version.h"

uint16_t GetVersionNum(void);

uint16_t app_version = 0;
uint16_t hard_version = 0;
const char AppName[] = PROJECT_NAME;
uint16_t GetVersionNum(void)
{
    uint16_t gimbal_version_num = 0;
    char arry[20] = GIMBAL_VERSION;
    char *ptr = arry;

    // remove tail content
    if (strlen(arry) >= 8)
    {
        ptr = strtok(arry, "-");
    }

    if (strlen(ptr) == 6)
    {
        gimbal_version_num = (arry[0] - 0x30) * 1000 + (arry[2] - 0x30) * 100 + (arry[3] - 0x30) * 10 + (arry[5] - 0x30);
    }
    else if (strlen(ptr) == 7)
    {
        gimbal_version_num = (arry[0] - 0x30) * 10000 + (arry[1] - 0x30) * 1000 + (arry[3] - 0x30) * 100 + (arry[4] - 0x30) * 10 + (arry[6] - 0x30);
    }
    return gimbal_version_num;
}
