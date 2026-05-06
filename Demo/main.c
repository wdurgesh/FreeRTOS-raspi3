#include <stddef.h>
#include <stdint.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"

#include "demo.h"

void vApplicationTickHook(void)
{

}

void vApplicationIdleHook(void)
{

}

void main(void)
{
#if 0	
	uart_init();
#endif	
	extern void vUARTCommandConsoleStart( uint16_t usStackSize, UBaseType_t uxPriority );

	vUARTCommandConsoleStart(1024 /* Stack Size */, 7 /* Thread Priority*/ );

#if 0	
	uart_puts("qemu exit: Ctrl-A x / qemu monitor: Ctrl-A c\n");
	uart_puts("hello world\n");
#endif	

	vTaskStartScheduler();
}
