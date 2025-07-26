#include "MAX7219.h"

//blog.csdn.net/weichen_78/article/details/128284559
void MAX7219_Init(void)
{
	//PE1 PE3 PE5
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_5;
	GPIO_Init(GPIOE, &GPIO_InitStruct);




}