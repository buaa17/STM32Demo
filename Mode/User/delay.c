#include "delay.h"

uint64_t TimingDelay;

void SysTick_Init(void)
{
	 /*72000 1ms�ж�һ��
    *720 10us�ж�һ��
    *72 1us�ж�һ��
    */
     if(SysTick_Config(72))  //10us�ж�һ��
     {
         /* Capture error */
         while(1);
    }
    //�رյδ��ʱ��     SysTick_CTRL_ENABLE_Msk
    SysTick -> CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


void delay_us(uint64_t nTime)
{
	  TimingDelay = nTime;
    //ʹ�ܵδ��ʱ��
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


