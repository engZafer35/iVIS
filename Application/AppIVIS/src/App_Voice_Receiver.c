/******************************************************************************
* #Author       : zafer.satilmis
* #Revision     : 1.0
* #Date         : Nov 3, 2021 - 11:40:57 PM
* #File Name    : App_Voice_Receiver.c
*******************************************************************************/
/******************************************************************************
*
*
*******************************************************************************/
#define SHOW_PAGE_DBG_MSG  (DISABLE)
/********************************* INCLUDES ***********************************/
#include "App_Voice_Receiver.h"

#include "core/net.h"
#include "drivers/eth/enc28j60_driver.h"
#include "dhcp/dhcp_client.h"
#include "http/http_client.h"
#include "debug.h"
#include "spi_driver.h"
#include "ext_int_driver.h"
#include "core/bsd_socket.h"
#include "../../../CycloneTcp/cyclone_tcp/core/socket.h"


#include "MiddDigitalIOControl.h"
/****************************** MACRO DEFINITIONS *****************************/
//Ethernet interface configuration
#define APP_IF_NAME     "eth0"
#define APP_HOST_NAME   "iVIS-Master"
#define APP_MAC_ADDR    "02:03:04:05:06:07"

#define APP_IPV4_HOST_ADDR          "192.168.0.35"
#define APP_IPV4_SUBNET_MASK        "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY    "192.168.0.254"
/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/
#include "core/ping.h"
static void vrTaskFunc(void const* argument)
{
    //TODO: creat socket

    error_t err = ERROR_FAILURE;
    IpAddr ip;

    osDelayTask(500);

    ip.length = sizeof(Ipv4Addr);
    ip.ipv4Addr  = IPV4_ADDR(192,168, 0, 88);

    while(1)
    {
        err = ping(&netInterface[0], &ip, 32, 0xFF, 500, NULL);

        middIOToggle(EN_OUT_ERR_LED);

        osDelay(1000);
    }
}
/***************************** PUBLIC FUNCTIONS  ******************************/
RETURN_STATUS appVoiceRecInit(void)
{
    RETURN_STATUS retVal = SUCCESS;
    error_t error;
    NetInterface *interface;
    MacAddr macAddr;
    Ipv4Addr ipv4Addr;

    //TCP/IP stack initialization
    error = netInit();
    if(error)
    {
        middIOWrite(EN_OUT_ERR_LED, TRUE);
        TRACE_ERROR("Failed to initialize TCP/IP stack!\r\n");
        retVal = FAILURE;
    }

    if (SUCCESS == retVal)
    {
        interface = &netInterface[0];

        //Set interface name
        netSetInterfaceName(interface, APP_IF_NAME);
        //Set host name
        netSetHostname(interface, APP_HOST_NAME);
        //Set host MAC address
        macStringToAddr(APP_MAC_ADDR, &macAddr);
        netSetMacAddr(interface, &macAddr);
        //Select the relevant network adapter

        netSetDriver(interface, &enc28j60Driver);
        netSetSpiDriver(interface, &spiDriver);
        netSetExtIntDriver(interface, &extIntDriver);

        //Initialize network interface
        error = netConfigInterface(interface);
        //Any error to report?
        if(error)
        {
            middIOWrite(EN_OUT_ERR_LED, TRUE);
            TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
            retVal = FAILURE;
        }

        if (SUCCESS == retVal)
        {
            //Set IPv4 host address
            ipv4StringToAddr(APP_IPV4_HOST_ADDR, &ipv4Addr);
            ipv4SetHostAddr(interface, ipv4Addr);

            //Set subnet mask
            ipv4StringToAddr(APP_IPV4_SUBNET_MASK, &ipv4Addr);
            ipv4SetSubnetMask(interface, ipv4Addr);

            //Set default gateway
            ipv4StringToAddr(APP_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
            ipv4SetDefaultGateway(interface, ipv4Addr);
        }
    }

    return retVal;
}


RETURN_STATUS appVoiceRecSuspendClient(U32 clinetNum, BOOL stat)
{
    RETURN_STATUS retVal = SUCCESS;

    return retVal;
}

RETURN_STATUS appVoiceRecMuteClient(U32 clinetNum, BOOL stat)
{
    RETURN_STATUS retVal = SUCCESS;

    return retVal;
}

RETURN_STATUS appVoiceRecMuteAllClient(U32 clinetNum, BOOL stat)
{
    RETURN_STATUS retVal = SUCCESS;

    return retVal;
}

TaskFunc_t appVoiceRecGetTaskFunc(void)
{
    return vrTaskFunc;
}
/******************************** End Of File *********************************/
