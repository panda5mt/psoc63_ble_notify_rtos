################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/utilities/retarget_io/retarget.c 

OBJS += \
./psoc6sw-1.0/components/psoc6pdl/utilities/retarget_io/retarget.o 

C_DEPS += \
./psoc6sw-1.0/components/psoc6pdl/utilities/retarget_io/retarget.d 


# Each subdirectory must supply rules for building sources it contributes
psoc6sw-1.0/components/psoc6pdl/utilities/retarget_io/retarget.o: /Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/utilities/retarget_io/retarget.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -Og -ffunction-sections -fdata-sections -Wall  -g3 -DCYBLE_416045_02 -DDEBUG -DAPP_NAME='"rtos_ble_cm4"' -I"/Users/atsu/mtw/rtos/rtos_ble_config/GeneratedSource" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/ble/config/single_cm4_softfp" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/cmsis/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/include" -I"/Users/atsu/mtw/rtos/rtos_ble_config" -I"/Users/atsu/mtw/rtos/rtos_ble_mainapp/Source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/ble" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable/GCC/CM4F" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/ble/common" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm4_low" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm4_high" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/linker/cm4" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/utilities/retarget_io" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/ble/config/base" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source" -std=gnu11 -mfpu=fpv4-sp-d16 -ffat-lto-objects -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

