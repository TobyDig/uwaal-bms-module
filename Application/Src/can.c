/**
 * @name can.c
 * @brief Source file for CAN bus configuration.
 * @author Toby Digney
 * @date 15/10/2022
 */

#include "can.h"


static CAN_HandleTypeDef *canHandlePtr = NULL;
static GPIO_TypeDef *rateSelectPort = NULL;
static uint16_t rateSelectPin = UINT16_MAX;

extern uint32_t can_address;

static CAN_FilterTypeDef filter;

void InitCan(GPIO_TypeDef *_rateSelectPort, uint16_t _rateSelectPin, CAN_HandleTypeDef *_canHandlePtr)
{

	rateSelectPort = _rateSelectPort;
	rateSelectPin = _rateSelectPin;
	canHandlePtr = _canHandlePtr;

	HAL_GPIO_WritePin(rateSelectPort, rateSelectPin, GPIO_PIN_RESET);

	//TODO: check if IRQ initialisation as per stm32l4xx_hal_can.c is done automatically by generated code.

	ConfigureFilters();

	HAL_CAN_Start(canHandlePtr);
}

void ConfigureFilters(void)
{
	// filter01: receive any message addressed TO_ALL nodes
	filter01_mask = (STID_TO_Msk << STID_TO_Pos) << STID_Pos;
	filter01_id = (TO_ALL << STID_TO_Pos) << STID_Pos;

	// filter02: receive any message FROM_FC_TO_BMS that is addressed to the current BMS
	filter02_mask = (STID_DIRECTION_Msk << STID_DIRECTION_Pos) << STID_Pos;
	filter02_id = ((FROM_FC_TO_BMS << STID_DIRECTION_Pos) | (can_address << STID_ADDRESS_Pos)) << STID_Pos;

	filter.FilterMaskIdHigh = filter01_mask;
	filter.FilterIdHigh = filter01_id;
	filter.FilterMaskIdLow = filter02_mask;
	filter.FilterIdLow = filter02_id;
	filter.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	filter.FilterBank = 0;
	filter.FilterMode = CAN_FILTERMODE_IDMASK;
	filter.FilterScale = CAN_FILTERSCALE_16BIT;
	filter.FilterActivation = CAN_FILTER_ENABLE;
	filter.SlaveStartFilterBank = 0; //this field is irrelevant.

	HAL_CAN_ConfigFilter(canHandlePtr, &filter);
}

canRxMessageTypeDef ReadCanMessage(void)
{

	uint32_t direction = 0;

	CAN_RxHeaderTypeDef rxHeader = {
		.StdId = 0,
		.ExtId = 0,
		.IDE = 0,
		.RTR = 0,
		.DLC = 0,
		.Timestamp = 0,
		.FilterMatchIndex = 0
	};

	canRxMessageTypeDef message = {
			.sender = 0,
			.dataLength = 0,
			.data[8] = {0, 0, 0, 0, 0, 0, 0, 0}
	};

	HAL_CAN_GetRxMessage(canHandlePtr, CAN_RX_FIFO0, &rxHeader, message.data);

	direction = (rxHeader.StdId & (STID_DIRECTION_Msk << STID_DIRECTION_Pos)) >> STID_DIRECTION_Pos;

	switch (direction)
	{
	case FROM_BMS_TO_ALL:
		message.sender = (rxHeader.StdId & (STID_ADDRESS_Msk << STID_ADDRESS_Pos)) >> STID_ADDRESS_Pos;
		break;
	case FROM_FC_TO_ALL:
		message.sender = FC_ADDRESS;
		break;
	case FROM_FC_TO_BMS:
		message.sender = FC_ADDRESS;
		break;
	}

	message.dataLength = rxHeader.DLC;

	return message; //slow compared to returning a pointer but cbf changing rn
}


void SendCanMessage(canTxMessageTypeDef *message)
{
	uint32_t id = (message->priority << STID_PRIORITY_Pos) | (message->direction << STID_DIRECTION_Pos) | (can_address << STID_ADDRESS_Pos);

	CAN_TxHeaderTypeDef txHeader = {
		.StdId = id,
		.ExtId = 0,
		.IDE = CAN_ID_STD,
		.RTR = CAN_RTR_DATA,
		.DLC = message->dataLength,
		.TransmitGlobalTime = DISABLE
	};

	HAL_CAN_AddTxMessage(canHandlePtr, &txHeader, message->data, &(message->txMailbox));
}


