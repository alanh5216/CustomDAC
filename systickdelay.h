#ifndef SYSTICKDELAY_H
#define SYSTICKDELAY_H

void SysTick_init_low_level();

void SysTick_wait(uint32_t delay);

void SysTick_wait100us(uint32_t delay);

void SysTick_wait10us(uint32_t delay);

void SysTick_wait1us(uint32_t delay);

void SysTick_wait1ms(uint32_t delay);

void SysTick_wait10ms(uint32_t delay);

#endif