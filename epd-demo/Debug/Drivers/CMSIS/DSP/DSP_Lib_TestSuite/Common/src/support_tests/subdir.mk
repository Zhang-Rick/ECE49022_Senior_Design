################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/copy_tests.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/fill_tests.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_common_data.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_group.c \
../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/x_to_y_tests.c 

OBJS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/copy_tests.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/fill_tests.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_common_data.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_group.o \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/x_to_y_tests.o 

C_DEPS += \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/copy_tests.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/fill_tests.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_common_data.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_group.d \
./Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/x_to_y_tests.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/copy_tests.o: ../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/copy_tests.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../FATFS/App -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../FATFS/Target -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/rfal/Inc -I../Inc -I../User/SDcard -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/copy_tests.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/fill_tests.o: ../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/fill_tests.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../FATFS/App -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../FATFS/Target -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/rfal/Inc -I../Inc -I../User/SDcard -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/fill_tests.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_common_data.o: ../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_common_data.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../FATFS/App -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../FATFS/Target -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/rfal/Inc -I../Inc -I../User/SDcard -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_common_data.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_group.o: ../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_group.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../FATFS/App -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../FATFS/Target -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/rfal/Inc -I../Inc -I../User/SDcard -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/support_test_group.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/x_to_y_tests.o: ../Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/x_to_y_tests.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../FATFS/App -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../FATFS/Target -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/rfal/Inc -I../Inc -I../User/SDcard -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/DSP/DSP_Lib_TestSuite/Common/src/support_tests/x_to_y_tests.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

