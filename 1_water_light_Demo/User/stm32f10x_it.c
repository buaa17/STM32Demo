#include "stm32f10x_it.h"
#include "stdio.h"
#include "stm32f10x_exti.h"

extern unsigned char flag;

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
void EXTI1_IRQHandl(void)
{
	/* ����Ҫ�� -> ��С�������ٶȿ� */
	//1. ���ܴ����
	//2. ����дprintf֮��ĺ���
	//3. ��Ҫ����double��float֮�������
	//4. ��Ҫ�з���ֵ return ret;
	
	//flag = ~flag;
	flag ^= (1<<0);
	//flag = 1 - flag;
	EXTI_ClearITPendingBit(EXTI_Line1);
	
}





