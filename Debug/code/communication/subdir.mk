################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/communication/CircleBuffer.c \
../code/communication/ComPort.c \
../code/communication/ComTask.c \
../code/communication/Communication.c \
../code/communication/DebugData.c 

OBJS += \
./code/communication/CircleBuffer.o \
./code/communication/ComPort.o \
./code/communication/ComTask.o \
./code/communication/Communication.o \
./code/communication/DebugData.o 

C_DEPS += \
./code/communication/CircleBuffer.d \
./code/communication/ComPort.d \
./code/communication/ComTask.d \
./code/communication/Communication.d \
./code/communication/DebugData.d 


# Each subdirectory must supply rules for building sources it contributes
code/communication/%.o: ../code/communication/%.c code/communication/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../include" -I"../include/libraries/drivers/inc" -I"../include/libraries/cmsis/cm4/core_support" -I"../include/libraries/cmsis/cm4/device_support" -I"E:\at_workspace\GBA_PowerControl\code\APP" -I"E:\at_workspace\GBA_PowerControl\code\communication" -I"E:\at_workspace\GBA_PowerControl\code\mcu_drive" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


