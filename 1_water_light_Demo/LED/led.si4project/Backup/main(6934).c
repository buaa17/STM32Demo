#include "s3c2440_soc.h"
#include "uart.h"

int main(void)
{
	unsigned char c;
	uart0_init();
	puts("Hello World!\n");


	while (1)
	{
		c = getchar();//ªÒ»°
		putchar(c);//ªÿœ‘
	}
	return 0;
}
