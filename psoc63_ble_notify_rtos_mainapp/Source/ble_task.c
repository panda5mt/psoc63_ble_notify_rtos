/******************************************************************************
* File Name: ble_task.c
*
* Version: 1.0
*
* Description: This file contains the task that handles custom BLE services
*
* Related Document: CE223508_PSoC6_BLE_MultiSlave_RTOS.pdf
*
* Hardware Dependency: CY8CKIT-062-BLE PSoC 6 BLE Pioneer Kit
*
*******************************************************************************
* Copyright (2018), Cypress Semiconductor Corporation. All rights reserved.
*******************************************************************************
* This software, including source code, documentation and related materials
* (“Software”), is owned by Cypress Semiconductor Corporation or one of its
* subsidiaries (“Cypress”) and is protected by and subject to worldwide patent
* protection (United States and foreign), United States copyright laws and
* international treaty provisions. Therefore, you may use this Software only
* as provided in the license agreement accompanying the software package from
* which you obtained this Software (“EULA”).
*
* If no EULA applies, Cypress hereby grants you a personal, nonexclusive,
* non-transferable license to copy, modify, and compile the Software source
* code solely for use in connection with Cypress’s integrated circuit products.
* Any reproduction, modification, tra   nslation, compilation, or representation
* of this Software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, 
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress 
* reserves the right to make changes to the Software without notice. Cypress 
* does not assume any liability arising out of the application or use of the 
* Software or any product or circuit described in the Software. Cypress does 
* not authorize its products for use in any products where a malfunction or 
* failure of the Cypress product may reasonably be expected to result in 
* significant property damage, injury or death (“High Risk Product”). By 
* including Cypress’s product in a High Risk Product, the manufacturer of such 
* system or application assumes all risk of such use and in doing so agrees to 
* indemnify Cypress against all liability.
*******************************************************************************/

/* Header file includes */

#include "cy_device_headers.h"
#include "cycfg_ble.h"
#include "cycfg.h"
#include "ble_task.h"
#include "timers.h"
#include "uart_debug.h"
#include "ble_custom_service_config.h"
//#include "rgb_led_task.h"
//#include "status_led_task.h"
//#include "temperature_task.h"
#include "math.h"

/* BLE application timeout */
#define TIMEOUT_INTERVAL    pdMS_TO_TICKS(1 * 60000u) /* 1 x 60 sec = 1min */
#define HIBERNATE_ENABLE		0 // 0:disable
/* Queue Handle for BLE command and data */
QueueHandle_t bleCommandDataQ;

/* Timer handles */
TimerHandle_t xBleTimer;

/* Variable for storing custom service data */
uint8_t customServiceData[CUSTOM_SERVICE_128BIT_RW_SERVICE_LEN];
uint8_t customNotificationData[CUSTOM_NOTIFICATIN_SERVICE_LEN];

/* Variable used to maintain connection information */
static cy_stc_ble_conn_handle_t appConnHandle[CY_BLE_CONN_COUNT];

/** 
 * These static functions are used by the BLE Task. These are not available 
 * outside this file. See the respective function definitions for more 
 * details. 
 */
static void BleControllerInterruptEventHandler(void);
static void StackEventHandler(uint32_t eventType, void *eventParam);
static void CallbackHts(uint32_t eventType, void* eventParam);
static void BleTimerCallback(TimerHandle_t xTimer);
static void StartAdvertisement(void);
static void SendCustomNotificatioon(void *data);
//static void UpdateStatusLed(status_led_command_t redLed, status_led_command_t orangeLed);
//static void SendTemperatureIndication(float temperature);
static void HandleWriteReq_CustomService(cy_stc_ble_gatts_write_cmd_req_param_t writeReqParameter);
//static void HandleWriteReq_RgbLed(cy_stc_ble_gatts_write_cmd_req_param_t writeReqParameter);
static void UpdateGattDB(cy_stc_ble_gatts_write_cmd_req_param_t writeReqParam);

