/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 3, 2021 - 11:33:03 PM
* #File Name    : App_Voice_Receiver.h
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __APP_VOICE_RECEIVER_H__
#define __APP_VOICE_RECEIVER_H__
/*********************************INCLUDES*************************************/
#include "Project_Conf.h"

#include "core/net.h"
/******************************MACRO DEFINITIONS*******************************/
#define MAX_CLIENT_NUMBER   (8)

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/**
 * \brief   init voice receiver
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appVoiceRecInit(void);

/**
 * \brief   suspend a client. After this function invoked
 *          client voice is not received by master.
 *          Also Client can not receive voice.
 * \param   Client number
 * \param   TRUE for suspend, FALSE for resume
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appVoiceRecSuspendClient(U32 clinetNum, BOOL stat);

/**
 * \brief   Mute a client. After this function invoked
 *          client voice is not received by master.
 *          Client can hear speech
 * \param   Client number
 * \param   TRUE for Mute, FALSE for UNMUTE
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appVoiceRecMuteClient(U32 clinetNum, BOOL stat);

/**
 * \brief   Mute all client. After this function invoked
 *          client voice is not received by master.
 *          Client can hear speech
 * \param   Client number
 * \param   TRUE for Mute, FALSE for UNMUTE
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appVoiceRecMuteAllClient(U32 clinetNum, BOOL stat);

/**
 * \brief   get voice receiver task function. this function
 * \return  task function pointer
 */
TaskFunc_t appVoiceRecGetTaskFunc(void);

#endif /* __APP_VOICE_RECEIVER_H__ */

/********************************* End Of File ********************************/
