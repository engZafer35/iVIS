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

#include "pdm2pcm_glo.h"
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


#define WR_BUFFER_SIZE           4096

#define HTONS(A)  ((((uint16_t)(A) & 0xff00) >> 8) | (((uint16_t)(A) & 0x00ff) << 8))
/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/
static VoidCallback hrcb;
static VoidCallback frcb;

static U16 InternalBuffer[INTERNAL_BUFF_SIZE];
static uint16_t RecBuf[PCM_OUT_SIZE*2];/* PCM stereo samples are saved in RecBuf */
static U16 *ibuff;
uint16_t WrBuffer[WR_BUFFER_SIZE];

volatile U32 ITCounter = 0;

volatile uint32_t AUDIODataReady = 0, AUDIOBuffOffset = 0;
PDM_Filter_Handler_t  PDM_FilterHandler[2];
PDM_Filter_Config_t   PDM_FilterConfig[2];
/***************************** STATIC FUNCTIONS  ******************************/
/**
  * @brief  Initializes the PDM library.
  * @param  AudioFreq: Audio sampling frequency
  * @param  ChnlNbrIn: Number of input audio channels in the PDM buffer
  * @param  ChnlNbrOut: Number of desired output audio channels in the  resulting PCM buffer
  *         Number of audio channels (1: mono; 2: stereo)
  */
static void PDMDecoder_Init(uint32_t AudioFreq, uint32_t ChnlNbrIn, uint32_t ChnlNbrOut)
{
  uint32_t index = 0;

  /* Enable CRC peripheral to unlock the PDM library */
  __HAL_RCC_CRC_CLK_ENABLE();

  for(index = 0; index < ChnlNbrIn; index++)
  {
    /* Init PDM filters */
    PDM_FilterHandler[index].bit_order  = PDM_FILTER_BIT_ORDER_LSB;
    PDM_FilterHandler[index].endianness = PDM_FILTER_ENDIANNESS_LE;
    PDM_FilterHandler[index].high_pass_tap = 2122358088;
    PDM_FilterHandler[index].out_ptr_channels = ChnlNbrOut;
    PDM_FilterHandler[index].in_ptr_channels  = ChnlNbrIn;
    PDM_Filter_Init((PDM_Filter_Handler_t *)(&PDM_FilterHandler[index]));

    /* PDM lib config phase */
    PDM_FilterConfig[index].output_samples_number = AudioFreq/1000;
    PDM_FilterConfig[index].mic_gain = 24;
    PDM_FilterConfig[index].decimation_factor = PDM_FILTER_DEC_FACTOR_64;
    PDM_Filter_setConfig((PDM_Filter_Handler_t *)&PDM_FilterHandler[index], &PDM_FilterConfig[index]);
  }
}


void foo (int offset)
{
    static uint16_t audioOutBuffer[2048] = {0};
    static int flag = 0;

    if (0 == flag && (AUDIODataReady))
    {
        memcpy(audioOutBuffer, (WrBuffer+offset), 2048*2);
    }

    HAL_I2S_Transmit_DMA(&hi2s3,(uint16_t*)audioOutBuffer, 2048);

}

static void halfReceiveCb(void)
{
    /* PDM to PCM data convert */
    middVoiceInRecordPDMToPCM((uint16_t*)&InternalBuffer[0], (uint16_t*)&RecBuf[0]);

    /* Copy PCM data in internal buffer */
    memcpy((uint16_t*)&WrBuffer[ITCounter * (PCM_OUT_SIZE*2)], RecBuf, PCM_OUT_SIZE*4);
    if(ITCounter == (WR_BUFFER_SIZE/(PCM_OUT_SIZE*4))-1)
    {
      AUDIODataReady = 1;
      AUDIOBuffOffset = 0;
      foo(AUDIOBuffOffset);
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

static void fullReceiveCb(void)
{

    middVoiceInRecordPDMToPCM((uint16_t*)&InternalBuffer[INTERNAL_BUFF_SIZE/2], (uint16_t*)&RecBuf[0]);

    memcpy((uint16_t*)&WrBuffer[ITCounter * (PCM_OUT_SIZE*2)], RecBuf, PCM_OUT_SIZE*4);

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
    PDMDecoder_Init(freq, ChnlNbr, 2);

    MP45DT02Init(freq,BitRes, halfReceiveCb, fullReceiveCb);


    MP45DT02Start(InternalBuffer, INTERNAL_BUFF_SIZE);

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
      PDM_Filter((uint8_t*)&AppPDM[index], (uint16_t*)&(PCMBuf[index]), &PDM_FilterHandler[index]);
    }

    /* Duplicate samples since a single microphone in mounted on STM32F4-Discovery */
    for(index = 0; index < PCM_OUT_SIZE; index++)
    {
        PCMBuf[(index<<1)+1] = PCMBuf[index<<1];
    }
}

/******************************** End Of File *********************************/
