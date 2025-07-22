#include "usart1.h"

void Usart1_Init(u32 Baud)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);
	//PA9  --- tx
	//PA10 --- rx
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP; //推挽复用输出
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING; //浮空输入
	GPIO_Init(GPIOA, &GPIO_InitStruct);


	USART_InitTypeDef USART_InitStruct = { 0 };
	USART_InitStruct.USART_BaudRate = Baud;
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_StopBits = 1;
	USART_InitStruct.USART_WordLength = 8;
	USART_Init(USART1, &USART_InitStruct);

	USART_Cmd(USART1, ENABLE);

}

u8 Usart1_SendByte(u8 data)
{
	while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET)
	{
		USART_SendData(USART1, data);
	}
	return data;
}