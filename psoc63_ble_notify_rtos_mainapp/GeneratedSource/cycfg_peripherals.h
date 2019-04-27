/*******************************************************************************
* File Name: cycfg_peripherals.h
*
* Description:
* Peripheral Hardware Block configuration
* This file was automatically generated and should not be modified.
* 
********************************************************************************
* Copyright 2017-2019 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
********************************************************************************/

#if !defined(CYCFG_PERIPHERALS_H)
#define CYCFG_PERIPHERALS_H

#include "cycfg_notices.h"
#include "cy_scb_spi.h"
#include "cy_sysclk.h"
#include "cy_scb_uart.h"
#include "cy_mcwdt.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define CY_BLE_CORE_CORTEX_M4 4U
#define CY_BLE_CORE_CORTEX_M0P 0U
#define CY_BLE_CORE_DUAL 255U
#ifndef CY_BLE_CORE
	#define CY_BLE_CORE 4U
#endif
#define CY_BLE_IRQ bless_interrupt_IRQn
#define SPI_0_HW SCB1
#define SPI_0_IRQ scb_1_interrupt_IRQn
#define KIT_UART_HW SCB2
#define KIT_UART_IRQ scb_2_interrupt_IRQn
#define DEBUG_UART_HW SCB5
#define DEBUG_UART_IRQ scb_5_interrupt_IRQn
#define MCWDT_HW MCWDT_STRUCT0
#define MCWDT_IRQ srss_interrupt_mcwdt_0_IRQn

extern const cy_stc_scb_spi_config_t SPI_0_config;
extern const cy_stc_scb_uart_config_t KIT_UART_config;
extern const cy_stc_scb_uart_config_t DEBUG_UART_config;
extern const cy_stc_mcwdt_config_t MCWDT_config;

void init_cycfg_peripherals(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_PERIPHERALS_H */
