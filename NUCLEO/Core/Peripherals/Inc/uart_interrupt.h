#ifndef UART_INTERRUPT_H
#define UART_INTERRUPT_H

extern UART_HandleTypeDef huart1;

void uart_IRQ_init(void);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
int _write(int file, char* ptr, int len);
int uart_putchar(int ch);

extern uint8_t tx_buffer[10];
extern uint8_t rx_buffer[10];

#endif /* UART_H */
