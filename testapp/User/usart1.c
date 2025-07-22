#include "usart1.h"
#include <stdio.h>
#include <string.h>

void Usart1_Init(u32 Baud)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);
	// PA9  --- tx
	// PA10 --- rx
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz; // 高速模式，适合串口通信
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP; // 推挽复用输出
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING; // 浮空输入
	GPIO_Init(GPIOA, &GPIO_InitStruct);


	USART_InitTypeDef USART_InitStruct = { 0 };
	USART_InitStruct.USART_BaudRate = Baud;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//硬件流控制
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART1, &USART_InitStruct);

	USART_Cmd(USART1, ENABLE);
}

//void Usart1_SendByte(u8 data)
//{
//	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
//	USART_SendData(USART1, data);
//}
//
//void Usart_SendStr(char *str)
//{
//	while (*str != '\0')
//	{
//		Usart1_SendByte(*str);
//		str++;
//	}
//	Usart1_SendByte('\0');
//}

/****************************************************
函数功能：printf重定向
参    数：None
返 回 值：None
备    注：
*****************************************************/
#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE
{
	int handle;
};

FILE __stdout;
//定义_sys_exit()以避免使用半主机模式    
void _sys_exit(int x)
{
	x = x;
}
void _ttywrch(int ch)
{
	ch = ch;
}
//重定义fputc函数 
int fputc(int ch, FILE *f)
{
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
	USART_SendData(USART1, ch);
	return ch;
}

/**********************printf support end**********************/
#endif