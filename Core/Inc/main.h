/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED1_Pin GPIO_PIN_13
#define LED1_GPIO_Port GPIOC
#define LED0_Pin GPIO_PIN_14
#define LED0_GPIO_Port GPIOC
#define TRIP_Pin GPIO_PIN_15
#define TRIP_GPIO_Port GPIOC
#define SWITCH_LED_Pin GPIO_PIN_0
#define SWITCH_LED_GPIO_Port GPIOC
#define SWITCH_SOFTTOUCH_Pin GPIO_PIN_1
#define SWITCH_SOFTTOUCH_GPIO_Port GPIOC
#define STAT_Pin GPIO_PIN_2
#define STAT_GPIO_Port GPIOC
#define PG_Pin GPIO_PIN_3
#define PG_GPIO_Port GPIOC
#define OPAMP_NINV_IN_HISENSE_Pin GPIO_PIN_0
#define OPAMP_NINV_IN_HISENSE_GPIO_Port GPIOA
#define OPAMP_INV_IN_HISENSE_Pin GPIO_PIN_1
#define OPAMP_INV_IN_HISENSE_GPIO_Port GPIOA
#define ALERT_Pin GPIO_PIN_2
#define ALERT_GPIO_Port GPIOA
#define OPAMP_OUT_HISENSE_Pin GPIO_PIN_3
#define OPAMP_OUT_HISENSE_GPIO_Port GPIOA
#define DAC_CHARGE_Pin GPIO_PIN_4
#define DAC_CHARGE_GPIO_Port GPIOA
#define DAC_HISENSE_Pin GPIO_PIN_5
#define DAC_HISENSE_GPIO_Port GPIOA
#define PRECHG_EN_Pin GPIO_PIN_6
#define PRECHG_EN_GPIO_Port GPIOA
#define DISCHG_EN_Pin GPIO_PIN_7
#define DISCHG_EN_GPIO_Port GPIOA
#define CE_Pin GPIO_PIN_4
#define CE_GPIO_Port GPIOC
#define ADC_LISENSE_Pin GPIO_PIN_5
#define ADC_LISENSE_GPIO_Port GPIOC
#define ADC_CV_Pin GPIO_PIN_0
#define ADC_CV_GPIO_Port GPIOB
#define ADC_TEMP_Pin GPIO_PIN_1
#define ADC_TEMP_GPIO_Port GPIOB
#define AFE_SCL_Pin GPIO_PIN_10
#define AFE_SCL_GPIO_Port GPIOB
#define AFE_SDA_Pin GPIO_PIN_11
#define AFE_SDA_GPIO_Port GPIOB
#define MODE_Pin GPIO_PIN_15
#define MODE_GPIO_Port GPIOB
#define AFE_ALERT_EXTI_Pin GPIO_PIN_6
#define AFE_ALERT_EXTI_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_7
#define LED2_GPIO_Port GPIOC
#define LED3_Pin GPIO_PIN_8
#define LED3_GPIO_Port GPIOC
#define LED4_Pin GPIO_PIN_9
#define LED4_GPIO_Port GPIOC
#define CHG_LEDP_Pin GPIO_PIN_8
#define CHG_LEDP_GPIO_Port GPIOA
#define CHG_LEDN_Pin GPIO_PIN_9
#define CHG_LEDN_GPIO_Port GPIOA
#define CAN_RS_Pin GPIO_PIN_12
#define CAN_RS_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define BUS_DETECT_EXTI_Pin GPIO_PIN_15
#define BUS_DETECT_EXTI_GPIO_Port GPIOA
#define DBG_TX_Pin GPIO_PIN_10
#define DBG_TX_GPIO_Port GPIOC
#define DBG_RX_Pin GPIO_PIN_11
#define DBG_RX_GPIO_Port GPIOC
#define ADDR_SEL3_Pin GPIO_PIN_12
#define ADDR_SEL3_GPIO_Port GPIOC
#define ADDR_SEL2_Pin GPIO_PIN_2
#define ADDR_SEL2_GPIO_Port GPIOD
#define FAULT_Pin GPIO_PIN_3
#define FAULT_GPIO_Port GPIOB
#define ADDR_SEL1_Pin GPIO_PIN_4
#define ADDR_SEL1_GPIO_Port GPIOB
#define ADDR_SEL0_Pin GPIO_PIN_5
#define ADDR_SEL0_GPIO_Port GPIOB
#define MEM_SCL_Pin GPIO_PIN_6
#define MEM_SCL_GPIO_Port GPIOB
#define MEM_SDA_Pin GPIO_PIN_7
#define MEM_SDA_GPIO_Port GPIOB
#define CAN_RX_Pin GPIO_PIN_8
#define CAN_RX_GPIO_Port GPIOB
#define CAN_TX_Pin GPIO_PIN_9
#define CAN_TX_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
