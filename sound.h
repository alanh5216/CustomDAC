#ifndef SOUND_H
#define SOUND_H
#include <stdint.h>

extern uint8_t counter;
extern uint8_t values[32];
extern uint8_t notes[16];


void sound_play(uint8_t note);

#endif