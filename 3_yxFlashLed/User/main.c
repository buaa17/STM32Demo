#include "stm32f10x.h"
#include "delay.h"
#include "led.h"

unsigned char flag = 1;
int main(void)
{ 
	
	  Led_Config();
	  Interrupt_Init();
	  
    while (1) {
			  if (flag) {
        GPIO_ResetBits(GPIOB, GPIO_Pin_13);
			  GPIO_SetBits(GPIOB, GPIO_Pin_14);
        delay_ms(1000);
        GPIO_SetBits(GPIOB, GPIO_Pin_13);
			  GPIO_ResetBits(GPIOB, GPIO_Pin_14);
        delay_ms(1000);
				}
    }
}



