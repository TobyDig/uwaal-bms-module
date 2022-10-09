/**
 * @name timers.h
 * @brief Header file for the special gpio functions.
 * @author Toby Digney
 * @date 06/10/2022
 */

#ifndef INC_TIMERS_H_
#define INC_TIMERS_H_

#define HSE_FREQUENCY 16000000

void StartTimer(TIM_TypeDef *timer);
void StopTimer(TIM_TypeDef *timer);
void SetTimerFrequency(TIM_TypeDef *timer, uint32_t frequency);

#endif /* INC_TIMERS_H_ */
