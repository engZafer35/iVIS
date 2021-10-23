################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CycloneTcp/cyclone_tcp/http/http_client.c \
../CycloneTcp/cyclone_tcp/http/http_client_auth.c \
../CycloneTcp/cyclone_tcp/http/http_client_misc.c \
../CycloneTcp/cyclone_tcp/http/http_client_transport.c \
../CycloneTcp/cyclone_tcp/http/http_common.c \
../CycloneTcp/cyclone_tcp/http/mime.c 

OBJS += \
./CycloneTcp/cyclone_tcp/http/http_client.o \
./CycloneTcp/cyclone_tcp/http/http_client_auth.o \
./CycloneTcp/cyclone_tcp/http/http_client_misc.o \
./CycloneTcp/cyclone_tcp/http/http_client_transport.o \
./CycloneTcp/cyclone_tcp/http/http_common.o \
./CycloneTcp/cyclone_tcp/http/mime.o 

C_DEPS += \
./CycloneTcp/cyclone_tcp/http/http_client.d \
./CycloneTcp/cyclone_tcp/http/http_client_auth.d \
./CycloneTcp/cyclone_tcp/http/http_client_misc.d \
./CycloneTcp/cyclone_tcp/http/http_client_transport.d \
./CycloneTcp/cyclone_tcp/http/http_common.d \
./CycloneTcp/cyclone_tcp/http/mime.d 


# Each subdirectory must supply rules for building sources it contributes
CycloneTcp/cyclone_tcp/http/%.o: ../CycloneTcp/cyclone_tcp/http/%.c CycloneTcp/cyclone_tcp/http/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DGPL_LICENSE_TERMS_ACCEPTED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/common" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/cyclone_tcp" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/STM32-CycloneTCP-ENC28J60-master" -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

