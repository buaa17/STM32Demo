#ifndef _DMA1_H
#define _DMA1_H

#define SendBuff_SIZE 11
#define ADC1_DR_Address ((u32)0x40012400+0x4c)

void DMA1Config(void);
void NVIC_Config(void);
float Data_Deal(void);
void Restart(void);

#endif

