################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f100xb.s \
../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f100xe.s \
../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f101x6.s \
../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f101xb.s \
../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f101xe.s \
../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f101xg.s \
../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f102x6.s \
../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f102xb.s \
../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f103x6.s \
../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f103xb.s \
../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f103xe.s \
../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f103xg.s \
../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f105xc.s \
../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f107xc.s 

OBJS += \
./Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f100xb.o \
./Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f100xe.o \
./Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f101x6.o \
./Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f101xb.o \
./Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f101xe.o \
./Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f101xg.o \
./Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f102x6.o \
./Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f102xb.o \
./Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f103x6.o \
./Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f103xb.o \
./Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f103xe.o \
./Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f103xg.o \
./Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f105xc.o \
./Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/startup_stm32f107xc.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/%.o: ../Drivers/CMSIS/Device/ST/STM32F1xx/Source/Templates/iar/%.s
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -c -x assembler-with-cpp --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

