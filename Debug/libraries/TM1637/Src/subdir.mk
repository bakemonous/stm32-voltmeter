################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/TM1637/Src/delay_micros.c \
../libraries/TM1637/Src/tm1637.c 

OBJS += \
./libraries/TM1637/Src/delay_micros.o \
./libraries/TM1637/Src/tm1637.o 

C_DEPS += \
./libraries/TM1637/Src/delay_micros.d \
./libraries/TM1637/Src/tm1637.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/TM1637/Src/%.o libraries/TM1637/Src/%.su libraries/TM1637/Src/%.cyclo: ../libraries/TM1637/Src/%.c libraries/TM1637/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"../libraries/TM1637/Inc" -I"../libraries/tm1637-main" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-libraries-2f-TM1637-2f-Src

clean-libraries-2f-TM1637-2f-Src:
	-$(RM) ./libraries/TM1637/Src/delay_micros.cyclo ./libraries/TM1637/Src/delay_micros.d ./libraries/TM1637/Src/delay_micros.o ./libraries/TM1637/Src/delay_micros.su ./libraries/TM1637/Src/tm1637.cyclo ./libraries/TM1637/Src/tm1637.d ./libraries/TM1637/Src/tm1637.o ./libraries/TM1637/Src/tm1637.su

.PHONY: clean-libraries-2f-TM1637-2f-Src

