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
#include "App_Voice_Receiver.h"
#include "App_Global_Variables.h"

#include "MiddDigitalIOControl.h"
#include "Midd_Memory_Opr.h"
/****************************** MACRO DEFINITIONS *****************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/
VoidCallback cbList[MAX_INFORM_UNIT_NUMBER];


extern struct VoiceCircularBuff g_rcvVoiceBuff;

U8 voice[UDP_VOICE_PACKET_SIZE];
const U8 emptyBuff[UDP_VOICE_PACKET_SIZE];

U32 g_currIndex;

struct QueueStr
{
    void *buff;
};

static osMessageQId vcQueID;
/***************************** STATIC FUNCTIONS  ******************************/

/**< after end of sum of speeches, call callback functions */
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

static void vcTaskFunc(void const* argument)
{
    int z;
    int cli;
//    EventBits_t event;

    while(1)
    {
        xEventGroupWaitBits(GLOBAL_EVENT_LIST_ID, EN_EVENT_VOICES_RECEIVED, pdTRUE, pdTRUE, portMAX_DELAY);

//        if (event & EN_EVENT_VOICES_RECEIVED)
        {
//            if (g_rcvVoiceBuff.rcvClientVoice[g_currIndex].clientVoice[0].isNew)
//            {
//                FAST_MEMCPY(voice, g_rcvVoiceBuff.rcvClientVoice[g_currIndex].clientVoice[0].voice.voice, sizeof(voice));
//            }
//            else
//            {
//                FAST_MEMCPY(voice, emptyBuff, sizeof(voice));
//            }

            for (cli = 1; cli < MAX_CLIENT_NUMBER; ++cli)
            {
                if (g_rcvVoiceBuff.rcvClientVoice[g_currIndex].clientVoice[cli].isNew) //check is there new voice data
                {
                    for (z = 0; z < UDP_VOICE_PACKET_SIZE; ++z)
                    {
                        voice[z] += g_rcvVoiceBuff.rcvClientVoice[g_currIndex].clientVoice[cli].voice.voice[z];
                    }
                }
            }
            xEventGroupSetBits(GLOBAL_EVENT_LIST_ID, EN_EVENT_INTEGTATED_VOICE_READY);
            middIOToggle(EN_OUT_JOB_LED);
        }
    }
}

/***************************** PUBLIC FUNCTIONS  ******************************/
RETURN_STATUS appVoCreatInit(void)
{
    osMessageQDef(vcQueue, 4, struct QueueStr);
    vcQueID = osMessageCreate(osMessageQ(vcQueue), NULL);

    return SUCCESS;
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

TaskFunc_t appVoCreatGetTaskFunc(void)
{
    return vcTaskFunc;
}
/******************************** End Of File *********************************/
