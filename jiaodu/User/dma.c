#include "dma.h"
#include "stm32f10x.h"

extern uint32_t SendBuff;
//uint8_t ADC_Received2[SendBuff_SIZE];
//extern uint8_t ADC_Flag;
//uint32_t ADC_Received1;

void DMA1Config(void)
{
	//配置ADC->Memory
	DMA_InitTypeDef DMA1_InitStructure;
	
	//使能时钟
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	DMA1_InitStructure.DMA_BufferSize = 1;//
	DMA1_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA1_InitStructure.DMA_M2M = DMA_M2M_Disable;//diasble
	DMA1_InitStructure.DMA_MemoryBaseAddr = (u32)&SendBuff;
	DMA1_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA1_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Disable;//disable
	DMA1_InitStructure.DMA_Mode = DMA_Mode_Circular;//
	DMA1_InitStructure.DMA_PeripheralBaseAddr = (u32)&ADC1->DR;
	DMA1_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA1_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;//DIsABLE
	DMA1_InitStructure.DMA_Priority = DMA_Priority_High;//high
	DMA_Init(DMA1_Channel1,&DMA1_InitStructure);
	DMA_Cmd(DMA1_Channel1,ENABLE);
}
//发送完毕后产生中
//配置中断
void NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	//配置串口中断	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	//EXTI9_5_IRQHandler
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
//	EXTI15_10_IRQHandler
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStructure);
	
}




