################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CycloneTcp/common/cpu_endian.c \
../CycloneTcp/common/date_time.c \
../CycloneTcp/common/debug.c \
../CycloneTcp/common/os_port_freertos.c \
../CycloneTcp/common/path.c \
../CycloneTcp/common/str.c 

OBJS += \
./CycloneTcp/common/cpu_endian.o \
./CycloneTcp/common/date_time.o \
./CycloneTcp/common/debug.o \
./CycloneTcp/common/os_port_freertos.o \
./CycloneTcp/common/path.o \
./CycloneTcp/common/str.o 

C_DEPS += \
./CycloneTcp/common/cpu_endian.d \
./CycloneTcp/common/date_time.d \
./CycloneTcp/common/debug.d \
./CycloneTcp/common/os_port_freertos.d \
./CycloneTcp/common/path.d \
./CycloneTcp/common/str.d 


# Each subdirectory must supply rules for building sources it contributes
CycloneTcp/common/%.o: ../CycloneTcp/common/%.c CycloneTcp/common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -DGPL_LICENSE_TERMS_ACCEPTED -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/common" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/CycloneTcp/cyclone_tcp" -I"/home/CORP.AIRTIES.COM/zafer.satilmis/STM32CubeIDE/workspace_1.7.0/evk_spi/STM32-CycloneTCP-ENC28J60-master" -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

