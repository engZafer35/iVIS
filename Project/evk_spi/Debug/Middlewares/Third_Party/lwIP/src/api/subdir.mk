################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/lwIP/src/api/api_lib.c \
../Middlewares/Third_Party/lwIP/src/api/api_msg.c \
../Middlewares/Third_Party/lwIP/src/api/err.c \
../Middlewares/Third_Party/lwIP/src/api/netbuf.c \
../Middlewares/Third_Party/lwIP/src/api/netdb.c \
../Middlewares/Third_Party/lwIP/src/api/netifapi.c \
../Middlewares/Third_Party/lwIP/src/api/sockets.c \
../Middlewares/Third_Party/lwIP/src/api/tcpip.c 

OBJS += \
./Middlewares/Third_Party/lwIP/src/api/api_lib.o \
./Middlewares/Third_Party/lwIP/src/api/api_msg.o \
./Middlewares/Third_Party/lwIP/src/api/err.o \
./Middlewares/Third_Party/lwIP/src/api/netbuf.o \
./Middlewares/Third_Party/lwIP/src/api/netdb.o \
./Middlewares/Third_Party/lwIP/src/api/netifapi.o \
./Middlewares/Third_Party/lwIP/src/api/sockets.o \
./Middlewares/Third_Party/lwIP/src/api/tcpip.o 

C_DEPS += \
./Middlewares/Third_Party/lwIP/src/api/api_lib.d \
./Middlewares/Third_Party/lwIP/src/api/api_msg.d \
./Middlewares/Third_Party/lwIP/src/api/err.d \
./Middlewares/Third_Party/lwIP/src/api/netbuf.d \
./Middlewares/Third_Party/lwIP/src/api/netdb.d \
./Middlewares/Third_Party/lwIP/src/api/netifapi.d \
./Middlewares/Third_Party/lwIP/src/api/sockets.d \
./Middlewares/Third_Party/lwIP/src/api/tcpip.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/lwIP/src/api/%.o: ../Middlewares/Third_Party/lwIP/src/api/%.c Middlewares/Third_Party/lwIP/src/api/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/lwIP/src/include -I../Middlewares/Third_Party/lwIP/system -I../Middlewares/Third_Party/lwIP/src/include/lwip -I../Middlewares/Third_Party/lwIP/src/include/netif -I../Middlewares/Third_Party/lwIP/src/include/posix -I../Middlewares/Third_Party/lwIP/src/include/posix/sys -I/evk_spi/Middlewares/Third_Party/lwIP/system/arch -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

