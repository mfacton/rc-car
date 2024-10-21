################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/Src/display/templates/option.cpp \
../Application/Src/display/templates/screen.cpp \
../Application/Src/display/templates/stream.cpp \
../Application/Src/display/templates/title.cpp 

OBJS += \
./Application/Src/display/templates/option.o \
./Application/Src/display/templates/screen.o \
./Application/Src/display/templates/stream.o \
./Application/Src/display/templates/title.o 

CPP_DEPS += \
./Application/Src/display/templates/option.d \
./Application/Src/display/templates/screen.d \
./Application/Src/display/templates/stream.d \
./Application/Src/display/templates/title.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/display/templates/%.o Application/Src/display/templates/%.su Application/Src/display/templates/%.cyclo: ../Application/Src/display/templates/%.cpp Application/Src/display/templates/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Application/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-Src-2f-display-2f-templates

clean-Application-2f-Src-2f-display-2f-templates:
	-$(RM) ./Application/Src/display/templates/option.cyclo ./Application/Src/display/templates/option.d ./Application/Src/display/templates/option.o ./Application/Src/display/templates/option.su ./Application/Src/display/templates/screen.cyclo ./Application/Src/display/templates/screen.d ./Application/Src/display/templates/screen.o ./Application/Src/display/templates/screen.su ./Application/Src/display/templates/stream.cyclo ./Application/Src/display/templates/stream.d ./Application/Src/display/templates/stream.o ./Application/Src/display/templates/stream.su ./Application/Src/display/templates/title.cyclo ./Application/Src/display/templates/title.d ./Application/Src/display/templates/title.o ./Application/Src/display/templates/title.su

.PHONY: clean-Application-2f-Src-2f-display-2f-templates

