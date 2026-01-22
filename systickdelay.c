#include "systickdelay.h"
#include "stm32f051x8.h"

void SysTick_init_low_level() {
  /* Initialize SysTick Timer in PM0215 4.4 */
  /* Register STK_CSR (Control & Status Register) Setting it to 0 to disable it */
  SysTick->CTRL = 0;
  /* Register STK_RVR (Reload Value Register) Setting reload to max value 4.4.1 in PM0215 */
  SysTick->LOAD = 0x00FFFFFF;
  /* Register STK_CSR (Current Value Register) any write sets value to 0 & COUNTFLAG in STK_CSR to 0 4.4.3 in PM0215 */
  SysTick->VAL = 0;
  /* Register STK_CSR (Control & Status Register) Setting bit 0 & bit 2 to enable & set clock to processor core clock 4.4.1 in PM0215 */
  SysTick->CTRL = 0x5;
}


/* SysTick uses 24 bit down counter. Max delay value to be passed is ~16million which is about 1/3 Seconds. */
void SysTick_wait(uint32_t delay) {
  if(delay <= 1 ) return;
  SysTick->LOAD = delay-1;
  SysTick->VAL = 0;
  while( (SysTick->CTRL & 0x00010000) == 0) {}
}

void SysTick_wait10ms(uint32_t delay) {
  for(int i = 0;i < delay;i++) {
    SysTick_wait(480000);
  }
}

void SysTick_wait1ms(uint32_t delay) {
  for(int i = 0;i < delay;i++) {
    SysTick_wait(48000);
  }
}

void SysTick_wait100us(uint32_t delay) {
  for(int i = 0;i < delay;i++) {
    SysTick_wait(4800);
  }
}
void SysTick_wait10us(uint32_t delay) {
  for(int i = 0;i < delay;i++) {
    SysTick_wait(480);
  }
}
void SysTick_wait1us(uint32_t delay) {
  for(int i = 0;i < delay;i++) {
    SysTick_wait(48);
  }
}