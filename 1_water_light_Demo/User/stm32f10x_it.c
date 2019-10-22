#include "stm32f10x_it.h"
#include "stdio.h"
#include "stm32f10x_exti.h"

extern unsigned char flag;

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
void EXTI1_IRQHandl(void)
{
	/* 总体要求 -> 短小精悍，速度快 */
	//1. 不能传入参
	//2. 不能写printf之类的函数
	//3. 不要进行double、float之类的运算
	//4. 不要有返回值 return ret;
	
	//flag = ~flag;
	flag ^= (1<<0);
	//flag = 1 - flag;
	EXTI_ClearITPendingBit(EXTI_Line1);
	
}





