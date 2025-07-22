#include "main.h"

void delay(int xms)
{
	int i = 72;
	int j = 0;
	while (xms--)
	{
		for (; j < i; j++)
		{
			__nop();
		}
	}
}
int main()
{
	LED_Init();
	Usart1_Init(115200);
	while (1)
	{
		LED3_ON;
		delay(1000000);
		LED3_OFF;
		delay(1000000);
		Usart1_SendByte('A');
		delay(1000000);
	}
	return 0;
}