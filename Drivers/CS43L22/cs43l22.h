/**
  ******************************************************************************
  * @file    cs43l22.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the cs43l22.c driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2015 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CS43L22_H
#define __CS43L22_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup BSP
  * @{
  */ 

/** @addtogroup Component
  * @{
  */ 
  
/** @addtogroup CS43L22
  * @{
  */

/** @defgroup CS43L22_Exported_Types
  * @{
  */

/**
  * @}
  */

/** @defgroup CS43L22_Exported_Constants
  * @{
  */ 

/******************************************************************************/
/***************************  Codec User defines ******************************/
/******************************************************************************/
/* Codec output DEVICE */
#define OUTPUT_DEVICE_SPEAKER         1
#define OUTPUT_DEVICE_HEADPHONE       2
#define OUTPUT_DEVICE_BOTH            3
#define OUTPUT_DEVICE_AUTO            4

/* Volume Levels values */
#define DEFAULT_VOLMIN                0x00
#define DEFAULT_VOLMAX                0xFF
#define DEFAULT_VOLSTEP               0x04

#define AUDIO_PAUSE                   0
#define AUDIO_RESUME                  1

/* Codec POWER DOWN modes */
#define CODEC_PDWN_HW                 1
#define CODEC_PDWN_SW                 2

/* MUTE commands */
#define AUDIO_MUTE_ON                 1
#define AUDIO_MUTE_OFF                0

/* AUDIO FREQUENCY */
#define AUDIO_FREQUENCY_192K          ((uint32_t)192000)
#define AUDIO_FREQUENCY_96K           ((uint32_t)96000)
#define AUDIO_FREQUENCY_48K           ((uint32_t)48000)
#define AUDIO_FREQUENCY_44K           ((uint32_t)44100)
#define AUDIO_FREQUENCY_32K           ((uint32_t)32000)
#define AUDIO_FREQUENCY_22K           ((uint32_t)22050)
#define AUDIO_FREQUENCY_16K           ((uint32_t)16000)
#define AUDIO_FREQUENCY_11K           ((uint32_t)11025)
#define AUDIO_FREQUENCY_8K            ((uint32_t)8000)  

/** CS43l22 Registers  ***/
#define   CS43L22_REG_ID                  0x01
#define   CS43L22_REG_POWER_CTL1          0x02
#define   CS43L22_REG_POWER_CTL2          0x04
#define   CS43L22_REG_CLOCKING_CTL        0x05
#define   CS43L22_REG_INTERFACE_CTL1      0x06
#define   CS43L22_REG_INTERFACE_CTL2      0x07
#define   CS43L22_REG_PASSTHR_A_SELECT    0x08
#define   CS43L22_REG_PASSTHR_B_SELECT    0x09
#define   CS43L22_REG_ANALOG_ZC_SR_SETT   0x0A
#define   CS43L22_REG_PASSTHR_GANG_CTL    0x0C
#define   CS43L22_REG_PLAYBACK_CTL1       0x0D
#define   CS43L22_REG_MISC_CTL            0x0E
#define   CS43L22_REG_PLAYBACK_CTL2       0x0F
#define   CS43L22_REG_PASSTHR_A_VOL       0x14
#define   CS43L22_REG_PASSTHR_B_VOL       0x15
#define   CS43L22_REG_PCMA_VOL            0x1A
#define   CS43L22_REG_PCMB_VOL            0x1B
#define   CS43L22_REG_BEEP_FREQ_ON_TIME   0x1C
#define   CS43L22_REG_BEEP_VOL_OFF_TIME   0x1D
#define   CS43L22_REG_BEEP_TONE_CFG       0x1E
#define   CS43L22_REG_TONE_CTL            0x1F
#define   CS43L22_REG_MASTER_A_VOL        0x20
#define   CS43L22_REG_MASTER_B_VOL        0x21
#define   CS43L22_REG_HEADPHONE_A_VOL     0x22
#define   CS43L22_REG_HEADPHONE_B_VOL     0x23
#define   CS43L22_REG_SPEAKER_A_VOL       0x24
#define   CS43L22_REG_SPEAKER_B_VOL       0x25
#define   CS43L22_REG_CH_MIXER_SWAP       0x26
#define   CS43L22_REG_LIMIT_CTL1          0x27
#define   CS43L22_REG_LIMIT_CTL2          0x28
#define   CS43L22_REG_LIMIT_ATTACK_RATE   0x29
#define   CS43L22_REG_OVF_CLK_STATUS      0x2E
#define   CS43L22_REG_BATT_COMPENSATION   0x2F
#define   CS43L22_REG_VP_BATTERY_LEVEL    0x30
#define   CS43L22_REG_SPEAKER_STATUS      0x31
#define   CS43L22_REG_TEMPMONITOR_CTL     0x32
#define   CS43L22_REG_THERMAL_FOLDBACK    0x33
#define   CS43L22_REG_CHARGE_PUMP_FREQ    0x34

