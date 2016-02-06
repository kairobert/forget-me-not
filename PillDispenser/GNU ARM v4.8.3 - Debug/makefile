################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include Drivers/subdir.mk
-include CMSIS/efm32gg/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: PillDispenser.axf

# Tool invocations
PillDispenser.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C++ Linker'
	arm-none-eabi-g++ -g -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "PillDispenser.ld" --specs=nosys.specs -Xlinker --gc-sections -Xlinker -Map="PillDispenser.map" --specs=nano.specs -o PillDispenser.axf "./src/gpio.o" "./src/interruptHandlers.o" "./src/leTimer.o" "./src/main.o" "./src/rtc.o" "./emlib/em_cmu.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_lcd.o" "./emlib/em_letimer.o" "./emlib/em_rtc.o" "./emlib/em_system.o" "./Drivers/segmentlcd.o" "./CMSIS/efm32gg/startup_efm32gg.o" "./CMSIS/efm32gg/system_efm32gg.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: PillDispenser.hex'
	arm-none-eabi-objcopy -O ihex "PillDispenser.axf" "PillDispenser.hex"
	@echo ' '

	@echo 'Building bin file: PillDispenser.bin'
	arm-none-eabi-objcopy -O binary "PillDispenser.axf" "PillDispenser.bin"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "PillDispenser.axf"
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) PillDispenser.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
