################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/STM32N657X0_Q/ThreadX_Projects/LED_TEST_H7/led_h7/Middlewares/ST/netxduo/addons/auto_ip/nx_auto_ip.c 

OBJS += \
./Middlewares/NetXDuo/Network/NetXDuo/Addons\ AutoIP/nx_auto_ip.o 

C_DEPS += \
./Middlewares/NetXDuo/Network/NetXDuo/Addons\ AutoIP/nx_auto_ip.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/NetXDuo/Network/NetXDuo/Addons\ AutoIP/nx_auto_ip.o: E:/STM32N657X0_Q/ThreadX_Projects/LED_TEST_H7/led_h7/Middlewares/ST/netxduo/addons/auto_ip/nx_auto_ip.c Middlewares/NetXDuo/Network/NetXDuo/Addons\ AutoIP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DCORE_CM7 -DUSE_HAL_DRIVER -DSTM32H745xx -DUSE_PWR_DIRECT_SMPS_SUPPLY -DTX_INCLUDE_USER_DEFINE_FILE -DNX_INCLUDE_USER_DEFINE_FILE -c -I../Core/Inc -I../AZURE_RTOS/App -I../../Middlewares/ST/threadx/common/inc/ -I../../Middlewares/ST/threadx/ports/cortex_m7/gnu/inc/ -I../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../Drivers/CMSIS/Include -I../NetXDuo/App -I../../Middlewares/ST/netxduo/addons/auto_ip/ -I../../Middlewares/ST/netxduo/common/inc/ -I../../Middlewares/ST/netxduo/ports/cortex_m7/gnu/inc/ -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Middlewares/NetXDuo/Network/NetXDuo/Addons AutoIP/nx_auto_ip.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-NetXDuo-2f-Network-2f-NetXDuo-2f-Addons-20-AutoIP

clean-Middlewares-2f-NetXDuo-2f-Network-2f-NetXDuo-2f-Addons-20-AutoIP:
	-$(RM) ./Middlewares/NetXDuo/Network/NetXDuo/Addons\ AutoIP/nx_auto_ip.cyclo ./Middlewares/NetXDuo/Network/NetXDuo/Addons\ AutoIP/nx_auto_ip.d ./Middlewares/NetXDuo/Network/NetXDuo/Addons\ AutoIP/nx_auto_ip.o ./Middlewares/NetXDuo/Network/NetXDuo/Addons\ AutoIP/nx_auto_ip.su

.PHONY: clean-Middlewares-2f-NetXDuo-2f-Network-2f-NetXDuo-2f-Addons-20-AutoIP

