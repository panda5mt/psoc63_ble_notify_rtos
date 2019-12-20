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
#define ARM_MATH_CM4
#include "arm_math.h"
#include "arm_const_structs.h"

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

void arm_chilbert_f32(
	const arm_cfft_instance_f32* S,
	float32_t* p1)
{
	uint32_t i, L;

	L = (S->fftLen);

	arm_cfft_f32(S, p1, 0, 1); //fft
//
//	for(i = 1; i < L-1; i++){
//		p1[i] = 2 * p1[i];
//		//p1[i+1] = 2 * p1[i+1];
//	}
//	p1[0] = 1;
//
//	for(i = L-1 ; i < 2*L; i++){
//			p1[i] = 0;
//			p1[i+1] = 0;
//	}
//	p1[L-1] = 1;

	for(i = 0; i <= (L*2)-1; i += 2){
		if(i == 0 || i == L) {}
		else if(i <= L-2) {
			p1[i] = 2 * p1[i];
			p1[i+1] = 2 * p1[i+1];
		}
		else {
			p1[i] = 0;
			p1[i+1] = 0;
		}
	}
	arm_cfft_f32(S, p1, 1, 1); // ifft

	//for(i = 0 ; i <= (2*L)-1 ;i++)if((float32_t)0.00 > p1[i]) p1[i] = -p1[i]; //else p1[i];
}

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

	static float32_t data_samples[] = {
		// Re[i],Im[i],Re[i+1],Im[i+1],....の順番で記述されている
		// 正弦波１周期分
//		0.198669330795061, 0.0, 0.564642473395035,0.0,
//		0.841470984807897, 0.0, 0.98544972998846, 0.0,
//		0.973847630878195, 0.0, 0.80849640381959, 0.0,
//		0.515501371821464, 0.0, 0.141120008059867,0.0,
//		-0.255541102026831, 0.0, -0.611857890942719, 0.0,
//		-0.871575772413588, 0.0, -0.993691003633464, 0.0,
//		-0.958924274663138, 0.0, -0.772764487555987, 0.0,
//		-0.464602179413757, 0.0, -0.0830894028174964, 0.0
0.841470984807897,0,
0.454648713412841,0,
0.0470400026866224,0,
-0.189200623826982,0,
-0.191784854932628,0,
-0.046569249699821,0,
0.0938552283883984,0,
0.123669780827923,0,
0.0457909428046396,0,
-0.054402111088937,0,
-0.0909082005955185,0,
-0.0447144098333696,0,
0.032320541294357,0,
0.0707576682639193,0,
0.0433525226771411,0,
-0.0179939572915666,0,
-0.0565527936399739,0,
-0.0417215137095376,0,
0.00788827419278697,0,
0.0456472625363814,0,
0.0398407446921931,0,
-0.000402332240472903,0,
-0.036792191485877,0,
-0.037732431750276,0,
-0.00529407000391092,0,
0.0293291711722924,0,
0.0354213306816483,0,
0.00967520672528104,0,
-0.0228839270418265,0,
-0.0329343874697621,0,
-0.0130334724297763,0,
0.0172320837888028,0
	};

	float32_t env[32];
	for (int k =0 ; k<64 ;k+=2){
		DebugPrintf("%.16f ,",data_samples[k]); // ヒルベルト変換前(実数軸のみ)
	}
	DebugPrintf("\r\n\r\n");

	//Cy_GPIO_Set(HILB_TIME_PORT,HILB_TIME_PIN); //high();
	arm_chilbert_f32(&arm_cfft_sR_f32_len32, data_samples); // ヒルベルト変換
	//Cy_GPIO_Clr(HILB_TIME_PORT,HILB_TIME_PIN); //low();
	for (int k = 1 ; k<64 ;k+=2){
		DebugPrintf("%.16f ,",data_samples[k]); // ヒルベルト変換後(虚数軸のみ)
	}
	// Comparator settings
	/* Enable the whole LPComp block */
	Cy_LPComp_GlobalEnable(COMP_0_HW);

	/* Configure LPComp output mode and hysteresis for channel 1 */
	Cy_LPComp_Init(COMP_0_HW, CY_LPCOMP_CHANNEL_0, &COMP_0_config);

	/* Set both terminals to GPIO inputs */
	Cy_LPComp_SetInputs(COMP_0_HW, CY_LPCOMP_CHANNEL_0, CY_LPCOMP_SW_GPIO, CY_LPCOMP_SW_GPIO);

	/* Set channel 0 power mode - Low Power mode */
	Cy_LPComp_SetPower(COMP_0_HW, CY_LPCOMP_CHANNEL_0, CY_LPCOMP_MODE_NORMAL);

	/* It needs 10us start-up time to settle LPComp channel in LP mode after power up */
	Cy_SysLib_DelayUs(10);




	DebugPrintf("LPCOMP OK\r\n");
	//while(1);
	// i2c settings 0x60:Si5351A 's I2C Slave Address

	Cy_SCB_I2C_Init(I2C_0_HW, &I2C_0_config, &I2C_0_context);
	Cy_SCB_I2C_Enable(I2C_0_HW);

	Cy_SCB_I2C_MasterSendStart(I2C_0_HW, 0x60, CY_SCB_I2C_WRITE_XFER, 10, &I2C_0_context);
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x02, 10, &I2C_0_context); // address 0x02
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x53, 10, &I2C_0_context);
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);
	Cy_SCB_I2C_MasterSendStop(I2C_0_HW, 10, &I2C_0_context);

	Cy_SCB_I2C_MasterSendStart(I2C_0_HW, 0x60, CY_SCB_I2C_WRITE_XFER, 10, &I2C_0_context);
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x07, 10, &I2C_0_context); // address:0x07
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);
	Cy_SCB_I2C_MasterSendStop(I2C_0_HW, 10, &I2C_0_context);

	Cy_SCB_I2C_MasterSendStart(I2C_0_HW, 0x60, CY_SCB_I2C_WRITE_XFER, 10, &I2C_0_context);
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x0F, 10, &I2C_0_context); // address:0x0F

	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//0f
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x0F, 10, &I2C_0_context);	//10

	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x8C, 10, &I2C_0_context);	//11
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x4F, 10, &I2C_0_context);	//12

	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x8C, 10, &I2C_0_context);	//13
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x8C, 10, &I2C_0_context);	//14

	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x8C, 10, &I2C_0_context);	//15
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x8C, 10, &I2C_0_context);	//16
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x8C, 10, &I2C_0_context);	//17
	Cy_SCB_I2C_MasterSendStop(I2C_0_HW, 10, &I2C_0_context);
