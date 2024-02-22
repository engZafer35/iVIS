/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Feb 22, 2024 - 2:09:59 PM
* #File Name    : App_Global_Variables.c
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
#define SHOW_PAGE_DBG_MSG  (DISABLE)
/********************************* INCLUDES ***********************************/
#include "Project_Conf.h"

#include "MP45DT02.h"
/****************************** MACRO DEFINITIONS *****************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/
static VoidCallback hrcb;
static VoidCallback frcb;
/***************************** STATIC FUNCTIONS  ******************************/
/**
  * @brief  Rx Transfer completed callbacks
  * @param  hi2s: I2S handle
  */
I2S_REC_CPLT_DMA_IT_FUNCTION
{
    if (IS_VOICE_REC_I2S_LINE())
    {
        if (NULL != frcb)
        {
            frcb();
        }
    }
}

/**
  * @brief  Rx Half Transfer completed callbacks.
  * @param  hi2s: I2S handle
  */
I2S_REC_HALF_DMA_IT_FUNCTION
{
    if (IS_VOICE_REC_I2S_LINE())
    {
        if (NULL != hrcb)
        {
            hrcb();
        }
    }
}
/***************************** PUBLIC FUNCTIONS  ******************************/
RETURN_STATUS MP45DT02Init(U32 freq, U32 BitRes, VoidCallback cbHalfRec, VoidCallback cbFullRec)
{
    // middMCUI2SInit() is already called in App_IVIS.c file.
    /*
     * In I2S_Init function, hAudioInI2s.Init.AudioFreq = 2*AudioFreq; should be like that.
     * But I don't think to update it in run time. Change frequency in CubeMx
     */
    hrcb = cbHalfRec;
    frcb = cbFullRec;
    return SUCCESS;
}

RETURN_STATUS MP45DT02Start(U16* pbuf, U32 size)
{
    RETURN_STATUS retVal = SUCCESS;

    if (DRV_RET_FAILURE == I2S_RECIVE_DMA(MP45DT02_I2S_LINE, pbuf, size))
    {
        retVal = FAILURE;
    }

    return retVal;
}

RETURN_STATUS MP45DT02Stop(void)
{
    RETURN_STATUS retVal = SUCCESS;

    if (DRV_RET_FAILURE == I2S_REC_DMA_STOP(MP45DT02_I2S_LINE))
    {
        retVal = FAILURE;
    }

    return retVal;
}

RETURN_STATUS MP45DT02Pause(void)
{
    RETURN_STATUS retVal = SUCCESS;

    if (DRV_RET_FAILURE == I2S_REC_DMA_PAUSE(MP45DT02_I2S_LINE))
    {
        retVal = FAILURE;
    }

    return retVal;
}

RETURN_STATUS MP45DT02Resume(void)
{
    RETURN_STATUS retVal = SUCCESS;

    if (DRV_RET_FAILURE == I2S_REC_DMA_RESUME(MP45DT02_I2S_LINE))
    {
        retVal = FAILURE;
    }

    return retVal;
}
/******************************** End Of File *********************************/
