
void delay(volatile int d)
{
	while (d--);
}

int led_on(int which)
{
	unsigned int *pGPFCON = (unsigned int *)0x56000050;
	unsigned int *pGPFDAT = (unsigned int *)0x56000054;

	/* 设置GPFCON让GPF4/5/6配置为输出模式 */
	*pGPFCON &= ~((1<<12)|(1<<10)|(1<<8));//清零
	*pGPFCON |= ((1<<12)|(1<<10)|(1<<8));

	/* 设置GPFDAT让GPF4/5/6输出低电平 */
	*pGPFDAT &= ~((1<<4)|(1<<5)|(1<<6));//4\5\6清零
	
	return 0;
}



