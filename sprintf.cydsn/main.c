
#include "project.h"
#include <stdio.h>
#include <stdarg.h>

#define MAX_FORMAT_BUFFER_SIZE	(255)
static uint8_t s_formatBuffer[MAX_FORMAT_BUFFER_SIZE];

#define asprintf(...) sprintf((char *)s_formatBuffer,__VA_ARGS__); UART_UartPutString((const char *)s_formatBuffer)

//Heap = 0x80
//Flash used: 4806 of 131072 bytes (3.7 %).
//SRAM used: 2852 of 16384 bytes (17.4 %). Stack: 2048 bytes. Heap: 128 bytes.
int main(void)
{
    CyGlobalIntEnable; 
    UART_Start();
    
    asprintf("Int=%d  String=%s\n",1,"asdf");
    
    for(;;)
    {
    }
}
