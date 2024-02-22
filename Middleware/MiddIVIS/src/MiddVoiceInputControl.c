/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Feb 22, 2024 - 2:00:31 PM
* #File Name    : MiddVoiceInputControl.c
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
#define SHOW_PAGE_DBG_MSG  (DISABLE)
/********************************* INCLUDES ***********************************/
#include "MiddVoiceInputControl.h"
#include "MP45DT02.h"
/****************************** MACRO DEFINITIONS *****************************/
/* AudioFreq * DataSize (2 bytes) * NumChannels (Stereo: 2) */
#define DEFAULT_AUDIO_IN_FREQ                 I2S_AUDIOFREQ_16K
#define DEFAULT_AUDIO_IN_BIT_RESOLUTION       16
#define DEFAULT_AUDIO_IN_CHANNEL_NBR          1 /* Mono = 1, Stereo = 2 */
#define DEFAULT_AUDIO_IN_VOLUME               64

/* PDM buffer input size */
#define INTERNAL_BUFF_SIZE                    128*DEFAULT_AUDIO_IN_FREQ/16000*DEFAULT_AUDIO_IN_CHANNEL_NBR
/* PCM buffer output size */
#define PCM_OUT_SIZE                          DEFAULT_AUDIO_IN_FREQ/1000
#define CHANNEL_DEMUX_MASK                    0x55

#define HTONS(A)  ((((uint16_t)(A) & 0xff00) >> 8) | (((uint16_t)(A) & 0x00ff) << 8))
/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/
static VoidCallback hrcb;
static VoidCallback frcb;

static U16 InternalBuffer[INTERNAL_BUFF_SIZE];
static uint16_t RecBuf[PCM_OUT_SIZE*2];/* PCM stereo samples are saved in RecBuf */
static U16 *ibuff;

volatile U32 ITCounter = 0;

/***************************** STATIC FUNCTIONS  ******************************/
static void halfReceiveCb(void)
{

}

static void fullReceiveCb(void)
{

    middVoiceInRecordPDMToPCM((uint16_t*)&InternalBuffer[INTERNAL_BUFF_SIZE/2], (uint16_t*)&RecBuf[0]);

    memcpy((uint16_t*)&ibuff[ITCounter * (PCM_OUT_SIZE*2)], RecBuf, PCM_OUT_SIZE*4);

    if(ITCounter == (WR_BUFFER_SIZE/(PCM_OUT_SIZE*4))-1)
    {
      AUDIODataReady = 1;
      AUDIOBuffOffset = 0;
      ITCounter++;
    }
    else if(ITCounter == (WR_BUFFER_SIZE/(PCM_OUT_SIZE*2))-1)
    {
      AUDIODataReady = 1;
      AUDIOBuffOffset = WR_BUFFER_SIZE/2;
      ITCounter = 0;
    }
    else
    {
      ITCounter++;
    }

}
/***************************** PUBLIC FUNCTIONS  ******************************/
RETURN_STATUS middVoiceInInit(U32 freq, U32 BitRes, U32 ChnlNbr)
{
    RETURN_STATUS retVal = SUCCESS;

    // middMCUI2SInit() is already called in App_IVIS.c file.
//    PDMDecoder_Init(freq, ChnlNbr, 2);

    MP45DT02Init(freq,BitRes, halfReceiveCb, fullReceiveCb);

    return retVal;
}

RETURN_STATUS middVoiceInRecordStart(U16 *rbuff, U32 size, VoidCallback cbHalfRec, VoidCallback cbFullfRec)
{
    ibuff = ibuff;
    return MP45DT02Start(InternalBuffer, INTERNAL_BUFF_SIZE);
}

RETURN_STATUS middVoiceInRecordStop(void)
{
    return MP45DT02Stop();
}

RETURN_STATUS middVoiceInRecordPause(void)
{
    return MP45DT02Pause();
}

RETURN_STATUS middVoiceInRecordResume(void)
{
    return MP45DT02Resume();
}

void middVoiceInRecordPDMToPCM(U16 *PDMBuf, U16 *PCMBuf)
{
    uint16_t AppPDM[INTERNAL_BUFF_SIZE/2];
    uint32_t index = 0;

    /* PDM Demux */
    for(index = 0; index<INTERNAL_BUFF_SIZE/2; index++)
    {
        AppPDM[index] = HTONS(PDMBuf[index]);
    }

    for(index = 0; index < DEFAULT_AUDIO_IN_CHANNEL_NBR; index++)
    {
      /* PDM to PCM filter */
//      PDM_Filter((uint8_t*)&AppPDM[index], (uint16_t*)&(PCMBuf[index]), &PDM_FilterHandler[index]);
    }

    /* Duplicate samples since a single microphone in mounted on STM32F4-Discovery */
    for(index = 0; index < PCM_OUT_SIZE; index++)
    {
        PCMBuf[(index<<1)+1] = PCMBuf[index<<1];
    }
}

/******************************** End Of File *********************************/
