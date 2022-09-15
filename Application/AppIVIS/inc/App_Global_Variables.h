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
typedef enum _GLOBAL_EVENT_LIST
{
    EN_EVENT_VOICES_RECEIVED            = 0X01,
    EN_EVENT_INTEGTATED_VOICE_SEND      = 0X02,
    EN_EVENT_INTEGTATED_VOICE_RECORD    = 0X04,

}GLOBAL_EVENT_LIST;
/************************* GLOBAL VARIBALE REFERENCES *************************/
extern struct _GlobalVar GlobalVar;

extern EventGroupHandle_t g_voiceEventID;
#define GLOBAL_VOICE_EVENT_LIST_ID    (g_voiceEventID)
/************************* GLOBAL FUNCTION DEFINITIONS ************************/

/**
 * \brief   initialize global variables
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appGVInit(void);

/**
 * \brief   get muted client list. Each bit corresponds a client,
 *          1 bit client muted, 0 bit client unmuted
 * \return  Client muted/unmuted value
 */
U8 appGvGetMuteClient(void);

/**
 * \brief   set a client muted
 * \param   client number, (0-8)
 */
void appGvSetMuteClient(U8 client);

/**
 * \brief   set a client unmuted
 * \param   client number, (0-8)
 */
void appGvSetUnmteClient(U8 client);

#endif /* __APP_GLOBAL_VARIABLES_H__ */

/********************************* End Of File ********************************/
