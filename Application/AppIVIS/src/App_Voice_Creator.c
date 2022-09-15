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
#define CLIENT_VOICE_BUFF(indx, cli)            (g_rcvVoiceBuff.rcvClientVoice[indx].clientVoice[cli].voice.voice)
#define IS_NEW_CLIENT_VOICE_DATA(indx, cli)     (g_rcvVoiceBuff.rcvClientVoice[indx].clientVoice[cli].isNew)

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/
VoidCallback cbList[MAX_INFORM_UNIT_NUMBER];

extern struct VoiceCircularBuff g_rcvVoiceBuff;

U8 voice[UDP_VOICE_PACKET_SIZE];
const U8 emptyBuff[UDP_VOICE_PACKET_SIZE];

U32 g_currIndex;

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
        xEventGroupWaitBits(GLOBAL_VOICE_EVENT_LIST_ID, EN_EVENT_VOICES_RECEIVED, pdTRUE, pdTRUE, portMAX_DELAY);

//        if (event & EN_EVENT_VOICES_RECEIVED)
        {
            /**
             * check if first client(index=0) has new voice data,
             * We can use fast memcpy instead of for loop for first client
             */
//            if (IS_NEW_CLIENT_VOICE_DATA(g_currIndex, 0))
//            {
//                FAST_MEMCPY(voice, CLIENT_VOICE_BUFF(g_currIndex, 0), sizeof(voice));
//            }
//            else
//            {
//                FAST_MEMCPY(voice, emptyBuff, sizeof(voice));
//            }

            for (cli = 1; cli < MAX_CLIENT_NUMBER; ++cli)
            {
                if (IS_NEW_CLIENT_VOICE_DATA(g_currIndex, cli)) //check is there new voice data
                {
                    for (z = 0; z < UDP_VOICE_PACKET_SIZE; ++z)
                    {
                        voice[z] += CLIENT_VOICE_BUFF(g_currIndex, cli)[z];
                    }
                }
            }
            xEventGroupSetBits(GLOBAL_VOICE_EVENT_LIST_ID, EN_EVENT_INTEGTATED_VOICE_SEND);
            xEventGroupSetBits(GLOBAL_VOICE_EVENT_LIST_ID, EN_EVENT_INTEGTATED_VOICE_RECORD);

            middIOToggle(EN_OUT_JOB_LED);
        }
    }
}

/***************************** PUBLIC FUNCTIONS  ******************************/
RETURN_STATUS appVoCreatInit(void)
{

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
