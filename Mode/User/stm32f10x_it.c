#include "stm32f10x_it.h"
#include "delay.h"

extern uint64_t TimingDelay;

void TimingDelay_Decrement()
{
    if(TimingDelay != 0x00)
    {
        TimingDelay--;
    }
}

void SysTick_Handler(void)
{
	TimingDelay_Decrement();
}

