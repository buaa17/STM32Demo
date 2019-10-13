#include "uart.h"

void uart0_init(void)
{
	/* 无奇偶校验、一个停止位、8个数据位*/
	ULCON0 |= ((1<<0)|(1<<1));

	UCON0  |= ((1<<2)|(1<<0));

	UBRDIV0 = 26;
}

/*
 * 输出c
 */
int putc(char c)
{
	while (UTRSTAT0 & (1<<2))
	{
		UTXH0 = c;
	}
	return 0;
}

/*
 * 从串口获取数据返回
 */
int getchar(void)
{
	while (UTRSTAT0 & (1<<0));//当receive buffer中有数据时候，0位为1
	return URXH0;
}

int puts(char* s)
{
	while (*s)
	{
		putc(*s);
	}
	return 0;
}
