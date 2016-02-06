/*
 * interuptHandlers.cpp
 *
 *  Created on: 5 Feb 2016
 *      Author: Eivind
 */


#include "em_rtc.h"
#inclde "em_letimer.h"
#include "em_gpio.h"

void RTC_IRQHandler(void)
{
	/* Clear interrupt source */
	RTC_IntClear(RTC_IFC_COMP0);

	GPIO_PinOutToggle(gpioPortC, 0);

}

void LETIMER0_IRQHandler(void){

}


void GPIO_EVEN_IRQHandler(void)
{

}


