/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Mar 8, 2021 - 9:55:55 AM
* #File Name    : GeneralBoardConfig.h
******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/****************************** IFNDEF & DEFINE ******************************/
#ifndef __GENERAL_BOARD_CONFIG_H__
#define __GENERAL_BOARD_CONFIG_H__
/********************************* INCLUDES **********************************/

/****************************** MACRO DEFINITIONS ****************************/
#define BOARD_LINUX_PC          (1)
#define BOARD_STM_010101        (2)
#define BOARD_STM_LP_010101     (3)
#define BOARD_NXP_010102        (4)
/* add new board*/


#ifdef __linux
#define CURRENT_BOARD   (BOARD_LINUX_PC)
#else
#define CURRENT_BOARD   (BOARD_STM_010101)
#endif


#if (CURRENT_BOARD == BOARD_STM_010101)
#include "BoardConfig_STM_021121.h"
#elif (CURRENT_BOARD == BOARD_STM_LP_010101)
#include "BoardConfig_STM_LP_010101.h"
#elif (CURRENT_BOARD == BOARD_NXP_010102)
#include "BoardConfig_NXP_010102.h"
#elif (CURRENT_BOARD == BOARD_LINUX_PC)
#include "BoardConfig_LinuxPC.h"
#else
#error " !!! Current board is undefined, Check GeneralBoardConfig.h !!!"
#endif

typedef _DRV_RET_TYPE           DRV_RET_TYPE;
#define DRV_RET_SUCCESS         _DRV_RET_OK
#define DRV_RET_FAILURE         _DRV_RET_ERROR
#define DRV_RET_BUSY            _DRV_RET_BUSY
#define DRV_RET_TIMEOUT         _DRV_RET_TIMEOUT


typedef _EN_INTERRUPT_LIST EN_INTERRUPT_LIST;
/****************** BOARD MCU CLOCK CONTROL *******************/

#define MCU_CORE_INIT()         _MCU_CORE_INIT()
#define CONF_MCU_CLOCK()        _CONF_MCU_CLOCK()

#define DELAY_MS(x)             _DELAY_MS(x)

/****************** BOARD GPI0 CONTROL *******************/
#define GPIO_INIT()                         _GPIO_INIT()

#define GPIO_WRITE(port, pin, status)       _GPIO_WRITE(port, pin, status)
#define GPIO_READ(port, pin)                _GPIO_READ(port, pin)
#define GPIO_TOGGLE(port, pin)              _GPIO_TOGGLE(port, pin)


#define POWER_STATUS_LED(x)             _LED_2(x)
#define JOB_STATUS_LED(x)               _LED_1(x)
#define ERR_STATUS_LED(x)               _LED_3(x)
#define INFO_STATUS_LED(x)              _LED_4(x)

#define TOGGLE_POWER_STATUS_LED()       _TOGGLE_LED_2()
#define TOGGLE_JOB_STATUS_LED()         _TOGGLE_LED_1()

#define CORE_EXT_IT_FUNCTION            _CORE_EXT_IT_FUNCTION

/****************** BOARD I2C CONTROL *******************/
#define I2C1_INIT()                                 _I2C1_INIT()
#define I2C2_INIT()                                 _I2C2_INIT()

#define I2C1_LINE                                   _I2C1_LINE
#define I2C2_LINE                                   _I2C2_LINE

#define TCA9555_I2C_ADDR                            _TCA9555_I2C_ADDR
#define LM75B_I2C_ADDR                              _LM75B_I2C_ADDR

#define I2C_SEND(line, devAddr, buff, leng)         _I2C_SEND(line, devAddr, buff, leng)
#define I2C_RCV(line, devAddr, buff, leng)          _I2C_RCV(line, devAddr, buff, leng)

#define I2C_WRITE(line, devAddr, addr, buff, leng)  _I2C_WRITE(line, devAddr, addr, buff, leng)
#define I2C_READ(line, devAddr, addr, buff, leng)   _I2C_READ(line, devAddr, addr, buff, leng)

/****************** BOARD UART CONTROL *******************/
#define UART_DEBUG_INIT()                           _UART_DEBUG_INIT()
#define UART_COMM_INIT()                            _UART_COMM_INIT()

#define UART_LINE_OBJ_TYPE                          _UART_LINE_OBJ_TYPE
#define UART_LINE_1                                 _UART_COMM_LINE_1
#define UART_LINE_2                                 _UART_COMM_LINE_2
#define UART_LINE_3                                 _UART_DEBUG_LINE
#define UART_LINE_6                                 _UART_DEBUG_LINE

#define LINE_DBG_RX_IT_ID                           _LINE_DBG_RX_IT_ID
#define LINE_COMM_1_RX_IT_ID                        _LINE_COMM_1_RX_IT_ID
#define LINE_COMM_2_RX_IT_ID                        _LINE_COMM_2_RX_IT_ID

#define UART_RCV_IT_FUNCTION                        _UART_RCV_IT_FUNCTION

#define IS_DBG_UART_IT()                            _IS_DBG_UART_IT()
#define IS_COMM_1_UART_IT()                         _IS_COMM_1_UART_IT()
#define IS_COMM_2_UART_IT()                         _IS_COMM_2_UART_IT()

