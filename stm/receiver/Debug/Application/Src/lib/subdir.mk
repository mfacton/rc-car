################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/Src/lib/i2c_eeprom.c \
../Application/Src/lib/nrf24l01p.c \
../Application/Src/lib/ssd1306.c \
../Application/Src/lib/ssd1306_fonts.c 

C_DEPS += \
./Application/Src/lib/i2c_eeprom.d \
./Application/Src/lib/nrf24l01p.d \
./Application/Src/lib/ssd1306.d \
./Application/Src/lib/ssd1306_fonts.d 

OBJS += \
./Application/Src/lib/i2c_eeprom.o \
./Application/Src/lib/nrf24l01p.o \
./Application/Src/lib/ssd1306.o \
./Application/Src/lib/ssd1306_fonts.o 


# Each subdirectory must supply rules for building sources it contributes
Application/Src/lib/%.o Application/Src/lib/%.su Application/Src/lib/%.cyclo: ../Application/Src/lib/%.c Application/Src/lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Application/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Application-2f-Src-2f-lib

clean-Application-2f-Src-2f-lib:
	-$(RM) ./Application/Src/lib/i2c_eeprom.cyclo ./Application/Src/lib/i2c_eeprom.d ./Application/Src/lib/i2c_eeprom.o ./Application/Src/lib/i2c_eeprom.su ./Application/Src/lib/nrf24l01p.cyclo ./Application/Src/lib/nrf24l01p.d ./Application/Src/lib/nrf24l01p.o ./Application/Src/lib/nrf24l01p.su ./Application/Src/lib/ssd1306.cyclo ./Application/Src/lib/ssd1306.d ./Application/Src/lib/ssd1306.o ./Application/Src/lib/ssd1306.su ./Application/Src/lib/ssd1306_fonts.cyclo ./Application/Src/lib/ssd1306_fonts.d ./Application/Src/lib/ssd1306_fonts.o ./Application/Src/lib/ssd1306_fonts.su

.PHONY: clean-Application-2f-Src-2f-lib

