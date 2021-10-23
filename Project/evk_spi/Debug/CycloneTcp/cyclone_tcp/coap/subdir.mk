################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CycloneTcp/cyclone_tcp/coap/coap_client.c \
../CycloneTcp/cyclone_tcp/coap/coap_client_block.c \
../CycloneTcp/cyclone_tcp/coap/coap_client_misc.c \
../CycloneTcp/cyclone_tcp/coap/coap_client_observe.c \
../CycloneTcp/cyclone_tcp/coap/coap_client_request.c \
../CycloneTcp/cyclone_tcp/coap/coap_client_transport.c \
../CycloneTcp/cyclone_tcp/coap/coap_debug.c \
../CycloneTcp/cyclone_tcp/coap/coap_message.c \
../CycloneTcp/cyclone_tcp/coap/coap_option.c \
../CycloneTcp/cyclone_tcp/coap/coap_server.c \
../CycloneTcp/cyclone_tcp/coap/coap_server_misc.c \
../CycloneTcp/cyclone_tcp/coap/coap_server_request.c \
../CycloneTcp/cyclone_tcp/coap/coap_server_transport.c 

OBJS += \
./CycloneTcp/cyclone_tcp/coap/coap_client.o \
./CycloneTcp/cyclone_tcp/coap/coap_client_block.o \
./CycloneTcp/cyclone_tcp/coap/coap_client_misc.o \
./CycloneTcp/cyclone_tcp/coap/coap_client_observe.o \
./CycloneTcp/cyclone_tcp/coap/coap_client_request.o \
./CycloneTcp/cyclone_tcp/coap/coap_client_transport.o \
./CycloneTcp/cyclone_tcp/coap/coap_debug.o \
./CycloneTcp/cyclone_tcp/coap/coap_message.o \
./CycloneTcp/cyclone_tcp/coap/coap_option.o \
./CycloneTcp/cyclone_tcp/coap/coap_server.o \
./CycloneTcp/cyclone_tcp/coap/coap_server_misc.o \
./CycloneTcp/cyclone_tcp/coap/coap_server_request.o \
./CycloneTcp/cyclone_tcp/coap/coap_server_transport.o 

C_DEPS += \
./CycloneTcp/cyclone_tcp/coap/coap_client.d \
./CycloneTcp/cyclone_tcp/coap/coap_client_block.d \
./CycloneTcp/cyclone_tcp/coap/coap_client_misc.d \
./CycloneTcp/cyclone_tcp/coap/coap_client_observe.d \
./CycloneTcp/cyclone_tcp/coap/coap_client_request.d \
./CycloneTcp/cyclone_tcp/coap/coap_client_transport.d \
./CycloneTcp/cyclone_tcp/coap/coap_debug.d \
./CycloneTcp/cyclone_tcp/coap/coap_message.d \
./CycloneTcp/cyclone_tcp/coap/coap_option.d \
./CycloneTcp/cyclone_tcp/coap/coap_server.d \
./CycloneTcp/cyclone_tcp/coap/coap_server_misc.d \
./CycloneTcp/cyclone_tcp/coap/coap_server_request.d \
./CycloneTcp/cyclone_tcp/coap/coap_server_transport.d 


# Each subdirectory must supply rules for building sources it contributes
CycloneTcp/cyclone_tcp/coap/%.o: ../CycloneTcp/cyclone_tcp/coap/%.c CycloneTcp/cyclone_tcp/coap/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DGPL_LICENSE_TERMS_ACCEPTED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/common" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/cyclone_tcp" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/STM32-CycloneTCP-ENC28J60-master" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