#define AUDIO_I2C_ADDRESS                     0x94

/******************************************************************************/
/****************************** REGISTER MAPPING ******************************/
/******************************************************************************/
/** 
  * @brief  CS43L22 ID  
  */  
#define  CS43L22_ID            0xE0
#define  CS43L22_ID_MASK       0xF8
/**
  * @brief Chip ID Register: Chip I.D. and Revision Register
  *  Read only register
  *  Default value: 0x01
  *  [7:3] CHIPID[4:0]: I.D. code for the CS43L22.
  *        Default value: 11100b
  *  [2:0] REVID[2:0]: CS43L22 revision level.
  *        Default value: 
  *        000 - Rev A0
  *        001 - Rev A1
  *        010 - Rev B0
  *        011 - Rev B1
  */
#define CS43L22_CHIPID_ADDR    0x01


enum EN_BEEP_ON_TIME
{
    BEEP_ON_TM_ms86   = 0x0, //! 86 ms
    BEEP_ON_TM_ms430  = 0x1, //! 430 ms
    BEEP_ON_TM_ms780  = 0x2, //! 780 ms
    BEEP_ON_TM_ms1200 = 0x3, //! 1.20 s
    BEEP_ON_TM_ms1500 = 0x4, //! 1.50 s
    BEEP_ON_TM_ms1800 = 0x5, //! 1.80 s
    BEEP_ON_TM_ms2200 = 0x6, //! 2.20 s
    BEEP_ON_TM_ms2500 = 0x7, //! 2.50 s
    BEEP_ON_TM_ms2800 = 0x8, //! 2.80 s
    BEEP_ON_TM_ms3200 = 0x9, //! 3.20 s
    BEEP_ON_TM_ms3500 = 0xA, //! 3.50 s
    BEEP_ON_TM_ms3800 = 0xB, //! 3.80 s
    BEEP_ON_TM_ms4200 = 0xC, //! 4.20 s
    BEEP_ON_TM_ms4500 = 0xD, //! 4.50 s
    BEEP_ON_TM_ms4800 = 0xE, //! 4.80 s
    BEEP_ON_TM_ms5200 = 0xF, //! 5.20 s
};

enum EN_BEEP_FREQUENCY
{
    BEEP_FRQ_hz260  = 0x0,  //! 260.78 Hz
	BEEP_FRQ_hz521  = 0x10, //! 521.74 Hz
	BBEEP_FRQ_hz585 = 0x20, //! 585.37 Hz
	BEEP_FRQ_hz666  = 0x30, //! 666.67 Hz
    BEEP_FRQ_hz705  = 0x40, //! 705.88 Hz
    BEEP_FRQ_hz774  = 0x50, //! 774.19 Hz
    BEEP_FRQ_hz888  = 0x60, //! 888.89 Hz
    BEEP_FRQ_hz1000 = 0x70, //! 1000.00 Hz
    BEEP_FRQ_hz1043 = 0x80, //! 1043.48 Hz
    BEEP_FRQ_hz1200 = 0x90, //! 1200.00 Hz
    BEEP_FRQ_hz1333 = 0xA0, //! 1333.33 Hz
    BEEP_FRQ_hz1411 = 0xB0, //! 1411.76 Hz
    BEEP_FRQ_hz1600 = 0xC0, //! 1600.00 Hz
    BEEP_FRQ_hz1714 = 0xD0, //! 1714.29 Hz
    BEEP_FRQ_hz2000 = 0xE0, //! 2000.00 Hz
    BEEP_FRQ_hz2181 = 0xF0, //! 2181.82 Hz
};