/*******************************************************************************
* Function Name: void Task_Ble(void *pvParameters)
********************************************************************************
* Summary:
*  Task that processes the BLE state and events, and then commands other tasks 
*  to take an action based on the current BLE state and data received over BLE  
*
* Parameters:
*  void *pvParameters : Task parameter defined during task creation (unused)                            
*
* Return:
*  None
*
*******************************************************************************/
void Task_Ble(void* pvParameters)
{
    /* Variable used to store the return values of RTOS APIs */
    BaseType_t rtosApiResult;
    
    /* Variable used to store the return values of BLE APIs */
    cy_en_ble_api_result_t bleApiResult;
    
    /* Variable that stores BLE commands that need to be processed */
    ble_commandAndData_t bleCommandData;
    
    /* Remove warning for unused parameter */
    (void)pvParameters;
    
    /** 
     * Create an RTOS timer. 
	 * This timer is used to monitor, if no device is connected for 30 sec then
	 * goto hibernate mode.
     */
#if (HIBERNATE_ENABLE)
    xBleTimer =  xTimerCreate ("BLE Timer",         /* Timer name */
                                TIMEOUT_INTERVAL,   /* Timer period */
                                pdFALSE,            /* Auto reload enable */
                                NULL,               /* Timer ID */
                                BleTimerCallback);  /* Timer callback function */
#endif

    /* Start the BLE component and register the stack event handler */
    //bleApiResult = Cy_BLE_Start(StackEventHandler);
    /////
    
    /* Register the generic event handler */
    	Cy_BLE_RegisterEventCallback(StackEventHandler);

    	/* Initialize the BLE host */
    	bleApiResult = Cy_BLE_Init(&cy_ble_config);

    	if(bleApiResult != CY_BLE_SUCCESS)
    	{
    		/* BLE stack initialization failed, check configuration,
    		   notify error and halt CPU in debug mode */
    		DebugPrintf("Cy_BLE_Init API Error: %x \r\n", bleApiResult);
    	}
    	else
    	{
    		DebugPrintf("Cy_BLE_Init API Success: %x \r\n", bleApiResult);
    	}

    	/* Enable BLE */
    	bleApiResult = Cy_BLE_Enable();

    /* Check if the operation was successful */
    if(bleApiResult == CY_BLE_SUCCESS)
    {
        Task_DebugPrintf("Success  : BLE - Stack initialization", 0u);
    
        /* Register the application Host callback */
        Cy_BLE_RegisterAppHostCallback(BleControllerInterruptEventHandler);
        
        /* Register the HTS callback handler  */
        Cy_BLE_HTS_RegisterAttrCallback(CallbackHts);
        
        /* Process BLE events to turn the stack on */
        Cy_BLE_ProcessEvents();
    }
    else
    {
        Task_DebugPrintf("Failure! : BLE  - Stack initialization. Error Code:",
                         bleApiResult);
    }
    
    /* Repeatedly running part of the task */
    for(;;)
    {
        /* Block until a BLE command has been received over bleCommandDataQ */
        rtosApiResult = xQueueReceive(bleCommandDataQ, &bleCommandData, portMAX_DELAY);
        
        /* Command has been received from bleCommandQ */
        if(rtosApiResult == pdTRUE)
        {
            switch(bleCommandData.command)
            {
                /*~~~~~~~~~~~~~~ Command to process BLE events ~~~~~~~~~~~~~~~*/
                case PROCESS_BLE_EVENTS:
                {
                    /* Process event callback to handle BLE events. The events and 
                       associated actions taken by this application are inside the 
                       'StackEventHandler' routine. Note that Cortex M4 only handles 
                       the BLE host portion of the stack, while Cortex M0+ handles 
                       the BLE controller portion */
                    Cy_BLE_ProcessEvents();
                    break;
                }
                
                /*~~~~~~~~~~~~~~ Command to send temperature indication ~~~~~~*/
//                case SEND_TEMP_INDICATION:
//                {
//                    /* Send temperature data over BLE HTS notification */
//                    SendTemperatureIndication(*(float*)bleCommandData.data);
//                    break;
//                }
                
                case SEND_NOTIFICATION:
                {
                    /* Send notification to all the connected devices */
                    SendCustomNotificatioon((uint8_t *)bleCommandData.data);
                    break;
                }
                
                /*~~~~~~~~~~~~~~ Command to stop BLE ~~~~~~~~~~~~~~~~~~~~~~~~~*/
                case STOP_BLE:
                {
                    /* Stop the BLE and update the LED status*/
                    bleApiResult = Cy_BLE_Disable();
                    
                    if(bleApiResult != CY_BLE_SUCCESS)
                    {
                        Task_DebugPrintf("Failure! : BLE - Stack shutdown API", 0u);
                    }
                    //UpdateStatusLed(LED_TURN_ON, LED_TURN_OFF);
                    Cy_BLE_ProcessEvents();
                    break;
                }
                
                /*~~~~~~~~~~~~~~ Unknown command ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
                default:
                {
                    Task_DebugPrintf("Info     : BLE - Unknown BLE command", 0u);
                    break;
                }
            }
        }
        
        /* Task has timed out and received no commands during an interval of 
           portMAXDELAY ticks */
        else
        {
            Task_DebugPrintf("Warning! : BLE - Task Timed out ", 0u);
        }
    }
    
}

/*******************************************************************************
* Function Name: bool Task_Ble_Tickless_Idle_Readiness (void) 
********************************************************************************
* Summary:
*  This function returns the Tickless Idle readiness of Task_Ble
* 
* Parameters: 
*  None
*
* Return:
*  bool: returns the Tickless Idle readiness of Task_Ble
*******************************************************************************/
bool Task_Ble_Tickless_Idle_Readiness (void) 
{
    /* Return "true" if the BLE is on, "false" otherwise */
    return (Cy_BLE_GetState() == CY_BLE_STATE_ON) ? true : false;
}

/*******************************************************************************
* Function Name: static void StackEventHandler(uint32_t event, void *eventParam)
********************************************************************************
* Summary:
*  Call back event function to handle various events from the BLE stack. Note 
*  that Cortex M4 only handles the BLE host portion of the stack, while 
*  Cortex M0+ handles the BLE controller portion. 
*
* Parameters:
*  event        :	BLE event occurred
*  eventParam   :	Pointer to the value of event specific parameters
*
* Return:
*  None
*
*******************************************************************************/
static void StackEventHandler(uint32_t eventType, void *eventParam)
{
    /* Local variable to store write request  parameter */
    static cy_stc_ble_gatts_write_cmd_req_param_t writeReqParameter;
    
    /* Local variable for storing connection handle */ 
    static cy_stc_ble_conn_handle_t connHandle; 
    
    /* Take an action based on the current event */
    switch ((cy_en_ble_event_t)eventType)
    {
        /*~~~~~~~~~~~~~~~~~~~~~~ GENERAL  EVENTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        
        /* This event is received when the BLE stack is Started */
        case CY_BLE_EVT_STACK_ON:
        {
            Task_DebugPrintf("Info     : BLE - Stack on", 0u);
            StartAdvertisement();
            break;
        }
        
        /* This event is used to inform the application that BLE Stack shutdown is completed */
#if (HIBERNATE_ENABLE)
        case CY_BLE_EVT_STACK_SHUTDOWN_COMPLETE:
        {
            DebugPrintf("Info     : BLE - Stack shutdown complete\r\n");
            DebugPrintf("Info     : Entering hibernate mode\r\n");
            /* Wait for UART transmission complete */
            WAIT_FOR_UART_TX_COMPLETE;    
            
            /* Enter hibernate mode */
            Cy_SysPm_Hibernate();
            break;
        }
#endif
        /* This event is received when there is a timeout */
        case CY_BLE_EVT_TIMEOUT:
        {    
            Task_DebugPrintf("Info     : BLE - Event timeout", 0u);
            break;
        }
        
        /*~~~~~~~~~~~~~~~~~~~~~~~~~~ GATT EVENTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        /* This event is received when device is connected over GATT level */    
        case CY_BLE_EVT_GATT_CONNECT_IND:
        {
            Task_DebugPrintf("Info     : BLE - GATT connection established",
                              0u);
            /* Get connection handle of connected device */
            connHandle = *(cy_stc_ble_conn_handle_t*)eventParam;
            
            /* Updates the connection information */
            appConnHandle[connHandle.attId].attId    = connHandle.attId;
            appConnHandle[connHandle.attId].bdHandle = connHandle.bdHandle;
            break;
        }
        
        /* This event is received when device is disconnected */
        case CY_BLE_EVT_GATT_DISCONNECT_IND:
        {
            Task_DebugPrintf("Info     : BLE - GATT disconnection occurred", 0u);
            
            /* Get connection handle of disconnected device */
            connHandle = *(cy_stc_ble_conn_handle_t*)eventParam;
            
            /* Update connection handle array */
            appConnHandle[connHandle.attId].attId    = connHandle.attId;
            appConnHandle[connHandle.attId].bdHandle = CY_BLE_INVALID_CONN_HANDLE_VALUE;                        
            break;
        }
        
        /* This event is received when Central device sends a write command
           on an Attribute */
        case CY_BLE_EVT_GATTS_WRITE_REQ:
        {
            writeReqParameter = 
                *(cy_stc_ble_gatts_write_cmd_req_param_t*)eventParam;
            
            Task_DebugPrintf("Info     : BLE - GATT write request", 0u);    

            writeReqParameter.handleValPair.value.val[ writeReqParameter.handleValPair.value.len] = '\0';
            DebugPrintf("write value = %s \r\n", writeReqParameter.handleValPair.value.val);
            
            /* Send the response to the write request received */
            Cy_BLE_GATTS_WriteRsp(writeReqParameter.connHandle);    
            
            /* write request for 128-bit read write custom service */
            if(writeReqParameter.handleValPair.attrHandle ==
                CUSTOM_SERVICE_128BIT_RW_CCC_HANDLE)
            {
                HandleWriteReq_CustomService(writeReqParameter);
            }
            
//            /* Write request for RGB LED service */
//            if(CY_BLE_RGB_LED_RGB_LED_CONTROL_CHAR_HANDLE == \
//                    writeReqParameter.handleValPair.attrHandle)
//            {
//                HandleWriteReq_RgbLed(writeReqParameter);
//            }
                       
            /* Queue BLE command to send notification to all the connected devices */
//            ble_commandAndData_t bleCommand = {.command = SEND_NOTIFICATION, .data="unko"};
//            xQueueSend(bleCommandDataQ, &bleCommand, 0u);
            
            break;
        }
        /* This event is received when Central device sends a read command
           on an Attribute */
        case CY_BLE_EVT_GATTS_READ_CHAR_VAL_ACCESS_REQ:
        {
            Task_DebugPrintf("Info     : BLE - GATT read request", 0u);
            break;
        }
        
        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~ GAP EVENTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
        
        /* This event indicates peripheral device has started/stopped
           advertising */
        case CY_BLE_EVT_GAPP_ADVERTISEMENT_START_STOP:
        {   
            Task_DebugPrintf("Info     : BLE - Advertisement start/stop event",
                              0u);
            
            if(Cy_BLE_GetAdvertisementState() == CY_BLE_ADV_STATE_ADVERTISING)
            {
                /* Toggle Orange LED periodically to indicate that BLE is in a 
                    advertising state */
                //UpdateStatusLed(LED_TURN_OFF, LED_TOGGLE_EN);
            	DebugPrintf("CY_BLE_ADV_STATE_ADVERTISING\r\n");
            }
            break;                
        }
        
        /* This event is generated at the GAP Peripheral end after connection 
           is completed with peer Central device */
        case CY_BLE_EVT_GAP_ENHANCE_CONN_COMPLETE:
        case CY_BLE_EVT_GAP_DEVICE_CONNECTED:
        {  
            Task_DebugPrintf("Info     : BLE - GAP device connected", 0u);
            Task_DebugPrintf("Info     : Connected device", Cy_BLE_GetNumOfActiveConn());
                        
            /* Start advertisement for next device. */
            StartAdvertisement();
            
            /* If active connection count is CY_BLE_CONN_COUNT then turn on Orange LED */ 
            if(Cy_BLE_GetNumOfActiveConn() == CY_BLE_CONN_COUNT)
            {
            	/*  Turn on the Red LED to show maximum allowed devices are connected */
                //UpdateStatusLed(LED_TURN_OFF, LED_TURN_ON);
            }
            
#if (HIBERNATE_ENABLE)
            /**
             * Stop BLE timer.
             * If any device is connected then system will not go to
             * hibernate mode 
             */
            if(xTimerIsTimerActive(xBleTimer))
            {
                xTimerStop(xBleTimer, 0u);
            }
#endif
            break;
        }
        
        /* This event is generated when disconnected from remote device or 
           failed to establish connection */
        case CY_BLE_EVT_GAP_DEVICE_DISCONNECTED:
        {    
            Task_DebugPrintf("Info     : BLE - GAP device disconnected", 0u);
            Task_DebugPrintf("Info     : Connected device", Cy_BLE_GetNumOfActiveConn());
            /* Start advertisement for next device. */
            StartAdvertisement();
            break;            
        }
        /*~~~~~~~~~~~~~~~~~~~~~~~~~~ OTHER EVENTS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/ 
        
         /* See the data-type cy_en_ble_event_t to understand the event 
			occurred */
        default:
        {
            /* Other BLE events */
            break;
        }
    }
} 

/*******************************************************************************
* Function Name: void CallbackHts(uint32_t event, void *eventParam)
********************************************************************************
*
* Summary:
*  This is an event callback function to receive events from the BLE Component,
*  which are specific to Health Thermometer Service.
*
* Parameters:  
*  event:       Event for Health Thermometer Service.
*  eventParams: Event parameter for Health Thermometer Service.
*
* Return: 
*  None
*
*******************************************************************************/
void CallbackHts(uint32_t event, void *eventParam)
{     
    static uint8_t htsRequestCount;
    
    /* Variable used to store the return values of RTOS APIs */
    BaseType_t rtosApiResult;
    
    switch(event)
    {
        /* This event is received when indication are enabled by the central */
        case CY_BLE_EVT_HTSS_INDICATION_ENABLED:
        {
            Task_DebugPrintf("Info     : BLE - HTS indication enabled", 0);
            
            /* Send command to Temperature task for enabling temperature scan */
//            temperature_command_t command = ENABLE_SCAN;
//            rtosApiResult = xQueueSend(temperatureCommandQ, &command, 0);
//            /* Check if the operation has been successful */
//            if(rtosApiResult != pdTRUE)
//            {
//                Task_DebugPrintf("Failure!  : BLE - Send temperature command", 0);
//            }

            /* Tracking how many devices requested for HTS */
            htsRequestCount++;
            break;
        }

        /* This event is received when indication are enabled by the central */
        case CY_BLE_EVT_HTSS_INDICATION_DISABLED:
        {
            Task_DebugPrintf("Info     : BLE - HTS indication disabled", 0);
            
            if(--htsRequestCount == 0)
            {
            	/* Send command to Temperature task for disabling temperature scan */
//                temperature_command_t command = DISABLE_SCAN;
//                rtosApiResult = xQueueSend(temperatureCommandQ, &command, 0);
//                /* Check if the operation has been successful */
//                if(rtosApiResult != pdTRUE)
//                {
//                    Task_DebugPrintf("Failure!  : BLE - Send temperature command",
//                        rtosApiResult);
//                }
            }
            break;
        }
        default:
        {
        	/* Error handling */
            break;
        }
    }
    /* To avoid compiler warning */
    (void)eventParam;
}

/*******************************************************************************
* Function Name: static void BleControllerInterruptEventHandler(void)
********************************************************************************
* Summary:
*  Call back event function to handle interrupts from BLE Controller
*  (Cortex M0+)
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void BleControllerInterruptEventHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken;
    
    /* Send command to process BLE events  */
    ble_commandAndData_t bleCommand = {.command = PROCESS_BLE_EVENTS};
    xQueueSendFromISR(bleCommandDataQ, &bleCommand,&xHigherPriorityTaskWoken);

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken );
}

