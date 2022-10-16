/**
 * @name charge_led.h
 * @brief Header file for charge LED functions.
 * @author Toby Digney
 * @date 09/10/2022
 */

#ifndef INC_CHARGE_LED_H_
#define INC_CHARGE_LED_H_

#include "stm32l431xx.h"

#define HSE_FREQUENCY 16000000

typedef enum
{
	CHARGE_LED_ABSENT = 0,
	CHARGE_LED_PRESENT = 1
} ChargeLedState_t;

/**
 * @brief Used to detect whether or not the charge LED is connected to the BMS module, run once during initialization.
 * @return Returns whether or not the charge LED is connected.
 * @note This function is optional, if used it must be run before InitChargeLed.
 */
ChargeLedState_t DetectChargeLed(void);

/**
 * @brief Used to initialise the pins which drive the charge LED, run once during initialization.
 * @note This function must be called to initialise the charge LED, if DetectChargeLed is used, this function must be executed after it.
 */
void InitChargeLed(void);

/**
 * @brief Used to enable the charge LED when it is disabled.
 */
void StartChargeLed(void);

/**
 * @brief Used to disable the charge LED when it is enabled.
 */
void StopChargeLed(void);

/**
 * @brief Used to set the frequency that the charge LED blinks at. Can be called at any time. Must called at least once after reset to set the frequency.
 * @param frequency The frequency in Hertz to set the charge LED blink rate to.
 */
void SetChargeLedFrequency(uint16_t frequency);

#endif /* INC_CHARGE_LED_H_ */
