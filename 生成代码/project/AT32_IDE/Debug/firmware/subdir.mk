################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_adc.c \
E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_crm.c \
E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_dac.c \
E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_debug.c \
E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_dma.c \
E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_flash.c \
E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_gpio.c \
E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_misc.c \
E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_pwc.c \
E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_tmr.c \
E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_usart.c \
E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_wdt.c 

OBJS += \
./firmware/at32f423_adc.o \
./firmware/at32f423_crm.o \
./firmware/at32f423_dac.o \
./firmware/at32f423_debug.o \
./firmware/at32f423_dma.o \
./firmware/at32f423_flash.o \
./firmware/at32f423_gpio.o \
./firmware/at32f423_misc.o \
./firmware/at32f423_pwc.o \
./firmware/at32f423_tmr.o \
./firmware/at32f423_usart.o \
./firmware/at32f423_wdt.o 

C_DEPS += \
./firmware/at32f423_adc.d \
./firmware/at32f423_crm.d \
./firmware/at32f423_dac.d \
./firmware/at32f423_debug.d \
./firmware/at32f423_dma.d \
./firmware/at32f423_flash.d \
./firmware/at32f423_gpio.d \
./firmware/at32f423_misc.d \
./firmware/at32f423_pwc.d \
./firmware/at32f423_tmr.d \
./firmware/at32f423_usart.d \
./firmware/at32f423_wdt.d 


# Each subdirectory must supply rules for building sources it contributes
firmware/at32f423_adc.o: E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_adc.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_crm.o: E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_crm.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_dac.o: E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_dac.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_debug.o: E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_debug.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_dma.o: E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_dma.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_flash.o: E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_flash.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_gpio.o: E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_gpio.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_misc.o: E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_misc.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_pwc.o: E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_pwc.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_tmr.o: E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_tmr.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_usart.o: E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_usart.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

firmware/at32f423_wdt.o: E:/at_workspace/GBA_PowerControl/libraries/drivers/src/at32f423_wdt.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../../../libraries/drivers/inc" -I"../../../libraries/cmsis/cm4/core_support/" -I"../../../libraries/cmsis/cm4/device_support/" -I"../../inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


