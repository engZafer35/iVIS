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

typedef _DRV_RET_TYPE       DRV_RET_TYPE;
#define DRV_RET_OK          _DRV_RET_OK
#define DRV_RET_ERROR       _DRV_RET_ERROR
#define DRV_RET_BUSY        _DRV_RET_BUSY
#define DRV_RET_TIMEOUT     _DRV_RET_TIMEOUT
/****************** BOARD MCU CLOCK CONTROL *******************/

#define CORE_MCU_INIT()     _CORE_MCU_INIT()
#define CONF_MCU_CLOCK()    _CONF_MCU_CLOCK()

#define DELAY_MS(x)         _DELAY_MS(x)

/****************** BOARD GPI0 CONTROL *******************/
#define GPIO_INIT()                         _GPIO_INIT()

#define GPIO_WRITE(port, pin, status)       _GPIO_WRITE(port, pin, status)
#define GPIO_READ(port, pin)                _GPIO_READ(port, pin)
#define GPIO_TOGGLE(port, pin)              _GPIO_TOGGLE(port, pin)

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
#define UART1_COMM_INIT()                       _UART1_COMM_INIT()
#define UART2_DBG_INIT()                        _UART2_DBG_INIT()

#define UART_SEND(line, buff, leng, timeout)    _UART_SEND(line, buff, leng, timeout)
#define UART_RCV(line, buff, leng, timeout)     _UART_RCV(line, buff, leng, timeout)

#define UART_RX_IT_DISABLE(line)                _UART_RX_IT_DISABLE(line)
#define UART_RX_IT_ENABLE(line)                 _UART_RX_IT_ENABLE(line)

/****************** BOARD SPI CONTROL *******************/
#define SPI_INIT()              _SPI_INIT()

/****************** BOARD TIMER CONTROL *******************/
#define TIMER_ALERT_INIT()      _TIMER_ALERT_INIT()
#define TIMER_EVENT_INIT()      _TIMER_EVENT_INIT()


#define TIMER_EVENT_START()     _TIMER_EVENT_START()
#define TIMER_ALERT_START()     _TIMER_ALERT_START()
/****************** BOARD CAN CONTROL *******************/
#define CAN_1_START()           _CAN_1_START()
#define CAN_2_START()           _CAN_2_START()
/****************** BOARD WDT CONTROL *******************/
#define WDT_INIT()              _WDT_INIT()
#define WDT_START()             _WDT_START()
#define WDT_FEED()              _WDT_FEED()

/****************** BOARD ADC CONTROL *******************/
#define ADC_TEMP_INIT()         _ADC_TEMP_INIT()


/****************** BOARD CAN CONTROL *******************/
#define CAN_1_INIT()            _CAN_1_INIT()
#define CAN_2_INIT()            _CAN_2_INIT()

/******************************* TYPE DEFINITIONS ****************************/

/************************* GLOBAL VARIBALE REFERENCES ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

#endif /* __GENERAL_BOARD_CONFIG_H__ */

/********************************* End Of File ********************************/

