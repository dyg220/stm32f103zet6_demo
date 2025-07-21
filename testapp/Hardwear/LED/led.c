#include "led.h"

/*
	PB5---D3
	PE5---D4
	PA5---D5
	PA6---D6
*/
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOE, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_WriteBit(GPIOB, GPIO_Pin_5, Bit_RESET);
	GPIO_WriteBit(GPIOE, GPIO_Pin_4, Bit_RESET);
	GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_RESET);
	GPIO_WriteBit(GPIOA, GPIO_Pin_6, Bit_RESET);
}