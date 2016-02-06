/*
 * interruptHandlers.h
 *
 *  Created on: 5 Feb 2016
 *      Author: Eivind
 */

#ifndef INTERRUPTHANDLERS_H_
#define INTERRUPTHANDLERS_H_

void RTC_IRQHandler(void);

void LETIMER0_IRQHandler(void);

void GPIO_EVEN_IRQHandler(void);

#endif /* INTERRUPTHANDLERS_H_ */
