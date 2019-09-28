#include "delay.h"

uint64_t TimingDelay;

void SysTick_Init(void)
{
	 /*72000 1ms中断一次
    *720 10us中断一次
    *72 1us中断一次
    */
     if(SysTick_Config(72))  //10us中断一次
     {
         /* Capture error */
         while(1);
    }
    //关闭滴答计时器     SysTick_CTRL_ENABLE_Msk
    SysTick -> CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


void delay_us(uint64_t nTime)
{
	  TimingDelay = nTime;
    //使能滴答计时器
    SysTick -> CTRL |= SysTick_CTRL_ENABLE_Msk;
    while(TimingDelay != 0);
}


void delay_ms(uint64_t nTime)
{
	while(nTime-- != 0)
	{
		delay_us(1000);
	}
}


void delay_s(uint64_t nTime)
{
	while(nTime-- != 0)
	{
		delay_ms(1000);
	}
}


