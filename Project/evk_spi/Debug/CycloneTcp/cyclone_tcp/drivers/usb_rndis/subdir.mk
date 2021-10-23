################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CycloneTcp/cyclone_tcp/drivers/usb_rndis/rndis.c \
../CycloneTcp/cyclone_tcp/drivers/usb_rndis/rndis_debug.c \
../CycloneTcp/cyclone_tcp/drivers/usb_rndis/rndis_driver.c \
../CycloneTcp/cyclone_tcp/drivers/usb_rndis/usbd_desc.c \
../CycloneTcp/cyclone_tcp/drivers/usb_rndis/usbd_rndis.c 

OBJS += \
./CycloneTcp/cyclone_tcp/drivers/usb_rndis/rndis.o \
./CycloneTcp/cyclone_tcp/drivers/usb_rndis/rndis_debug.o \
./CycloneTcp/cyclone_tcp/drivers/usb_rndis/rndis_driver.o \
./CycloneTcp/cyclone_tcp/drivers/usb_rndis/usbd_desc.o \
./CycloneTcp/cyclone_tcp/drivers/usb_rndis/usbd_rndis.o 

C_DEPS += \
./CycloneTcp/cyclone_tcp/drivers/usb_rndis/rndis.d \
./CycloneTcp/cyclone_tcp/drivers/usb_rndis/rndis_debug.d \
./CycloneTcp/cyclone_tcp/drivers/usb_rndis/rndis_driver.d \
./CycloneTcp/cyclone_tcp/drivers/usb_rndis/usbd_desc.d \
./CycloneTcp/cyclone_tcp/drivers/usb_rndis/usbd_rndis.d 


# Each subdirectory must supply rules for building sources it contributes
CycloneTcp/cyclone_tcp/drivers/usb_rndis/%.o: ../CycloneTcp/cyclone_tcp/drivers/usb_rndis/%.c CycloneTcp/cyclone_tcp/drivers/usb_rndis/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DGPL_LICENSE_TERMS_ACCEPTED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/common" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/cyclone_tcp" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/STM32-CycloneTCP-ENC28J60-master" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

