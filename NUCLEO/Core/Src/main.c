#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "stm32f4xx_hal.h"
#include "../Peripherals/Inc/uart.h"
#include "../Peripherals/Inc/uart_interrupt.h"
#include "../Peripherals/Inc/led.h"
#include "../Peripherals/Inc/exti.h"
#include "../Peripherals/Inc/tim.h"
#include "../Peripherals/Inc/adc.h"
#include "../Peripherals/Inc/adc_single_conversion.h"

ADC_HandleTypeDef hadc2;
uint32_t sensor_value;

int main(void){

	HAL_Init();
//	uart_init();
	uart_IRQ_init();
//	tim_timebase_init();
//	adc_single_conversion_init_start();
//	gpio_pc13_interrupt_init();
//	adc_init_start();
//	pa5_led_init();

//	uint32_t value;

	HAL_UART_Transmit_IT(&huart1, tx_buffer, 10);
	HAL_UART_Receive_IT(&huart1, rx_buffer, 10);

    while (1)
    {
//    	HAL_ADC_Start(&hadc2);
//    	HAL_ADC_PollForConversion(&hadc2, 1);
//    	value = pa0_adc_single_conversion_read();
//    	printf("%" PRIu32 ": number \n", value);
//    	printf("hello! \n\r");
//    	HAL_Delay(3000);
    }
}
