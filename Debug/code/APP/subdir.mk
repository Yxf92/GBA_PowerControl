################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../code/APP/ConctrolLed.c \
../code/APP/Loop.c \
../code/APP/McuDriveInit.c \
../code/APP/Tasksch.c \
../code/APP/UserIdentifier.c \
../code/APP/main.c \
../code/APP/protect.c \
../code/APP/version.c 

OBJS += \
./code/APP/ConctrolLed.o \
./code/APP/Loop.o \
./code/APP/McuDriveInit.o \
./code/APP/Tasksch.o \
./code/APP/UserIdentifier.o \
./code/APP/main.o \
./code/APP/protect.o \
./code/APP/version.o 

C_DEPS += \
./code/APP/ConctrolLed.d \
./code/APP/Loop.d \
./code/APP/McuDriveInit.d \
./code/APP/Tasksch.d \
./code/APP/UserIdentifier.d \
./code/APP/main.d \
./code/APP/protect.d \
./code/APP/version.d 


# Each subdirectory must supply rules for building sources it contributes
code/APP/%.o: ../code/APP/%.c code/APP/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../include" -I"../include/libraries/drivers/inc" -I"../include/libraries/cmsis/cm4/core_support" -I"../include/libraries/cmsis/cm4/device_support" -I"E:\at_workspace\GBA_PowerControl\code\APP" -I"E:\at_workspace\GBA_PowerControl\code\communication" -I"E:\at_workspace\GBA_PowerControl\code\mcu_drive" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


