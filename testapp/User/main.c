#include "main.h"

void delay(int xms)
{
	int i = SystemCoreClock / 1000;
	int j = 0;
	while (xms--)
	{
		for (j = 0; j < i; j++)
		{
			__NOP();
		}
	}
}
int main()
{
	LED_Init();
	while (1)
	{
		LED3_ON;
		delay(10);
		LED3_OFF;
		delay(10);
	}
	return 0;
}