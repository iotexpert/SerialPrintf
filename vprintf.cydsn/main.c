
#include "project.h"
#include <stdio.h>
#include <stdarg.h>

#define MAX_FORMAT_BUFFER_SIZE	(255)
static uint8_t s_formatBuffer[MAX_FORMAT_BUFFER_SIZE];

void dbg_printf(char *format,...)                                      ///< Function Name        
{
	uint8_t iWriteNum = 0,i=0;	
	va_list  ap;
	
	if(!format)
		return;
	
	va_start(ap,format);
	iWriteNum = vsprintf((char *)s_formatBuffer,format,ap);
	va_end(ap);
	
	if(iWriteNum > MAX_FORMAT_BUFFER_SIZE)
		iWriteNum = MAX_FORMAT_BUFFER_SIZE;
	
	for(i=0;i<iWriteNum;i++)
    {
		UART_UartPutChar(s_formatBuffer[i]);                            ///< Uart Function        
	}
}

#define DBG_ENABLE                              (1)                                 ///< Enable Printf
#if DBG_ENABLE
    #define DBG_PRINTF(format,...)              dbg_printf(format,##__VA_ARGS__)
#else
    #define DBG_PRINTF(...)
#endif

// Heap=0x400
//Flash used: 4838 of 131072 bytes (3.7 %).
//SRAM used: 3748 of 16384 bytes (22.9 %). Stack: 2048 bytes. Heap: 1024 bytes.

//Heap = 0x80
//Flash used: 4838 of 131072 bytes (3.7 %).
//SRAM used: 2852 of 16384 bytes (17.4 %). Stack: 2048 bytes. Heap: 128 bytes.
int main(void)
{
    CyGlobalIntEnable; 
    UART_Start();
    
    DBG_PRINTF("Int=%d  String=%s\n",1,"asdf");
    
    for(;;)
    {
    }
}
