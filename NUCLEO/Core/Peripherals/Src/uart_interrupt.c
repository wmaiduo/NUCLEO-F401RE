#include <stdio.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"

UART_HandleTypeDef huart1;

void uart_IRQ_init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_USART1_CLK_ENABLE();

	GPIO_InitStruct.Pin = GPIO_PIN_9 | GPIO_PIN_10;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;

	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_UART_Init(&huart1);

	HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
}

void USART1_IRQHandler(void) {
	HAL_UART_IRQHandler(&huart1);
}

uint32_t tx_counter, rx_counter;

uint8_t tx_buffer[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
uint8_t rx_buffer[10];

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	tx_counter++;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	rx_counter++;
}
