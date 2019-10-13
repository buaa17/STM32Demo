
#include "uart.h"


/* 115200,8n1 */
void uart0_init()
{
	/* ??????????????? */
	/* GPH2,3????TxD0, RxD0 */
	GPHCON &= ~((3<<4) | (3<<6));
	GPHCON |= ((2<<4) | (2<<6));

	GPHUP &= ~((1<<2) | (1<<3));  /* ?????????? */
	

	/* ???¨°????? */
	/* UBRDIVn = (int)( UART clock / ( buad rate x 16) ) ?C1
	 *  UART clock = 50M
	 *  UBRDIVn = (int)( 50000000 / ( 115200 x 16) ) ?C1 = 26
	 */
	UCON0 = 0x00000005; /* PCLK,?§Ø?/????? */
	UBRDIV0 = 26;

	/* ?????????? */
	ULCON0 = 0x00000003; /* 8n1: 8??????¦Ë, ?????¦Ë, 1????¦Ë */

	/*  */

}

int putch(int c)
{
	/* UTRSTAT0 */
	/* UTXH0 */

	while (!(UTRSTAT0 & (1<<2)));
	UTXH0 = (unsigned char)c;
	
}

int getch(void)
{
	while (!(UTRSTAT0 & (1<<0)));
	return URXH0;
}

int putstr(const char *s)
{
	while (*s)
	{
		putch(*s);
		s++;
	}
}