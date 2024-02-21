/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 3, 2021 - 7:38:13 PM
* #File Name    : MiddMCUCore.h
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __MIDD_MCU_CORE_H_
#define __MIDD_MCU_CORE_H_
/*********************************INCLUDES*************************************/
#include "Project_Conf.h"
/******************************MACRO DEFINITIONS*******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/
/**
 * @brief init MCU clock
 * @param void
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middMCUClockInit(void);

/**
 * @brief enter sleep mode
 * @param void
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middMCUEnterSleepMode(void);

/**
 * @brief init input and output GPIO
 * @param void
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middMCUGpioInit(void);

 /**
  * @brief init I2C
  * @param void
  * @return if everything is OK, return SUCCES
  *         otherwise return FAILURE
  */
RETURN_STATUS middMCUI2CInit(void);

/**
 * @brief init SPI
 * @param void
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middMCUSPIInit(void);

/**
 * @brief init I2S
 * @param void
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middMCUI2SInit(void);

/**
 * @brief init DMA
 * @param void
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middMCUDmaInit(void);

/**
 * @brief init using timers
 * @param void
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middMCUTimers(void);

/**
* @brief init all UART Channel
* @param void
* @return if everything is OK, return SUCCES
*         otherwise return FAILURE
*/
RETURN_STATUS middMCUUartInit(void);

/**
* @brief init all CAN Channel
* @param void
* @return if everything is OK, return SUCCES
*         otherwise return FAILURE
*/
RETURN_STATUS middMCUCanInit(void);

/**
* @brief init all ADC Channel
* @param void
* @return if everything is OK, return SUCCES
*         otherwise return FAILURE
*/
RETURN_STATUS middMCUADCInit(void);

/**
* @brief init internal RTC
* @param void
* @return if everything is OK, return SUCCES
*         otherwise return FAILURE
*/
RETURN_STATUS middMcuRTCInit(void);

 /**
  * @brief init WDT init
  * @param wdt time ms
  * @return if everything is OK, return SUCCES
  *         otherwise return FAILURE
  */
RETURN_STATUS middMCUWdtInit(U32 timeMs);

/**
 * @brief stop WDT
 * @param void
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middMCUWdtStart(void);

/**
 * @brief feed WDT
 * @param void
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middMCUWdtFeed(void);

/**
 * @brief init FMC
 * @param void
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middMcuFmcInit(void);

#endif /* __MIDD_MCU_CORE_H_ */

/********************************* End Of File ********************************/
