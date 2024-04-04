/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************

2. Glow LEDs in direction of inclination when axis value is above some fixed threshold value.
*/

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

//#include "uart.h"
//#include "i2c_lcd.h"
#include "lis3dsh.h"
#include "led.h"
#include "spi.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{   SystemInit();
	LIS_Data val;
	LIS_Init();
	LedInit(LED_GREEN);
	LedInit(LED_ORANGE);
	LedInit(LED_RED);
	LedInit(LED_BLUE);
	//DelayMs(1);

	while(1) {
           val = LIS_GetData();

            if(val.x>4000)
            	{
            	LedOn(LED_RED);
                DelayMs(400);
                LedOff(LED_RED);
                DelayMs(400);
            	}
            else if(val.y>4000)
              {
            	LedOn(LED_ORANGE);
            	DelayMs(400);
            	LedOff(LED_ORANGE);
            	DelayMs(400);
                }
            else if(val.y<-4000)
				 {
				LedOn(LED_BLUE);
				DelayMs(400);
				LedOff(LED_BLUE);
				DelayMs(400);
				 }

            else if(val.x<-5000)
			{
              LedOn(LED_GREEN);
              DelayMs(400);
              LedOff(LED_GREEN);
              DelayMs(400);
			}
	  }

	  return 0;
}







