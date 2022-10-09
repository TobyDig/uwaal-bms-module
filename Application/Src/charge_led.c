/*
 * charge_led.c
 *
 *  Created on: Oct 9, 2022
 *      Author: tobya
 */

#include "charge_led.h"

void InitChargeLed(void)
{

	uint32_t temp;

	RCC->AHB2ENR |= 0b1; // connect clock to GPIOA
	RCC->APB2ENR |= (0b1 << 11); // connect clock to TIM1

	temp= GPIOA->MODER;
	temp |= (0b1 << 17); // alternate function mode for PA8
	temp &= ~(0b1 << 16); // alternate function mode for PA8
	GPIOA->MODER = temp;

	temp = GPIOA->AFR[1];
	temp |= 0b1; // set PA8 to alternate function 1
	temp &= ~(0b111 << 1); // set PA8 to alternate function 1
	GPIOA->AFR[1] = temp;


	not needed
	TIM2->CR1 &= ~(0b1 << 4); // set as down counter

	TIM2->SMCR &= ~(0b1 << 16); // disable slave mode
	TIM2->SMCR &= ~0b111; // disable slave mode


	timer->CCER |= 0b1; // enable capture mode

	//TODO: read modify write these properly.
	timer->CCMR1 &= ~0b11; // set channel 1 to output compare mode

	TIM2->CCMR1 &= ~(0b1 << 16); // Set output to toggle on compare match
	TIM2->CCMR1 &= ~(0b1 << 6); // Set output to toggle on compare match
	TIM2->CCMR1 |= (0b011 << 4); // Set output to toggle on compare match

	TIM2->PSC = 1; // Set timer prescaler to 2 (1 is added implicitly)

	TIM2->CR1 |= (0b1 << 7); // Enable auto-reload preload register
}
