/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Feb 16, 2024 - 10:43:44 PM
* #File Name    : ZDebug.h
******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/****************************** IFNDEF & DEFINE ******************************/
#ifndef APPCOMM_INC_ZDEBUG_H_
#define APPCOMM_INC_ZDEBUG_H_
/********************************* INCLUDES **********************************/

/****************************** MACRO DEFINITIONS ****************************/
#include <stdio.h>

//DEBUG level definitions
#define DEBUG_LEVEL_OFF      0
#define DEBUG_LEVEL_FATAL    1
#define DEBUG_LEVEL_ERROR    2
#define DEBUG_LEVEL_WARNING  3
#define DEBUG_LEVEL_INFO     4
#define DEBUG_LEVEL_DEBUG    5
#define DEBUG_LEVEL_VERBOSE  6

//Default DEBUG level
#ifndef DEBUG_LEVEL
   #define DEBUG_LEVEL DEBUG_LEVEL_INFO
#endif

//DEBUG output redirection
#define DEBUG_PRINTF(format, args...)   fprintf(stdout, "-> %s():%d: ", __FUNCTION__, __LINE__), \
                                        fprintf(stdout, format , ##args), \
                                        fprintf(stdout, "\r\n")

//#ifndef DEBUG_ARRAY
//   #define DEBUG_ARRAY(p, a, n)  debugDisplayArray(stderr, p, a, n), osResumeAllTasks()
//#endif
//
//#ifndef DEBUG_MPI
//   #define DEBUG_MPI(p, a) osSuspendAllTasks(), mpiDump(stderr, p, a), osResumeAllTasks()
//#endif

//Debugging macros
#if (DEBUG_LEVEL >= DEBUG_LEVEL_FATAL)
   #define DEBUG_FATAL(...) DEBUG_PRINTF(__VA_ARGS__)
   #define DEBUG_FATAL_ARRAY(p, a, n) DEBUG_ARRAY(p, a, n)
   #define DEBUG_FATAL_MPI(p, a) DEBUG_MPI(p, a)
#else
   #define DEBUG_FATAL(...)
   #define DEBUG_FATAL_ARRAY(p, a, n)
   #define DEBUG_FATAL_MPI(p, a)
#endif

#if (DEBUG_LEVEL >= DEBUG_LEVEL_ERROR)
   #define DEBUG_ERROR(...) DEBUG_PRINTF(__VA_ARGS__)
   #define DEBUG_ERROR_ARRAY(p, a, n) DEBUG_ARRAY(p, a, n)
   #define DEBUG_ERROR_MPI(p, a) DEBUG_MPI(p, a)
#else
   #define DEBUG_ERROR(...)
   #define DEBUG_ERROR_ARRAY(p, a, n)
   #define DEBUG_ERROR_MPI(p, a)
#endif

#if (DEBUG_LEVEL >= DEBUG_LEVEL_WARNING)
   #define DEBUG_WARNING(...) DEBUG_PRINTF(__VA_ARGS__)
   #define DEBUG_WARNING_ARRAY(p, a, n) DEBUG_ARRAY(p, a, n)
   #define DEBUG_WARNING_MPI(p, a) DEBUG_MPI(p, a)
#else
   #define DEBUG_WARNING(...)
   #define DEBUG_WARNING_ARRAY(p, a, n)
   #define DEBUG_WARNING_MPI(p, a)
#endif

#if (DEBUG_LEVEL >= DEBUG_LEVEL_INFO)
   #define DEBUG_INFO(...) DEBUG_PRINTF(__VA_ARGS__)
   #define DEBUG_INFO_ARRAY(p, a, n) DEBUG_ARRAY(p, a, n)
   #define DEBUG_INFO_NET_BUFFER(p, b, o, n)
   #define DEBUG_INFO_MPI(p, a) DEBUG_MPI(p, a)
#else
   #define DEBUG_INFO(...)
   #define DEBUG_INFO_ARRAY(p, a, n)
   #define DEBUG_INFO_NET_BUFFER(p, b, o, n)
   #define DEBUG_INFO_MPI(p, a)
#endif

#if (DEBUG_LEVEL >= DEBUG_LEVEL_DEBUG)
   #define DEBUG_DEBUG(...) DEBUG_PRINTF(__VA_ARGS__)
   #define DEBUG_DEBUG_ARRAY(p, a, n) DEBUG_ARRAY(p, a, n)
   #define DEBUG_DEBUG_NET_BUFFER(p, b, o, n)
   #define DEBUG_DEBUG_MPI(p, a) DEBUG_MPI(p, a)
#else
   #define DEBUG_DEBUG(...)
   #define DEBUG_DEBUG_ARRAY(p, a, n)
   #define DEBUG_DEBUG_NET_BUFFER(p, b, o, n)
   #define DEBUG_DEBUG_MPI(p, a)
#endif

#if (DEBUG_LEVEL >= DEBUG_LEVEL_VERBOSE)
   #define DEBUG_VERBOSE(...) DEBUG_PRINTF(__VA_ARGS__)
   #define DEBUG_VERBOSE_ARRAY(p, a, n) DEBUG_ARRAY(p, a, n)
   #define DEBUG_VERBOSE_NET_BUFFER(p, b, o, n)
   #define DEBUG_VERBOSE_MPI(p, a) DEBUG_MPI(p, a)
#else
   #define DEBUG_VERBOSE(...)
   #define DEBUG_VERBOSE_ARRAY(p, a, n)
   #define DEBUG_VERBOSE_NET_BUFFER(p, b, o, n)
   #define DEBUG_VERBOSE_MPI(p, a)
#endif

/******************************* TYPE DEFINITIONS ****************************/

/************************* GLOBAL VARIBALE REFERENCES ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

#endif /* APPCOMM_INC_ZDEBUG_H_ */

/********************************* End Of File ********************************/
