/**
 * @name can.h
 * @brief Header file for CAN bus configuration.
 * @author Toby Digney
 * @date 15/10/2022
 */

#ifndef INC_CAN_H_
#define INC_CAN_H_

#include "stm32l4xx_hal_can.h"
#include "stm32l4xx_hal_gpio.h"
#include <stdio.h>

// 16 bit filter bit field offsets
#define STID_Pos	5
#define RTR_Pos		4
#define IDE_Pos		3
#define EXID_Pos	0

// Application defined standard ID bit field offset positions and masks
#define STID_PRIORITY_Pos		8
#define STID_DIRECTION_Pos		6
#define STID_TO_Pos				STID_DIRECTION_Pos
#define STID_FROM_Pos			STID_DIRECTION_Pos + 1
#define STID_DIRECTION_Pos		6
#define STID_ADDRESS_Pos		0

#define STID_PRIORITY_Msk		0b111
#define STID_DIRECTION_Msk		0b11
#define STID_TO_Msk				0b1
#define STID_FROM_Msk			0b1
#define STID_ADDRESS_Msk		0b111111

// Definition of direction field
#define FROM_BMS_TO_ALL		0b00
#define FROM_BMS_TO_FC		0b01
#define FROM_FC_TO_ALL		0b10
#define	FROM_FC_TO_BMS		0b11

// Definition of from/to fields
#define FROM_BMS		0b0
#define FROM_FC			0b1
#define TO_ALL			0b0
#define TO_NODE			0b1 //BMS or FC depending on FROM bit

// Definition of FC address
#define FC_ADDRESS		0b1000000 //1 more than maximum BMS address


typedef struct
{
	uint32_t sender; // address of sender
	uint32_t dataLength; // length of data payload in bytes (maximum of 8)
	uint8_t data[8]; // copy of data buffer
} canRxMessageTypeDef;

typedef struct
{
	uint32_t priority; // priority of message must be a value from 0 (highest) to 7 (lowest).
	uint32_t direction; // direction of message. must be either FROM_BMS_TO_ALL or FROM_BMS_TO_FC
	uint32_t dataLength; // length of data payload in bytes (maximum of 8)
	uint8_t data[8]; // length of data payload in bytes (maximum of 8)
	uint32_t txMailbox; // This value is updated automatically by firmware to a value of @arg CAN_Tx_Mailboxes once a mailbox is assigned. Initialise to 0.
} canTxMessageTypeDef;

void InitCan(GPIO_TypeDef *_rateSelectPort, uint16_t _rateSelectPin, CAN_HandleTypeDef *_canHandlePtr);
void ConfigureFilters(void);
canRxMessageTypeDef ReadCanMessage(void);
void SendCanMessage(canTxMessageTypeDef *message);

//TODO: add doxygen comments

#endif /* INC_CAN_H_ */
