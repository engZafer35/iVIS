/**
 * @file ext_int.c
 * @brief External interrupt line driver
 *
 * @section License
 *
 * Copyright (C) 2010-2015 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneTCP Open.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 1.6.5
 **/

#include "ext_int_driver.h"

#include "gpio.h"
#include "enc28j60Config.h"
#include "../../CycloneTcp/common/debug.h"
#include "../../CycloneTcp/cyclone_tcp/core/net.h"
#include "../../CycloneTcp/cyclone_tcp/drivers/eth/enc28j60_driver.h"


/**
 * @brief External interrupt line driver
 **/

const ExtIntDriver extIntDriver =
{
   extIntInit,
   extIntEnableIrq,
   extIntDisableIrq
};


/**
 * @brief EXTI configuration
 * @return Error code
 **/

error_t extIntInit(void)
{
  
   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Enable external interrupts
 **/

void extIntEnableIrq(void)
{
   //Enable EXTI15_10 interrupt
   NVIC_EnableIRQ(_ENC28J60_EXT);
}


/**
 * @brief Disable external interrupts
 **/

void extIntDisableIrq(void)
{
   //Disable EXTI15_10 interrupt
   NVIC_DisableIRQ(_ENC28J60_EXT);
}


/**
 * @brief External interrupt handler
 **/

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  NetInterface *interface;
	if(GPIO_Pin == _ENC28J60_EXT_PIN)
	{
		interface = &netInterface[0];
		enc28j60IrqHandler(interface);
	}	
}
