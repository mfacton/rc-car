################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Src/control.c \
../Application/Src/input.c \
../Application/Src/receiver.c 

C_DEPS += \
./Application/Src/control.d \
./Application/Src/input.d \
./Application/Src/receiver.d 

OBJS += \
./Application/Src/control.o \
./Application/Src/input.o \
./Application/Src/receiver.o 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/%.o Application/Src/%.su Application/Src/%.cyclo: ../Application/Src/%.c Application/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Application/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-Src

clean-Application-2f-Src:
	-$(RM) ./Application/Src/control.cyclo ./Application/Src/control.d ./Application/Src/control.o ./Application/Src/control.su ./Application/Src/input.cyclo ./Application/Src/input.d ./Application/Src/input.o ./Application/Src/input.su ./Application/Src/receiver.cyclo ./Application/Src/receiver.d ./Application/Src/receiver.o ./Application/Src/receiver.su

.PHONY: clean-Application-2f-Src

