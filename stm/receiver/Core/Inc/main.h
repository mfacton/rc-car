/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define ROT_Pin GPIO_PIN_0
#define ROT_GPIO_Port GPIOA
#define PR1_Pin GPIO_PIN_1
#define PR1_GPIO_Port GPIOA
#define PR2_Pin GPIO_PIN_2
#define PR2_GPIO_Port GPIOA
#define PR3_Pin GPIO_PIN_3
#define PR3_GPIO_Port GPIOA
#define PR4_Pin GPIO_PIN_4
#define PR4_GPIO_Port GPIOA
#define PR5_Pin GPIO_PIN_5
#define PR5_GPIO_Port GPIOA
#define PR6_Pin GPIO_PIN_6
#define PR6_GPIO_Port GPIOA
#define BTN4_Pin GPIO_PIN_7
#define BTN4_GPIO_Port GPIOA
#define BTN2_Pin GPIO_PIN_0
#define BTN2_GPIO_Port GPIOB
#define BTN3_Pin GPIO_PIN_1
#define BTN3_GPIO_Port GPIOB
#define BTN1_Pin GPIO_PIN_2
#define BTN1_GPIO_Port GPIOB
#define IRQ_Pin GPIO_PIN_12
#define IRQ_GPIO_Port GPIOB
#define CE_Pin GPIO_PIN_8
#define CE_GPIO_Port GPIOA
#define CSN_Pin GPIO_PIN_9
#define CSN_GPIO_Port GPIOA
#define SIG_ESC_Pin GPIO_PIN_11
#define SIG_ESC_GPIO_Port GPIOA
#define SIG_SERVO_Pin GPIO_PIN_15
#define SIG_SERVO_GPIO_Port GPIOA
#define WP_Pin GPIO_PIN_5
#define WP_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
