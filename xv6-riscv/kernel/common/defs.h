#pragma once

#include "types.h"

// console.c
void console_putchar(u8);
void console_write();

// uart.c
void uart_init();
void uart_putc();
void uart_putc_sync(u8);
int uart_getc();
