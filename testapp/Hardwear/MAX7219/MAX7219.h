#ifndef _MAX7219_H_
#define _MAX7219_H_
#include "stm32f10x.h"

#define MAX7219_CS_H	GPIO_SetBits(GPIOE, GPIO_Pin_1)
#define MAX7219_CS_L	GPIO_ResetBits(GPIOE, GPIO_Pin_1)


void MAX7219_Init(void);



#endif // !_MAX7219_H_

