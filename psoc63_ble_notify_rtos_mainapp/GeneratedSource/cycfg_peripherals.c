/*******************************************************************************
* File Name: cycfg_peripherals.c
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

#include "cycfg_peripherals.h"

#define PWM_FreqGen_INPUT_DISABLED 0x7U
#define PWM_Window_INPUT_DISABLED 0x7U
#define Counter_0_INPUT_DISABLED 0x7U

const cy_stc_lpcomp_config_t COMP_0_config = 
{
	.outputMode = CY_LPCOMP_OUT_SYNC,
	.hysteresis = CY_LPCOMP_HYST_ENABLE,
	.power = CY_LPCOMP_MODE_NORMAL,
	.intType = CY_LPCOMP_INTR_DISABLE,
};
const cy_stc_sysanalog_config_t AREF_config = 
{
	.startup = CY_SYSANALOG_STARTUP_FAST,
	.iztat = CY_SYSANALOG_IZTAT_SOURCE_LOCAL,
	.vref = CY_SYSANALOG_VREF_SOURCE_LOCAL_1_2V,
	.deepSleep = CY_SYSANALOG_DEEPSLEEP_DISABLE,
};
const cy_stc_scb_i2c_config_t I2C_0_config = 
{
	.i2cMode = CY_SCB_I2C_MASTER,
	.useRxFifo = true,
	.useTxFifo = true,
	.slaveAddress = 0U,
	.slaveAddressMask = 0U,
	.acceptAddrInFifo = false,
	.ackGeneralAddr = false,
	.enableWakeFromSleep = false,
	.enableDigitalFilter = true,
	.lowPhaseDutyCycle = 16,
	.highPhaseDutyCycle = 10,
};
const cy_stc_scb_spi_config_t SPI_0_config = 
{
	.spiMode = CY_SCB_SPI_MASTER,
	.subMode = CY_SCB_SPI_MOTOROLA,
	.sclkMode = CY_SCB_SPI_CPHA0_CPOL0,
	.oversample = 16,
	.rxDataWidth = 8UL,
	.txDataWidth = 8UL,
	.enableMsbFirst = true,
	.enableInputFilter = false,
	.enableFreeRunSclk = false,
	.enableMisoLateSample = true,
	.enableTransferSeperation = false,
	.ssPolarity = ((CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT0) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT1) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT2) | \
                                         (CY_SCB_SPI_ACTIVE_LOW << CY_SCB_SPI_SLAVE_SELECT3)),
	.enableWakeFromSleep = false,
	.rxFifoTriggerLevel = 63UL,
	.rxFifoIntEnableMask = 0UL,
	.txFifoTriggerLevel = 63UL,
	.txFifoIntEnableMask = 0UL,
	.masterSlaveIntEnableMask = 0UL,
};
const cy_stc_scb_uart_config_t DEBUG_UART_config = 
{
	.uartMode = CY_SCB_UART_STANDARD,
	.enableMutliProcessorMode = false,
	.smartCardRetryOnNack = false,
	.irdaInvertRx = false,
	.irdaEnableLowPowerReceiver = false,
	.oversample = 8,
	.enableMsbFirst = false,
	.dataWidth = 8UL,
	.parity = CY_SCB_UART_PARITY_NONE,
	.stopBits = CY_SCB_UART_STOP_BITS_1,
	.enableInputFilter = false,
	.breakWidth = 11UL,
	.dropOnFrameError = false,
	.dropOnParityError = false,
	.receiverAddress = 0x0UL,
	.receiverAddressMask = 0x0UL,
	.acceptAddrInFifo = false,
	.enableCts = false,
	.ctsPolarity = CY_SCB_UART_ACTIVE_LOW,
	.rtsRxFifoLevel = 0UL,
	.rtsPolarity = CY_SCB_UART_ACTIVE_LOW,
	.rxFifoTriggerLevel = 63UL,
	.rxFifoIntEnableMask = 0UL,
	.txFifoTriggerLevel = 63UL,
	.txFifoIntEnableMask = 0UL,
};
const cy_stc_scb_uart_config_t KIT_UART_config = 
{
	.uartMode = CY_SCB_UART_STANDARD,
	.enableMutliProcessorMode = false,
	.smartCardRetryOnNack = false,
	.irdaInvertRx = false,
	.irdaEnableLowPowerReceiver = false,
	.oversample = 8,
	.enableMsbFirst = false,
	.dataWidth = 8UL,
	.parity = CY_SCB_UART_PARITY_NONE,
	.stopBits = CY_SCB_UART_STOP_BITS_1,
	.enableInputFilter = false,
	.breakWidth = 11UL,
	.dropOnFrameError = false,
	.dropOnParityError = false,
	.receiverAddress = 0x0UL,
	.receiverAddressMask = 0x0UL,
	.acceptAddrInFifo = false,
	.enableCts = false,
	.ctsPolarity = CY_SCB_UART_ACTIVE_LOW,
	.rtsRxFifoLevel = 0UL,
	.rtsPolarity = CY_SCB_UART_ACTIVE_LOW,
	.rxFifoTriggerLevel = 63UL,
	.rxFifoIntEnableMask = 0UL,
	.txFifoTriggerLevel = 63UL,
	.txFifoIntEnableMask = 0UL,
};
const cy_stc_mcwdt_config_t MCWDT_config = 
{
	.c0Match = 65535U,
	.c1Match = 32768U,
	.c0Mode = CY_MCWDT_MODE_INT,
	.c1Mode = CY_MCWDT_MODE_NONE,
	.c2ToggleBit = 16U,
	.c2Mode = CY_MCWDT_MODE_NONE,
	.c0ClearOnMatch = true,
	.c1ClearOnMatch = false,
	.c0c1Cascade = false,
	.c1c2Cascade = false,
};
const cy_stc_tcpwm_pwm_config_t PWM_FreqGen_config = 
{
	.pwmMode = CY_TCPWM_PWM_MODE_PWM,
	.clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
	.pwmAlignment = CY_TCPWM_PWM_LEFT_ALIGN,
	.deadTimeClocks = 0,
	.runMode = CY_TCPWM_PWM_CONTINUOUS,
	.period0 = 35,
	.period1 = 32768,
	.enablePeriodSwap = false,
	.compare0 = 18,
	.compare1 = 16384,
	.enableCompareSwap = false,
	.interruptSources = CY_TCPWM_INT_NONE,
	.invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
	.invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
	.killMode = CY_TCPWM_PWM_STOP_ON_KILL,
	.swapInputMode = PWM_FreqGen_INPUT_DISABLED & 0x3U,
	.swapInput = CY_TCPWM_INPUT_0,
	.reloadInputMode = PWM_FreqGen_INPUT_DISABLED & 0x3U,
	.reloadInput = CY_TCPWM_INPUT_0,
	.startInputMode = PWM_FreqGen_INPUT_DISABLED & 0x3U,
	.startInput = CY_TCPWM_INPUT_0,
	.killInputMode = PWM_FreqGen_INPUT_DISABLED & 0x3U,
	.killInput = CY_TCPWM_INPUT_0,
	.countInputMode = PWM_FreqGen_INPUT_DISABLED & 0x3U,
	.countInput = CY_TCPWM_INPUT_1,
};
const cy_stc_tcpwm_pwm_config_t PWM_Window_config = 
{
	.pwmMode = CY_TCPWM_PWM_MODE_PWM,
	.clockPrescaler = CY_TCPWM_PWM_PRESCALER_DIVBY_1,
	.pwmAlignment = CY_TCPWM_PWM_LEFT_ALIGN,
	.deadTimeClocks = 0,
	.runMode = CY_TCPWM_PWM_CONTINUOUS,
	.period0 = 24,
	.period1 = 32768,
	.enablePeriodSwap = false,
	.compare0 = 13,
	.compare1 = 16384,
	.enableCompareSwap = false,
	.interruptSources = CY_TCPWM_INT_NONE,
	.invertPWMOut = CY_TCPWM_PWM_INVERT_DISABLE,
	.invertPWMOutN = CY_TCPWM_PWM_INVERT_DISABLE,
	.killMode = CY_TCPWM_PWM_STOP_ON_KILL,
	.swapInputMode = PWM_Window_INPUT_DISABLED & 0x3U,
	.swapInput = CY_TCPWM_INPUT_0,
	.reloadInputMode = PWM_Window_INPUT_DISABLED & 0x3U,
	.reloadInput = CY_TCPWM_INPUT_0,
	.startInputMode = PWM_Window_INPUT_DISABLED & 0x3U,
	.startInput = CY_TCPWM_INPUT_0,
	.killInputMode = PWM_Window_INPUT_DISABLED & 0x3U,
	.killInput = CY_TCPWM_INPUT_0,
	.countInputMode = PWM_Window_INPUT_DISABLED & 0x3U,
	.countInput = CY_TCPWM_INPUT_1,
};
const cy_stc_tcpwm_counter_config_t Counter_0_config = 
{
	.period = 65535,
	.clockPrescaler = CY_TCPWM_COUNTER_PRESCALER_DIVBY_1,
	.runMode = CY_TCPWM_COUNTER_CONTINUOUS,
	.countDirection = CY_TCPWM_COUNTER_COUNT_UP,
	.compareOrCapture = CY_TCPWM_COUNTER_MODE_CAPTURE,
	.compare0 = 16384,
	.compare1 = 16384,
	.enableCompareSwap = false,
	.interruptSources = CY_TCPWM_INT_ON_CC_OR_TC,
	.captureInputMode = CY_TCPWM_INPUT_RISINGEDGE,
	.captureInput = TCPWM0_CNT2_CAPTURE_VALUE,
	.reloadInputMode = Counter_0_INPUT_DISABLED & 0x3U,
	.reloadInput = CY_TCPWM_INPUT_0,
	.startInputMode = Counter_0_INPUT_DISABLED & 0x3U,
	.startInput = CY_TCPWM_INPUT_0,
	.stopInputMode = Counter_0_INPUT_DISABLED & 0x3U,
	.stopInput = CY_TCPWM_INPUT_0,
	.countInputMode = CY_TCPWM_INPUT_RISINGEDGE,
	.countInput = TCPWM0_CNT2_COUNT_VALUE,
};


void init_cycfg_peripherals(void)
{
	Cy_SysClk_PeriphAssignDivider(PCLK_SCB1_CLOCK, CY_SYSCLK_DIV_8_BIT, 6U);

	Cy_SysClk_PeriphAssignDivider(PCLK_SCB2_CLOCK, CY_SYSCLK_DIV_8_BIT, 7U);

	Cy_SysClk_PeriphAssignDivider(PCLK_SCB5_CLOCK, CY_SYSCLK_DIV_16_BIT, 1U);

	Cy_SysClk_PeriphAssignDivider(PCLK_SCB6_CLOCK, CY_SYSCLK_DIV_16_BIT, 0U);

	Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKS0, CY_SYSCLK_DIV_8_BIT, 0U);

	Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKS1, CY_SYSCLK_DIV_8_BIT, 1U);

	Cy_SysClk_PeriphAssignDivider(PCLK_TCPWM0_CLOCKS2, CY_SYSCLK_DIV_8_BIT, 2U);
}
