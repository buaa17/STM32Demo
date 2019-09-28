#ifndef _DELAY_H
#define _DELAY_H

#include "stm32f10x.h"


void SysTick_Init(void);
void delay_us(uint64_t nTime);
void delay_ms(uint64_t nTime);
void delay_s(uint64_t nTime);

#endif

