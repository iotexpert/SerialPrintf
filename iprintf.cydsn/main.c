
#include "project.h"
#include "iprintf.h"

//Heap=0x400
//Flash used: 2952 of 131072 bytes (2.3 %).
//SRAM used: 3476 of 16384 bytes (21.2 %). Stack: 2048 bytes. Heap: 1024 bytes.

//Heap=0x80
//Flash used: 2952 of 131072 bytes (2.3 %).
//SRAM used: 2580 of 16384 bytes (15.7 %). Stack: 2048 bytes. Heap: 128 bytes.

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start();
    
    iprintf("Int=%d  String=%s\n",1,"asdf");

    for(;;)
    {
    }
}
