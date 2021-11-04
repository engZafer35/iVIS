/******************************************************************************
* #Author       : Zafer Satilmis
* #Revision     : 1.0
* #Date         : Jan 27, 2021 - 9:05:66 AM
* #File Name    : MiddDigitalIOControl.c
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
#define SHOW_PAGE_DBG_MSG    (DISABLE)//(ENABLE)//
/********************************* INCLUDES ***********************************/
#include "MiddDigitalIOControl.h"
#include "McuInterruptRegister.h"
/****************************** MACRO DEFINITIONS *****************************/

/*************************** FUNCTION PROTOTYPES ******************************/

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/
static VUICallback gCbList[EN_IN_MAX_NUM];

/***************************** STATIC FUNCTIONS  ******************************/
void cbGpioExtInt(int pin)
{
//    if ((EXT_S1_PWR_Pin == pin) && (NULL != gCbList[EN_IN_SW1_POWER]))
//    {
//        gCbList[EN_IN_SW1_POWER](GPIO_READ(EXT_S1_PWR_GPIO_Port, EXT_S1_PWR_Pin));
//    }
//    else if ((EXT_S16_EMG_Pin == pin) && (NULL != gCbList[EN_IN_SW16_EMG]))
//    {
//        gCbList[EN_IN_SW16_EMG](GPIO_READ(EXT_S16_EMG_GPIO_Port, EXT_S16_EMG_Pin));
//    }
//    else if ((EXT_PCA_INT2_U16_Pin == pin) && (NULL != gCbList[EN_IN_PCA_U16_INT]))
//    {
//        gCbList[EN_IN_PCA_U16_INT](FALSE); //Don't read gpio, just falling edge interrupt
//    }
//    else if ((EXT_INT1_PCA_U7_Pin == pin) && (NULL != gCbList[EN_IN_PCA_U7_INT]))
//    {
//        gCbList[EN_IN_PCA_U7_INT](FALSE); //Don't read gpio, just falling edge interrupt
//    }
//    else if ((EXT_INT4_PCA_U8_Pin == pin) && (NULL != gCbList[EN_IN_PCA_U8_INT]))
//    {
//        gCbList[EN_IN_PCA_U8_INT](FALSE); //Don't read gpio, just falling edge interrupt
//    }
}

/***************************** PUBLIC FUNCTIONS  ******************************/
/**
 * @brief  init digital IO
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middIOInit(void)
{
    RETURN_STATUS retVal = SUCCESS;

    //clear outputs
    JOB_STATUS_LED(FALSE);

    retVal = drvIntRegister(cbGpioExtInt, EN_EXTI0_IRQ);

    DBG_MSG("->[I] midd IO Init retVal: %d", retVal);
    return retVal;
}

/**
 * @brief  listen a interrupt input(Check whick input support interrupt)
 * @param  void(int) callback pointer
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middIOIntListen(EN_IN_LIST in, VUICallback cb, BOOL stat)
{
    RETURN_STATUS retVal = FAILURE;

    if ((EN_IN_MAX_NUM > in) && IS_SAFELY_PTR(cb))
    {
        retVal = SUCCESS;
        switch(in)
        {
            case EN_IN_USER_INPUT_1:
            {
                gCbList[EN_IN_USER_INPUT_1]  = stat ? cb : NULL;
                DBG_MSG("->[I] midd IO EN_IN_USER_INPUT_1 listener stat: %d - retVal: %d", stat, retVal);
                break;
            }
            case EN_IN_USER_INPUT_2:
            {
                gCbList[EN_IN_USER_INPUT_2]  = stat ? cb : NULL;
                DBG_MSG("->[I] midd IO EN_IN_USER_INPUT_2 listener stat: %d - retVal: %d", stat, retVal);
                break;
            }
            default: retVal = FAILURE;
        }
    }

    return retVal;
}

/**
 * @brief  set output
 * @param  output channel list
 * @param  ENABLE active, DISABLE passif
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */

RETURN_STATUS middIOWrite(EN_OUT_LIST out, BOOL stat)
{
    RETURN_STATUS retVal = SUCCESS;

    switch(out)
    {
        case EN_OUT_JOB_LED:    JOB_STATUS_LED(stat);   break;
        case EN_OUT_ERR_LED:    ERR_STATUS_LED(stat);   break;
        case EN_OUT_POWER_LED:  POWER_STATUS_LED(stat); break;

        default: retVal = FAILURE;
    }

    return retVal;
}

/**
 * @brief  read input
 * @param  input channel list
 * @return 1 or 0,
 */
BOOL middIORead(EN_IN_LIST in)
{
    BOOL retVal = 0;
    switch(in)
    {
//        case EN_IN_USER_INPUT_1: retVal = GPIO_READ(EXT_IO_EXP_GPIO_Port, EXT_IO_EXP_Pin);  break;
//        case EN_IN_USER_INPUT_2: retVal = GPIO_READ(EXT_KEYPAD_GPIO_Port, EXT_KEYPAD_Pin);  break;

        default: break;
    }

    return retVal;
}

/**
 * @brief  toogle status output
 * @param  ID
 * @param  status, enable or disable
 * @return if everything is OK, return SUCCES
 *         otherwise return FAILURE
 */
RETURN_STATUS middIOToggle(EN_OUT_LIST out)
{
    switch(out)
    {
        case EN_OUT_JOB_LED:
        {
            TOGGLE_POWER_STATUS_LED();
            break;
        }
        case EN_OUT_ERR_LED:
        {
            TOGGLE_JOB_STATUS_LED();
            break;
        }
        case EN_OUT_POWER_LED:
        {
            TOGGLE_POWER_STATUS_LED();
            break;
        }
    }

    return SUCCESS;
}

/**
 * @brief  read board ID
 * @param  void
 * @return if everything is OK, return input value
 *         otherwise return (-1)(FAILURE)
 */
S32 middIOCtrlGetBoardID(void)
{
    return FAILURE;
}
/******************************** End Of File *********************************/
