################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../firmware/at32f423_acc.c \
../firmware/at32f423_adc.c \
../firmware/at32f423_can.c \
../firmware/at32f423_crc.c \
../firmware/at32f423_crm.c \
../firmware/at32f423_dac.c \
../firmware/at32f423_debug.c \
../firmware/at32f423_dma.c \
../firmware/at32f423_ertc.c \
../firmware/at32f423_exint.c \
../firmware/at32f423_flash.c \
../firmware/at32f423_gpio.c \
../firmware/at32f423_i2c.c \
../firmware/at32f423_misc.c \
../firmware/at32f423_pwc.c \
../firmware/at32f423_scfg.c \
../firmware/at32f423_spi.c \
../firmware/at32f423_tmr.c \
../firmware/at32f423_usart.c \
../firmware/at32f423_usb.c \
../firmware/at32f423_wdt.c \
../firmware/at32f423_wwdt.c \
../firmware/at32f423_xmc.c 

OBJS += \
./firmware/at32f423_acc.o \
./firmware/at32f423_adc.o \
./firmware/at32f423_can.o \
./firmware/at32f423_crc.o \
./firmware/at32f423_crm.o \
./firmware/at32f423_dac.o \
./firmware/at32f423_debug.o \
./firmware/at32f423_dma.o \
./firmware/at32f423_ertc.o \
./firmware/at32f423_exint.o \
./firmware/at32f423_flash.o \
./firmware/at32f423_gpio.o \
./firmware/at32f423_i2c.o \
./firmware/at32f423_misc.o \
./firmware/at32f423_pwc.o \
./firmware/at32f423_scfg.o \
./firmware/at32f423_spi.o \
./firmware/at32f423_tmr.o \
./firmware/at32f423_usart.o \
./firmware/at32f423_usb.o \
./firmware/at32f423_wdt.o \
./firmware/at32f423_wwdt.o \
./firmware/at32f423_xmc.o 

C_DEPS += \
./firmware/at32f423_acc.d \
./firmware/at32f423_adc.d \
./firmware/at32f423_can.d \
./firmware/at32f423_crc.d \
./firmware/at32f423_crm.d \
./firmware/at32f423_dac.d \
./firmware/at32f423_debug.d \
./firmware/at32f423_dma.d \
./firmware/at32f423_ertc.d \
./firmware/at32f423_exint.d \
./firmware/at32f423_flash.d \
./firmware/at32f423_gpio.d \
./firmware/at32f423_i2c.d \
./firmware/at32f423_misc.d \
./firmware/at32f423_pwc.d \
./firmware/at32f423_scfg.d \
./firmware/at32f423_spi.d \
./firmware/at32f423_tmr.d \
./firmware/at32f423_usart.d \
./firmware/at32f423_usb.d \
./firmware/at32f423_wdt.d \
./firmware/at32f423_wwdt.d \
./firmware/at32f423_xmc.d 


# Each subdirectory must supply rules for building sources it contributes
firmware/%.o: ../firmware/%.c firmware/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../include" -I"../include/libraries/drivers/inc" -I"../include/libraries/cmsis/cm4/core_support" -I"../include/libraries/cmsis/cm4/device_support" -I"E:\at_workspace\GBA_PowerControl\code\APP" -I"E:\at_workspace\GBA_PowerControl\code\communication" -I"E:\at_workspace\GBA_PowerControl\code\Instruction" -I"E:\at_workspace\GBA_PowerControl\code\mcu_drive" -I"E:\at_workspace\GBA_PowerControl\code\MAVLINK2" -I"E:\at_workspace\GBA_PowerControl\code\MAVLINK2\common" -I"E:\at_workspace\GBA_PowerControl\code\MAVLINK2\goertek" -I"E:\at_workspace\GBA_PowerControl\code\MAVLINK2\minimal" -I"E:\at_workspace\GBA_PowerControl\code\MAVLINK2\standard" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


