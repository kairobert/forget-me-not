/*
 * leTimer.cpp
 *
 *  Created on: 5 Feb 2016
 *      Author: Eivind
 */
#include "em_letimer.h"
#include "em_cmu.h"
#include "leTimer.h"

#define LE_TIMER_CLOCK_FREQ 32768
#define LE_TIMER_CLOCK_DIVISION 1

void leTimerSetup(){

	/* 32 clock division to save energy */
//	CMU_ClockDivSet(cmuClock_LETIMER0, cmuClkDiv_32);



	NVIC_EnableIRQ(LETIMER0_IRQn);

	leTimerTurnOn();
}

void leTimerTurnOff(){
	/* Disable LE timer */
	CMU_ClockEnable(cmuClock_LETIMER0, false);

	/* Reset LE timer */
	LETIMER_Reset(LETIMER0);

}

void leTimerTurnOn(){
	CMU_ClockEnable(cmuClock_LETIMER0, true);

	LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;

	letimerInit.enable   = false;  /* Do not start LE timer after initialization is complete. */

	/* Initialising LE timer */
	LETIMER_Init(LETIMER0, &letimerInit);

	/* Setting timer interrupt time to 1 second */
	LETIMER_CompareSet(LETIMER0, 0, (LE_TIMER_CLOCK_FREQ/ 1));

	/*Enabling interrupt */
	LETIMER_IntEnable(LETIMER0, LETIMER_IF_COMP0);

	/* Initialize LE timer */
	LETIMER_Enable(LETIMER0, true);
}