/*******************************************************************************
* Function Name: static void BleTimerCallback(TimerHandle_t xTimer)           
********************************************************************************
* Summary:
*  This function is called when the BLE application timer expires
*
* Parameters:
*  TimerHandle_t xTimer :  Current timer value (unused)
*
* Return:
*  None
*
*******************************************************************************/
static void BleTimerCallback(TimerHandle_t xTimer)  
{
    /* Variable used to store the return values of RTOS APIs */
    BaseType_t rtosApiResult;
    
    /* Remove warning for unused parameter */
    (void)xTimer;
    
    /* Send command to stop BLE */
    ble_commandAndData_t bleCommand = {.command = STOP_BLE};
    rtosApiResult = xQueueSend(bleCommandDataQ, &bleCommand, 0);
    
    /* Check if the operation has been successful */
    if(rtosApiResult != pdTRUE)
    {
        Task_DebugPrintf("Failure!  : BLE Timer - sending BLE command", 0);
    }
}

/*******************************************************************************
* Function Name: static void StartAdvertisement(void)
********************************************************************************
* Summary:
*  This function starts the advertisement if not already advertising and connected
*  device count is less than the maximum allowed devices.
*
* Parameters:
*  None
*
* Return:
*  None
*******************************************************************************/
static void StartAdvertisement(void)
{
    /* Variable used to store the return values of BLE APIs */
    cy_en_ble_api_result_t bleApiResult;
    
    /* Get the number of active connection */
    uint8_t numActiveConn = Cy_BLE_GetNumOfActiveConn();

    /* Start Advertisement and enter discoverable mode.
       Make sure that BLE is neither connected nor advertising
       already */
    if((Cy_BLE_GetAdvertisementState() == CY_BLE_ADV_STATE_STOPPED) && \
        (numActiveConn < CY_BLE_CONN_COUNT))
    {
        bleApiResult = Cy_BLE_GAPP_StartAdvertisement(CY_BLE_ADVERTISING_FAST,
                                       CY_BLE_PERIPHERAL_CONFIGURATION_0_INDEX); 
        if(bleApiResult != CY_BLE_SUCCESS )
        {
            Task_DebugPrintf("Failure! : BLE - Advertisement API, "\
                             "Error code:", bleApiResult);
        }
    }
#if (HIBERNATE_ENABLE)
    /* If no device is connected then start the 30 sec timer */
    if(numActiveConn == 0)
    {
        /* Start the timer */
        xTimerReset(xBleTimer, 0u);
        xTimerStart(xBleTimer, 0u);
    }
#endif
}

