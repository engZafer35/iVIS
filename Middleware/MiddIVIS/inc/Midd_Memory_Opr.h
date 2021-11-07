/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 6, 2021 - 10:47:09 PM
* #File Name    : Midd_Memory_Opr.h
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __MIDD_MEMORY_OPR_H__
#define __MIDD_MEMORY_OPR_H__
/*********************************INCLUDES*************************************/
#include "Project_Conf.h"
/******************************MACRO DEFINITIONS*******************************/
#if (CURRENT_BOARD != BOARD_LINUX_PC)
#define FAST_MEMCPY(dest, src, leng)

#elif (CURRENT_BOARD == BOARD_LINUX_PC)

extern void callCompletedFastCpy(void);
#define FAST_MEMCPY(dest, src, leng)    memcp(dest, src, leng), callCompletedCb();

#endif
/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

//init all dma here;
RETURN_STATUS middMemInit(void);


#endif /* __MIDD_MEMORY_OPR_H__ */

/********************************* End Of File ********************************/
