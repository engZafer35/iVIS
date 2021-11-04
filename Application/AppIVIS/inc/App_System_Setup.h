/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 3, 2021 - 3:12:19 PM
* #File Name    : App_System_Setup.h
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __APP_SYSTEM_SETUP_H__
#define __APP_SYSTEM_SETUP_H__
/*********************************INCLUDES*************************************/
#include "Project_Conf.h"
/******************************MACRO DEFINITIONS*******************************/

/*******************************TYPE DEFINITIONS ******************************/
typedef enum HARDWARE_UNITS_
{
    EN_HW_UART_DEBUG,
    EN_HW_ETH,
    EN_HW_UART_COMM,
    EN_HW_CAN_BUS,
//    EN_HW_SPI_ETH,
    EN_HW_USB,
    EN_HW_VOICE,
    EN_HW_TOUCH_SCREEN,

}HARDWARE_UNITS;
/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/**
 * \brief   init all hardware units
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appSysInitAllHwUnit(void);

/**
 * \brief   close a hardware unit.
 * \param   hardware unit id
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appSysCloseHw(HARDWARE_UNITS unit);

/**
 * \brief   start a hardware unit
 * \param   hardware unit
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appSysStartHw(HARDWARE_UNITS unit);

/**
 * \brief   restart a hardware unit
 * \param   hardware unit
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appSysRestartHw(HARDWARE_UNITS unit);


#endif /* __APP_SYSTEM_SETUP_H__ */

/********************************* End Of File ********************************/
