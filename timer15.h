#ifndef TIMER15INTERRUPT_H
#define TIMER15INTERRUPT_H

void tim15_init_lowlevel();

void tim15_enable();

void tim15_disable();

void tim15_change_arr(uint16_t arr);

#endif
