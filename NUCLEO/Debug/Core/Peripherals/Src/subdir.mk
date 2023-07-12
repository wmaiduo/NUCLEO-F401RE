################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Peripherals/Src/adc.c \
../Core/Peripherals/Src/adc_single_conversion.c \
../Core/Peripherals/Src/exti.c \
../Core/Peripherals/Src/led.c \
../Core/Peripherals/Src/tim.c \
../Core/Peripherals/Src/uart.c \
../Core/Peripherals/Src/uart_interrupt.c 

OBJS += \
./Core/Peripherals/Src/adc.o \
./Core/Peripherals/Src/adc_single_conversion.o \
./Core/Peripherals/Src/exti.o \
./Core/Peripherals/Src/led.o \
./Core/Peripherals/Src/tim.o \
./Core/Peripherals/Src/uart.o \
./Core/Peripherals/Src/uart_interrupt.o 

C_DEPS += \
./Core/Peripherals/Src/adc.d \
./Core/Peripherals/Src/adc_single_conversion.d \
./Core/Peripherals/Src/exti.d \
./Core/Peripherals/Src/led.d \
./Core/Peripherals/Src/tim.d \
./Core/Peripherals/Src/uart.d \
./Core/Peripherals/Src/uart_interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Peripherals/Src/%.o Core/Peripherals/Src/%.su Core/Peripherals/Src/%.cyclo: ../Core/Peripherals/Src/%.c Core/Peripherals/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Peripherals-2f-Src

clean-Core-2f-Peripherals-2f-Src:
	-$(RM) ./Core/Peripherals/Src/adc.cyclo ./Core/Peripherals/Src/adc.d ./Core/Peripherals/Src/adc.o ./Core/Peripherals/Src/adc.su ./Core/Peripherals/Src/adc_single_conversion.cyclo ./Core/Peripherals/Src/adc_single_conversion.d ./Core/Peripherals/Src/adc_single_conversion.o ./Core/Peripherals/Src/adc_single_conversion.su ./Core/Peripherals/Src/exti.cyclo ./Core/Peripherals/Src/exti.d ./Core/Peripherals/Src/exti.o ./Core/Peripherals/Src/exti.su ./Core/Peripherals/Src/led.cyclo ./Core/Peripherals/Src/led.d ./Core/Peripherals/Src/led.o ./Core/Peripherals/Src/led.su ./Core/Peripherals/Src/tim.cyclo ./Core/Peripherals/Src/tim.d ./Core/Peripherals/Src/tim.o ./Core/Peripherals/Src/tim.su ./Core/Peripherals/Src/uart.cyclo ./Core/Peripherals/Src/uart.d ./Core/Peripherals/Src/uart.o ./Core/Peripherals/Src/uart.su ./Core/Peripherals/Src/uart_interrupt.cyclo ./Core/Peripherals/Src/uart_interrupt.d ./Core/Peripherals/Src/uart_interrupt.o ./Core/Peripherals/Src/uart_interrupt.su

.PHONY: clean-Core-2f-Peripherals-2f-Src

