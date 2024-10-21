################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Src/lib/nrf24l01p.c 

C_DEPS += \
./Application/Src/lib/nrf24l01p.d 

OBJS += \
./Application/Src/lib/nrf24l01p.o 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/lib/%.o Application/Src/lib/%.su Application/Src/lib/%.cyclo: ../Application/Src/lib/%.c Application/Src/lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Application/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-Src-2f-lib

clean-Application-2f-Src-2f-lib:
	-$(RM) ./Application/Src/lib/nrf24l01p.cyclo ./Application/Src/lib/nrf24l01p.d ./Application/Src/lib/nrf24l01p.o ./Application/Src/lib/nrf24l01p.su

.PHONY: clean-Application-2f-Src-2f-lib

