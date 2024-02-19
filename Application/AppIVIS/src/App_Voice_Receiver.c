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
#include "App_Voice_Creator.h"
#include "App_Global_Variables.h"

#include "core/net.h"
#include "drivers/eth/enc28j60_driver.h"
#include "dhcp/dhcp_client.h"
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

#define APP_IPV4_HOST_ADDR          "192.168.1.35"
#define APP_IPV4_SUBNET_MASK        "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY    "192.168.1.254"

#define UDP_SERVER_PORT_NUM (2000)


/********** Timer Macro ************/
#define LAST_PACKET_TIME    (100)//ms

/******************************* TYPE DEFINITIONS *****************************/

/********************************** VARIABLES *********************************/

static S32 g_UdpSocketFd;

static SemaphoreHandle_t mutexRcv;

osTimerId g_timerIDLastPacket;
static volatile BOOL g_IsTimerActive = FALSE;

static in_addr_t clientIPAddr[MAX_CLIENT_NUMBER];
/***************************** STATIC FUNCTIONS  ******************************/

/** Time has elapsed for all clients to send audio data */
static void lastVoicePacketTimerCb(const void *param)
{
    xSemaphoreTake(mutexRcv, portMAX_DELAY);

    appVoCreatAllClientVoiceReceived(); //all client voice received, inform voiceCreator unit
    g_IsTimerActive = FALSE;

    xSemaphoreGive(mutexRcv);
}

static RETURN_STATUS createUdpSockets(void)
{
    RETURN_STATUS retVal = SUCCESS;
    struct sockaddr_in serverAddr;

    g_UdpSocketFd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(g_UdpSocketFd >= 0)
    {
        serverAddr.sin_family        = AF_INET;
        serverAddr.sin_port          = htons(UDP_SERVER_PORT_NUM);
        serverAddr.sin_addr.s_addr   = inet_addr(APP_IPV4_HOST_ADDR);

        // Bind the socket with the server address
        if (bind(g_UdpSocketFd, (const struct sockaddr *)&serverAddr, sizeof(struct sockaddr_in)) < 0 )
        {
            retVal = FAILURE;
        }

        if (SUCCESS == retVal)
        {
            DEBUG_INFO("[I]-> UDP Server created !!!");
            DEBUG_INFO("[I]-> UDP Server IP: %s", APP_IPV4_HOST_ADDR);
            DEBUG_INFO("[I]-> UDP Server Port: %d", UDP_SERVER_PORT_NUM);
        }
    }
    else
    {
        retVal = FAILURE;
        DEBUG_ERROR("[E]-> UDP Socket could not be created");
    }

    return retVal;
}

static void closeUdpSocket(U32 clientNum)
{
    closesocket(g_UdpSocketFd);
    g_UdpSocketFd = -1;
}

static void vrTaskFunc(void const* argument)
{
    my_fd_set fdSet;
    U32 cliCounter;

    struct sockaddr_in clientAddr;
    int server_struct_length = sizeof(clientAddr);

    U8 cliVoice[UDP_VOICE_PACKET_SIZE];

    osDelayTask(1000); //wait until net stack is ready, netTaskRunning can be used instead of sleep

    createUdpSockets();

    FD_ZERO(&fdSet);
    FD_SET(g_UdpSocketFd, &fdSet);

    while(1)
    {
        bsd_select(FD_SETSIZE, &fdSet, NULL, NULL, NULL);

        middIOToggle(EN_OUT_JOB_LED);

        // Receive the server's response:
        if(recvfrom(g_UdpSocketFd, cliVoice, sizeof(cliVoice), 0,  \
           (struct sockaddr*)&clientAddr, &server_struct_length) > 0)
        {
            /*
             * lastVoicePacketTimerCb might be running, if so, we can lose a voice packet because isTimerActive = TRUE,
             * it should be set to FALSE again to set timer when the first voice packet is received.
             */
            xSemaphoreTake(mutexRcv, portMAX_DELAY);

            for (cliCounter = 0; cliCounter < MAX_CLIENT_NUMBER; ++cliCounter)
            {
                if (clientIPAddr[cliCounter] == clientAddr.sin_addr.s_addr) //find client number = z
                {
                    int c = cliVoice[0]-48; //for test
                    appVoCreatAddVoice(cliVoice, c /*cliCounter*/);

                    if (FALSE == g_IsTimerActive)
                    {
                        osTimerStart(g_timerIDLastPacket, LAST_PACKET_TIME);
                        g_IsTimerActive = TRUE;
                    }
                    break;
                }
            }

            xSemaphoreGive(mutexRcv);
        }
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
        DEBUG_ERROR("Failed to initialize TCP/IP stack!\r\n");
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
            DEBUG_ERROR("Failed to configure interface %s!\r\n", interface->name);
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

    clientIPAddr[0] = inet_addr("192.168.1.88"); //TODO: set automatically

    if (SUCCESS == retVal)
    {
        osTimerDef(timerLastPacket, lastVoicePacketTimerCb);
        g_timerIDLastPacket = osTimerCreate (osTimer(timerLastPacket), osTimerOnce, NULL);
    }

    mutexRcv = xSemaphoreCreateMutex();

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
