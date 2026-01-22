#include "dac.h"
#include "stm32f051x8.h"
#include <stdint.h>


void dac_init_lowlevel() {
    RCC->AHBENR |= 0x20000;

    GPIOA->MODER |= 0x55;

    GPIOA->OTYPER &= ~0xF;

    GPIOA->OSPEEDR |= 0xFF;
}

void dac_out(uint8_t value) {
    value &= 0x0F;

    GPIOA->BSRR = 0xF0000;

    GPIOA->BSRR = value;
}