#define UART_RX_IT_DISABLE(line)                    _UART_RX_IT_DISABLE(line)
#define UART_RX_IT_ENABLE(line)                     _UART_RX_IT_ENABLE(line)
#define UART_RCV_IT(line, pBuff, leng)              _UART_RCV_IT(line, pBuff, leng)
#define UART_CLR_IT_FLAG(line, flag)                _UART_CLR_IT_FLAG(line, flag)
#define UART_SEND(line, buff, leng, timeout)        _UART_SEND(line, buff, leng, timeout)
#define UART_CLR_RX_INT_FLAG(line)                  _UART_CLR_IT_FLAG(line, UART_IT_RXNE)

#define IS_LINE1_UART_IT()                          IS_COMM_1_UART_IT()
#define IS_LINE2_UART_IT()                          IS_COMM_2_UART_IT()
#define IS_LINE6_UART_IT()                          IS_DBG_UART_IT()

#define LINE_UART1_RX_IT_ID                         LINE_COMM_1_RX_IT_ID
#define LINE_UART2_RX_IT_ID                         LINE_COMM_2_RX_IT_ID
#define LINE_UART3_RX_IT_ID                         ******
#define LINE_UART4_RX_IT_ID                         ******
#define LINE_UART5_RX_IT_ID                         ******
#define LINE_UART6_RX_IT_ID                         LINE_DBG_RX_IT_ID
#define LINE_UART7_RX_IT_ID                         ******
#define LINE_UART8_RX_IT_ID                         ******

#define UART_HW_LINE_1                              UART_LINE_1
#define UART_HW_LINE_2                              UART_LINE_2
#define UART_HW_LINE_3                              UART_LINE_3
#define UART_HW_LINE_4                              ******
#define UART_HW_LINE_5                              ******
#define UART_HW_LINE_6                              UART_LINE_6
#define UART_HW_LINE_7                              ******
#define UART_HW_LINE_8                              ******

#define UART_RX_IT_DISABLE(line)                    _UART_RX_IT_DISABLE(line)
#define UART_RX_IT_ENABLE(line)                     _UART_RX_IT_ENABLE(line)
#define UART_RCV_IT(line, pBuff, leng)              _UART_RCV_IT(line, pBuff, leng)
#define UART_CLR_IT_FLAG(line, flag)                _UART_CLR_IT_FLAG(line, flag)
#define UART_SEND(line, buff, leng, timeout)        _UART_SEND(line, buff, leng, timeout)
#define UART_CLR_RX_INT_FLAG(line)                  _UART_CLR_IT_FLAG(line, UART_IT_RXNE)

/****************** BOARD SPI CONTROL *******************/
#define SPI_INIT()      _SPI_INIT()

/****************** BOARD DMA CONTROL *******************/
#define DMA_INIT()      _DMA_INIT()

/****************** BOARD TIMER CONTROL *******************/
#define TIMER_ALERT_INIT()      _TIMER_ALERT_INIT()
#define TIMER_EVENT_INIT()      _TIMER_EVENT_INIT()


#define TIMER_EVENT_START()     _TIMER_EVENT_START()
#define TIMER_ALERT_START()     _TIMER_ALERT_START()

#define CORE_TIMER_IT_FUNCTION  _CORE_TIMER_IT_FUNCTION
/****************** BOARD CAN CONTROL *******************/
#define CAN_1_START()           _CAN_1_START()
#define CAN_2_START()           _CAN_2_START()
/****************** BOARD WDT CONTROL *******************/
#define WDT_INIT(x)             _WDT_INIT(x)
#define WDT_START()             _WDT_START()
#define WDT_FEED()              _WDT_FEED()

/****************** BOARD ADC CONTROL *******************/
#define ADC_TEMP_INIT()         _ADC_TEMP_INIT()


/****************** BOARD CAN CONTROL *******************/
#define CAN_INIT()                                     _CAN_INIT()

//typedef _HAL_CAN_TX_HEADER                              DRV_CAN_TX_HEADER;
//typedef _HAL_CAN_RX_HEADER                              DRV_CAN_RX_HEADER;
#define CAN_LINE1                                       _CAN_LINE1
#define CAN_LINE2                                       _CAN_LINE2

#define COM_CAN_RX_IT_FUNC                              _CORE_CAN_2_IT_FUNC

#define HAL_CAN_1_START()                               _HAL_CAN_1_START()
#define HAL_CAN_2_START()                               _HAL_CAN_2_START()

#define CAN_ADD_TX_MESSAGE(line, txHeader, data, mbox)  _HAL_CAN_ADD_TX_MESSAGE(line, txHeader, data, mbox)
#define HAL_CAN_GET_RX_MESSAGE(v1, v2, v3, v4)          _HAL_CAN_GET_RX_MESSAGE(v1, v2, v3, v4)
/******************************* TYPE DEFINITIONS ****************************/

/************************* GLOBAL VARIBALE REFERENCES ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

#endif /* __GENERAL_BOARD_CONFIG_H__ */

/********************************* End Of File ********************************/

