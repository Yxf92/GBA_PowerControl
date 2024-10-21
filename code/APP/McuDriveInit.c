#include "McuDriveInit.h"
#include "main.h"
#include "Loop.h"
#include "target.h"

void MCU_Drive_Init(void)
{
  GPIO_Init();
  SystemTim_Configuration();

  ADC1_Init();
  DAC_Init();

  MainLoopTime_Configuration();
  USART1_Config_Cbuf(500000);

  WDT_Init();

}
