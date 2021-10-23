################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CycloneTcp/cyclone_tcp/drivers/wifi/bcm43362_driver.c \
../CycloneTcp/cyclone_tcp/drivers/wifi/esp32_wifi_driver.c \
../CycloneTcp/cyclone_tcp/drivers/wifi/esp8266_driver.c \
../CycloneTcp/cyclone_tcp/drivers/wifi/mrf24wg_driver.c \
../CycloneTcp/cyclone_tcp/drivers/wifi/wf200_driver.c \
../CycloneTcp/cyclone_tcp/drivers/wifi/wilc1000_driver.c \
../CycloneTcp/cyclone_tcp/drivers/wifi/winc1500_driver.c 

OBJS += \
./CycloneTcp/cyclone_tcp/drivers/wifi/bcm43362_driver.o \
./CycloneTcp/cyclone_tcp/drivers/wifi/esp32_wifi_driver.o \
./CycloneTcp/cyclone_tcp/drivers/wifi/esp8266_driver.o \
./CycloneTcp/cyclone_tcp/drivers/wifi/mrf24wg_driver.o \
./CycloneTcp/cyclone_tcp/drivers/wifi/wf200_driver.o \
./CycloneTcp/cyclone_tcp/drivers/wifi/wilc1000_driver.o \
./CycloneTcp/cyclone_tcp/drivers/wifi/winc1500_driver.o 

C_DEPS += \
./CycloneTcp/cyclone_tcp/drivers/wifi/bcm43362_driver.d \
./CycloneTcp/cyclone_tcp/drivers/wifi/esp32_wifi_driver.d \
./CycloneTcp/cyclone_tcp/drivers/wifi/esp8266_driver.d \
./CycloneTcp/cyclone_tcp/drivers/wifi/mrf24wg_driver.d \
./CycloneTcp/cyclone_tcp/drivers/wifi/wf200_driver.d \
./CycloneTcp/cyclone_tcp/drivers/wifi/wilc1000_driver.d \
./CycloneTcp/cyclone_tcp/drivers/wifi/winc1500_driver.d 


# Each subdirectory must supply rules for building sources it contributes
CycloneTcp/cyclone_tcp/drivers/wifi/%.o: ../CycloneTcp/cyclone_tcp/drivers/wifi/%.c CycloneTcp/cyclone_tcp/drivers/wifi/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DGPL_LICENSE_TERMS_ACCEPTED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/common" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/cyclone_tcp" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/STM32-CycloneTCP-ENC28J60-master" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

