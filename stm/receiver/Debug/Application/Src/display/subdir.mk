################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/Src/display/display.cpp \
../Application/Src/display/screens.cpp 

OBJS += \
./Application/Src/display/display.o \
./Application/Src/display/screens.o 

CPP_DEPS += \
./Application/Src/display/display.d \
./Application/Src/display/screens.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/display/%.o Application/Src/display/%.su Application/Src/display/%.cyclo: ../Application/Src/display/%.cpp Application/Src/display/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Application/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-Src-2f-display

clean-Application-2f-Src-2f-display:
	-$(RM) ./Application/Src/display/display.cyclo ./Application/Src/display/display.d ./Application/Src/display/display.o ./Application/Src/display/display.su ./Application/Src/display/screens.cyclo ./Application/Src/display/screens.d ./Application/Src/display/screens.o ./Application/Src/display/screens.su

.PHONY: clean-Application-2f-Src-2f-display

