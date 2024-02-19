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
/****************************** MACRO DEFINITIONS *****************************/
/********** Voice Packet Parameters ************/
#define CLIENT_VOICE_BUFF_HEAD(clientNum)           (g_voiceBuff.rcvClientVoice[g_voiceBuff.head].clientsVoice[clientNum].voice)
#define IS_NEW_CLIENT_VOICE_DATA_HEAD(clientNum)    (g_voiceBuff.rcvClientVoice[g_voiceBuff.head].clientsVoice[clientNum].isNew)

#define CLIENT_VOICE_BUFF_TAIL(clientNum)           (g_voiceBuff.rcvClientVoice[g_voiceBuff.tail].clientsVoice[clientNum].voice)
#define IS_NEW_CLIENT_VOICE_DATA_TAIL(clientNum)    (g_voiceBuff.rcvClientVoice[g_voiceBuff.tail].clientsVoice[clientNum].isNew)

/********** Fast Copy Method ************/
#ifdef WORKING_PLATFORM_STM
#define FAST_MEMCPY(src, dst, leng) HAL_DMA_Start(&hdma_memtomem_dma2_stream0, (uint32_t)src, (uint32_t)dst , leng), \
                                    HAL_DMA_PollForTransfer(&hdma_memtomem_dma2_stream0, HAL_DMA_FULL_TRANSFER, HAL_MAX_DELAY)
#else
#define FAST_MEMCPY(src, dst, leng) memcpy(dst, src, leng)
#endif
/******************************* TYPE DEFINITIONS *****************************/
typedef struct VoiceBuff
{
    U8 voice[UDP_VOICE_PACKET_SIZE];
    U8 isNew;
}VoiceBuff_t;

typedef struct ClientsVoiceBuff
{
    VoiceBuff_t clientsVoice[MAX_CLIENT_NUMBER];
}ClientsVoiceBuff_t;

typedef struct VoiceCircularBuff
{
    ClientsVoiceBuff_t rcvClientVoice[CIRCULAR_BUFF_LENG];

    U8 head;
    U8 tail;
}VoiceCircularBuff_t;
/********************************** VARIABLES *********************************/
VoiceCircularBuff_t g_voiceBuff;

#define MAX_INFORM_UNIT_NUMBER (5)
VoidCallback cbList[MAX_INFORM_UNIT_NUMBER];

static U8 mergedVoice[UDP_VOICE_PACKET_SIZE];
static U8 emptyZeroBuff[UDP_VOICE_PACKET_SIZE]; //it is used to clear merged voice data by using FASTCOPY-dma
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

    while(1)
    {
        xEventGroupWaitBits(GLOBAL_VOICE_EVENT_LIST_ID, EN_EVENT_VOICES_RECEIVED, pdTRUE, pdTRUE, portMAX_DELAY);

        while (g_voiceBuff.tail != g_voiceBuff.head)
        {
//            xSemaphoreTake( mutex, portMAX_DELAY);
            for (cli = 0; cli < MAX_CLIENT_NUMBER; ++cli)
            {
                if (IS_NEW_CLIENT_VOICE_DATA_TAIL(cli)) //check is there new voice data
                {
                    for (z = 0; z < UDP_VOICE_PACKET_SIZE; ++z)
                    {
                        mergedVoice[z] += CLIENT_VOICE_BUFF_TAIL(cli)[z];
                    }

                    IS_NEW_CLIENT_VOICE_DATA_TAIL(cli) = FALSE; //clear used voice data
                }
            }

//            printf("%d\n\r", mergedVoice[1]);

            FAST_MEMCPY(emptyZeroBuff, mergedVoice, UDP_VOICE_PACKET_SIZE); //clear mergedVoice buff, it will be used again

            g_voiceBuff.tail++;
            if (g_voiceBuff.tail >= CIRCULAR_BUFF_LENG)
            {
                g_voiceBuff.tail = 0; //set beginning of buffer
            }

//            xSemaphoreGive( mutex );
        }

////            xEventGroupSetBits(GLOBAL_VOICE_EVENT_LIST_ID, EN_EVENT_INTEGTATED_VOICE_SEND);
////            xEventGroupSetBits(GLOBAL_VOICE_EVENT_LIST_ID, EN_EVENT_INTEGTATED_VOICE_RECORD);
        middIOToggle(EN_OUT_ERR_LED);
    }

}

/***************************** PUBLIC FUNCTIONS  ******************************/
RETURN_STATUS appVoCreatInit(void)
{

    return SUCCESS;
}
void appVoCreatAddVoice(U8 *voice, U32 clientNum)
{
    FAST_MEMCPY(voice, CLIENT_VOICE_BUFF_HEAD(clientNum), UDP_VOICE_PACKET_SIZE); //use fast memcpy method, DMA mem to mem
    IS_NEW_CLIENT_VOICE_DATA_HEAD(clientNum) = TRUE;
}

void appVoCreatAllClientVoiceReceived(void)
{
    g_voiceBuff.head++;
    if (g_voiceBuff.head >= CIRCULAR_BUFF_LENG)
    {
        g_voiceBuff.head = 0; //set beginning of buffer
    }

    xEventGroupSetBits(GLOBAL_VOICE_EVENT_LIST_ID, EN_EVENT_VOICES_RECEIVED);
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