enum EN_BEEP_OFF_TIME
{
    BEEP_OFF_TM_ms1230  = 0x0,  //! 1.23 s
    BEEP_OFF_TM_ms2580  = 0x20, //! 2.58 s
    BEEP_OFF_TM_ms3900  = 0x40, //! 3.90 s
    BEEP_OFF_TM_ms5200  = 0x60, //! 5.20 s
    BEEP_OFF_TM_ms6600  = 0x80, //! 6.60 s
    BEEP_OFF_TM_ms8050  = 0xA0, //! 8.05 s
    BEEP_OFF_TM_ms9350  = 0xC0, //! 9.35 s
    BEEP_OFF_TM_ms10800 = 0xE0, //! 10.80 s
};

enum EN_BEEP_MODE
{
	BEEP_MODE_OFF			= 0x00, //! close beep
    BEEP_MODE_SINGLE		= 0x40,	//! Play one beep
    BEEP_MODE_MULTIPLE		= 0x80,	//! Play beep for on_time, mute for off_time
    BEEP_MODE_CONTINUOUS	= 0xC0,	//! Play continuously
};


/**
  * @}
  */ 

/** @defgroup CS43L22_Exported_Macros
  * @{
  */

/**
  * @}
  */ 

/** @defgroup CS43L22_Exported_Functions
  * @{
  */
    
/*------------------------------------------------------------------------------
                           Audio Codec functions 
------------------------------------------------------------------------------*/
/* High Layer codec functions */
uint32_t cs43l22_Init(uint16_t DeviceAddr, uint16_t OutputDevice, uint8_t Volume, uint32_t AudioFreq);
void     cs43l22_DeInit(void);
uint32_t cs43l22_ReadID(uint16_t DeviceAddr);
uint32_t cs43l22_Play(uint16_t DeviceAddr, uint16_t* pBuffer, uint16_t Size);
uint32_t cs43l22_Pause(uint16_t DeviceAddr);
uint32_t cs43l22_Resume(uint16_t DeviceAddr);
uint32_t cs43l22_Stop(uint16_t DeviceAddr, uint32_t Cmd);
uint32_t cs43l22_SetVolume(uint16_t DeviceAddr, uint8_t Volume);
uint32_t cs43l22_SetFrequency(uint16_t DeviceAddr, uint32_t AudioFreq);
uint32_t cs43l22_SetMute(uint16_t DeviceAddr, uint32_t Cmd);
uint32_t cs43l22_SetOutputMode(uint16_t DeviceAddr, uint8_t Output);
uint32_t cs43l22_Reset(uint16_t DeviceAddr);


uint32_t cs43l22_setBeepConf(uint16_t DeviceAddr, enum EN_BEEP_FREQUENCY frq, enum EN_BEEP_ON_TIME onTime, enum EN_BEEP_OFF_TIME offTime);
uint32_t cs43l22_startStopBeep(uint16_t DeviceAddr, enum EN_BEEP_MODE mod);

/* AUDIO IO functions */
void      AUDIO_IO_Init(void);
void      AUDIO_IO_DeInit(void);
void      AUDIO_IO_Write(uint8_t Addr, uint8_t Reg, uint8_t Value);
uint8_t   AUDIO_IO_Read(uint8_t Addr, uint8_t Reg);

/* Audio driver structure */

#endif /* __CS43L22_H */

/**
  * @}
  */ 

/**
  * @}
  */ 

/**
  * @}
  */

/**
  * @}
  */
