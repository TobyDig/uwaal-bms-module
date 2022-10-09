/**
 * @name gpio.c
 * @brief Source file for the special gpio functions.
 * @author Toby Digney
 * @date 05/10/2022
 */

#include "gpio.h"

GPIO_PinState LowPowerRead(GPIO_TypeDef *gpio_port, uint16_t gpio_pin, uint32_t pupd)
{
	GPIO_PinState pinstatus;
	uint32_t temp = 0;

	// get the gpio pin number from the pin
	uint32_t gpio_pin_number = 0;
	while (((gpio_pin >> gpio_pin_number) & 0x1) != 0x1)
	{
		gpio_pin_number++;
	}

	// ensure the appropriate pull resistor is enabled.
    temp = gpio_port->PUPDR; // read PUPD register
    temp &= ~(GPIO_PUPDR_PUPD0 << (gpio_pin_number * 2U)); // clear the corresponding bits
    temp |= ((pupd) << (gpio_pin_number * 2U)); // write the new bit value
    gpio_port->PUPDR = temp; // update the register

    // delay to allow settling time before reading
	HAL_Delay(50);

	// read the pin
	pinstatus = HAL_GPIO_ReadPin(gpio_port, gpio_pin);

	// disable pull resitor to minimize power disipation.
	temp &= ~(GPIO_PUPDR_PUPD0 << (gpio_pin_number * 2U));// clear the corresponding bits
	gpio_port->PUPDR = temp; // update the register

	return pinstatus;
}

void IdentifyMode(void)
{
	//mode = LowPowerRead(MODE_GPIO_Port, MODE_Pin, GPIO_PULLUP);
}

void IdentifyCanAddress(void)
{
	//addr3 = LowPowerRead(ADDR_SEL3_GPIO_Port, ADDR_SEL3_Pin, GPIO_PULLDOWN);
	//addr2 = LowPowerRead(ADDR_SEL2_GPIO_Port, ADDR_SEL2_Pin, GPIO_PULLDOWN);
	//addr1 = LowPowerRead(ADDR_SEL1_GPIO_Port, ADDR_SEL1_Pin, GPIO_PULLDOWN);
	//addr0 = LowPowerRead(ADDR_SEL0_GPIO_Port, ADDR_SEL0_Pin, GPIO_PULLDOWN);
	//address = 0;
	//address = (addr3 << 3) | (addr2 << 2) | (addr1 << 1) | (addr0 << 0);
}
