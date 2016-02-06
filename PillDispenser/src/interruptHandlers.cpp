/*
 * interuptHandlers.cpp
 *
 *  Created on: 5 Feb 2016
 *      Author: Eivind
 */


#include "em_rtc.h"
#include "em_letimer.h"
#include "em_gpio.h"
#include "segmentlcd.h"

char *sentence[] = {"KAI", "TAKE", "YOUR", "MEDS."};
int wordPtr = 0;

void RTC_IRQHandler(void)
{
	/* Clear interrupt source */
	RTC_IntClear(RTC_IFC_COMP0);

	GPIO_PinOutToggle(gpioPortC, 0);

}

void LETIMER0_IRQHandler(void){
	SegmentLCD_Write(sentence[wordPtr]);
	wordPtr++;
	if(wordPtr == 4){wordPtr = 0;}
}


void GPIO_EVEN_IRQHandler(void)
{

}


