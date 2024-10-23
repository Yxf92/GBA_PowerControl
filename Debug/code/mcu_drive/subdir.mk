################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/mcu_drive/adc.c \
../code/mcu_drive/at32f423_clock.c \
../code/mcu_drive/at32f423_int.c \
../code/mcu_drive/dac.c \
../code/mcu_drive/delay.c \
../code/mcu_drive/flash.c \
../code/mcu_drive/gpio.c \
../code/mcu_drive/tim.c \
../code/mcu_drive/usart.c \
../code/mcu_drive/wdt.c 

OBJS += \
./code/mcu_drive/adc.o \
./code/mcu_drive/at32f423_clock.o \
./code/mcu_drive/at32f423_int.o \
./code/mcu_drive/dac.o \
./code/mcu_drive/delay.o \
./code/mcu_drive/flash.o \
./code/mcu_drive/gpio.o \
./code/mcu_drive/tim.o \
./code/mcu_drive/usart.o \
./code/mcu_drive/wdt.o 

C_DEPS += \
./code/mcu_drive/adc.d \
./code/mcu_drive/at32f423_clock.d \
./code/mcu_drive/at32f423_int.d \
./code/mcu_drive/dac.d \
./code/mcu_drive/delay.d \
./code/mcu_drive/flash.d \
./code/mcu_drive/gpio.d \
./code/mcu_drive/tim.d \
./code/mcu_drive/usart.d \
./code/mcu_drive/wdt.d 


# Each subdirectory must supply rules for building sources it contributes
code/mcu_drive/%.o: ../code/mcu_drive/%.c code/mcu_drive/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../include" -I"../include/libraries/drivers/inc" -I"../include/libraries/cmsis/cm4/core_support" -I"../include/libraries/cmsis/cm4/device_support" -I"E:\at_workspace\GBA_PowerControl\code\APP" -I"E:\at_workspace\GBA_PowerControl\code\communication" -I"E:\at_workspace\GBA_PowerControl\code\mcu_drive" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


