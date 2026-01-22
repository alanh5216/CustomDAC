#include "timer15.h"
#include "stm32f051x8.h"

void tim15_init_lowlevel() {
    /* Enable the TIM15 Clock (bit 16) RM0091 6.4.7 */
    RCC->APB2ENR |= 0x10000;
    /* Disable Timer During Configuration (Bit 0) 20.6.1 in RM0091*/
    TIM15->CR1 &= ~0x1;
    /* Enable Auto-Reload Preload (Bit 7) 20.4.1 & 20.6.1 in RM0091 */
    TIM15->CR1 |= 0x80;
    /* Enabled Only Counter Overflow/Underflow Generates Update Interrupt or DMA request (Bit 2) 20.6.1 in RM0091 */
    TIM15->CR1 |= 0x4;
    /* Update Event Enabled (Bit 1) 20.4.2 & 20.6.1 in RM0091 */
    TIM15->CR1 &= ~0x2;
    /* One Pulse Mode (One Shot Mode) Disabled (Bit 3) 20.6.1 in RM0091 */
    TIM15->CR1 &= ~0x8;
    /* Enabled Updates Generate Interrupts (Bit 0) 20.6.3 in RM0091 */
    TIM15->DIER |= 0x1;
    /* Clear Any Pending Update Interrupts (Bit 0) 20.6.4 in RM0091 */
    TIM15->SR &= ~0x1;
    /* Set Prescaler Assuming 8MHz Clock = 1MHz Counter Clock Frequency 20.4.1 & 20.6.10 in RM0091 
       Use Assignment Operator Instead (=) Using |= keeps old bits & ORs new ones on top; corrupting the values */
    TIM15->PSC = 0x7;
    /* Set Auto-Reload Register for 71us Assuming 1MHz Counter Clock Frequency 20.4.1 & 20.6.11 in RM0091 
       Use Assignment Operator Instead (=) Using |= keeps old bits & ORs new ones on top; corrupting the values */
    TIM15->ARR = 0x47;
}

void tim15_enable() {
    /* Enable Timer (Bit 0) 20.6.1 in RM0091*/
    TIM15->CR1 |= 0x1;
}

void tim15_disable() {
    /* Disable Timer (Bit 0) 20.6.1 in RM0091*/
    TIM15->CR1 &= ~0x1;
}

void tim15_change_arr(uint16_t arr) {
    TIM15->ARR = arr;
}