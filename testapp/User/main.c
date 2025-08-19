#include "main.h"


int main()
{
    LED_Init();
    Usart1_Init(115200);
	MAX7219_Init();
    while (1)
    {
        printf("test2222-------\r\n");

    }
    return 0;
}