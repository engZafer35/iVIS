/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 3, 2021 - 3:32:01 PM
* #File Name    : App_System_Setup.c
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
#define SHOW_PAGE_DBG_MSG  (DISABLE)
/********************************* INCLUDES ***********************************/
#include "App_System_Setup.h"
/****************************** MACRO DEFINITIONS *****************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/

RETURN_STATUS appSysInitAllHwUnit(void)
{
    RETURN_STATUS retVal = SUCCESS;






    DBG_MSG("All hardware initialization result %d", retVal);
    return retVal;
}

RETURN_STATUS appSysCloseHw(HARDWARE_UNITS unit)
{
    RETURN_STATUS retVal = SUCCESS;
    return retVal;
}

RETURN_STATUS appSysStartHw(HARDWARE_UNITS unit)
{
    RETURN_STATUS retVal = SUCCESS;
    return retVal;
}

RETURN_STATUS appSysRestartHw(HARDWARE_UNITS unit)
{
    RETURN_STATUS retVal = SUCCESS;
    return retVal;
}

/******************************** End Of File *********************************/
