#include "led.h"
#include "stm32f10x.h"
#include "delay.h"
#include "usart1.h"

unsigned char flag = 1;
int main(void)
{
	Interrupt_Init();
	led_flash();
	//USART1_Config();
	while(1)
	{ 
		if (flag) {
			GPIO_ResetBits(GPIOB,GPIO_Pin_13);
			GPIO_SetBits(GPIOB,GPIO_Pin_14);;
			delay_ms(1000);
			GPIO_ResetBits(GPIOB,GPIO_Pin_14);
			GPIO_SetBits(GPIOB,GPIO_Pin_13);
			delay_ms(1000);
		}
	}
}


