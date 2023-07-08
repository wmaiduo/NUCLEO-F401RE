#ifndef UART_H
#define UART_H

void uart_init(void);
int _write(int file, char* ptr, int len);
int uart_putchar(int ch);

#endif /* UART_H */
