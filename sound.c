#include "sound.h"
#include <stdint.h>
#include "stm32f051x8.h"
#include "systickdelay.h"
#include "dac.h"

uint8_t counter = 0;


uint8_t values[32] = {8, 9, 11, 12, 13, 14, 14, 15, 15, 15, 14, 14, 13, 12, 11, 9, 8, 7,
                          5, 4, 3, 2, 2, 1, 1, 1, 2, 2, 3, 4, 5, 7};
uint8_t notes[16] = {70, 63, 60, 60, 60, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};

void sound_play(uint8_t note) {
    for(int k = 0; k < 100000; k++) {
        for(int i = 0; i < 32; i++) {
            dac_out(values[i]);
            SysTick_wait1us(notes[note]);
        }
    }
}