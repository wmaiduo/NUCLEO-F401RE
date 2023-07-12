 #include <inttypes.h>
#include <stdio.h>

#include "stm32f4xx_hal.h"
#include "../Inc/adc.h"

extern ADC_HandleTypeDef hadc2;

uint32_t pa0_adc_single_conversion_read(void){
	return HAL_ADC_GetValue(&hadc2);
};

static void adc_continuous_conv_init(void){
	//configure pc0 as analog pin
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	ADC_ChannelConfTypeDef sConfig = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	//configure ADC module for continuous conversion
	__HAL_RCC_ADC1_CLK_ENABLE();

	hadc2.Instance = ADC1;
	hadc2.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
	hadc2.Init.Resolution = ADC_RESOLUTION_12B;
	hadc2.Init.ContinuousConvMode = DISABLE;
	hadc2.Init.DiscontinuousConvMode = DISABLE;
	hadc2.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	hadc2.Init.ExternalTrigConv = ADC_SOFTWARE_START;
	hadc2.Init.NbrOfConversion = 1;
	hadc2.Init.DMAContinuousRequests = DISABLE;
	hadc2.Init.EOCSelection = ADC_EOC_SINGLE_CONV;

	HAL_ADC_Init(&hadc2);

	sConfig.Channel = ADC_CHANNEL_0;
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;

	HAL_ADC_ConfigChannel(&hadc2, &sConfig);

	NVIC_SetPriority(ADC_IRQn, 0);
	NVIC_EnableIRQ(ADC_IRQn);
}

void adc_single_conversion_init_start(void){
	adc_continuous_conv_init();
	HAL_ADC_Start(&hadc2);
};

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
	uint32_t sensor_value;
	sensor_value = pa0_adc_single_conversion_read();
	printf("%" PRIu32 ": number \n", sensor_value);
};

void ADC_IRQHandler(void){
	HAL_ADC_IRQHandler(&hadc2);
};

