#ifndef _UART_H
#define _UART_H
#define ULCON0   *(volatile unsigned int*)0x50000000
#define UCON0    *(volatile unsigned int*)0x50000004
#define UTXH0    *(volatile unsigned int*)0x50000020
#define URXH0    *(volatile unsigned int*)0x50000024
#define UBRDIV0  *(volatile unsigned int*)0x50000028
#define UTRSTAT0 *(volatile unsigned int*)0x50000010


void uart0_init(void);
int putc(char c);
int puts(char* c);
int getchar(void);
void led_init(void);
#endif