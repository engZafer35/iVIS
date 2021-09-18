/******************************************************************************
* #Author       : Zafer Satılmış
* #Revision     : 1.0
* #Date         : Mar 8, 2021 - 10:52:52 AM
* #File Name    : BoardConfig_LinuxPC.h
******************************************************************************/

/******************************************************************************
* 
******************************************************************************/
/****************************** IFNDEF & DEFINE ******************************/
#ifndef __BOARD_CONFIG_LINUX_PC_H__
#define __BOARD_CONFIG_LINUX_PC_H__
/********************************* INCLUDES **********************************/
#include <unistd.h>
/****************************** MACRO DEFINITIONS ****************************/
#define BOARD_NAME          "EBP_LINUX_PC_BOARD"
#define BOARD_VERSION       "V1.0.0"
#define BOARD_FILE_NAME     "BoardConfig_LinuxPC.h"
#define WORKING_PLATFORM    (01)
#define _WORKING_PLATFORM   (WORKING_PLATFORM)
#define PLATFORM_NAME      "LINUX_GCC"
#define MCU_BIT_SIZE       (64)
#define MCU_CORE           "X86-LINUX"
#define MCU_PART_NUM       "LINUX_PC"

typedef enum
{
    EN_DRV_RET_OK,
    EN_DRV_RET_ERROR,
    EN_DRV_RET_BUSY,
    EN_DRV_RET_TIMEOUT
}DRV_RET;

typedef DRV_RET             _DRV_RET_TYPE;
#define _DRV_RET_OK         (EN_DRV_RET_OK)
#define _DRV_RET_ERROR      (EN_DRV_RET_ERROR)
#define _DRV_RET_BUSY       (EN_DRV_RET_BUSY)
#define _DRV_RET_TIMEOUT    (EN_DRV_RET_TIMEOUT)

/****************** BOARD MCU CLOCK CONTROL *******************/
#define _CORE_MCU_INIT()
#define _CONF_MCU_CLOCK()

#define _DELAY_MS(x)    usleep(x*1000)
/****************** BOARD GPI0 CONTROL *******************/
#define _GPIO_INIT()

#define _GPIO_WRITE(port, pin, status)
#define _GPIO_READ(port, pin)
#define _GPIO_TOGGLE(port, pin)

/****************** BOARD I2C CONTROL *******************/
#define _I2C1_INIT()
#define _I2C2_INIT()

#define _I2C1_LINE  (1)
#define _I2C2_LINE  (2)

#define _TCA9555_I2C_ADDR   (0x10)
#define _LM75B_I2C_ADDR     (0x20)

#define _I2C_SEND(line, devAddr, buff, leng)        (EN_DRV_RET_OK)
#define _I2C_RCV(line, devAddr, buff, leng)         (EN_DRV_RET_OK)

#define _I2C_WRITE(line, devAddr, addr, buff, leng) (EN_DRV_RET_OK)
#define _I2C_READ(line, devAddr, addr, buff, leng)  (EN_DRV_RET_OK)

/****************** BOARD UART CONTROL *******************/
#define _UART1_COMM_INIT()
#define _UART2_DBG_INIT()

#define _UART_SEND(line, buff, leng, timeout)   (EN_DRV_RET_OK)
#define _UART_RCV(line, buff, leng, timeout)    (EN_DRV_RET_OK)

#define _UART_RX_IT_DISABLE(line)
#define _UART_RX_IT_ENABLE(line)

/****************** BOARD SPI CONTROL *******************/
#define _SPI_INIT()

/****************** BOARD TIMER CONTROL *******************/
#define _TIMER_ALERT_INIT()
#define _TIMER_EVENT_INIT()


#define _TIMER_EVENT_START()    (EN_DRV_RET_OK)
#define _TIMER_ALERT_START()    (EN_DRV_RET_OK)

/****************** BOARD CAN CONTROL *******************/
#define _CAN_1_INIT()            (EN_DRV_RET_OK)
#define _CAN_2_INIT()            (EN_DRV_RET_OK)


#define _CAN_1_START()          (EN_DRV_RET_OK)
#define _CAN_2_START()          (EN_DRV_RET_OK)

/****************** BOARD ADC CONTROL *******************/
#define _ADC_TEMP_INIT()

/****************** BOARD WDT CONTROL *******************/
#define _WDT_INIT()
#define _WDT_START()
#define _WDT_FEED()
/******************************* TYPE DEFINITIONS ****************************/

/************************* GLOBAL VARIBALE REFERENCES ************************/

/************************* GLOBAL FUNCTION DEFINITIONS ************************/

#endif /* __BOARD_CONFIG_LINUX_PC_H__ */

/********************************* End Of File ********************************/