/*******************************************************************************
* Function Name: static void SendCustomNotificatioon(void)
********************************************************************************
* Summary:
*  This function sends modification to all the connected devices.
*
* Parameters:
*  cy_ble_gatt_db_attr_handle_t attrHandle: GATT DB attribute handle 
*  uint8_t* val : Attribute value
*  uint16_t length: Attribute length
*  cy_stc_ble_conn_handle_t connHandle: Connection handle 
*
* Return:
*  None
*******************************************************************************/
static void SendCustomNotificatioon(void *data)
{
    uint8_t i;
    int8_t str[NOTIFY_STRING_MAX_LENGTH];
    strcpy(str,data);
    int length = strlen(data);

    /* Send notification top all the connected device */
    //DebugPrintf("data = %s ,length = %d\r\n",str,length);
    DebugPrintf("%s\r\n",str);
    for(i = 0; i < CY_BLE_CONN_COUNT; i++)
    {
        
       if(Cy_BLE_GetConnectionState(appConnHandle[i]) ==  CY_BLE_CONN_STATE_CONNECTED )
       {
        		//DebugPrintf("notify send...\r\n");

        		/*  Local variable used for storing notification parameter */
            cy_stc_ble_gatts_handle_value_ntf_t customNotificationHandle = 
            {
                .connHandle = appConnHandle[i],
                .handleValPair.attrHandle   = CUSTOM_NOTIFICATION_CCC_HANDLE,//CY_BLE_CUSTOM_SERVICE_CUSTOM_CHARACTERISTIC_CHAR_HANDLE,
                .handleValPair.value.val    = str,//customNotificationData,
                .handleValPair.value.len    = length //CUSTOM_NOTIFICATIN_SERVICE_LEN
            };
            
            /* Send the updated handle as part of attribute for notifications */
            Cy_BLE_GATTS_Notification(&customNotificationHandle);
        }
    }
}

