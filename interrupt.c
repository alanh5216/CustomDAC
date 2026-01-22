#include "interrupt.h"
#include "stm32f051x8.h"
#include "dac.h"
#include "sound.h"


void interrupts_init_lowlevel() {
    /* Enable the SYSCFG Clock (Bit 0) RM0091 6.4.7 */
    RCC->APB2ENR |= 0x1;
}   

void interrupts_tim15_init_enable_lowlevel() {
    /* Enable the Timer 15 Global Interrupt in NVIC ISER (bit 20) PM0215 4.2.2 & RM0091 11.1.3 */
    NVIC->ISER[0] |= 0x100000;
    /* Set the priority of Timer 15 Interrupt Register 5 (Bits 7-0) Only top 2 bits hold priority value (Bits 7:6),
       meaning only 4 priority levels are possible, the lower the number, the higher the priority PM0215 4.2.6 */
    NVIC->IP[5] |= 0xC0;
}

void interrupts_tim15_clear_pending_lowlevel() {
    /* Clear the Timer 15 Global Interrupt Pending in NVIC ICPR (Bit 20) PM0215 4.2.5 & RM0091 11.1.3 
       This line is not required to clear the interrupt. */
    /* NVIC Internal Pending Status Clear Register this register clears pending interrupts for that specific interrupt in the NVIC.
       However, NVIC ICPR does not clear the interrupt for EXTI interrupts, this is only its internal signal, therefore you must still clear 
       the interrupt in the EXTI register for EXTI interrupts. Otherwise if you do not clear the EXTI_PR in the ISR as soon as you exit it 
       will call the interrupt again and the will have infinite loop of interrupt being called.*/    
       //NVIC->ICPR[0] |= 0x100000;
    /* Clear the Timer 15 Update Interrupt Flag (Bit 0) RM0091 20.6.4 
       This Line is Required. This clears the interrupt. */
    TIM15->SR &= ~0x1;
}

void TIM15_IRQHandler(void) {
    dac_out(values[counter]);
    counter++;
    if(counter >= 32) {
        counter = 0;
    }
    interrupts_tim15_clear_pending_lowlevel();
}