################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CycloneTcp/cyclone_tcp/ipv4/arp.c \
../CycloneTcp/cyclone_tcp/ipv4/auto_ip.c \
../CycloneTcp/cyclone_tcp/ipv4/auto_ip_misc.c \
../CycloneTcp/cyclone_tcp/ipv4/icmp.c \
../CycloneTcp/cyclone_tcp/ipv4/ipv4.c \
../CycloneTcp/cyclone_tcp/ipv4/ipv4_frag.c \
../CycloneTcp/cyclone_tcp/ipv4/ipv4_misc.c 

OBJS += \
./CycloneTcp/cyclone_tcp/ipv4/arp.o \
./CycloneTcp/cyclone_tcp/ipv4/auto_ip.o \
./CycloneTcp/cyclone_tcp/ipv4/auto_ip_misc.o \
./CycloneTcp/cyclone_tcp/ipv4/icmp.o \
./CycloneTcp/cyclone_tcp/ipv4/ipv4.o \
./CycloneTcp/cyclone_tcp/ipv4/ipv4_frag.o \
./CycloneTcp/cyclone_tcp/ipv4/ipv4_misc.o 

C_DEPS += \
./CycloneTcp/cyclone_tcp/ipv4/arp.d \
./CycloneTcp/cyclone_tcp/ipv4/auto_ip.d \
./CycloneTcp/cyclone_tcp/ipv4/auto_ip_misc.d \
./CycloneTcp/cyclone_tcp/ipv4/icmp.d \
./CycloneTcp/cyclone_tcp/ipv4/ipv4.d \
./CycloneTcp/cyclone_tcp/ipv4/ipv4_frag.d \
./CycloneTcp/cyclone_tcp/ipv4/ipv4_misc.d 


# Each subdirectory must supply rules for building sources it contributes
CycloneTcp/cyclone_tcp/ipv4/%.o: ../CycloneTcp/cyclone_tcp/ipv4/%.c CycloneTcp/cyclone_tcp/ipv4/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DGPL_LICENSE_TERMS_ACCEPTED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/common" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/cyclone_tcp" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/STM32-CycloneTCP-ENC28J60-master" -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

