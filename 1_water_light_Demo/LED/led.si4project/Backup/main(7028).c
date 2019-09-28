#include "uart.h"

int main()
{
	//执行测试程序
	led_init();
	uart0_init();
	putstr("hello uart!\n\r");
	return 0;
}
