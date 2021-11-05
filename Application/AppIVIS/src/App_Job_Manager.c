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
#include "App_Voice_Receiver.h"

#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

#include "MiddDigitalIOControl.h"
/****************************** MACRO DEFINITIONS *****************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

struct JobTask
{
    TaskFunc_t taskFunc;
    osThreadId taskId;
    U8 taskStat; // JOB_STATUS
};

static struct JobTask g_jobList[EN_JOB_MAX_NUMBER];

/***************************** STATIC FUNCTIONS  ******************************/
static void jobTaskFunc(void const* argument)
{
    g_jobList[EN_JOB_MANAGER].taskStat = EN_RUNNING;

    while(1)
    {
        osDelay(200);
        middIOToggle(EN_OUT_JOB_LED);
    }
}
/***************************** PUBLIC FUNCTIONS  ******************************/
RETURN_STATUS appJobInit(void)
{
    RETURN_STATUS retVal = SUCCESS;

    g_jobList[EN_JOB_VOICE_RECEIVER].taskFunc = appVoiceRecGetTaskFunc();
    /*g_jobList[EN_JOB_VOICE_RECEIVER].jobStat = EN_NOT_CREATED;*/      /* < not needed, still zero */
    /*g_jobList[EN_JOB_VOICE_RECEIVER].taskStat = 0; */                 /* < not needed, still zero */


    //TODO: Create queue

    g_jobList[EN_JOB_MANAGER].taskFunc = jobTaskFunc;
    osThreadDef(JOB_MANAGER, g_jobList[EN_JOB_MANAGER].taskFunc, osPriorityNormal, 0, 128);
    g_jobList[EN_JOB_MANAGER].taskId = osThreadCreate(osThread(JOB_MANAGER), NULL);


//    EN_JOB_SYS_EVENT_HANDLER,
//    EN_JOB_EVENT_MANAGER,
//    EN_JOB_UI_MAGER,
//    EN_JOB_PLAYER,
//    EN_JOB_VOICE_RECEIVER,
//    EN_JOB_VOICE_CREATOR,
//    EN_JOB_MIC_SPEAKER,
//    EN_JOB_RECORD_MANAGER,
//    EN_JOB_UPDATE_MANAGER,

    return retVal;
}

RETURN_STATUS appJobCreatJob(EN_JOB_LIST job)
{
    RETURN_STATUS retVal = SUCCESS;

    if (EN_JOB_MAX_NUMBER <= job)
    {
        return FAILURE;
    }

    if (NULL != g_jobList[job].taskId)
    {
        return SUCCESS; /*< task has been already created */
    }

    switch(job)
    {
        case EN_JOB_MANAGER:
        {
            /* job manger task has been created in appJobInit(). */
            break;
        }

        case EN_JOB_SYS_EVENT_HANDLER:
        {
            osThreadDef(JOB_SYS_EVENT_HANDLER, g_jobList[EN_JOB_SYS_EVENT_HANDLER].taskFunc, osPriorityNormal, 0, 128);
            g_jobList[EN_JOB_SYS_EVENT_HANDLER].taskId = osThreadCreate(osThread(JOB_SYS_EVENT_HANDLER), NULL);
            break;
        }

        case EN_JOB_EVENT_MANAGER:
        {
            osThreadDef(JOB_EVENT_MANAGER, g_jobList[EN_JOB_EVENT_MANAGER].taskFunc, osPriorityNormal, 0, 128);
            g_jobList[EN_JOB_EVENT_MANAGER].taskId = osThreadCreate(osThread(JOB_EVENT_MANAGER), NULL);
            break;
        }

        case EN_JOB_UI_MAGER:
        {
            osThreadDef(JOB_UI_MAGER, g_jobList[EN_JOB_UI_MAGER].taskFunc, osPriorityNormal, 0, 128);
            g_jobList[EN_JOB_UI_MAGER].taskId = osThreadCreate(osThread(JOB_UI_MAGER), NULL);
            break;
        }

        case EN_JOB_PLAYER:
        {
            osThreadDef(JOB_PLAYER, g_jobList[EN_JOB_PLAYER].taskFunc, osPriorityNormal, 0, 128);
            g_jobList[EN_JOB_PLAYER].taskId = osThreadCreate(osThread(JOB_PLAYER), NULL);
            break;
        }

        case EN_JOB_VOICE_RECEIVER:
        {
            osThreadDef(JOB_VOICE_RECEIVER, g_jobList[EN_JOB_VOICE_RECEIVER].taskFunc, osPriorityNormal, 0, 512);
            g_jobList[EN_JOB_VOICE_RECEIVER].taskId = osThreadCreate(osThread(JOB_VOICE_RECEIVER), NULL);
            break;
        }

        case EN_JOB_VOICE_CREATOR:
        {
            osThreadDef(JOB_VOICE_CREATOR, g_jobList[EN_JOB_VOICE_CREATOR].taskFunc, osPriorityNormal, 0, 128);
            g_jobList[EN_JOB_VOICE_CREATOR].taskId = osThreadCreate(osThread(JOB_VOICE_CREATOR), NULL);
            break;
        }
        case EN_JOB_MIC_SPEAKER:
        {
            osThreadDef(JOB_MIC_SPEAKER, g_jobList[EN_JOB_MIC_SPEAKER].taskFunc, osPriorityNormal, 0, 128);
            g_jobList[EN_JOB_MIC_SPEAKER].taskId = osThreadCreate(osThread(JOB_MIC_SPEAKER), NULL);
            break;
        }

        case EN_JOB_RECORD_MANAGER:
        {
            osThreadDef(JOB_RECORD_MANAGER, g_jobList[EN_JOB_RECORD_MANAGER].taskFunc, osPriorityNormal, 0, 128);
            g_jobList[EN_JOB_RECORD_MANAGER].taskId = osThreadCreate(osThread(JOB_RECORD_MANAGER), NULL);
            break;
        }

        case EN_JOB_UPDATE_MANAGER:
        {
            osThreadDef(JOB_UPDATE_MANAGER, g_jobList[EN_JOB_UPDATE_MANAGER].taskFunc, osPriorityNormal, 0, 128);
            g_jobList[EN_JOB_UPDATE_MANAGER].taskId = osThreadCreate(osThread(JOB_UPDATE_MANAGER), NULL);
            break;
        }
        default:break;
    }

    g_jobList[job].taskStat = EN_RUNNING; /*< task created. when RTOS start, all task will start to run.*/

    return retVal;
}

