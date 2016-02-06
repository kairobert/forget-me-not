/*
 * gpio.c++
 *
 *  Created on: 5 Feb 2016
 *      Author: Eivind
 */

#include "em_cmu.h"
#include "em_gpio.h"
#include "stepmotor.h"

void gpioSetup(){

	/* Enable GPIO in CMU */
	CMU_ClockEnable(cmuClock_GPIO, true);

	/* Configure PC0 as Output */
	GPIO_PinModeSet(gpioPortC, 0, gpioModePushPull, 0);

	/* Configure PD0 as input */
	GPIO_PinModeSet(gpioPortB, 9, gpioModeInput, 0);

	/* Set rising edge interrupt for both ports */
	GPIO_IntConfig(gpioPortB, 9, true, false, true);

	motor_gpioSetup(); //set up the output pins for the step motor

	/* Enable interrupt in core for even and odd gpio interrupts */
	NVIC_ClearPendingIRQ(GPIO_EVEN_IRQn);
	NVIC_EnableIRQ(GPIO_EVEN_IRQn);

	/* Set PC0 to 0 */
	GPIO_PinOutSet(gpioPortC, 0);
}


