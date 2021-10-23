################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CycloneTcp/cyclone_tcp/ipv6/icmpv6.c \
../CycloneTcp/cyclone_tcp/ipv6/ipv6.c \
../CycloneTcp/cyclone_tcp/ipv6/ipv6_frag.c \
../CycloneTcp/cyclone_tcp/ipv6/ipv6_misc.c \
../CycloneTcp/cyclone_tcp/ipv6/ipv6_pmtu.c \
../CycloneTcp/cyclone_tcp/ipv6/ipv6_routing.c \
../CycloneTcp/cyclone_tcp/ipv6/mld.c \
../CycloneTcp/cyclone_tcp/ipv6/ndp.c \
../CycloneTcp/cyclone_tcp/ipv6/ndp_cache.c \
../CycloneTcp/cyclone_tcp/ipv6/ndp_misc.c \
../CycloneTcp/cyclone_tcp/ipv6/ndp_router_adv.c \
../CycloneTcp/cyclone_tcp/ipv6/ndp_router_adv_misc.c \
../CycloneTcp/cyclone_tcp/ipv6/slaac.c \
../CycloneTcp/cyclone_tcp/ipv6/slaac_misc.c 

OBJS += \
./CycloneTcp/cyclone_tcp/ipv6/icmpv6.o \
./CycloneTcp/cyclone_tcp/ipv6/ipv6.o \
./CycloneTcp/cyclone_tcp/ipv6/ipv6_frag.o \
./CycloneTcp/cyclone_tcp/ipv6/ipv6_misc.o \
./CycloneTcp/cyclone_tcp/ipv6/ipv6_pmtu.o \
./CycloneTcp/cyclone_tcp/ipv6/ipv6_routing.o \
./CycloneTcp/cyclone_tcp/ipv6/mld.o \
./CycloneTcp/cyclone_tcp/ipv6/ndp.o \
./CycloneTcp/cyclone_tcp/ipv6/ndp_cache.o \
./CycloneTcp/cyclone_tcp/ipv6/ndp_misc.o \
./CycloneTcp/cyclone_tcp/ipv6/ndp_router_adv.o \
./CycloneTcp/cyclone_tcp/ipv6/ndp_router_adv_misc.o \
./CycloneTcp/cyclone_tcp/ipv6/slaac.o \
./CycloneTcp/cyclone_tcp/ipv6/slaac_misc.o 

C_DEPS += \
./CycloneTcp/cyclone_tcp/ipv6/icmpv6.d \
./CycloneTcp/cyclone_tcp/ipv6/ipv6.d \
./CycloneTcp/cyclone_tcp/ipv6/ipv6_frag.d \
./CycloneTcp/cyclone_tcp/ipv6/ipv6_misc.d \
./CycloneTcp/cyclone_tcp/ipv6/ipv6_pmtu.d \
./CycloneTcp/cyclone_tcp/ipv6/ipv6_routing.d \
./CycloneTcp/cyclone_tcp/ipv6/mld.d \
./CycloneTcp/cyclone_tcp/ipv6/ndp.d \
./CycloneTcp/cyclone_tcp/ipv6/ndp_cache.d \
./CycloneTcp/cyclone_tcp/ipv6/ndp_misc.d \
./CycloneTcp/cyclone_tcp/ipv6/ndp_router_adv.d \
./CycloneTcp/cyclone_tcp/ipv6/ndp_router_adv_misc.d \
./CycloneTcp/cyclone_tcp/ipv6/slaac.d \
./CycloneTcp/cyclone_tcp/ipv6/slaac_misc.d 


# Each subdirectory must supply rules for building sources it contributes
CycloneTcp/cyclone_tcp/ipv6/%.o: ../CycloneTcp/cyclone_tcp/ipv6/%.c CycloneTcp/cyclone_tcp/ipv6/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DGPL_LICENSE_TERMS_ACCEPTED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/common" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/cyclone_tcp" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/STM32-CycloneTCP-ENC28J60-master" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

