/**
 * @file nbns_responder.h
 * @brief NBNS responder (NetBIOS Name Service)
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

#ifndef _NBNS_RESPONDER_H
#define _NBNS_RESPONDER_H

//Dependencies
#include "../../../CycloneTcp/cyclone_tcp/core/net.h"
#include "../../../CycloneTcp/cyclone_tcp/core/udp.h"
#include "../../../CycloneTcp/cyclone_tcp/dns/dns_common.h"
#include "../../../CycloneTcp/cyclone_tcp/netbios/nbns_common.h"

//NBNS responder support
#ifndef NBNS_RESPONDER_SUPPORT
   #define NBNS_RESPONDER_SUPPORT ENABLED
#elif (NBNS_RESPONDER_SUPPORT != ENABLED && NBNS_RESPONDER_SUPPORT != DISABLED)
   #error NBNS_RESPONDER_SUPPORT parameter is not valid
#endif

//C++ guard
#ifdef __cplusplus
extern "C" {
#endif

//NBNS related functions
void nbnsProcessQuery(NetInterface *interface, const Ipv4PseudoHeader *pseudoHeader,
   const UdpHeader *udpHeader, const NbnsHeader *message, size_t length);

error_t nbnsSendResponse(NetInterface *interface,
   const IpAddr *destIpAddr, uint16_t destPort, uint16_t id);

//C++ guard
#ifdef __cplusplus
}
#endif

#endif
