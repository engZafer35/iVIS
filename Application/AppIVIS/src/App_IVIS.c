/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 3, 2021 - 4:06:26 PM
* #File Name    : App_IVIS.c
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
#define SHOW_PAGE_DBG_MSG  (DISABLE)
/********************************* INCLUDES ***********************************/
#include "App_IVIS.h"
#include "App_Job_Manager.h"
#include "App_Voice_Receiver.h"
#include "App_Voice_Creator.h"
#include "App_Global_Variables.h"
#include "App_Record_Manager.h"

#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

#include "MiddMCUCore.h"
#include "MiddDigitalIOControl.h"
#include "MiddCanComm.h"
/****************************** MACRO DEFINITIONS *****************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/
#if (OS_SUPPORT_STATIC_ALLOCATION == ENABLE)
/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* GetTimerTaskMemory prototype (linked to static allocation support) */
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}

static StaticTask_t xTimerTaskTCBBuffer;
static StackType_t xTimerStack[configTIMER_TASK_STACK_DEPTH];

void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize )
{
  *ppxTimerTaskTCBBuffer = &xTimerTaskTCBBuffer;
  *ppxTimerTaskStackBuffer = &xTimerStack[0];
  *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
  /* place for user code */
}
#endif

static RETURN_STATUS initMcuCore(void)
{
    RETURN_STATUS retVal = SUCCESS;

    retVal |= middMCUClockInit(); //firstly init clock and system
    retVal |= middMCUGpioInit();
    retVal |= middMCUDmaInit();
    retVal |= middMCUI2CInit();
    retVal |= middMCUI2SInit();
    retVal |= middMCUSPIInit();

    retVal |= middMCUUartInit();

//    retVal |= middMCUCanInit();
//    retVal |= middMCUTimers();

    DBG_MSG(" ->[I] initMcuCore return: %d", retVal);

    return retVal;
}

static RETURN_STATUS initSwUnits(void)
{
    RETURN_STATUS retVal = SUCCESS;

    /** !< Firstly init midd layer */
//    retVal |= middSysTimerInit();   //init system timer
//    retVal |= middEventTimerInit(); //init periodic event timer
    retVal |= middIOInit();
    retVal |= MiddCanCommInit();

    /** don't need to check to set system failure */
//    middSerialCommInit();

    if (SUCCESS == retVal)
    {
        retVal |= appGVInit();
        retVal |= appVoiceRecInit();
//        retVal |= appVoCreatInit();
//        retVal |= appRecInit();

        retVal |= appJobInit();
    }

    DBG_MSG(" ->[I] initSWRequirement return value: %d ", retVal);
    return retVal;
}

static RETURN_STATUS initDeviceDrivers(void)
{
    return SUCCESS;
}
/***************************** PUBLIC FUNCTIONS  ******************************/
RETURN_STATUS appIvisInit(void)
{
    RETURN_STATUS retVal = FAILURE;

    if (SUCCESS == initMcuCore())
    {
        //use fprintf to show system info for every time.
        DBG_MSG("\n\r##--- > Board File: %s - Board Name: %s - Board Version: %s Board MCU: %s-%s \n\r", BOARD_FILE_NAME, BOARD_NAME, BOARD_VERSION, MCU_PART_NUM, MCU_CORE);
        DBG_MSG("##--- > SW Version %d.%d.%d \n\r", SW_VERSION_MAJOR, SW_VERSION_MINOR, SW_VERSION_BUGFX);

        if (SUCCESS == initDeviceDrivers())
        {
            retVal = initSwUnits();
        }

        middIOWrite(EN_OUT_POWER_LED, ENABLE);
    }

    return retVal;
}

RETURN_STATUS appIvisStart(void)
{
    RETURN_STATUS retVal = SUCCESS;

    retVal |= appJobCreatJob(EN_JOB_VOICE_RECEIVER);
//    retVal |= appJobCreatJob(EN_JOB_VOICE_CREATOR);
//    retVal |= appJobCreatJob(EN_JOB_RECORD_MANAGER);

    //TODO: create other jobs

    osKernelStart();

    while (1)
        ;

    return retVal;
}

/******************************** End Of File *********************************/
