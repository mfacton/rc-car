################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/Src/display/screens/edit.cpp \
../Application/Src/display/screens/live.cpp \
../Application/Src/display/screens/scroll.cpp 

OBJS += \
./Application/Src/display/screens/edit.o \
./Application/Src/display/screens/live.o \
./Application/Src/display/screens/scroll.o 

CPP_DEPS += \
./Application/Src/display/screens/edit.d \
./Application/Src/display/screens/live.d \
./Application/Src/display/screens/scroll.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/display/screens/%.o Application/Src/display/screens/%.su Application/Src/display/screens/%.cyclo: ../Application/Src/display/screens/%.cpp Application/Src/display/screens/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Application/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-Src-2f-display-2f-screens

clean-Application-2f-Src-2f-display-2f-screens:
	-$(RM) ./Application/Src/display/screens/edit.cyclo ./Application/Src/display/screens/edit.d ./Application/Src/display/screens/edit.o ./Application/Src/display/screens/edit.su ./Application/Src/display/screens/live.cyclo ./Application/Src/display/screens/live.d ./Application/Src/display/screens/live.o ./Application/Src/display/screens/live.su ./Application/Src/display/screens/scroll.cyclo ./Application/Src/display/screens/scroll.d ./Application/Src/display/screens/scroll.o ./Application/Src/display/screens/scroll.su

.PHONY: clean-Application-2f-Src-2f-display-2f-screens

