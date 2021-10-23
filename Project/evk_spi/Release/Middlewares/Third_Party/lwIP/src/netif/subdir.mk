################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/lwIP/src/netif/etharp.c \
../Middlewares/Third_Party/lwIP/src/netif/ethernetif.c \
../Middlewares/Third_Party/lwIP/src/netif/slipif.c 

OBJS += \
./Middlewares/Third_Party/lwIP/src/netif/etharp.o \
./Middlewares/Third_Party/lwIP/src/netif/ethernetif.o \
./Middlewares/Third_Party/lwIP/src/netif/slipif.o 

C_DEPS += \
./Middlewares/Third_Party/lwIP/src/netif/etharp.d \
./Middlewares/Third_Party/lwIP/src/netif/ethernetif.d \
./Middlewares/Third_Party/lwIP/src/netif/slipif.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/lwIP/src/netif/%.o: ../Middlewares/Third_Party/lwIP/src/netif/%.c Middlewares/Third_Party/lwIP/src/netif/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/lwIP/src/include -I../Middlewares/Third_Party/lwIP/system -I../Middlewares/Third_Party/lwIP/src/include/lwip -I../Middlewares/Third_Party/lwIP/src/include/netif -I../Middlewares/Third_Party/lwIP/src/include/posix -I../Middlewares/Third_Party/lwIP/src/include/posix/sys -I/evk_spi/Middlewares/Third_Party/lwIP/system/arch -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

