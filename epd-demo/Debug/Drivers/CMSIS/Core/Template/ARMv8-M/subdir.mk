################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/Core/Template/ARMv8-M/main_s.c \
../Drivers/CMSIS/Core/Template/ARMv8-M/tz_context.c 

OBJS += \
./Drivers/CMSIS/Core/Template/ARMv8-M/main_s.o \
./Drivers/CMSIS/Core/Template/ARMv8-M/tz_context.o 

C_DEPS += \
./Drivers/CMSIS/Core/Template/ARMv8-M/main_s.d \
./Drivers/CMSIS/Core/Template/ARMv8-M/tz_context.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/Core/Template/ARMv8-M/main_s.o: ../Drivers/CMSIS/Core/Template/ARMv8-M/main_s.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../FATFS/App -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../FATFS/Target -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/rfal/Inc -I../Inc -I../User/SDcard -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Core/Template/ARMv8-M/main_s.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/CMSIS/Core/Template/ARMv8-M/tz_context.o: ../Drivers/CMSIS/Core/Template/ARMv8-M/tz_context.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../FATFS/App -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../FATFS/Target -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/rfal/Inc -I../Inc -I../User/SDcard -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/Core/Template/ARMv8-M/tz_context.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

