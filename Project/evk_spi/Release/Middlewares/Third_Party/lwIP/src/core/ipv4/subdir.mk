################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/lwIP/src/core/ipv4/autoip.c \
../Middlewares/Third_Party/lwIP/src/core/ipv4/icmp.c \
../Middlewares/Third_Party/lwIP/src/core/ipv4/igmp.c \
../Middlewares/Third_Party/lwIP/src/core/ipv4/inet.c \
../Middlewares/Third_Party/lwIP/src/core/ipv4/inet_chksum.c \
../Middlewares/Third_Party/lwIP/src/core/ipv4/ip.c \
../Middlewares/Third_Party/lwIP/src/core/ipv4/ip_addr.c \
../Middlewares/Third_Party/lwIP/src/core/ipv4/ip_frag.c 

OBJS += \
./Middlewares/Third_Party/lwIP/src/core/ipv4/autoip.o \
./Middlewares/Third_Party/lwIP/src/core/ipv4/icmp.o \
./Middlewares/Third_Party/lwIP/src/core/ipv4/igmp.o \
./Middlewares/Third_Party/lwIP/src/core/ipv4/inet.o \
./Middlewares/Third_Party/lwIP/src/core/ipv4/inet_chksum.o \
./Middlewares/Third_Party/lwIP/src/core/ipv4/ip.o \
./Middlewares/Third_Party/lwIP/src/core/ipv4/ip_addr.o \
./Middlewares/Third_Party/lwIP/src/core/ipv4/ip_frag.o 

C_DEPS += \
./Middlewares/Third_Party/lwIP/src/core/ipv4/autoip.d \
./Middlewares/Third_Party/lwIP/src/core/ipv4/icmp.d \
./Middlewares/Third_Party/lwIP/src/core/ipv4/igmp.d \
./Middlewares/Third_Party/lwIP/src/core/ipv4/inet.d \
./Middlewares/Third_Party/lwIP/src/core/ipv4/inet_chksum.d \
./Middlewares/Third_Party/lwIP/src/core/ipv4/ip.d \
./Middlewares/Third_Party/lwIP/src/core/ipv4/ip_addr.d \
./Middlewares/Third_Party/lwIP/src/core/ipv4/ip_frag.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/lwIP/src/core/ipv4/%.o: ../Middlewares/Third_Party/lwIP/src/core/ipv4/%.c Middlewares/Third_Party/lwIP/src/core/ipv4/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/lwIP/src/include -I../Middlewares/Third_Party/lwIP/system -I../Middlewares/Third_Party/lwIP/src/include/lwip -I../Middlewares/Third_Party/lwIP/src/include/netif -I../Middlewares/Third_Party/lwIP/src/include/posix -I../Middlewares/Third_Party/lwIP/src/include/posix/sys -I/evk_spi/Middlewares/Third_Party/lwIP/system/arch -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

