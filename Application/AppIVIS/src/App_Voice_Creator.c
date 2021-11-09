/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 8, 2021 - 10:49:03 PM
* #File Name    : App_Voice_Creator.c
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
#define SHOW_PAGE_DBG_MSG  (DISABLE)
/********************************* INCLUDES ***********************************/
#include "App_Voice_Creator.h"
/****************************** MACRO DEFINITIONS *****************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/
VoidCallback cbList[MAX_INFORM_UNIT_NUMBER];

/***************************** STATIC FUNCTIONS  ******************************/

/**< after end of sum of speeches, call calback functions */
void callCbFunc(void)
{
    U32 z;

    for (z = 0; z < MAX_INFORM_UNIT_NUMBER; ++z)
    {
        if (NULL == cbList[z])
        {
            cbList[z]();
        }
    }
}

/***************************** PUBLIC FUNCTIONS  ******************************/
RETURN_STATUS appVoCreatInit(void)
{
    return SUCCESS;
}

void appVoCreatStart(void)
{

}

void appVoCreatAddedVoice(U32 clientum)
{

}

RETURN_STATUS appVoCreatRegisterVoiceReadyCb(VoidCallback cb)
{
    RETURN_STATUS retVal = FAILURE;
    U32 z;

    for (z = 0; z < MAX_INFORM_UNIT_NUMBER; ++z)
    {
        if (NULL == cbList[z])
        {
            cbList[z] = cb;
            retVal = SUCCESS;
        }
    }

    return retVal;
}

void appVoCreatUnregisterVoiceReadyCb(VoidCallback cb)
{
    U32 z;

    for (z = 0; z < MAX_INFORM_UNIT_NUMBER; ++z)
    {
        if (cbList[z] == cb)
        {
            cbList[z] = NULL;
        }
    }
}

/******************************** End Of File *********************************/
