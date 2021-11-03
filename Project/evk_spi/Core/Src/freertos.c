/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "core/net.h"
#include "drivers/eth/enc28j60_driver.h"
#include "dhcp/dhcp_client.h"
#include "http/http_client.h"
#include "debug.h"
#include "spi_driver.h"
#include "ext_int_driver.h"
#include "core/bsd_socket.h"
#include "../../../CycloneTcp/cyclone_tcp/core/socket.h"

#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "https-client-demo"
#define APP_MAC_ADDR "02:AA:35:66:40:44"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.35"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"


#define APP_SET_CIPHER_SUITES   DISABLED
#define APP_SET_SERVER_NAME     ENABLED
#define APP_SET_TRUSTED_CA_LIST ENABLED
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
HttpClientContext httpClientContext;
/* USER CODE END Variables */
osThreadId defaultTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void secondTaskLoop(void const * argument);
void udpTaskLoop(void const * argument);
void thirdTaskLoop(void const * argument);

SemaphoreHandle_t xSemaphore = NULL;
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

    error_t error;
    NetInterface *interface;
    MacAddr macAddr;
    Ipv4Addr ipv4Addr;


       //TCP/IP stack initialization
    error = netInit();
    if(error)
    {
        HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, TRUE);
        //Debug message
//        TRACE_ERROR("Failed to initialize TCP/IP stack!\r\n");
    }

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
       //Debug message
        HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, TRUE);
//       TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
    }

   //Set IPv4 host address
   ipv4StringToAddr(APP_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
//   ipv4StringToAddr(APP_IPV4_PRIMARY_DNS, &ipv4Addr);
//   ipv4SetDnsServer(interface, 0, ipv4Addr);
//   ipv4StringToAddr(APP_IPV4_SECONDARY_DNS, &ipv4Addr);
//   ipv4SetDnsServer(interface, 1, ipv4Addr);

//   HAL_Delay(10000);

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
//  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 512);
//  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */

//  osThreadDef(secondTask, secondTaskLoop, osPriorityNormal, 0, 512);
//  defaultTaskHandle = osThreadCreate(osThread(secondTask), NULL);
//
//  osThreadDef(udpTask, udpTaskLoop, osPriorityNormal, 0, 512);
//  defaultTaskHandle = osThreadCreate(osThread(udpTask), NULL);
//
//   HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, TRUE);
//
//  osThreadDef(thirdTask, thirdTaskLoop, osPriorityNormal, 0, 512);
//  defaultTaskHandle = osThreadCreate(osThread(thirdTask), NULL);

  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */

    int socket_desc;
    struct sockaddr_in server_addr;
    char server_message[100] = "";
    char client_message[100] = "zafer";
    int i = 0;

    osDelayTask(500);

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_desc < 0){
        return ;
    }

    // Set port and IP the same as server-side:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2005);
    server_addr.sin_addr.s_addr = inet_addr("192.168.0.88");

    // Send connection request to server:
    if(connect(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
    {
        HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
    }
    printf("Connected with server successfully\n");

  for(;;)
  {
      sprintf(client_message, "--> Client STM Msg %d", i++);
      if(send(socket_desc, client_message, strlen(client_message), 0) < 0)
      {
          HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, TRUE);
      }

//      // Receive the server's response:
//      if(recv(socket_desc, server_message, sizeof(server_message), 0) < 0)
//      {
//          HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, TRUE);
//      }

      HAL_GPIO_TogglePin(LED_4_GPIO_Port, LED_4_Pin);
      osDelayTask(500);
  }

  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Application */
void udpTaskLoop(void const * argument)
{
    int socket_desc;
    struct sockaddr_in server_addr;
    char server_message[32] = "", client_message[32] = "";
    int server_struct_length = sizeof(server_addr);
    int i = 0;

    osDelayTask(500);

    // Clean buffers:
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    // Create socket:
    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if(socket_desc < 0)
    {
        printf("Error while creating socket\n");
        HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);

    }

    // Set port and IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2001);
    server_addr.sin_addr.s_addr = inet_addr("192.168.0.88");

    while(1)
    {
        sprintf(client_message, "--> Client UDP STM Msg %d ", i++);
        // Send the message to server:
        if(sendto(socket_desc, client_message, strlen(client_message), 0, \
           (struct sockaddr*)&server_addr, server_struct_length) < 0)
        {
            HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
        }

//        // Receive the server's response:
//        if(recvfrom(socket_desc, server_message, sizeof(server_message), 0,
//            (struct sockaddr*)&server_addr, &server_struct_length) < 0)
//        {
//            HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
//        }

        HAL_GPIO_TogglePin(LED_4_GPIO_Port, LED_4_Pin);
        osDelayTask(500);
    }
}


/* ... Do other things. */
void secondTaskLoop(void const * argument)
{
    int socket_desc, client_sock, client_size;
    struct sockaddr_in server_addr, client_addr;
    char server_message[32] = "", client_message[32] = "1";
    int i;

    osDelayTask(600);

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if(socket_desc < 0)
    {
        printf("Error while creating socket\n");
    }

    // Set port and IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("192.168.0.35");

    // Bind to the set port and IP:
    if(bind(socket_desc, (struct sockaddr*)&server_addr, sizeof(server_addr))<0){
        printf("Couldn't bind to the port\n");
    }

    // Listen for clients:
    if(listen(socket_desc, 1) < 0){
        printf("Error while listening\n");
    }

    // Accept an incoming connection:
    client_size = sizeof(client_addr);
    client_sock = accept(socket_desc, (struct sockaddr*)&client_addr, &client_size);

    printf("Client connected at IP: %s and port: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while(1)
    {
        sprintf(server_message, "--> Server STM Msg %d ", i++);
        if (send(client_sock, server_message, strlen(server_message), 0) < 0)
        {
            HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, TRUE);
        }

//        if (recv(client_sock, client_message, sizeof(client_message), 0) < 0)
//        {
//            HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, TRUE);
//        }

        HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);

        osDelayTask(500);
    }

    // Closing the socket:
    close(client_sock);
    close(socket_desc);
}

#include "core/ping.h"
void thirdTaskLoop(void const * argument)
{
    error_t err = ERROR_FAILURE;
    IpAddr ip;

    osDelayTask(500);

    ip.length = sizeof(Ipv4Addr);
    ip.ipv4Addr  = IPV4_ADDR(192,168, 0, 88);

    while(1)
    {
        err = ping(&netInterface[0], &ip, 32, 0xFF, 500, NULL);

        HAL_GPIO_TogglePin(LED_3_GPIO_Port, LED_3_Pin);
        osDelay(1000);
    }
}

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
