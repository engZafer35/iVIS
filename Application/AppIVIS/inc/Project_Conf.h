/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 2, 2021 - 11:08:23 PM
* #File Name    : Project_Conf.h
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __PROJECT_CONF_H_
#define __PROJECT_CONF_H_
/*********************************INCLUDES*************************************/
#include "GeneralBoardConfig.h"
#include "Global_Definitions.h"
#include "ZDebug.h"
/******************************MACRO DEFINITIONS*******************************/
#define SW_VERSION_MAJOR (0x01)
#define SW_VERSION_MINOR (0x00)
#define SW_VERSION_BUGFX (0x00)

/* ********************** Debug Macros **********************/

#define ALL_DBG_MSG_ACTIVE      (ENABLE)//(DISABLE)//
#include <stdio.h>

#ifndef SHOW_PAGE_DBG_MSG
    #define SHOW_PAGE_DBG_MSG  (DISABLE)//(ENABLE)
#endif

#if (ALL_DBG_MSG_ACTIVE || SHOW_PAGE_DBG_MSG)

#define DBG_MSG(format, args...) fprintf(stdout, "-> %s():%d: ", __FUNCTION__, __LINE__), \
                                 fprintf(stdout, format , ##args), \
                                 fprintf(stdout, "\r\n")
#else
#define DBG_MSG(format, args...)
#endif

/*-------------- SYSTEM PARAMETERS ----------*/
/**
 * set hw timer period (ms), System need two hardware timer and both period should be same.
 * MIN_TIMER_PERIOD_MS will used in MiddSysTimer and MiddEventTimer
 */
#define MIN_TIMER_PERIOD_MS (10)
#if ((MIN_TIMER_PERIOD_MS  <= 0)) //|| (!(defined MIN_TIMER_PERIOD_MS)))
#error "Hardware timer period is not know. Please set MIN_TIMER_PERIOD_MS macros"
#endif

/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/
#endif /* INC_PROJECT_CONF_H_ */

/********************************* End Of File ********************************/
