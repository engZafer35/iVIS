/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 2, 2021 - 10:43:24 PM
* #File Name    : App_Job_Manager.h
*******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/******************************IFNDEF & DEFINE********************************/
#ifndef __APP_JOB_MANAGER_H__
#define __APP_JOB_MANAGER_H__
/*********************************INCLUDES*************************************/
#include "Project_Conf.h"
/******************************MACRO DEFINITIONS*******************************/
typedef enum JOB_LIST
{
    EN_JOB_MANAGER,
    EN_JOB_SYS_EVENT_HANDLER,
    EN_JOB_EVENT_MANAGER,
    EN_JOB_UI_MAGER,
    EN_JOB_PLAYER,
    EN_JOB_VOICE_RECEIVER,
    EN_JOB_VOICE_CREATOR,
    EN_JOB_MIC_SPEAKER,
    EN_JOB_RECORD_MANAGER,
    EN_JOB_UPDATE_MANAGER,

    EN_JOB_MAX_NUMBER
}EN_JOB_LIST;

typedef enum _JOB_STATUS
{
    EN_NOT_CREATED,
    EN_RUNNING,
    EN_STOPED,
    EN_KILLED,
}JOB_STATUS;
/*******************************TYPE DEFINITIONS ******************************/

/************************* GLOBAL VARIBALE REFERENCES *************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/
/**
* \brief   init job
* \return  if everything is OK, return EN_SUCCES
*          otherwise return EN_FAILURE
*/
RETURN_STATUS appJobInit(void);

/**
 * \brief   start
 * \param   job id
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appJobCreatJob(EN_JOB_LIST job);

/**
 * \brief   start job, before appJobCreatJob must be called
 * \param   job id
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appJobStartJob(EN_JOB_LIST job);

/**
 * \brief   stop job. not destroy job variables and not remove memory
 * \param   job id
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appJobStoptJob(EN_JOB_LIST job);

/**
 * \brief   stop all job. not destroy job variables and not remove memory
 * \param   job id
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appJobStopAll(void);

/**
 * \brief   stop and destroy job. All variables of job is deleted from memory.
 *          if wanted to start the same job again, firstly appJobCreatJob must be called
 * \param   job id
 * \return  if everything is OK, return EN_SUCCES
 *          otherwise return EN_FAILURE
 */
RETURN_STATUS appJobKillJob(EN_JOB_LIST job);

/**
 * \brief   get job status
 * \param   job id
 * \return  return job status, error -1
 */
JOB_STATUS appJobGetJobStatus(EN_JOB_LIST job);

#endif /* __APP_JOB_MANAGER_H__ */

/********************************* End Of File ********************************/
