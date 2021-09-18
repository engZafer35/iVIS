/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Mar 5, 2021 - 5:29:31 PM
* #File Name    : ProjectConf.h
******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/****************************** IFNDEF & DEFINE ******************************/
#ifndef __PROJECT_CONF_H__
#define __PROJECT_CONF_H__
/********************************* INCLUDES **********************************/
#include "GeneralBoardConfig.h"
#include "GlobalDefinitions.h"
/****************************** MACRO DEFINITIONS ****************************/

#define SW_VERSION_MAJOR    (1)
#define SW_VERSION_MINOR    (0)
#define SW_VERSION_BUGFIX   (0)

#define ALL_DBG_MSG_ACTIVE  (1)

#if (ALL_DBG_MSG_ACTIVE || SHOW_PAGE_DBG_MSG)
#include <stdio.h>
#define DBG_MSG(format, args...)    fprintf(stdout, "-> %s():%d: ", __FUNCTION__, __LINE__), \
                                    fprintf(stdout, format, ##args), \
                                    fprintf(stdout, "\n\r")
#else
#define DBG_MSG(format, args...)
#endif

#define MIN_TIMER_PERIOD_MS (10)
#if (MIN_TIMER_PERIOD_MS <= 0)
#error "Hardware timer period is not know. Check MIN_TIMER_PERIOD_MS macro"
#endif

/******************************* TYPE DEFINITIONS ****************************/

/************************* GLOBAL VARIBALE REFERENCES ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

#endif /* __PROJECT_CONF_H__ */

/********************************* End Of File ********************************/
