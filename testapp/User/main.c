#include "main.h"

void delay(int xms)
{
    while (xms--);
}
int main()
{
    LED_Init();
    Usart1_Init(115200);
    while (1)
    {
		LED_ON;
        printf("test1----------------------\r\n");
        delay(0xFFFFF);
        printf("test2----------------------\r\n");
		LED_OFF;
		delay(0xFFFFF); 
    }
    return 0;
}