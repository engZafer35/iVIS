/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 3, 2021 - 4:03:04 PM
* #File Name    : App_IVIS.h
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __APP_IVIS_H__
#define __APP_IVIS_H___
/*********************************INCLUDES*************************************/
#include "Project_Conf.h"
/******************************MACRO DEFINITIONS*******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/**
 * \brief   init IVIS application
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appIvisInit(void);

/**
 * \brief   start IVIS application
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appIvisStart(void);

#endif /* __APP_IVIS_H__ */

/********************************* End Of File ********************************/
