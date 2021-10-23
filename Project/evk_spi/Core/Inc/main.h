/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f4xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

#define DEST_IP_ADDR0   192
#define DEST_IP_ADDR1   168
#define DEST_IP_ADDR2   0
#define DEST_IP_ADDR3   88

#define DEST_PORT       7

/*Static IP ADDRESS: IP_ADDR0.IP_ADDR1.IP_ADDR2.IP_ADDR3 */
#define IP_ADDR0   192
#define IP_ADDR1   168
#define IP_ADDR2   0
#define IP_ADDR3   66

/*NETMASK*/
#define NETMASK_ADDR0   255
#define NETMASK_ADDR1   255
#define NETMASK_ADDR2   255
#define NETMASK_ADDR3   0

/*Gateway Address*/
#define GW_ADDR0   0
#define GW_ADDR1   0
#define GW_ADDR2   0
#define GW_ADDR3   0
/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

//#define ENC_INT_Pin 		GPIO_PIN_4
//#define ENC_INT_GPIO_Port 	GPIOA
//#define ENC_CS_Pin 			GPIO_PIN_4
//#define ENC_CS_GPIO_Port 	GPIOC
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ENC_CS_Pin GPIO_PIN_4
#define ENC_CS_GPIO_Port GPIOC
#define ENC_INT_Pin GPIO_PIN_5
#define ENC_INT_GPIO_Port GPIOC
#define ENC_INT_EXTI_IRQn EXTI9_5_IRQn
#define LED_1_Pin GPIO_PIN_12
#define LED_1_GPIO_Port GPIOD
#define LED_2_Pin GPIO_PIN_13
#define LED_2_GPIO_Port GPIOD
#define LED_3_Pin GPIO_PIN_14
#define LED_3_GPIO_Port GPIOD
#define LED_4_Pin GPIO_PIN_15
#define LED_4_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
