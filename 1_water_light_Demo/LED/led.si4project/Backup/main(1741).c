#include "s3c2440_soc.h"
#include "uart.h"
#include ""
int main(void)
{
	unsigned char c;
	uart0_init();
	puts("Enter the Tacc Val: \n\r");


	while (1)
	{
		c = getchar();//��ȡ
		putchar(c);//����
		
		bank0_tacc_set(c - '0');

		led_test();
		
	}
	return 0;
}
