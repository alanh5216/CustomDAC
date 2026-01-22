#include "dac.c"
#include "main.h"
#include "sound.h"
#include "systickdelay.c"
#include "piano.c"
#include "stm32f051x8.h"
#include "sound.c"
#include "interrupt.c"
#include "timer15.c"
#include "timer15.h"
#include <stdint.h>

int main(void) {
    SysTick_init_low_level();
    dac_init_lowlevel();
    piano_init_lowlevel();
    tim15_init_lowlevel();
    interrupts_init_lowlevel();
    interrupts_tim15_init_enable_lowlevel();
    tim15_enable();

    while(1) {
      //sound_play(0);
      uint16_t key = piano_input();
      if(key != 0) {
        tim15_enable();
        tim15_change_arr(notes[key - 1]);
      }
      else {
        tim15_disable();
        dac_out(0);
      }
    }
    

}
//0.09 0.18 0.27 0.36 0.45 0.53 0.63 0.72 0.82 0.89 0.99 1.08 1.17 1.26 1.35