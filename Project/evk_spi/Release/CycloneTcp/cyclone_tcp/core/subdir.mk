################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CycloneTcp/cyclone_tcp/core/bsd_socket.c \
../CycloneTcp/cyclone_tcp/core/ethernet.c \
../CycloneTcp/cyclone_tcp/core/ethernet_misc.c \
../CycloneTcp/cyclone_tcp/core/ip.c \
../CycloneTcp/cyclone_tcp/core/net.c \
../CycloneTcp/cyclone_tcp/core/net_mem.c \
../CycloneTcp/cyclone_tcp/core/net_misc.c \
../CycloneTcp/cyclone_tcp/core/nic.c \
../CycloneTcp/cyclone_tcp/core/ping.c \
../CycloneTcp/cyclone_tcp/core/raw_socket.c \
../CycloneTcp/cyclone_tcp/core/socket.c \
../CycloneTcp/cyclone_tcp/core/socket_misc.c \
../CycloneTcp/cyclone_tcp/core/tcp.c \
../CycloneTcp/cyclone_tcp/core/tcp_fsm.c \
../CycloneTcp/cyclone_tcp/core/tcp_misc.c \
../CycloneTcp/cyclone_tcp/core/tcp_timer.c \
../CycloneTcp/cyclone_tcp/core/udp.c 

OBJS += \
./CycloneTcp/cyclone_tcp/core/bsd_socket.o \
./CycloneTcp/cyclone_tcp/core/ethernet.o \
./CycloneTcp/cyclone_tcp/core/ethernet_misc.o \
./CycloneTcp/cyclone_tcp/core/ip.o \
./CycloneTcp/cyclone_tcp/core/net.o \
./CycloneTcp/cyclone_tcp/core/net_mem.o \
./CycloneTcp/cyclone_tcp/core/net_misc.o \
./CycloneTcp/cyclone_tcp/core/nic.o \
./CycloneTcp/cyclone_tcp/core/ping.o \
./CycloneTcp/cyclone_tcp/core/raw_socket.o \
./CycloneTcp/cyclone_tcp/core/socket.o \
./CycloneTcp/cyclone_tcp/core/socket_misc.o \
./CycloneTcp/cyclone_tcp/core/tcp.o \
./CycloneTcp/cyclone_tcp/core/tcp_fsm.o \
./CycloneTcp/cyclone_tcp/core/tcp_misc.o \
./CycloneTcp/cyclone_tcp/core/tcp_timer.o \
./CycloneTcp/cyclone_tcp/core/udp.o 

C_DEPS += \
./CycloneTcp/cyclone_tcp/core/bsd_socket.d \
./CycloneTcp/cyclone_tcp/core/ethernet.d \
./CycloneTcp/cyclone_tcp/core/ethernet_misc.d \
./CycloneTcp/cyclone_tcp/core/ip.d \
./CycloneTcp/cyclone_tcp/core/net.d \
./CycloneTcp/cyclone_tcp/core/net_mem.d \
./CycloneTcp/cyclone_tcp/core/net_misc.d \
./CycloneTcp/cyclone_tcp/core/nic.d \
./CycloneTcp/cyclone_tcp/core/ping.d \
./CycloneTcp/cyclone_tcp/core/raw_socket.d \
./CycloneTcp/cyclone_tcp/core/socket.d \
./CycloneTcp/cyclone_tcp/core/socket_misc.d \
./CycloneTcp/cyclone_tcp/core/tcp.d \
./CycloneTcp/cyclone_tcp/core/tcp_fsm.d \
./CycloneTcp/cyclone_tcp/core/tcp_misc.d \
./CycloneTcp/cyclone_tcp/core/tcp_timer.d \
./CycloneTcp/cyclone_tcp/core/udp.d 


# Each subdirectory must supply rules for building sources it contributes
CycloneTcp/cyclone_tcp/core/%.o: ../CycloneTcp/cyclone_tcp/core/%.c CycloneTcp/cyclone_tcp/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DGPL_LICENSE_TERMS_ACCEPTED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/common" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/cyclone_tcp" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/STM32-CycloneTCP-ENC28J60-master" -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