/*******************************************************************************
* Function Name: static void HandleWriteReq_CustomService(
*					cy_stc_ble_gatts_write_cmd_req_param_t writeReqParameter)
********************************************************************************
* Summary:
*  This function handles write request for 128-bit read write custom service
*
* Parameters:
*  cy_stc_ble_gatts_write_cmd_req_param_t writeReqParameter: Write command request
*   parameter
*
* Return:
*  None
*******************************************************************************/
static void HandleWriteReq_CustomService(cy_stc_ble_gatts_write_cmd_req_param_t writeReqParameter)
{
    /* Extract the write value sent by the Client for 128-bit read
       write custom service */
    memcpy(customServiceData, writeReqParameter.handleValPair.value.val,
        CUSTOM_SERVICE_128BIT_RW_SERVICE_LEN);

    /* Update GATT database with new value */    
    UpdateGattDB(writeReqParameter);

    /* Update custom notification data */
    customNotificationData[CUSTOM_NOTIFICATION_DEVICE_INDEX] = \
        CY_BLE_CONN_COUNT - writeReqParameter.connHandle.attId;
    customNotificationData[CUSTOM_NOTIFICATION_SERVICE_INDEX] = \
        CUSTOM_SERVICE_128BIT_READ_WRITE;
}

/*******************************************************************************
* Function Name: static void UpdateGattDB(
*                       cy_stc_ble_gatts_write_cmd_req_param_t writeReqParam)
********************************************************************************
*
* Summary:
*  This function update the value field of the specified attribute  in the GATT 
*  database of a GATT Server by a peer device.
*
* Parameters:  
*  cy_stc_ble_gatts_write_cmd_req_param_t writeReqParam: Write request paramete
*
* Return: 
*  None
*
*******************************************************************************/
static void UpdateGattDB(cy_stc_ble_gatts_write_cmd_req_param_t writeReqParam)
{
    /* Local variable that stores custom service data parameters */
    cy_stc_ble_gatt_handle_value_pair_t  handleValue = 
    {
        .attrHandle = writeReqParam.handleValPair.attrHandle,
        .value      = writeReqParam.handleValPair.value,
    };
    Cy_BLE_GATTS_WriteAttributeValuePeer(&writeReqParam.connHandle, &handleValue);
}

/* [] END OF FILE */
