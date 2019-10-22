#include "usart1.h"
#include "stdio.h"
#include "stm32f10x.h"

void USART1_Config(void)
{
	//��ʼ��ʹ�õĶ˿� A9->TX   A10->Rx
	//��ʼ��GPIO
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART1_InitStructure;	
	//ʹ��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;//�����������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//��������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//���ò����ʵ�
	USART1_InitStructure.USART_BaudRate = 115200;
	USART1_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//None
	USART1_InitStructure.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;//
	USART1_InitStructure.USART_Parity = USART_Parity_No;//No
	USART1_InitStructure.USART_StopBits = USART_StopBits_1;//1
	USART1_InitStructure.USART_WordLength = USART_WordLength_8b;//8b
	//����
	USART_Init(USART1,&USART1_InitStructure);
//	USART_DMACmd(USART1, USART_DMAReq_Tx, ENABLE);
	//ʹ��
	USART_Cmd(USART1,ENABLE);
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_ITConfig(USART1,USART_IT_IDLE,ENABLE);
}

int fputc(int ch,FILE* f)
{
	USART_SendData(USART1,(unsigned char) ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC) != SET);
	return ch;
}


