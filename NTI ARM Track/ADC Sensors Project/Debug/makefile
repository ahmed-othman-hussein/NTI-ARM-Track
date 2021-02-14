################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

BUILD_ARTIFACT_NAME := GPIO_Driver_BSRR_BRR
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
GPIO_Driver_BSRR_BRR.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
GPIO_Driver_BSRR_BRR.list \

OBJCOPY_HEX += \
GPIO_Driver_BSRR_BRR.hex \

OBJCOPY_BIN += \
GPIO_Driver_BSRR_BRR.bin \


# All Target
all: main-build

# Main-build Target
main-build: GPIO_Driver_BSRR_BRR.elf secondary-outputs

# Tool invocations
GPIO_Driver_BSRR_BRR.elf: $(OBJS) $(USER_OBJS) G:\STM32CubeIDE\workspace_1.5.0\GPIO_Driver_BSRR_BRR\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "GPIO_Driver_BSRR_BRR.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"G:\STM32CubeIDE\workspace_1.5.0\GPIO_Driver_BSRR_BRR\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="GPIO_Driver_BSRR_BRR.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

GPIO_Driver_BSRR_BRR.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "GPIO_Driver_BSRR_BRR.list"
	@echo 'Finished building: $@'
	@echo ' '

GPIO_Driver_BSRR_BRR.hex: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "GPIO_Driver_BSRR_BRR.hex"
	@echo 'Finished building: $@'
	@echo ' '

GPIO_Driver_BSRR_BRR.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "GPIO_Driver_BSRR_BRR.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
