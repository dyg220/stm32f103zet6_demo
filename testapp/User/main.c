#include "main.h"

void delay(int xms)
{
    while (xms--);
}
int main()
{
    LED_Init();
    Usart1_Init(115200);
	MAX7219_Init();
    while (1)
    {
        printf("test1----------------------\r\n");
        delay(0xFFFFF);

    }
    return 0;
}