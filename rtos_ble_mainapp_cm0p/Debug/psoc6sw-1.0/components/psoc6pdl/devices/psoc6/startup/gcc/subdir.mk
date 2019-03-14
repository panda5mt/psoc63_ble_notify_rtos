################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/gcc/startup_psoc6_01_cm0plus.S 

OBJS += \
./psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/gcc/startup_psoc6_01_cm0plus.o 

S_UPPER_DEPS += \
./psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/gcc/startup_psoc6_01_cm0plus.d 


# Each subdirectory must supply rules for building sources it contributes
psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/gcc/%.o: ../psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/gcc/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -Og -ffunction-sections -fdata-sections -Wall  -g3 -x assembler-with-cpp -DCYBLE_416045_02 -DDEBUG -DAPP_NAME='"rtos_ble_cm0p"' -I"/Users/atsu/psoc63_ble_notify_rtos/rtos_ble_config/GeneratedSource" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/cmsis/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/include" -I"/Users/atsu/psoc63_ble_notify_rtos/rtos_ble_config" -I"/Users/atsu/psoc63_ble_notify_rtos/rtos_ble_mainapp_cm0p/Source_cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_low" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_high" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/linker/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/cm0p" -ffat-lto-objects -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


