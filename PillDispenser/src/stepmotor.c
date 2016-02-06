/**************************************************************************//**
 * @file
 * @brief LCD controller and Energy Mode/RTC demo for EFM32GG_STK3700
 * @version 4.2.1
 ******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 *
 ******************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_rtc.h"
#include "em_lcd.h"
#include "vddcheck.h"
#include "segmentlcd.h"
#include "bsp.h"
#include "bsp_trace.h"
#include "em_letimer.h"
#include "leTimer.h"
#include "stepmotor.h"


/*A B C D are debug values set to the output values going to the step motor*/
unsigned char A = 0;
unsigned char B = 0;
unsigned char C = 0;
unsigned char D = 0;

unsigned char number_of_motor_phases = 4; // the number of rows in motor_vectors
/*motor_vector[0] contains the values of A, B, C and D in the step motor first phase*/
unsigned char motor_vectors[4][4] = {
   {0, 0, 0, 1} ,
   {0, 1, 0, 0} ,
   {1, 0, 0, 0} ,
   {0, 0, 1, 0} ,
};
unsigned char motor_phase_counter = 0;


/**************************************************************************//**
 * @brief Setup GPIO interrupt to set the time
 *****************************************************************************/
void motor_gpioSetup(void)
{
  /* Enable GPIO in CMU */
  CMU_ClockEnable(cmuClock_GPIO, true);

  /* configure Pc0, Pc3, Pc4, Pc5  as outputs for step motor control */
  GPIO_PinModeSet(gpioPortC, 0, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortC, 3, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortC, 4, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortC, 5, gpioModePushPull, 0);

  GPIO_PinModeSet(gpioPortC, 6, gpioModePushPull, 0); //Pc6 as enable signal for the driver
}

/**************************************************************************//**
 * @brief motor timer interrupt handler, for controlling the step motor, one_step_completed must be set to 0 in order to start 4 microsteps
 *****************************************************************************/
unsigned char motor_microstep(void){
	if(motor_phase_counter < number_of_motor_phases){
		//set the debug values
		A = motor_vectors[motor_phase_counter][0];
		B = motor_vectors[motor_phase_counter][1];
		C = motor_vectors[motor_phase_counter][2];
		D = motor_vectors[motor_phase_counter][3];

		//either set or clear output pin depending on the desired value in the motor_vectors[i] vector
		//set or clear output A
		if(motor_vectors[motor_phase_counter][0] == 0){
			GPIO_PinOutClear(gpioPortC, 0); }
		else{
			GPIO_PinOutSet(gpioPortC, 0); }
		//set or clear output B
		if(motor_vectors[motor_phase_counter][1] == 0){
			GPIO_PinOutClear(gpioPortC, 3); }
		else{
			GPIO_PinOutSet(gpioPortC, 3); }
		//set or clear output C
		if(motor_vectors[motor_phase_counter][2] == 0){
			GPIO_PinOutClear(gpioPortC, 4); }
		else{
			GPIO_PinOutSet(gpioPortC, 4); }
		//set or clear output D
		if(motor_vectors[motor_phase_counter][3] == 0){
			GPIO_PinOutClear(gpioPortC, 5); }
		else{
			GPIO_PinOutSet(gpioPortC, 5); }

		motor_phase_counter++; //go to next vector in motor_vectors upon the next interrupt
	}
	else{
		motor_phase_counter = 0;
	}

	return motor_phase_counter;
}
