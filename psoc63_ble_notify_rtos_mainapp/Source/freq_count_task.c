#include "cy_device_headers.h"
#include "cycfg.h"
#include "freq_count_task.h"

#define fl_SET                 (1u)
#define fl_RESET               (!fl_SET)
#define MAXCOUNT            (65535u)

uint8_t intFlag = fl_RESET;
uint32_t counterOverflow = fl_RESET;
uint32_t captureVal,capturePrev=0,freq;
const cy_stc_sysint_t SysInt_Counter_cfg = {
		.intrSrc = (IRQn_Type)Counter_0_IRQ,
		.intrPriority = 3u
};

void IsrCounter(void)
{
	/* Get which event triggered the interrupt */
	uint32_t intSource = Cy_TCPWM_GetInterruptStatus(Counter_0_HW, Counter_0_NUM);
		/* Local variable used to count number of overflow events */
	static uint32_t overflowCount=0;


	/* If the interrupt is triggered by capture event then set the flag for frequency
	   calculation */
	if(intSource == CY_TCPWM_INT_ON_CC)
	{
		Cy_GPIO_Set(TEST_PIN_PORT,TEST_PIN_PIN);
		/* Set interrupt flag */
		intFlag = fl_SET;
//		counterOverflow = overflowCount;
//		overflowCount = fl_RESET;
		captureVal = Cy_TCPWM_Counter_GetCapture(Counter_0_HW, Counter_0_NUM);
		freq = captureVal - capturePrev;
		capturePrev = captureVal;
		Cy_GPIO_Clr(TEST_PIN_PORT,TEST_PIN_PIN);
	}

	/* If the interrupt is triggered by an overflow event, then counting how
	   many times counter overflow happened in one second */
	if(intSource == CY_TCPWM_INT_ON_TC)
	{
		overflowCount++;
	}
	/* Clear interrupt */
	Cy_TCPWM_ClearInterrupt(Counter_0_HW, Counter_0_NUM, CY_TCPWM_INT_ON_CC_OR_TC);

}

// Counter init
void freqCountTask(void* pvParameters)
{
    /* Variable used to store the return values of RTOS APIs */
    BaseType_t rtosApiResult;

    /* Remove warning for unused parameter */
    (void)pvParameters;

	if (CY_TCPWM_SUCCESS != Cy_TCPWM_PWM_Init(PWM_FreqGen_HW, PWM_FreqGen_NUM, &PWM_FreqGen_config))
	{
		DebugPrintf("PWM error!\r\n");
	}
	Cy_TCPWM_PWM_Enable(PWM_FreqGen_HW, PWM_FreqGen_NUM);
	Cy_TCPWM_TriggerReloadOrIndex(PWM_FreqGen_HW, PWM_FreqGen_MASK);

	if (CY_TCPWM_SUCCESS != Cy_TCPWM_PWM_Init(PWM_Window_HW, PWM_Window_NUM, &PWM_Window_config))
	{
		DebugPrintf("PWM error!\r\n");
	}
	Cy_TCPWM_PWM_Enable(PWM_Window_HW, PWM_Window_NUM);
	Cy_TCPWM_TriggerReloadOrIndex(PWM_Window_HW, PWM_Window_MASK);

	 if (CY_TCPWM_SUCCESS != Cy_TCPWM_Counter_Init(Counter_0_HW, Counter_0_NUM, &Counter_0_config))
	{
		 DebugPrintf("Counter error!\r\n");
	}
	Cy_TCPWM_Counter_Enable(Counter_0_HW, Counter_0_NUM);
	Cy_TCPWM_TriggerStart(Counter_0_HW, Counter_0_MASK);

	/* Hookup and enable interrupt */
	Cy_SysInt_Init(&SysInt_Counter_cfg, IsrCounter);
	NVIC_ClearPendingIRQ(SysInt_Counter_cfg.intrSrc);
	NVIC_EnableIRQ((IRQn_Type)SysInt_Counter_cfg.intrSrc);
	//Cy_TCPWM_TriggerCaptureOrSwap(Counter_0_HW, Counter_0_MASK);

	/* Now we can get the latest captured value
	 * (captured during the second call of Cy_TCPWM_TriggerCaptureOrSwap)
	 */

	//Cy_TCPWM_TriggerCaptureOrSwap(Counter_0_HW, Counter_0_MASK);
	while(1)
	{
		if(intFlag)    /* Interrupt was trigerred, read the captured counter value now */
		{
			//scs.high();
			/* Get the Counter value */
			//captureVal = Cy_TCPWM_Counter_GetCapture(Counter_0_HW, Counter_0_NUM);

			/* Calculate freaquency */
			///freq = counterOverflow * MAXCOUNT+   captureVal - capturePrev;
			counterOverflow = fl_RESET;

			//capturePrev = captureVal;
			/* Clear the interrupt flag */
			intFlag = fl_RESET;
			//DebugPrintf("%d Hz \n\r", freq );

		}
	}
}
