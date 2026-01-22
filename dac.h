#ifndef DAC_H
#define DAC_H
#include <stdint.h>


void dac_init_lowlevel();

void dac_out(uint8_t value);
#endif