/******************************************************************************
* File Name: ble_task.h
*
* Version: 1.0
*
* Description: This file is the public interface of ble_task.c source file 
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
* Any reproduction, modification, translation, compilation, or representation
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
/******************************************************************************
* This file contains the declaration of tasks and functions used for the BLE
* application
*******************************************************************************/

/* Include guard */
#ifndef BLE_TASK_H
#define BLE_TASK_H

/* Header file includes */ 
#include "cy_device_headers.h"
#include "cycfg.h"
#include "FreeRTOS.h"
#include "queue.h"

#define NOTIFY_STRING_MAX_LENGTH (250u)
/* List of BLE commands */
typedef enum
{
    PROCESS_BLE_EVENTS,             /* Process pending Stack event*/
    SEND_TEMP_INDICATION,           /* Send temperature indication */
    SEND_NOTIFICATION,              /* Send custom notification */
    STOP_BLE                        /* Stop BLE */
}   ble_commands_list_t;

/* Data-type of BLE commands and data */
typedef struct
{   
    ble_commands_list_t command;
    void* data;
}   ble_commandAndData_t;

/* Handle for the Queue that contains BLE commands and data */
extern QueueHandle_t bleCommandDataQ;

/* Task_Ble takes care of the BLE module in this code example */    
void Task_Ble(void *pvParameters);

/* Function that returns the Tickless Idle readiness of Task_Ble */
bool Task_Ble_Tickless_Idle_Readiness (void);

#endif /* BLE_TASK_H */

/* [] END OF FILE */
