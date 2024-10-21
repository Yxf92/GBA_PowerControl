################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../cmsis/startup_at32f423.s 

C_SRCS += \
../cmsis/system_at32f423.c 

OBJS += \
./cmsis/startup_at32f423.o \
./cmsis/system_at32f423.o 

S_DEPS += \
./cmsis/startup_at32f423.d 

C_DEPS += \
./cmsis/system_at32f423.d 


# Each subdirectory must supply rules for building sources it contributes
cmsis/%.o: ../cmsis/%.s cmsis/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

cmsis/%.o: ../cmsis/%.c cmsis/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -ffunction-sections  -g -DAT_START_F423_V1 -DAT32F423KCU7_4 -DUSE_STDPERIPH_DRIVER -I"../include" -I"../include/libraries/drivers/inc" -I"../include/libraries/cmsis/cm4/core_support" -I"../include/libraries/cmsis/cm4/device_support" -I"E:\at_workspace\GBA_PowerControl\code\APP" -I"E:\at_workspace\GBA_PowerControl\code\communication" -I"E:\at_workspace\GBA_PowerControl\code\Instruction" -I"E:\at_workspace\GBA_PowerControl\code\mcu_drive" -I"E:\at_workspace\GBA_PowerControl\code\MAVLINK2" -I"E:\at_workspace\GBA_PowerControl\code\MAVLINK2\common" -I"E:\at_workspace\GBA_PowerControl\code\MAVLINK2\goertek" -I"E:\at_workspace\GBA_PowerControl\code\MAVLINK2\minimal" -I"E:\at_workspace\GBA_PowerControl\code\MAVLINK2\standard" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


