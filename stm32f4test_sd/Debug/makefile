################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/Third_Party/FatFs/src/option/subdir.mk
-include Middlewares/Third_Party/FatFs/src/subdir.mk
-include FATFS/Target/subdir.mk
-include FATFS/App/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
stm32f4test_sd.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
stm32f4test_sd.list \

OBJCOPY_BIN += \
stm32f4test_sd.bin \


# All Target
all: stm32f4test_sd.elf secondary-outputs

# Tool invocations
stm32f4test_sd.elf: $(OBJS) $(USER_OBJS) /Users/apple/STM32CubeIDE/workspace_1.2.0/stm32f4test_sd/STM32F413ZHTX_FLASH.ld
	arm-none-eabi-gcc -o "stm32f4test_sd.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/Users/apple/STM32CubeIDE/workspace_1.2.0/stm32f4test_sd/STM32F413ZHTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="stm32f4test_sd.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

stm32f4test_sd.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "stm32f4test_sd.list"
	@echo 'Finished building: $@'
	@echo ' '

stm32f4test_sd.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "stm32f4test_sd.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
