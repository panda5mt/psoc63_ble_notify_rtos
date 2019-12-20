/*
* Copyright YOUR COMPANY, THE YEAR
* All Rights Reserved
* UNPUBLISHED, LICENSED SOFTWARE.
*
* CONFIDENTIAL AND PROPRIETARY INFORMATION
* WHICH IS THE PROPERTY OF your company.
*/


#include "cy_device_headers.h"
#include "cycfg.h"
#include "stdio.h"

#include "uart_debug.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "tickless_idle.h"
#include "cy_sysint.h"
#include "cycfg_ble.h"
#include "ble_task.h"
#include "lcd_task.h"
#include "freq_count_task.h"

cy_stc_scb_i2c_context_t I2C_0_context;

uint8_t ucHeap[ configTOTAL_HEAP_SIZE ];

const cy_stc_sysint_t bless_isr_cfg = {
	.intrSrc = (IRQn_Type)bless_interrupt_IRQn,
	.intrPriority = 3u//MCWDT_IRQ__INTC_CORTEXM4_PRIORITY
};


/*******************************************************************************
* Function Name: BlessInterrupt
*******************************************************************************/
void BlessInterrupt(void)
{
    Cy_BLE_BlessIsrHandler();
}

/**
 * Priorities of user tasks in this project - spaced at intervals of 5 for
 * the ease of further modification and addition of new tasks.
 * Larger number indicates higher priority.
 */
#define TASK_BLE_PRIORITY           (20u)

/* Stack sizes of user tasks in this project */
#define TASK_BLE_STACK_SIZE         (1024u)

/* Queue lengths of message queues used in this project */
#define BLE_COMMAND_QUEUE_LEN           (10u)


bool IsSystemReadyForTicklessIdle(void);
void uartTask(void *arg);

/* The instance-specific context structure.
* The driver uses this as a scratch pad for its operations.
* Do not modify this structure.
*/
cy_stc_scb_uart_context_t DEBUG_UART_context;
cy_stc_scb_uart_context_t KIT_UART_context;



int main(void)
{
    /* Configure switch SW2 as hibernate wake up source */
    Cy_SysPm_SetHibWakeupSource(CY_SYSPM_HIBPIN1_LOW);

	/* Set up the device based on configurator selections */
	init_cycfg_all();
	__enable_irq();

	cy_ble_config.hw->blessIsrConfig = &bless_isr_cfg;
	Cy_SysInt_Init(cy_ble_config.hw->blessIsrConfig, BlessInterrupt);


	/**
	* Create the queues.
	* See the respective data-types for details of queue contents.
	*/
	bleCommandDataQ = xQueueCreate(BLE_COMMAND_QUEUE_LEN,
									   sizeof(ble_commandAndData_t));

	// uart settings
	Task_DebugInit();
	DebugPrintfInit();
	KitUartInit();
	DebugPrintf("\033[2J\033[H");


	/**
	* Create the user Tasks.
	* See the respective Task definition for more details of these tasks
	*/
	xTaskCreate(Task_Ble, "BLE Task", TASK_BLE_STACK_SIZE,
			NULL, TASK_BLE_PRIORITY, NULL);
	xTaskCreate(uartTask,"UART Task",1024,0,1,0);
	xTaskCreate(lcdTask,"LCD Task",configMINIMAL_STACK_SIZE,0,1,0);
	xTaskCreate(freqCountTask,"FREQ TASK",configMINIMAL_STACK_SIZE,0,1,0);

	/* Initialize Tickless Idle mode */
	TicklessIdleInit(IsSystemReadyForTicklessIdle);

	/* Start the RTOS scheduler. This function should never return */
	vTaskStartScheduler();

	for(;;)
	{
		/* vTaskStartScheduler never returns */
	}
}



/*******************************************************************************
* Function Name: bool IsSystemReadyForTicklessIdle(void)
********************************************************************************
*
* Summary:
*  This function returns the Tickless Idle readiness of the system.
*
* Parameters:
*  None
*
* Return:
*  bool: Tickless Idle readiness of the system.
*
*******************************************************************************/
bool IsSystemReadyForTicklessIdle(void)
{
    return  ((Task_Ble_Tickless_Idle_Readiness())      &&/*
             (Task_RgbLed_Tickless_Idle_Readiness())   &&
             (Task_Temp_Tickless_Idle_Readiness())     && */
             (Task_Debug_Tickless_Idle_Readiness()));
}

/*******************************************************************************
* Function Name: void vApplicationIdleHook(void)
********************************************************************************
*
* Summary:
*  This function is called when the RTOS in idle mode
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void vApplicationIdleHook(void)
{
    /* Enter sleep-mode */
    Cy_SysPm_Sleep(CY_SYSPM_WAIT_FOR_INTERRUPT);
}

/*******************************************************************************
* Function Name: void vApplicationStackOverflowHook(TaskHandle_t *pxTask,
*                                                   signed char *pcTaskName)
********************************************************************************
*
* Summary:
*  This function is called when a stack overflow has been detected by the RTOS
*
* Parameters:
*  TaskHandle_t  : Handle to the task
*  signed char   : Name of the task
*
* Return:
*  None
*
*******************************************************************************/
void vApplicationStackOverflowHook(TaskHandle_t *pxTask,
                                   signed char *pcTaskName)
{
    /* Remove warning for unused parameters */
    (void)pxTask;

    /**
     * Print the error message with task name if debug is enabled in
     * uart_debug.h file
     */
    DebugPrintf("Error!   : RTOS - stack overflow in %s \r\n", pcTaskName);

    /* Halt the CPU */
    CY_ASSERT(0);
}

/*******************************************************************************
* Function Name: void vApplicationMallocFailedHook(void)
********************************************************************************
*
* Summary:
*  This function is called when a memory allocation operation by the RTOS
*  has failed
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void vApplicationMallocFailedHook(void)
{
    /* Print the error message if debug is enabled in uart_debug.h file */
    DebugPrintf("Error!   : RTOS - Memory allocation failed \r\n");

    /* Halt the CPU */
    CY_ASSERT(0);
}
/*******************************************************************************
* Function Name: void uartTask(void *arg)
********************************************************************************
*
* Summary:
*  This function is called when a memory allocation operation by the RTOS
*  has failed
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/

void uartTask(void *arg){
	(void)arg;


	uint32_t counter = 0;
	bool readyToSendNotify = false;
	int8_t c, str[NOTIFY_STRING_MAX_LENGTH];
	setvbuf(stdin,0,_IONBF,0);
	while(1)
	{
		c = getchar();

		str[counter++] = c;
		if( counter > NOTIFY_STRING_MAX_LENGTH - 2){
			str[counter] = '\0';
			readyToSendNotify = true;
		} else if((c=='\r')|(c=='\n')){
			str[counter - 1] = '\0';
			readyToSendNotify = true;
		}

		if(readyToSendNotify){
			if(counter > 1){
				ble_commandAndData_t bleCommand = {.command = SEND_NOTIFICATION, .data=str };
				xQueueSend(bleCommandDataQ, &bleCommand, 0u);
			}
			counter = 0;
			readyToSendNotify = false;
		}
	}
}




/* [] END OF FILE */
