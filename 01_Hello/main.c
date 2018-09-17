#include <stdio.h>
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"

#include "pin_mux.h"
#include "clock_config.h"

volatile uint32_t g_systickCounter;

void SysTick_Handler(void)
{
    if (g_systickCounter != 0U) { 
        g_systickCounter--;
    }
}

void delay_ms(uint32_t n)
{
    g_systickCounter = n;
    
    while(g_systickCounter != 0U) {
    }
}

int main(void)
{
    BOARD_InitPins();   
    BOARD_BootClockRUN();

    SysTick_Config(SystemCoreClock / 1000U);
    BOARD_InitDebugConsole();

    PRINTF("Hello World! \r\n");
    printf("Hello again! \r\n");

    int count = 0;
    while (1){
        PRINTF("Count = %d \r\n", count++);
        delay_ms(1000);  
    }
}
