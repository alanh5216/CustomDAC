#include "piano.h"
#include "stm32f051x8.h"
#include <stdint.h>


void piano_init_lowlevel() {
    RCC->AHBENR |= 0x40000;

    GPIOB->MODER &= ~0x3F;

    GPIOB->PUPDR |= 0x15;
}

uint8_t piano_input() {
    uint8_t value = 0;

    if (!(GPIOB->IDR & 0x1)) {
        value |= 0x01;
    }
    if (!(GPIOB->IDR & 0x2)) {
        value |= 0x02;
    }
    if (!(GPIOB->IDR & 0x4)) {
        value |= 0x03;
    }

    return value;
}