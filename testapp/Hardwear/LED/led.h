#ifndef _LED_H_
#define _LED_H_
#include "stm32f10x.h"

#define LED3_ON   GPIO_ResetBits(GPIOB, GPIO_Pin_5)
#define LED3_OFF  GPIO_SetBits(GPIOB, GPIO_Pin_5)

#define LED4_ON   GPIO_ResetBits(GPIOE, GPIO_Pin_5)
#define LED4_OFF  GPIO_SetBits(GPIOE, GPIO_Pin_5)

#define LED5_ON   GPIO_ResetBits(GPIOA, GPIO_Pin_5)
#define LED5_OFF  GPIO_SetBits(GPIOA, GPIO_Pin_5)

#define LED6_ON   GPIO_ResetBits(GPIOA, GPIO_Pin_6)
#define LED6_OFF  GPIO_SetBits(GPIOA, GPIO_Pin_6)

#define LED_ON   GPIO_SetBits(GPIOB, GPIO_Pin_12)
#define LED_OFF  GPIO_ResetBits(GPIOB, GPIO_Pin_12)

void LED_Init(void);


#endif //

