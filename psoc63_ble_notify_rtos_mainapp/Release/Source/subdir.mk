################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Source/ble_task.c \
../Source/main.c \
../Source/stdio_user.c \
../Source/tickless_idle.c \
../Source/uart_debug.c 

OBJS += \
./Source/ble_task.o \
./Source/main.o \
./Source/stdio_user.o \
./Source/tickless_idle.o \
./Source/uart_debug.o 

C_DEPS += \
./Source/ble_task.d \
./Source/main.d \
./Source/stdio_user.d \
./Source/tickless_idle.d \
./Source/uart_debug.d 


# Each subdirectory must supply rules for building sources it contributes
Source/%.o: ../Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=softfp -Os -ffunction-sections -fdata-sections -Wall  -g -DCYBLE_416045_02 -DNDEBUG -DAPP_NAME='"psoc63_ble_notify_rtos_cm4"' -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/ble/config/single_cm4_softfp" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/include" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/cmsis/include" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/drivers/include" -I"/Users/atsu/mtw/rtos_mtw1.1/psoc63_ble_notify_rtos_mainapp/GeneratedSource" -I"/Users/atsu/mtw/rtos_mtw1.1/psoc63_ble_notify_rtos_mainapp/Source" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/include" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable/GCC/CM4F" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/ble" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/ble/common" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/drivers/source" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/cm4_low" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/startup/cm4_high" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/linker/cm4" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/utilities/retarget_io" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6mw/ble/config/base" -I"/Applications/ModusToolbox_1.1/libraries/psoc6sw-1.1/components/psoc6pdl/devices/psoc6/cm0p/prebuilt" -std=gnu11 -mfpu=fpv4-sp-d16 -ffat-lto-objects -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


