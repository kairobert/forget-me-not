/**************************************************************************//**
 * @file
 * @brief Empty Project
 * @author Energy Micro AS
 * @version 3.20.2
 ******************************************************************************
 * @section License
 * <b>(C) Copyright 2014 Silicon Labs, http://www.silabs.com</b>
 *******************************************************************************
 *
 * This file is licensed under the Silicon Labs Software License Agreement. See 
 * "http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt"  
 * for details. Before using this software for any purpose, you must agree to the 
 * terms of that agreement.
 *
 ******************************************************************************/
#include "em_device.h"
#include "em_chip.h"
#include "em_emu.h"
#include "rtc.h"
#include "gpio.h"
#include "interruptHandlers.h"
#include "leTimer.h"
#include "segmentlcd.h"

/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/
int main(void)
{
  /* Chip errata */
  CHIP_Init();

  gpioSetup();
  SegmentLCD_Init(false); //init the segment lcd, bool used to check if power supply i low
  rtcSetup();
  leTimerSetup();
  /* Infinite loop */
  while (1) {
	  EMU_EnterEM2(true);
  }
}
