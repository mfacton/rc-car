################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/Src/display/streams/print.cpp 

OBJS += \
./Application/Src/display/streams/print.o 

CPP_DEPS += \
./Application/Src/display/streams/print.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/display/streams/%.o Application/Src/display/streams/%.su Application/Src/display/streams/%.cyclo: ../Application/Src/display/streams/%.cpp Application/Src/display/streams/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Application/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-Src-2f-display-2f-streams

clean-Application-2f-Src-2f-display-2f-streams:
	-$(RM) ./Application/Src/display/streams/print.cyclo ./Application/Src/display/streams/print.d ./Application/Src/display/streams/print.o ./Application/Src/display/streams/print.su

.PHONY: clean-Application-2f-Src-2f-display-2f-streams

