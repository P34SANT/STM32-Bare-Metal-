/*
 * systick.c
 *
 *  Created on: Mar 27, 2026
 *      Author: Peasant
 */

#include "systick.h"

#define SYSTICK_LOAD_VAL  (16000 - 1)
#define CTRL_ENABLE       (1U << 0)
#define CTRL_CLKSRC       (1U << 2)
#define CTRL_COUNTFLAG    (1U << 16)
#define CTRL_TICKINT      (1U << 1)
#define SYSTICK_1HZ_VAL   (16000000)
void systick_init(void)
{
    SysTick->LOAD = SYSTICK_LOAD_VAL;
    SysTick->VAL = 0;
    SysTick->CTRL = CTRL_CLKSRC | CTRL_ENABLE;
}

void systick_delay_ms(uint32_t ms)
{
    for(uint32_t i = 0; i < ms; i++)
    {
        while(!(SysTick->CTRL & CTRL_COUNTFLAG));
    }
}

void systick_1hz_interrupt(void)
{
    SysTick->LOAD = SYSTICK_1HZ_VAL - 1;
    SysTick->VAL = 0;
    SysTick->CTRL = CTRL_CLKSRC | CTRL_ENABLE | CTRL_TICKINT;
}