RETURN_STATUS appJobStartJob(EN_JOB_LIST job)
{
    RETURN_STATUS retVal = FAILURE;

    if (job < EN_JOB_MAX_NUMBER)
    {
        if (EN_RUNNING == g_jobList[job].taskStat)
        {
            return SUCCESS;
        }
        else if (EN_STOPED != g_jobList[job].taskStat)
        {
            return FAILURE; /*< job killed, before start, it must be created */
        }

        osThreadResume(g_jobList[job].taskId);
        g_jobList[job].taskStat = EN_RUNNING;
        retVal = SUCCESS;
    }

    return retVal;
}

RETURN_STATUS appJobStoptJob(EN_JOB_LIST job)
{
    RETURN_STATUS retVal = FAILURE;

    if (job < EN_JOB_MAX_NUMBER)
    {
        if (EN_STOPED == g_jobList[job].taskStat)
        {
            return SUCCESS;
        }
        else if (EN_RUNNING != g_jobList[job].taskStat)
        {
            return FAILURE; /*< job killed, it can not be stopped */
        }

        osThreadSuspend(g_jobList[job].taskId);
        g_jobList[job].taskStat = EN_STOPED;
        retVal = SUCCESS;
    }

    return retVal;
}

RETURN_STATUS appJobStopAll(void)
{
    EN_JOB_LIST i;

    for (i = EN_JOB_SYS_EVENT_HANDLER; i < EN_JOB_MAX_NUMBER; ++i)
    {
        osThreadSuspend(g_jobList[i].taskId);
        g_jobList[i].taskStat = EN_STOPED;
    }

    return SUCCESS;
}

RETURN_STATUS appJobKillJob(EN_JOB_LIST job)
{
    RETURN_STATUS retVal = FAILURE;

    if (job < EN_JOB_MAX_NUMBER)
    {
        if (EN_KILLED == g_jobList[job].taskStat)
        {
            return SUCCESS;
        }
        else if (EN_NOT_CREATED == g_jobList[job].taskStat)
        {
            return FAILURE; /*< job not created, firstly it should be created*/
        }

        osThreadTerminate(g_jobList[job].taskId);
        g_jobList[job].taskStat = EN_KILLED;
        retVal = SUCCESS;
    }

    return retVal;
}

JOB_STATUS appJobGetJobStatus(EN_JOB_LIST job)
{
    JOB_STATUS retVal = -1;

    if (job < EN_JOB_MAX_NUMBER)
    {
        retVal = g_jobList[job].taskStat;
    }

    return retVal;
}

/******************************** End Of File *********************************/
