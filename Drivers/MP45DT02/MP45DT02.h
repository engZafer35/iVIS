/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Feb 22, 2024 - 2:09:47 PM
* #File Name    : MP45DT02.h
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __MP45DT02_MP45DT02_H__
#define __MP45DT02_MP45DT02_H__
/*********************************INCLUDES*************************************/
#include "Global_Definitions.h"
/******************************MACRO DEFINITIONS*******************************/
#define MP45DT02_I2S_LINE   (VOICE_REC_I2S_LINE_ID)
/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

RETURN_STATUS MP45DT02Init(U32 freq, U32 BitRes, VoidCallback cbHalfRec, VoidCallback cbFullRec);

RETURN_STATUS MP45DT02Start(U16* pbuf, U32 size);

RETURN_STATUS MP45DT02Stop(void);

RETURN_STATUS MP45DT02Pause(void);

RETURN_STATUS MP45DT02Resume(void);
#endif /* __MP45DT02_MP45DT02_H__ */

/********************************* End Of File ********************************/
