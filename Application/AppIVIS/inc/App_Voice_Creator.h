/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 8, 2021 - 10:30:38 PM
* #File Name    : App_Voice_Creator.h
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __VOICE_CREATOR_H__
#define __VOICE_CREATOR_H__
/*********************************INCLUDES*************************************/
#include "Project_Conf.h"
/******************************MACRO DEFINITIONS*******************************/
#define MAX_INFORM_UNIT_NUMBER  (5)
/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/
/**
 * \brief   init voice creator
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appVoCreatInit(void);

/**
 * \brief   when all client voice data is ready, this function
 *          can be invoked to create a voice that contains sum of all speech
 * \param   ready buffer index
 */
void appVoCreatStart(U32 buffIndex);

/**
 * \brief   When a client voice added buffer, this function
 *          can be invoked to sum with other already summed voice data.
 *          So, not need to wait for all client data to be ready.
 */
void appVoCreatAddedVoice(U32 clientNum);

/**
 * \brief   If needed to inform a unit when created voice ready
 *          Register by this function
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appVoCreatRegisterVoiceReadyCb(VoidCallback cb);

/**
 * \brief   Unregister from callback list
 */
void appVoCreatUnregisterVoiceReadyCb(VoidCallback cb);

/**
 * \brief   get voice creator task function.
 * \return  task function pointer
 */
TaskFunc_t appVoCreatGetTaskFunc(void);

#endif /* __VOICE_CREATOR_H__ */

/********************************* End Of File ********************************/
