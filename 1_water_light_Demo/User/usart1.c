#include "usart1.h"
#include "stm32f10x.h"
#include "stdio.h"
#include "delay.h"
#include "stm32f10x_usart.h"

//函数的实现
/****串口的配置****/
void USART1_Config(void)
{
	//所使用的GPIO口工作模式的初始化 A10->Rc  A9->Tx
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART1_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//悬空输入，作为I2C、USART接收端
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//	GPIO_InitStructure.GPIO_Speed = 3;//发送要速度
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//复用推挽输出作为串口的输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//具体设计USART1的工作参数和方式的配置
	
	USART1_InitStructure.USART_BaudRate = 115200;//115200
	USART1_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//None
	USART1_InitStructure.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;
	USART1_InitStructure.USART_Parity = USART_Parity_No;	//No
	USART1_InitStructure.USART_StopBits = USART_StopBits_1;//1
	USART1_InitStructure.USART_WordLength = USART_WordLength_8b;//8
	USART_Init(USART1,&USART1_InitStructure);
	USART_Cmd(USART1,ENABLE);
}

int fputc(int ch,FILE *f)
{
	USART_SendData(USART1,(unsigned char) ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC) != SET);
	return (ch);
}

