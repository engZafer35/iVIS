################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CycloneTcp/cyclone_tcp/ppp/chap.c \
../CycloneTcp/cyclone_tcp/ppp/ipcp.c \
../CycloneTcp/cyclone_tcp/ppp/ipv6cp.c \
../CycloneTcp/cyclone_tcp/ppp/lcp.c \
../CycloneTcp/cyclone_tcp/ppp/pap.c \
../CycloneTcp/cyclone_tcp/ppp/ppp.c \
../CycloneTcp/cyclone_tcp/ppp/ppp_debug.c \
../CycloneTcp/cyclone_tcp/ppp/ppp_fsm.c \
../CycloneTcp/cyclone_tcp/ppp/ppp_hdlc.c \
../CycloneTcp/cyclone_tcp/ppp/ppp_misc.c 

OBJS += \
./CycloneTcp/cyclone_tcp/ppp/chap.o \
./CycloneTcp/cyclone_tcp/ppp/ipcp.o \
./CycloneTcp/cyclone_tcp/ppp/ipv6cp.o \
./CycloneTcp/cyclone_tcp/ppp/lcp.o \
./CycloneTcp/cyclone_tcp/ppp/pap.o \
./CycloneTcp/cyclone_tcp/ppp/ppp.o \
./CycloneTcp/cyclone_tcp/ppp/ppp_debug.o \
./CycloneTcp/cyclone_tcp/ppp/ppp_fsm.o \
./CycloneTcp/cyclone_tcp/ppp/ppp_hdlc.o \
./CycloneTcp/cyclone_tcp/ppp/ppp_misc.o 

C_DEPS += \
./CycloneTcp/cyclone_tcp/ppp/chap.d \
./CycloneTcp/cyclone_tcp/ppp/ipcp.d \
./CycloneTcp/cyclone_tcp/ppp/ipv6cp.d \
./CycloneTcp/cyclone_tcp/ppp/lcp.d \
./CycloneTcp/cyclone_tcp/ppp/pap.d \
./CycloneTcp/cyclone_tcp/ppp/ppp.d \
./CycloneTcp/cyclone_tcp/ppp/ppp_debug.d \
./CycloneTcp/cyclone_tcp/ppp/ppp_fsm.d \
./CycloneTcp/cyclone_tcp/ppp/ppp_hdlc.d \
./CycloneTcp/cyclone_tcp/ppp/ppp_misc.d 


# Each subdirectory must supply rules for building sources it contributes
CycloneTcp/cyclone_tcp/ppp/%.o: ../CycloneTcp/cyclone_tcp/ppp/%.c CycloneTcp/cyclone_tcp/ppp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DGPL_LICENSE_TERMS_ACCEPTED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/common" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/cyclone_tcp" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/STM32-CycloneTCP-ENC28J60-master" -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

