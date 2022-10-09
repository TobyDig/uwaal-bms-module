/**
 * @name timers.c
 * @brief Source file for the special gpio functions.
 * @author Toby Digney
 * @date 06/10/2022
 */

#include "timers.h"

void StartTimer(TIM_TypeDef *timer)
{
	timer->CR1 |= 0b1; // Enable counter
	timer->EGR |= 0b1; // Trigger update event to ensure ARR preload value is loaded
}

void StopTimer(TIM_TypeDef *timer)
{
	timer->CR1 &= ~0b1; // Disable counter
}

void SetTimerFrequency(TIM_TypeDef *timer, uint32_t frequency)
{
	timer->ARR = HSE_FREQUENCY/(2 * (timer->PSC + 1) * frequency);
}



