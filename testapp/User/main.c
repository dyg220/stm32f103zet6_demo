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
		printf("test\r\n");
		delay(1000000);
	}
	return 0;
}