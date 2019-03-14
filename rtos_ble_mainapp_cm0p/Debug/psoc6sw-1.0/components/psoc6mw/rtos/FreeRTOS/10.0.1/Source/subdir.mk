################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/croutine.c \
/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/event_groups.c \
/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/list.c \
/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/queue.c \
/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/stream_buffer.c \
/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/tasks.c \
/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/timers.c 

OBJS += \
./psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/croutine.o \
./psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/event_groups.o \
./psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/list.o \
./psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/queue.o \
./psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/stream_buffer.o \
./psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/tasks.o \
./psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/timers.o 

C_DEPS += \
./psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/croutine.d \
./psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/event_groups.d \
./psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/list.d \
./psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/queue.d \
./psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/stream_buffer.d \
./psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/tasks.d \
./psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/croutine.o: /Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/croutine.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -Og -ffunction-sections -fdata-sections -Wall  -g3 -DCYBLE_416045_02 -DDEBUG -DAPP_NAME='"rtos_ble_cm0p"' -I"/Users/atsu/mtw/rtos/rtos_ble_config/GeneratedSource" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/cmsis/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/include" -I"/Users/atsu/mtw/rtos/rtos_ble_config" -I"/Users/atsu/mtw/rtos/rtos_ble_mainapp_cm0p/Source_cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable/GCC/CM4F" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_low" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_high" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/linker/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable" -std=gnu11 -ffat-lto-objects -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/event_groups.o: /Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/event_groups.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -Og -ffunction-sections -fdata-sections -Wall  -g3 -DCYBLE_416045_02 -DDEBUG -DAPP_NAME='"rtos_ble_cm0p"' -I"/Users/atsu/mtw/rtos/rtos_ble_config/GeneratedSource" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/cmsis/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/include" -I"/Users/atsu/mtw/rtos/rtos_ble_config" -I"/Users/atsu/mtw/rtos/rtos_ble_mainapp_cm0p/Source_cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable/GCC/CM4F" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_low" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_high" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/linker/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable" -std=gnu11 -ffat-lto-objects -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/list.o: /Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/list.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -Og -ffunction-sections -fdata-sections -Wall  -g3 -DCYBLE_416045_02 -DDEBUG -DAPP_NAME='"rtos_ble_cm0p"' -I"/Users/atsu/mtw/rtos/rtos_ble_config/GeneratedSource" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/cmsis/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/include" -I"/Users/atsu/mtw/rtos/rtos_ble_config" -I"/Users/atsu/mtw/rtos/rtos_ble_mainapp_cm0p/Source_cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable/GCC/CM4F" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_low" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_high" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/linker/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable" -std=gnu11 -ffat-lto-objects -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/queue.o: /Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/queue.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -Og -ffunction-sections -fdata-sections -Wall  -g3 -DCYBLE_416045_02 -DDEBUG -DAPP_NAME='"rtos_ble_cm0p"' -I"/Users/atsu/mtw/rtos/rtos_ble_config/GeneratedSource" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/cmsis/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/include" -I"/Users/atsu/mtw/rtos/rtos_ble_config" -I"/Users/atsu/mtw/rtos/rtos_ble_mainapp_cm0p/Source_cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable/GCC/CM4F" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_low" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_high" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/linker/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable" -std=gnu11 -ffat-lto-objects -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/stream_buffer.o: /Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/stream_buffer.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -Og -ffunction-sections -fdata-sections -Wall  -g3 -DCYBLE_416045_02 -DDEBUG -DAPP_NAME='"rtos_ble_cm0p"' -I"/Users/atsu/mtw/rtos/rtos_ble_config/GeneratedSource" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/cmsis/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/include" -I"/Users/atsu/mtw/rtos/rtos_ble_config" -I"/Users/atsu/mtw/rtos/rtos_ble_mainapp_cm0p/Source_cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable/GCC/CM4F" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_low" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_high" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/linker/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable" -std=gnu11 -ffat-lto-objects -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/tasks.o: /Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/tasks.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -Og -ffunction-sections -fdata-sections -Wall  -g3 -DCYBLE_416045_02 -DDEBUG -DAPP_NAME='"rtos_ble_cm0p"' -I"/Users/atsu/mtw/rtos/rtos_ble_config/GeneratedSource" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/cmsis/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/include" -I"/Users/atsu/mtw/rtos/rtos_ble_config" -I"/Users/atsu/mtw/rtos/rtos_ble_mainapp_cm0p/Source_cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable/GCC/CM4F" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_low" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_high" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/linker/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable" -std=gnu11 -ffat-lto-objects -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/timers.o: /Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/timers.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -Og -ffunction-sections -fdata-sections -Wall  -g3 -DCYBLE_416045_02 -DDEBUG -DAPP_NAME='"rtos_ble_cm0p"' -I"/Users/atsu/mtw/rtos/rtos_ble_config/GeneratedSource" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/cmsis/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/include" -I"/Users/atsu/mtw/rtos/rtos_ble_config" -I"/Users/atsu/mtw/rtos/rtos_ble_mainapp_cm0p/Source_cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/include" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable/GCC/CM4F" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/drivers/source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_low" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/startup/cm0p_high" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/linker/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6pdl/devices/psoc6/cm0p" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source" -I"/Applications/ModusToolbox_1.0/libraries/psoc6sw-1.0/components/psoc6mw/rtos/FreeRTOS/10.0.1/Source/portable" -std=gnu11 -ffat-lto-objects -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


