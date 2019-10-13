#include "stm32f10x.h"
#include "delay.h"


int main(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	//ִ�г���
	
	while(1)
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		GPIO_SetBits(GPIOB,GPIO_Pin_14);;
		delay_ms(1000);
		GPIO_ResetBits(GPIOB,GPIO_Pin_14);
		GPIO_SetBits(GPIOB,GPIO_Pin_13);;
		delay_ms(1000);
	}
}

