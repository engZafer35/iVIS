################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz8463_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz8563_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz8565_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz8567_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz8775_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz8794_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz8795_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz8863_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz8864_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz8873_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz8895_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz9477_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz9563_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz9893_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz9896_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/ksz9897_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/lan9303_driver.c \
../CycloneTcp/cyclone_tcp/drivers/switch/mv88e6060_driver.c 

OBJS += \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8463_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8563_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8565_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8567_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8775_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8794_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8795_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8863_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8864_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8873_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8895_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz9477_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz9563_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz9893_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz9896_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz9897_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/lan9303_driver.o \
./CycloneTcp/cyclone_tcp/drivers/switch/mv88e6060_driver.o 

C_DEPS += \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8463_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8563_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8565_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8567_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8775_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8794_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8795_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8863_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8864_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8873_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz8895_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz9477_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz9563_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz9893_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz9896_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/ksz9897_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/lan9303_driver.d \
./CycloneTcp/cyclone_tcp/drivers/switch/mv88e6060_driver.d 


# Each subdirectory must supply rules for building sources it contributes
CycloneTcp/cyclone_tcp/drivers/switch/%.o: ../CycloneTcp/cyclone_tcp/drivers/switch/%.c CycloneTcp/cyclone_tcp/drivers/switch/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DGPL_LICENSE_TERMS_ACCEPTED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/common" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/cyclone_tcp" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/STM32-CycloneTCP-ENC28J60-master" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

