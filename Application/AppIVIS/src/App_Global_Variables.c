/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 3, 2021 - 5:23:29 PM
* #File Name    : App_Global_Variables.c
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
#define SHOW_PAGE_DBG_MSG  (DISABLE)
/********************************* INCLUDES ***********************************/
#include "App_Global_Variables.h"
/****************************** MACRO DEFINITIONS *****************************/

/******************************* TYPE DEFINITIONS *****************************/
struct _GlobalVar
{
    union
    {
        U8 muteClient;
        struct
        {
            U8 client_1 :1;
            U8 client_2 :1;
            U8 client_3 :1;
            U8 client_4 :1;
            U8 client_5 :1;
            U8 client_6 :1;
            U8 client_7 :1;
            U8 client_8 :1;
        };
    }muteClientList;
}g_globalVar;
/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/
RETURN_STATUS appGVInit(void)
{
    RETURN_STATUS retVal = SUCCESS;

    return retVal;
}

U8 appGvGetMuteClient(void)
{
    U8 retVal;

    //todo: mutex lock
    retVal = g_globalVar.muteClientList.muteClient; // return all data
    //todo: mutex unlock

    return retVal;
}

void appGvSetMuteClient(U8 client)
{
    //todo: mutex lock
    SET_BIT(g_globalVar.muteClientList.muteClient, client);
    //todo: mutex unlock
}

void appGvSetUnmteClient(U8 client)
{
    //todo: mutex lock
    CLEAR_BIT(g_globalVar.muteClientList.muteClient, client);
    //todo: mutex unlock
}




/******************************** End Of File *********************************/
