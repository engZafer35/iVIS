/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 12, 2021 - 12:14:46 AM
* #File Name    : App_Record_Manager.h
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef INC_APP_RECORD_MANAGER_H_
#define INC_APP_RECORD_MANAGER_H_
/*********************************INCLUDES*************************************/
#include "Project_Conf.h"
/******************************MACRO DEFINITIONS*******************************/

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/
/**
 * \brief   init voice recorder
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appRecInit(void);

/**
 * \brief   get record manager task function.
 * \return  task function pointer
 */
TaskFunc_t appRecGetTaskFunc(void);

#endif /* INC_APP_RECORD_MANAGER_H_ */

/********************************* End Of File ********************************/
