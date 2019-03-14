################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/ble/common/cy_ble_common.c 

OBJS += \
./psoc6sw-1.0/components/psoc6mw/ble/common/cy_ble_common.o 

C_DEPS += \
./psoc6sw-1.0/components/psoc6mw/ble/common/cy_ble_common.d 


# Each subdirectory must supply rules for building sources it contributes
psoc6sw-1.0/components/psoc6mw/ble/common/cy_ble_common.o: /Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/ble/common/cy_ble_common.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -Og -ffunction-sections -fdata-sections -Wall  -g3 -DCYBLE_416045_02 -DDEBUG -DAPP_NAME='"rtos_ble_cm0p"' -I"/Users/atsu/mtw/rtos/rtos_ble_config/GeneratedSource" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/ble" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/ble/common" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/ble/config/dual_controller_cm0p_softfp" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable/GCC/CM4F" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/cmsis/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/include" -I"/Users/atsu/mtw/rtos/rtos_ble_config" -I"/Users/atsu/mtw/rtos/rtos_ble_mainapp_cm0p/Source_cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_low" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_high" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/linker/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/ble/config/base" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable" -std=gnu11 -ffat-lto-objects -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


