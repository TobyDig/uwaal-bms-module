/**
 * @name charge_led.c
 * @brief Source file for charge LED functions.
 * @author Toby Digney
 * @date 09/10/2022
 */

#include "charge_led.h"

ChargeLedState_t DetectChargeLed(void)
{
	ChargeLedState_t status = 0;

	RCC->AHB2ENR |= 0b1; // connect clock to GPIOA

	temp = GPIOA->MODER;
	temp |= (0b1 << 16); // output mode for PA8
	temp &= ~(0b1 << 17); // output mode for PA8
	temp &= ~(0b11 << 18); // input mode for PA9
	GPIOA->MODER = temp;

    temp = GPIOA->PUPDR;
    temp &= ~(0b1 << 18); // enable pull down on PA9
    temp |= (0b1 << 19); // enable pull down on PA9
    GPIOA->PUPDR = temp;

    GPIOA->BSRR = (0b1 << 8); // set PA8 ouput to high level

	HAL_Delay(50); // delay to allow settling time due to pull down

    temp = GPIOA->PUPDR;
    temp &= ~(0b11 << 18); // disable pull down on PA9
    GPIOA->PUPDR = temp;

    HAL_Delay(50); // delay to allow settling time due to external charge led pull up (if present)

    status = GPIOA->IDR & (0b1 << 9); // read PA9

    return status;
}

void InitChargeLed(void)
{

	uint32_t temp;

	RCC->AHB2ENR |= 0b1; // connect clock to GPIOA
	RCC->APB2ENR |= (0b1 << 11); // connect clock to TIM1

	temp= GPIOA->MODER;
	temp |= (0b1 << 17); // alternate function mode for PA8
	temp &= ~(0b1 << 16); // alternate function mode for PA8
	temp |= (0b1 << 18); // output mode for PA9
	temp &= ~(0b1 << 19); // output mode for PA9
	GPIOA->MODER = temp;

	temp = GPIOA->AFR[1];
	temp |= 0b1; // set PA8 to alternate function 1
	temp &= ~(0b111 << 1); // set PA8 to alternate function 1
	GPIOA->AFR[1] = temp;

	GPIOA->BSRR = (0b1 << 25) // set PA9 ouput to low level

	TIM1->CCER |= 0b1; // enable capture mode

	temp = TIM1->CCMR1;
	temp &= ~0b11; // set channel 1 to output compare mode
	temp |= (0b11 << 4);// Set output to toggle on match
	temp &= ~((0b1 << 16) | (0b1 << 6)); // Set output to toggle on match
	TIM1->CCMR1 = temp;

	TIM1->BDTR |= (0b1 << 15); // Main output enable (MOE)

	TIM1->PSC = 79; // Set timer prescaler to 80 (1 is added implicitly)

	TIM1->CR1 |= (0b1 << 7); // Enable auto-reload preload register

}

void StartChargeLed(void)
{
	TIM1->CR1 |= 0b1; // Enable counter
	TIM1->EGR |= 0b1; // Trigger update event to ensure ARR preload value is loaded
}

void StopChargeLed(void)
{
	TIM1->CR1 &= ~0b1; // Disable counter
}

void SetChargeLedFrequency(uint16_t frequency)
{
	TIM1->ARR =  (HSE_FREQUENCY/(2 * (TIM1->PSC + 1) * frequency));
}
