################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/Src/display/options/action.cpp \
../Application/Src/display/options/redirect.cpp \
../Application/Src/display/options/toggle.cpp 

OBJS += \
./Application/Src/display/options/action.o \
./Application/Src/display/options/redirect.o \
./Application/Src/display/options/toggle.o 

CPP_DEPS += \
./Application/Src/display/options/action.d \
./Application/Src/display/options/redirect.d \
./Application/Src/display/options/toggle.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/display/options/%.o Application/Src/display/options/%.su Application/Src/display/options/%.cyclo: ../Application/Src/display/options/%.cpp Application/Src/display/options/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Application/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-Src-2f-display-2f-options

clean-Application-2f-Src-2f-display-2f-options:
	-$(RM) ./Application/Src/display/options/action.cyclo ./Application/Src/display/options/action.d ./Application/Src/display/options/action.o ./Application/Src/display/options/action.su ./Application/Src/display/options/redirect.cyclo ./Application/Src/display/options/redirect.d ./Application/Src/display/options/redirect.o ./Application/Src/display/options/redirect.su ./Application/Src/display/options/toggle.cyclo ./Application/Src/display/options/toggle.d ./Application/Src/display/options/toggle.o ./Application/Src/display/options/toggle.su

.PHONY: clean-Application-2f-Src-2f-display-2f-options

