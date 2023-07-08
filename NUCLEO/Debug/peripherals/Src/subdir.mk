################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../peripherals/Src/exti.c \
../peripherals/Src/led.c 

OBJS += \
./peripherals/Src/exti.o \
./peripherals/Src/led.o 

C_DEPS += \
./peripherals/Src/exti.d \
./peripherals/Src/led.d 


# Each subdirectory must supply rules for building sources it contributes
peripherals/Src/%.o peripherals/Src/%.su peripherals/Src/%.cyclo: ../peripherals/Src/%.c peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-peripherals-2f-Src

clean-peripherals-2f-Src:
	-$(RM) ./peripherals/Src/exti.cyclo ./peripherals/Src/exti.d ./peripherals/Src/exti.o ./peripherals/Src/exti.su ./peripherals/Src/led.cyclo ./peripherals/Src/led.d ./peripherals/Src/led.o ./peripherals/Src/led.su

.PHONY: clean-peripherals-2f-Src

