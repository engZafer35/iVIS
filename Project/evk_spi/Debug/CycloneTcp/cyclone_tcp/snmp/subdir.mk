################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CycloneTcp/cyclone_tcp/snmp/snmp_agent.c \
../CycloneTcp/cyclone_tcp/snmp/snmp_agent_dispatch.c \
../CycloneTcp/cyclone_tcp/snmp/snmp_agent_inform.c \
../CycloneTcp/cyclone_tcp/snmp/snmp_agent_message.c \
../CycloneTcp/cyclone_tcp/snmp/snmp_agent_misc.c \
../CycloneTcp/cyclone_tcp/snmp/snmp_agent_object.c \
../CycloneTcp/cyclone_tcp/snmp/snmp_agent_pdu.c \
../CycloneTcp/cyclone_tcp/snmp/snmp_agent_trap.c \
../CycloneTcp/cyclone_tcp/snmp/snmp_agent_usm.c \
../CycloneTcp/cyclone_tcp/snmp/snmp_agent_vacm.c 

OBJS += \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent.o \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_dispatch.o \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_inform.o \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_message.o \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_misc.o \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_object.o \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_pdu.o \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_trap.o \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_usm.o \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_vacm.o 

C_DEPS += \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent.d \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_dispatch.d \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_inform.d \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_message.d \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_misc.d \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_object.d \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_pdu.d \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_trap.d \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_usm.d \
./CycloneTcp/cyclone_tcp/snmp/snmp_agent_vacm.d 


# Each subdirectory must supply rules for building sources it contributes
CycloneTcp/cyclone_tcp/snmp/%.o: ../CycloneTcp/cyclone_tcp/snmp/%.c CycloneTcp/cyclone_tcp/snmp/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DGPL_LICENSE_TERMS_ACCEPTED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/common" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/cyclone_tcp" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/STM32-CycloneTCP-ENC28J60-master" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

