#include "uart.h"

void uart0_init(void)
{
	/* 设置串口使用的引脚 GPH2，3用于TXD0、RXD0*/
	GPHCON &= ~((3<<6)|(3<<4));
	GPHCON |= ((2<<6)|(2<<4));

	GPHUP &= ~((1<<2) | (1<<3));  /* 使能内部上拉 */
	
	/* 无奇偶校验、一个停止位、8个数据位*/
	ULCON0 |= ((1<<0)|(1<<1));

	UCON0  |= ((1<<2)|(1<<0));

	UBRDIV0 = 26;
}

/*
 * 输出c
 */
int putch(int c)
{
	while (!(UTRSTAT0 & (1<<2)))
	{
		UTXH0 = (unsigned char)c;
	}
	return 0;
}

/*
 * 从串口获取数据返回
 */
int getch(void)
{
	while (!(UTRSTAT0 & (1<<0));//当receive buffer中有数据时候，0位为1
	return URXH0;
}

int putstr(const char* s)
{
	while (*s)
	{
		putc(*s);
		s++;
	}
	return 0;
}