// 162.020MHz
	Cy_SCB_I2C_MasterSendStart(I2C_0_HW, 0x60, CY_SCB_I2C_WRITE_XFER, 10, &I2C_0_context);
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x1A, 10, &I2C_0_context); // address:0x1A
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//1a
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0xFA, 10, &I2C_0_context);	//1b
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//1c
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x0A, 10, &I2C_0_context);	//1d
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0xF4, 10, &I2C_0_context); 	//1e
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//1f
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//20
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x38, 10, &I2C_0_context);	//21
	/*
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x38, 10, &I2C_0_context);	//22
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0xB5, 10, &I2C_0_context);	//23
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//24
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x0A, 10, &I2C_0_context);	//25
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0xF4, 10, &I2C_0_context);	//26
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//27
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//28
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x38, 10, &I2C_0_context);	//29
	*/
	Cy_SCB_I2C_MasterSendStop(I2C_0_HW, 10, &I2C_0_context);

	Cy_SCB_I2C_MasterSendStart(I2C_0_HW, 0x60, CY_SCB_I2C_WRITE_XFER, 10, &I2C_0_context);
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x2A, 10, &I2C_0_context); // address:0x2A
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x38, 10, &I2C_0_context);	//2a
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x97, 10, &I2C_0_context);	//2b
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//2c
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x02, 10, &I2C_0_context);	//2d
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x0C, 10, &I2C_0_context); 	//2e
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x10, 10, &I2C_0_context);	//2f
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x06, 10, &I2C_0_context);	//30
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0xEC, 10, &I2C_0_context);	//31
	/*
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//32
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x01, 10, &I2C_0_context);	//33
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x0C, 10, &I2C_0_context);	//34
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//35
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//36
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//37
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//38
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//39
	*/
	Cy_SCB_I2C_MasterSendStop(I2C_0_HW, 10, &I2C_0_context);

	Cy_SCB_I2C_MasterSendStart(I2C_0_HW, 0x60, CY_SCB_I2C_WRITE_XFER, 10, &I2C_0_context);
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x3A, 10, &I2C_0_context); // address:0x3A
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//3a
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x01, 10, &I2C_0_context);	//3b
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x0C, 10, &I2C_0_context);	//3c
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//3d
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//3e
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//3f
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//40
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//41
	Cy_SCB_I2C_MasterSendStop(I2C_0_HW, 10, &I2C_0_context);

	Cy_SCB_I2C_MasterSendStart(I2C_0_HW, 0x60, CY_SCB_I2C_WRITE_XFER, 10, &I2C_0_context);
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x5A, 10, &I2C_0_context); // address:0x5A
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//5a
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//5b
	Cy_SCB_I2C_MasterSendStop(I2C_0_HW, 10, &I2C_0_context);

	Cy_SCB_I2C_MasterSendStart(I2C_0_HW, 0x60, CY_SCB_I2C_WRITE_XFER, 10, &I2C_0_context);
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x95, 10, &I2C_0_context); // address:0x95
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//95
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//96
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//97
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//98
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//99
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//9a
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//9b
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//9c
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//9d
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//9e
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//9f
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//a0
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//a1
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//a2
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//a3
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x00, 10, &I2C_0_context);	//a4
	Cy_SCB_I2C_MasterSendStop(I2C_0_HW, 10, &I2C_0_context);

	Cy_SCB_I2C_MasterSendStart(I2C_0_HW, 0x60, CY_SCB_I2C_WRITE_XFER, 10, &I2C_0_context);
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0xb7, 10, &I2C_0_context); // address:0xb7
	Cy_SCB_I2C_MasterWriteByte(I2C_0_HW, 0x92, 10, &I2C_0_context);	//b7
	Cy_SCB_I2C_MasterSendStop(I2C_0_HW, 10, &I2C_0_context);


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
