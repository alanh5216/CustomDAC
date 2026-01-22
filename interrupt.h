#ifndef INTERRUPT_H
#define INTERRUPT_H

void interrupts_init_lowlevel();

void interrupts_tim15_init_enable_lowlevel();

void interrupts_tim15_clear_pending_lowlevel();

void TIM15_IRQHandler(void);

#endif
