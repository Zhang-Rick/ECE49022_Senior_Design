################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q15.c \
../Drivers/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q7.c \
../Drivers/CMSIS/NN/Source/ActivationFunctions/arm_relu_q15.c \
../Drivers/CMSIS/NN/Source/ActivationFunctions/arm_relu_q7.c 

OBJS += \
./Drivers/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q15.o \
./Drivers/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q7.o \
./Drivers/CMSIS/NN/Source/ActivationFunctions/arm_relu_q15.o \
./Drivers/CMSIS/NN/Source/ActivationFunctions/arm_relu_q7.o 

C_DEPS += \
./Drivers/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q15.d \
./Drivers/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q7.d \
./Drivers/CMSIS/NN/Source/ActivationFunctions/arm_relu_q15.d \
./Drivers/CMSIS/NN/Source/ActivationFunctions/arm_relu_q7.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q15.o: ../Drivers/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../FATFS/App -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../FATFS/Target -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/rfal/Inc -I../Inc -I../User/SDcard -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q15.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q7.o: ../Drivers/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../FATFS/App -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../FATFS/Target -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/rfal/Inc -I../Inc -I../User/SDcard -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/NN/Source/ActivationFunctions/arm_nn_activations_q7.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/CMSIS/NN/Source/ActivationFunctions/arm_relu_q15.o: ../Drivers/CMSIS/NN/Source/ActivationFunctions/arm_relu_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../FATFS/App -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../FATFS/Target -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/rfal/Inc -I../Inc -I../User/SDcard -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/NN/Source/ActivationFunctions/arm_relu_q15.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/CMSIS/NN/Source/ActivationFunctions/arm_relu_q7.o: ../Drivers/CMSIS/NN/Source/ActivationFunctions/arm_relu_q7.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../FATFS/App -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../FATFS/Target -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/rfal/Inc -I../Inc -I../User/SDcard -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/NN/Source/ActivationFunctions/arm_relu_q7.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

