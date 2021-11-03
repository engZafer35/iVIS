/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 2, 2021 - 10:47:18 PM
* #File Name    : App_Job_Manager.c
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
#define SHOW_PAGE_DBG_MSG  (DISABLE)
/********************************* INCLUDES ***********************************/
#include "App_Job_Manager.h"
/****************************** MACRO DEFINITIONS *****************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/

/***************************** PUBLIC FUNCTIONS  ******************************/
RETURN_STATUS appJobStartJob(EN_JOB_LIST job)
{
    RETURN_STATUS retVal = FAILURE_RET;

    if (job < EN_JOB_MAX_NUMBER)
    {
        retVal = SUCCESS_RET;
    }

    return retVal;
}

RETURN_STATUS appJobStoptJob(EN_JOB_LIST job)
{
    RETURN_STATUS retVal = FAILURE_RET;

    if (job < EN_JOB_MAX_NUMBER)
    {
        retVal = SUCCESS_RET;
    }

    return retVal;
}

RETURN_STATUS appJobStopAll(void)
{
    return SUCCESS_RET;
}

RETURN_STATUS appJobDestroyJob(EN_JOB_LIST job)
{
    RETURN_STATUS retVal = FAILURE_RET;

    if (job < EN_JOB_MAX_NUMBER)
    {
        retVal = SUCCESS_RET;
    }

    return retVal;
}

BOOL appJobIsRunning(EN_JOB_LIST job)
{
    BOOL retVal = FALSE;

    if (job < EN_JOB_MAX_NUMBER)
    {
        retVal = TRUE;
    }

    return retVal;
}

/******************************** End Of File *********************************/
