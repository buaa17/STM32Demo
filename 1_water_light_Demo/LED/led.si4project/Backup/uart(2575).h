#ifndef _UART_H
#define _UART_H
#define ULCON0   *(volatile unsigned int*)0x50000000
#define UCON0    *(volatile unsigned int*)0x50000004
#define UTXH0    *(volatile unsigned char*)0x50000020
#define URXH0    *(volatile unsigned char*)0x50000024
#define UBRDIV0  *(volatile unsigned int*)0x50000028
#define UTRSTAT0 *(volatile unsigned int*)0x50000010

#define GPFCON   *(volatile unsigned int*)0x56000050
#define GPFDAT   *(volatile unsigned int*)0x56000054

#define GPHCON   *(volatile unsigned int*)0x56000070
#define GPHUP	 *(volatile unsigned int*)0x56000078


void uart0_init(void);
int putch(const char c);
int putstr(const char* c);
int getch(void);
void led_init(void);

#endif
