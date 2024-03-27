// day03_1
// 1. Blink LEDs in clockwise and anti-clockwise continuously.
#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "led.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


int main(void)
{
	SystemInit();
	DelayMs(1);
	LedInit(LED_GREEN);
	LedInit(LED_ORANGE);
	LedInit(LED_RED);
	LedInit(LED_BLUE);
	while(1) {
		LedBlink(LED_GREEN, 300);
		LedBlink(LED_ORANGE, 300);
		LedBlink(LED_RED, 300);
		LedBlink(LED_BLUE, 300);

		LedBlink(LED_BLUE, 300);
		LedBlink(LED_RED, 300);
		LedBlink(LED_ORANGE, 300);
		LedBlink(LED_GREEN, 300);
	}
	return 0;
}


