/*******************************************************************************
* File Name: cycfg_routing.c
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

#include "cycfg_routing.h"

#include "cy_trigmux.h"

#include "stdbool.h"

#include "cy_device_headers.h"

void init_cycfg_routing(void)
{
	Cy_TrigMux_Connect(TRIG11_IN_TCPWM0_TR_COMPARE_MATCH0, TRIG11_OUT_TR_GROUP2_INPUT16, false, TRIGGER_TYPE_LEVEL);
	Cy_TrigMux_Connect(TRIG11_IN_TCPWM0_TR_COMPARE_MATCH1, TRIG11_OUT_TR_GROUP2_INPUT9, false, TRIGGER_TYPE_LEVEL);
	Cy_TrigMux_Connect(TRIG14_IN_LPCOMP_DSI_COMP0, TRIG14_OUT_TR_GROUP8_INPUT42, false, TRIGGER_TYPE_LEVEL);
	Cy_TrigMux_Connect(TRIG2_IN_TR_GROUP11_OUTPUT0, TRIG2_OUT_TCPWM0_TR_IN13, false, TRIGGER_TYPE_LEVEL);
	Cy_TrigMux_Connect(TRIG2_IN_TR_GROUP11_OUTPUT7, TRIG2_OUT_TCPWM0_TR_IN0, false, TRIGGER_TYPE_LEVEL);
	Cy_TrigMux_Connect(TRIG8_IN_TR_GROUP14_OUTPUT15, TRIG8_OUT_PERI_TR_IO_OUTPUT1, false, TRIGGER_TYPE_LEVEL);
	HSIOM->AMUX_SPLIT_CTL[4] = HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_SL_Msk |
		HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_SR_Msk |
		HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SL_Msk |
		HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SR_Msk;
	HSIOM->AMUX_SPLIT_CTL[5] = HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_SL_Msk |
		HSIOM_AMUX_SPLIT_CTL_SWITCH_AA_SR_Msk |
		HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SL_Msk |
		HSIOM_AMUX_SPLIT_CTL_SWITCH_BB_SR_Msk;
	LPCOMP->CMP0_SW = LPCOMP_CMP0_SW_CMP0_IN0_Msk |
		LPCOMP_CMP0_SW_CMP0_IP0_Msk;
	HSIOM->PRT[5].PORT_SEL1 = (HSIOM->PRT[5].PORT_SEL1 & ~HSIOM_PRT_PORT_SEL1_IO6_SEL_Msk) | (HSIOM_SEL_AMUXA << HSIOM_PRT_PORT_SEL1_IO6_SEL_Pos);
	HSIOM->PRT[5].PORT_SEL1 = (HSIOM->PRT[5].PORT_SEL1 & ~HSIOM_PRT_PORT_SEL1_IO7_SEL_Msk) | (HSIOM_SEL_AMUXB << HSIOM_PRT_PORT_SEL1_IO7_SEL_Pos);
}
