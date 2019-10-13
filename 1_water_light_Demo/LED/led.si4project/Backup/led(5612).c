
void delay(volatile int d)
{
	while (d--);
}

int led_on(int which)
{
	unsigned int *pGPFCON = (unsigned int *)0x56000050;
	unsigned int *pGPFDAT = (unsigned int *)0x56000054;

	/* 设置GPFCON让GPF4/5/6配置为输出模式 */
	/* 00 = INPUT
	 * 01 = OUTPUT
	 * 10 = EINT
	 * 11 = Reserved
	 * GPF4:[9:8]
	 * GPF5:[11:10]
	 * GPF6:[13:12]
	 */
	*pGPFCON &= ~((3<<12)|(3<<10)|(3<<8));//清零
	*pGPFCON |= ((1<<12)|(1<<10)|(1<<8));

	*pGPFDAT &= ~(7<<4);//4\5\6清零
	/* 设置GPFDAT让GPF4/5/6输出低电平 */
	while(1)
	{
		*pGPFDAT = 0x460;//4\5\6清零
		delay(100000);

		*pGPFDAT = 0x4c0;
		delay(100000);

		*pGPFDAT = 0x4a0;
		delay(100000);
		
	}
	
	return 0;
}



