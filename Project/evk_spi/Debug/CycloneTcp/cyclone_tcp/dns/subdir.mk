################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CycloneTcp/cyclone_tcp/dns/dns_cache.c \
../CycloneTcp/cyclone_tcp/dns/dns_client.c \
../CycloneTcp/cyclone_tcp/dns/dns_common.c \
../CycloneTcp/cyclone_tcp/dns/dns_debug.c 

OBJS += \
./CycloneTcp/cyclone_tcp/dns/dns_cache.o \
./CycloneTcp/cyclone_tcp/dns/dns_client.o \
./CycloneTcp/cyclone_tcp/dns/dns_common.o \
./CycloneTcp/cyclone_tcp/dns/dns_debug.o 

C_DEPS += \
./CycloneTcp/cyclone_tcp/dns/dns_cache.d \
./CycloneTcp/cyclone_tcp/dns/dns_client.d \
./CycloneTcp/cyclone_tcp/dns/dns_common.d \
./CycloneTcp/cyclone_tcp/dns/dns_debug.d 


# Each subdirectory must supply rules for building sources it contributes
CycloneTcp/cyclone_tcp/dns/%.o: ../CycloneTcp/cyclone_tcp/dns/%.c CycloneTcp/cyclone_tcp/dns/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DGPL_LICENSE_TERMS_ACCEPTED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/common" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/cyclone_tcp" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/STM32-CycloneTCP-ENC28J60-master" -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

