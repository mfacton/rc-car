################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Application/Src/display/titles/image.cpp \
../Application/Src/display/titles/text.cpp 

OBJS += \
./Application/Src/display/titles/image.o \
./Application/Src/display/titles/text.o 

CPP_DEPS += \
./Application/Src/display/titles/image.d \
./Application/Src/display/titles/text.d 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/display/titles/%.o Application/Src/display/titles/%.su Application/Src/display/titles/%.cyclo: ../Application/Src/display/titles/%.cpp Application/Src/display/titles/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Application/Inc -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-Src-2f-display-2f-titles

clean-Application-2f-Src-2f-display-2f-titles:
	-$(RM) ./Application/Src/display/titles/image.cyclo ./Application/Src/display/titles/image.d ./Application/Src/display/titles/image.o ./Application/Src/display/titles/image.su ./Application/Src/display/titles/text.cyclo ./Application/Src/display/titles/text.d ./Application/Src/display/titles/text.o ./Application/Src/display/titles/text.su

.PHONY: clean-Application-2f-Src-2f-display-2f-titles

