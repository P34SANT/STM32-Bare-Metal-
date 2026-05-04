//main.c
#include "uart.h"
#include <stdio.h>
#include <stdint.h>
#include <util.h>
#include "adc.h"
#include "systick.h"

char sensor[20];
uint32_t val;
uint32_t S = 0;
int main(void){
	systick_1hz_interrupt();
    pb0_adc_init();
    UART2_init();
    led_init();

    while(1){


    	val = SysTick->VAL;


    }
}
static void Systick_Callback(void){

    sprintf(sensor,"%lu\n\r",S);
    UART2_write_string(sensor);
    S++;
}

void SysTick_Handler(void){
	Systick_Callback();
}
