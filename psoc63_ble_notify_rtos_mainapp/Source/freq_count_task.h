#ifndef FREQ_COUNT_TASK_H
#define FREQ_COUNT_TASK_H

/* Header file includes */
#include "cy_device_headers.h"
#include "cycfg.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "uart_debug.h"
#include "stdio.h"
#include "task.h"
#include "tickless_idle.h"
#include "cy_sysint.h"

void freqCountTask(void* pvParameters);

#endif FREQ_COUNT_TASK_H
