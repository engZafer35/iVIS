/**
 * @file llmnr_common.c
 * @brief Definitions common to LLMNR client and responder
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2021 Oryx Embedded SARL. All rights reserved.
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
 * @version 2.1.0
 **/

//Switch to the appropriate trace level
#define TRACE_LEVEL LLMNR_TRACE_LEVEL

//Dependencies
#include "../../../CycloneTcp/cyclone_tcp/core/net.h"
#include "../../../CycloneTcp/cyclone_tcp/llmnr/llmnr_client.h"
#include "../../../CycloneTcp/cyclone_tcp/llmnr/llmnr_responder.h"
#include "../../../CycloneTcp/cyclone_tcp/llmnr/llmnr_common.h"
#include "../../../CycloneTcp/common/debug.h"

//Check TCP/IP stack configuration
#if (LLMNR_CLIENT_SUPPORT == ENABLED || LLMNR_RESPONDER_SUPPORT == ENABLED)

//LLMNR IPv6 multicast group (ff02::1:3)
const Ipv6Addr LLMNR_IPV6_MULTICAST_ADDR =
   IPV6_ADDR(0xFF02, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0001, 0x0003);

#endif
