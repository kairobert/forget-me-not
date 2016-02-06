################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Programs/SimplicityStudio/developer/sdks/efm32/v2/emlib/src/em_letimer.c 

OBJS += \
./em_letimer.o 

C_DEPS += \
./em_letimer.d 


# Each subdirectory must supply rules for building sources it contributes
em_letimer.o: D:/Programs/SimplicityStudio/developer/sdks/efm32/v2/emlib/src/em_letimer.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m3 -mthumb '-DEFM32GG990F1024=1' '-DDEBUG=1' -I"D:/Programs/SimplicityStudio/developer/sdks/efm32/v2/CMSIS/Include" -I"D:/Programs/SimplicityStudio/developer/sdks/efm32/v2/kits/common/bsp" -I"D:/Programs/SimplicityStudio/developer/sdks/efm32/v2/emlib/inc" -I"D:/Programs/SimplicityStudio/developer/sdks/efm32/v2/kits/common/drivers" -I"D:/Programs/SimplicityStudio/developer/sdks/efm32/v2/Device/SiliconLabs/EFM32GG/Include" -I"D:/Programs/SimplicityStudio/developer/sdks/efm32/v2/kits/EFM32GG_STK3700/config" -O0 -Wall -c -fmessage-length=0 -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -std=c99 -MMD -MP -MF"em_letimer.d" -MT"em_letimer.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


