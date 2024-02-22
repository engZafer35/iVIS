/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Feb 22, 2024 - 12:57:46 PM
* #File Name    : MiddVoiceInputControl.h
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __MIDD_VOICE_INPUT_CONTROL_H__
#define __MIDD_VOICE_INPUT_CONTROL_H__
/*********************************INCLUDES*************************************/
#include "Project_Conf.h"
/******************************MACRO DEFINITIONS*******************************/

/*******************************TYPE DEFINITIONS ******************************/
#define AUDIO_FREQ_192K     (192000U)
#define AUDIO_FREQ_96K      (96000U)
#define AUDIO_FREQ_48K      (48000U)
#define AUDIO_FREQ_44K      (44100U)
#define AUDIO_FREQ_32K      (32000U)
#define AUDIO_FREQ_22K      (22050U)
#define AUDIO_FREQ_16K      (16000U)
#define AUDIO_FREQ_11K      (11025U)
#define AUDIO_FREQ_8K       (8000U)

#define AUDIO_IN_8_BIT_RESOLUTION       (8)
#define AUDIO_IN_10_BIT_RESOLUTION       (10)
#define AUDIO_IN_12_BIT_RESOLUTION       (12)
#define AUDIO_IN_16_BIT_RESOLUTION       (16)

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

RETURN_STATUS middVoiceInInit(U32 freq, U32 BitRes, U32 ChnlNbr);
RETURN_STATUS middVoiceInRecordStart(U16 *rbuff, U32 size, VoidCallback cbHalfRec, VoidCallback cbFullfRec);
RETURN_STATUS middVoiceInRecordStop(void);
RETURN_STATUS middVoiceInRecordPause(void);
RETURN_STATUS middVoiceInRecordResume(void);
void middVoiceInRecordPDMToPCM(U16 *PDMBuf, U16 *PCMBuf);

#endif /* __MIDD_VOICE_INPUT_CONTROL_H__ */

/********************************* End Of File ********************************/
