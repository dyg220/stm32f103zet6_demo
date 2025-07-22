
#ifndef _USART1_H_
#define _USART1_H_
#include "stm32f10x.h"

void Usart1_Init(u32 Baud);
void Usart1_SendByte(u8 data);
void Usart_SendStr(char *str);


#endif // !_USART1_H_

