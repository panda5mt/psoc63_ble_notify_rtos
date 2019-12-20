/*******************************************************************************
* File Name: cycfg_routing.h
*
* Description:
* Establishes all necessary connections between hardware elements.
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

#if !defined(CYCFG_ROUTING_H)
#define CYCFG_ROUTING_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "cycfg_notices.h"
void init_cycfg_routing(void);
#define init_cycfg_connectivity() init_cycfg_routing()
#define ioss_0_port_0_pin_5_HSIOM P0_5_PERI_TR_IO_OUTPUT1
#define ioss_0_port_10_pin_0_HSIOM P10_0_SCB1_I2C_SCL
#define ioss_0_port_10_pin_1_HSIOM P10_1_SCB1_I2C_SDA
#define ioss_0_port_10_pin_3_HSIOM HSIOM_SEL_AMUXB
#define ioss_0_port_10_pin_5_HSIOM HSIOM_SEL_AMUXA
#define ioss_0_port_5_pin_0_HSIOM P5_0_SCB5_UART_RX
#define ioss_0_port_5_pin_1_HSIOM P5_1_SCB5_UART_TX
#define ioss_0_port_5_pin_6_HSIOM HSIOM_SEL_AMUXA
#define ioss_0_port_5_pin_7_HSIOM HSIOM_SEL_AMUXB
#define ioss_0_port_6_pin_2_HSIOM P6_2_TCPWM0_LINE1
#define ioss_0_port_6_pin_4_HSIOM P6_4_SCB6_UART_RX
#define ioss_0_port_6_pin_5_HSIOM P6_5_SCB6_UART_TX
#define ioss_0_port_6_pin_6_HSIOM P6_6_CPUSS_SWJ_SWDIO_TMS
#define ioss_0_port_6_pin_7_HSIOM P6_7_CPUSS_SWJ_SWCLK_TCLK
#define ioss_0_port_9_pin_0_HSIOM P9_0_SCB2_SPI_MOSI
#define ioss_0_port_9_pin_1_HSIOM P9_1_SCB2_SPI_MISO
#define ioss_0_port_9_pin_2_HSIOM P9_2_SCB2_SPI_CLK
#define ioss_0_port_9_pin_6_HSIOM P9_6_TCPWM0_LINE0

#define COMP_0_dsi_comp_0_TRIGGER_IN_0 TRIG14_IN_LPCOMP_DSI_COMP0
#define COMP_0_dsi_comp_0_TRIGGER_IN_1 TRIG8_IN_TR_GROUP14_OUTPUT15
#define Counter_0_capture_0_TRIGGER_OUT TRIG2_OUT_TCPWM0_TR_IN13
#define Counter_0_count_0_TRIGGER_OUT TRIG2_OUT_TCPWM0_TR_IN0
#define PWM_FreqGen_tr_compare_match_0_TRIGGER_IN_0 TRIG11_IN_TCPWM0_TR_COMPARE_MATCH0
#define PWM_FreqGen_tr_compare_match_0_TRIGGER_IN_1 TRIG2_IN_TR_GROUP11_OUTPUT7
#define PWM_Window_tr_compare_match_0_TRIGGER_IN_0 TRIG11_IN_TCPWM0_TR_COMPARE_MATCH1
#define PWM_Window_tr_compare_match_0_TRIGGER_IN_1 TRIG2_IN_TR_GROUP11_OUTPUT0
#define TEST_PIN_digital_out_0_TRIGGER_OUT TRIG8_OUT_PERI_TR_IO_OUTPUT1

#define TCPWM0_CNT2_CAPTURE_VALUE 0xf
#define TCPWM0_CNT2_COUNT_VALUE 0x2

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_ROUTING_H */
