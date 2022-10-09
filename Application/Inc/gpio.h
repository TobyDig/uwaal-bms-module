/**
 * @name gpio.h
 * @brief Header file for the special gpio functions.
 * @author Toby Digney
 * @date 05/10/2022
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "stm32l4xx_hal_gpio.h"

/**
 * @brief Used to read GPIOs which have a pull-up or pull-down resistor whilst minimizing power dissipation in the MCU package
 *
 * @param gpio_port Pointer to the GPIO handler. eg GPIOA
 * @param gpio_pin The GPIO pin number for the GPIO handle.
 * @param pupd The type of pull resistor needed for this pin's read operation to be valid. eg GPIO_PULLUP or GPIO_PULLDOWN
 * @return The pin state read.
 * @note
 * Can only be used to read one GPIO pin at a time. If multiple pins are passed by ORing (eg pin2|pin1|pin0) then only the lowest pin will be read.
 */
GPIO_PinState LowPowerRead(GPIO_TypeDef *gpio_port, uint16_t gpio_pin, uint32_t pupd);

void IdentifyMode(void);
void IdentifyCanAddress(void);

#endif /* INC_GPIO_H_ */
