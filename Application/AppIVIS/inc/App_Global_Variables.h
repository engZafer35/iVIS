/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 3, 2021 - 5:21:25 PM
* #File Name    : App_Global_Variables.h
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __APP_GLOBAL_VARIABLES_H__
#define __APP_GLOBAL_VARIABLES_H__
/*********************************INCLUDES*************************************/
#include "Project_Conf.h"
/******************************MACRO DEFINITIONS*******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/**
 * \brief   initialize global variables
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appGVInit(void);

#endif /* __APP_GLOBAL_VARIABLES_H__ */

/********************************* End Of File ********************************/
