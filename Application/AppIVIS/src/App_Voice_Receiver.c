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

/************* Connection Parameters ************/
//Ethernet interface configuration
#define APP_IF_NAME     "eth0"
#define APP_HOST_NAME   "iVIS-Master"
#define APP_MAC_ADDR    "02:03:04:05:06:07"

#define APP_IPV4_HOST_ADDR          "192.168.0.35"
#define APP_IPV4_SUBNET_MASK        "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY    "192.168.0.254"

#define UDP_BASE_PORT_NUM (2000)

/********** Voice Packet Parameters ************/
#define UDP_VOICE_PACKET_SIZE   (4096)
#define UDP_VOICE_PACKET_TIME   (100)   //ms


/******************************* TYPE DEFINITIONS *****************************/

struct ClientUdpSocket
{
    struct sockaddr_in serverAddr;
    U32  udpPortNum;
    S32  socketfd;
    BOOL isActive;
};

static struct ClientUdpSocket g_udpClients[MAX_CLIENT_NUMBER];

/********************************** VARIABLES *********************************/

/***************************** STATIC FUNCTIONS  ******************************/
/**
 * \brief   this function is called when time of waiting voice packet end.
 */
static void voiceTimeSlot(void)
{

}


//TODO: in order to copy received voice data to cycle buffer, dma should be used.


static RETURN_STATUS createUdpSockets(U32 clientNum)
{
    RETURN_STATUS retVal = SUCCESS;
    S32 socketfd;

    socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(socketfd < 0)
    {
        retVal = FAILURE;
        TRACE_ERROR("[E]-> Socket could not be created for %d client\n\r", clientNum);
    }

    if (SUCCESS == retVal)
    {
        g_udpClients[clientNum].serverAddr.sin_family        = AF_INET;
        g_udpClients[clientNum].serverAddr.sin_port          = htons(UDP_BASE_PORT_NUM + clientNum);
        g_udpClients[clientNum].serverAddr.sin_addr.s_addr   = inet_addr("192.168.0.88");

        // Bind the socket with the server address
        if (bind(socketfd, (const struct sockaddr *)&g_udpClients[clientNum].serverAddr, sizeof(struct sockaddr_in)) < 0 )
        {
            retVal = FAILURE;
        }
    }

    if (SUCCESS == retVal)
    {
        g_udpClients[clientNum].socketfd    = socketfd;
        g_udpClients[clientNum].udpPortNum  = UDP_BASE_PORT_NUM + clientNum;
        g_udpClients[clientNum].isActive    = TRUE;
        TRACE_DEBUG("[D]-> Socket created for %d client\n\r", clientNum);
    }

    return retVal;
}

static void closeUdpSocket(U32 clientNum)
{
    closesocket(g_udpClients[clientNum].socketfd);

    g_udpClients[clientNum].socketfd   = -1;
    g_udpClients[clientNum].udpPortNum = 0;
    g_udpClients[clientNum].isActive   = FALSE;
}

#include "core/ping.h"
static void vrTaskFunc(void const* argument)
{
    {
        U32 counterOK = 0;
        U32 i;
        for (i = 0; i < MAX_CLIENT_NUMBER; ++i)
        {
            if (SUCCESS == createUdpSockets(i))
            {
                counterOK++; //increase value for each created socket
            }
        }

        //handle error. now, I dont know what should I do.
    }

    //TODO: create broadcast or multicast UDP socket

    osDelayTask(500);

    while(1)
    {


        //todo: Give received all speech to voice creator to convert one voice signal.
        //todo: create a udp message which contains all speech.




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
