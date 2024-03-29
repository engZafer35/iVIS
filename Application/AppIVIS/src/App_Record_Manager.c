/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 12, 2021 - 12:15:51 AM
* #File Name    : App_Record_Manager.c
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
#define SHOW_PAGE_DBG_MSG  (DISABLE)
/********************************* INCLUDES ***********************************/
#include "App_Record_Manager.h"
#include "App_Global_Variables.h"

#include "MiddDigitalIOControl.h"
/****************************** MACRO DEFINITIONS *****************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/
char USBDISKPath[4];         /* USB Host logical drive path */

/***************************** STATIC FUNCTIONS  ******************************/
static void recTaskFunc(void const* argument)
{
    EventBits_t event;

    while(1)
    {
        event = xEventGroupWaitBits(GLOBAL_VOICE_EVENT_LIST_ID, EN_EVENT_INTEGTATED_VOICE_RECORD, pdTRUE, pdTRUE, portMAX_DELAY);

        if (event & EN_EVENT_INTEGTATED_VOICE_RECORD) //check if is correct event
        {
            //todo: record new voice data
        }
        middIOToggle(EN_OUT_POWER_LED);
    }
}
/***************************** PUBLIC FUNCTIONS  ******************************/
RETURN_STATUS appRecInit(void)
{
//    MX_FATFS_Init();
//    MX_USB_HOST_Init();

    //todo: mount file system.

    return SUCCESS;
}

TaskFunc_t appRecGetTaskFunc(void)
{
    return recTaskFunc;
}
/******************************** End Of File *********************************/
