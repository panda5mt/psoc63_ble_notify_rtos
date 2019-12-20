/*******************************************************************************
* File Name: cycfg_pins.h
*
* Description:
* Pin configuration
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

#if !defined(CYCFG_PINS_H)
#define CYCFG_PINS_H

#include "cycfg_notices.h"
#include "cy_gpio.h"
#include "cycfg_routing.h"
#include "cy_smartio.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define ioss_0_port_0_pin_0_PORT GPIO_PRT0
#define ioss_0_port_0_pin_0_PIN 0U
#define ioss_0_port_0_pin_0_NUM 0U
#define ioss_0_port_0_pin_0_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_0_pin_0_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_0_HSIOM
	#define ioss_0_port_0_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_0_pin_0_IRQ ioss_interrupts_gpio_0_IRQn
#define ioss_0_port_0_pin_1_PORT GPIO_PRT0
#define ioss_0_port_0_pin_1_PIN 1U
#define ioss_0_port_0_pin_1_NUM 1U
#define ioss_0_port_0_pin_1_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_0_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_1_HSIOM
	#define ioss_0_port_0_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_0_pin_1_IRQ ioss_interrupts_gpio_0_IRQn
#define KIT_BTN1_PORT GPIO_PRT0
#define KIT_BTN1_PIN 4U
#define KIT_BTN1_NUM 4U
#define KIT_BTN1_DRIVEMODE CY_GPIO_DM_PULLUP
#define KIT_BTN1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_4_HSIOM
	#define ioss_0_port_0_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define KIT_BTN1_HSIOM ioss_0_port_0_pin_4_HSIOM
#define KIT_BTN1_IRQ ioss_interrupts_gpio_0_IRQn
#define TEST_PIN_PORT GPIO_PRT0
#define TEST_PIN_PIN 5U
#define TEST_PIN_NUM 5U
#define TEST_PIN_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define TEST_PIN_INIT_DRIVESTATE 1
#ifndef ioss_0_port_0_pin_5_HSIOM
	#define ioss_0_port_0_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define TEST_PIN_HSIOM ioss_0_port_0_pin_5_HSIOM
#define TEST_PIN_IRQ ioss_interrupts_gpio_0_IRQn
#define I2C_0_SCL_PORT GPIO_PRT10
#define I2C_0_SCL_PIN 0U
#define I2C_0_SCL_NUM 0U
#define I2C_0_SCL_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define I2C_0_SCL_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_0_HSIOM
	#define ioss_0_port_10_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define I2C_0_SCL_HSIOM ioss_0_port_10_pin_0_HSIOM
#define I2C_0_SCL_IRQ ioss_interrupts_gpio_10_IRQn
#define I2C_0_SDA_PORT GPIO_PRT10
#define I2C_0_SDA_PIN 1U
#define I2C_0_SDA_NUM 1U
#define I2C_0_SDA_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define I2C_0_SDA_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_1_HSIOM
	#define ioss_0_port_10_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define I2C_0_SDA_HSIOM ioss_0_port_10_pin_1_HSIOM
#define I2C_0_SDA_IRQ ioss_interrupts_gpio_10_IRQn
#define ioss_0_port_10_pin_2_PORT GPIO_PRT10
#define ioss_0_port_10_pin_2_PIN 2U
#define ioss_0_port_10_pin_2_NUM 2U
#define ioss_0_port_10_pin_2_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_10_pin_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_2_HSIOM
	#define ioss_0_port_10_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_10_pin_2_IRQ ioss_interrupts_gpio_10_IRQn
#define ioss_0_port_10_pin_3_PORT GPIO_PRT10
#define ioss_0_port_10_pin_3_PIN 3U
#define ioss_0_port_10_pin_3_NUM 3U
#define ioss_0_port_10_pin_3_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_10_pin_3_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_3_HSIOM
	#define ioss_0_port_10_pin_3_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_10_pin_3_IRQ ioss_interrupts_gpio_10_IRQn
#define LCD_nCS_PORT GPIO_PRT10
#define LCD_nCS_PIN 4U
#define LCD_nCS_NUM 4U
#define LCD_nCS_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define LCD_nCS_INIT_DRIVESTATE 0
#ifndef ioss_0_port_10_pin_4_HSIOM
	#define ioss_0_port_10_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define LCD_nCS_HSIOM ioss_0_port_10_pin_4_HSIOM
#define LCD_nCS_IRQ ioss_interrupts_gpio_10_IRQn
#define A_VIN_PORT GPIO_PRT10
#define A_VIN_PIN 5U
#define A_VIN_NUM 5U
#define A_VIN_DRIVEMODE CY_GPIO_DM_ANALOG
#define A_VIN_INIT_DRIVESTATE 1
#ifndef ioss_0_port_10_pin_5_HSIOM
	#define ioss_0_port_10_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define A_VIN_HSIOM ioss_0_port_10_pin_5_HSIOM
#define A_VIN_IRQ ioss_interrupts_gpio_10_IRQn
#define DEBUG_UART_RX_PORT GPIO_PRT5
#define DEBUG_UART_RX_PIN 0U
#define DEBUG_UART_RX_NUM 0U
#define DEBUG_UART_RX_DRIVEMODE CY_GPIO_DM_HIGHZ
#define DEBUG_UART_RX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_0_HSIOM
	#define ioss_0_port_5_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define DEBUG_UART_RX_HSIOM ioss_0_port_5_pin_0_HSIOM
#define DEBUG_UART_RX_IRQ ioss_interrupts_gpio_5_IRQn
#define DEBUG_UART_TX_PORT GPIO_PRT5
#define DEBUG_UART_TX_PIN 1U
#define DEBUG_UART_TX_NUM 1U
#define DEBUG_UART_TX_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define DEBUG_UART_TX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_1_HSIOM
	#define ioss_0_port_5_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define DEBUG_UART_TX_HSIOM ioss_0_port_5_pin_1_HSIOM
#define DEBUG_UART_TX_IRQ ioss_interrupts_gpio_5_IRQn
#define ioss_0_port_5_pin_6_PORT GPIO_PRT5
#define ioss_0_port_5_pin_6_PIN 6U
#define ioss_0_port_5_pin_6_NUM 6U
#define ioss_0_port_5_pin_6_DRIVEMODE CY_GPIO_DM_HIGHZ
#define ioss_0_port_5_pin_6_INIT_DRIVESTATE 1
#ifndef ioss_0_port_5_pin_6_HSIOM
	#define ioss_0_port_5_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_5_pin_6_IRQ ioss_interrupts_gpio_5_IRQn
#define ioss_0_port_6_pin_2_PORT GPIO_PRT6
#define ioss_0_port_6_pin_2_PIN 2U
#define ioss_0_port_6_pin_2_NUM 2U
#define ioss_0_port_6_pin_2_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define ioss_0_port_6_pin_2_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_2_HSIOM
	#define ioss_0_port_6_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_6_pin_2_IRQ ioss_interrupts_gpio_6_IRQn
#define KIT_UART_RX_PORT GPIO_PRT6
#define KIT_UART_RX_PIN 4U
#define KIT_UART_RX_NUM 4U
#define KIT_UART_RX_DRIVEMODE CY_GPIO_DM_HIGHZ
#define KIT_UART_RX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_4_HSIOM
	#define ioss_0_port_6_pin_4_HSIOM HSIOM_SEL_GPIO
#endif
#define KIT_UART_RX_HSIOM ioss_0_port_6_pin_4_HSIOM
#define KIT_UART_RX_IRQ ioss_interrupts_gpio_6_IRQn
#define KIT_UART_TX_PORT GPIO_PRT6
#define KIT_UART_TX_PIN 5U
#define KIT_UART_TX_NUM 5U
#define KIT_UART_TX_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define KIT_UART_TX_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_5_HSIOM
	#define ioss_0_port_6_pin_5_HSIOM HSIOM_SEL_GPIO
#endif
#define KIT_UART_TX_HSIOM ioss_0_port_6_pin_5_HSIOM
#define KIT_UART_TX_IRQ ioss_interrupts_gpio_6_IRQn
#define SWDIO_PORT GPIO_PRT6
#define SWDIO_PIN 6U
#define SWDIO_NUM 6U
#define SWDIO_DRIVEMODE CY_GPIO_DM_PULLUP
#define SWDIO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_6_HSIOM
	#define ioss_0_port_6_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define SWDIO_HSIOM ioss_0_port_6_pin_6_HSIOM
#define SWDIO_IRQ ioss_interrupts_gpio_6_IRQn
#define SWCLK_PORT GPIO_PRT6
#define SWCLK_PIN 7U
#define SWCLK_NUM 7U
#define SWCLK_DRIVEMODE CY_GPIO_DM_PULLDOWN
#define SWCLK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_6_pin_7_HSIOM
	#define ioss_0_port_6_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define SWCLK_HSIOM ioss_0_port_6_pin_7_HSIOM
#define SWCLK_IRQ ioss_interrupts_gpio_6_IRQn
#define ioss_0_port_7_pin_1_PORT GPIO_PRT7
#define ioss_0_port_7_pin_1_PIN 1U
#define ioss_0_port_7_pin_1_NUM 1U
#define ioss_0_port_7_pin_1_DRIVEMODE CY_GPIO_DM_OD_DRIVESLOW
#define ioss_0_port_7_pin_1_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_1_HSIOM
	#define ioss_0_port_7_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_7_pin_1_IRQ ioss_interrupts_gpio_7_IRQn
#define ioss_0_port_7_pin_7_PORT GPIO_PRT7
#define ioss_0_port_7_pin_7_PIN 7U
#define ioss_0_port_7_pin_7_NUM 7U
#define ioss_0_port_7_pin_7_DRIVEMODE CY_GPIO_DM_ANALOG
#define ioss_0_port_7_pin_7_INIT_DRIVESTATE 1
#ifndef ioss_0_port_7_pin_7_HSIOM
	#define ioss_0_port_7_pin_7_HSIOM HSIOM_SEL_GPIO
#endif
#define ioss_0_port_7_pin_7_IRQ ioss_interrupts_gpio_7_IRQn
#define SPI_0_MOSI_PORT GPIO_PRT9
#define SPI_0_MOSI_PIN 0U
#define SPI_0_MOSI_NUM 0U
#define SPI_0_MOSI_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define SPI_0_MOSI_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_0_HSIOM
	#define ioss_0_port_9_pin_0_HSIOM HSIOM_SEL_GPIO
#endif
#define SPI_0_MOSI_HSIOM ioss_0_port_9_pin_0_HSIOM
#define SPI_0_MOSI_IRQ ioss_interrupts_gpio_9_IRQn
#define SPI_0_MISO_PORT GPIO_PRT9
#define SPI_0_MISO_PIN 1U
#define SPI_0_MISO_NUM 1U
#define SPI_0_MISO_DRIVEMODE CY_GPIO_DM_HIGHZ
#define SPI_0_MISO_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_1_HSIOM
	#define ioss_0_port_9_pin_1_HSIOM HSIOM_SEL_GPIO
#endif
#define SPI_0_MISO_HSIOM ioss_0_port_9_pin_1_HSIOM
#define SPI_0_MISO_IRQ ioss_interrupts_gpio_9_IRQn
#define SPI_0_SCLK_PORT GPIO_PRT9
#define SPI_0_SCLK_PIN 2U
#define SPI_0_SCLK_NUM 2U
#define SPI_0_SCLK_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define SPI_0_SCLK_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_2_HSIOM
	#define ioss_0_port_9_pin_2_HSIOM HSIOM_SEL_GPIO
#endif
#define SPI_0_SCLK_HSIOM ioss_0_port_9_pin_2_HSIOM
#define SPI_0_SCLK_IRQ ioss_interrupts_gpio_9_IRQn
#define PWM_FREQ_out_PORT GPIO_PRT9
#define PWM_FREQ_out_PIN 6U
#define PWM_FREQ_out_NUM 6U
#define PWM_FREQ_out_DRIVEMODE CY_GPIO_DM_STRONG_IN_OFF
#define PWM_FREQ_out_INIT_DRIVESTATE 1
#ifndef ioss_0_port_9_pin_6_HSIOM
	#define ioss_0_port_9_pin_6_HSIOM HSIOM_SEL_GPIO
#endif
#define PWM_FREQ_out_HSIOM ioss_0_port_9_pin_6_HSIOM
#define PWM_FREQ_out_IRQ ioss_interrupts_gpio_9_IRQn
#define SMARTIO_0_HW SMARTIO_PRT9

extern const cy_stc_gpio_pin_config_t ioss_0_port_0_pin_0_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_0_pin_1_config;
extern const cy_stc_gpio_pin_config_t KIT_BTN1_config;
extern const cy_stc_gpio_pin_config_t TEST_PIN_config;
extern const cy_stc_gpio_pin_config_t I2C_0_SCL_config;
extern const cy_stc_gpio_pin_config_t I2C_0_SDA_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_10_pin_2_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_10_pin_3_config;
extern const cy_stc_gpio_pin_config_t LCD_nCS_config;
extern const cy_stc_gpio_pin_config_t A_VIN_config;
extern const cy_stc_gpio_pin_config_t DEBUG_UART_RX_config;
extern const cy_stc_gpio_pin_config_t DEBUG_UART_TX_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_5_pin_6_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_6_pin_2_config;
extern const cy_stc_gpio_pin_config_t KIT_UART_RX_config;
extern const cy_stc_gpio_pin_config_t KIT_UART_TX_config;
extern const cy_stc_gpio_pin_config_t SWDIO_config;
extern const cy_stc_gpio_pin_config_t SWCLK_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_1_config;
extern const cy_stc_gpio_pin_config_t ioss_0_port_7_pin_7_config;
extern const cy_stc_gpio_pin_config_t SPI_0_MOSI_config;
extern const cy_stc_gpio_pin_config_t SPI_0_MISO_config;
extern const cy_stc_gpio_pin_config_t SPI_0_SCLK_config;
extern const cy_stc_gpio_pin_config_t PWM_FREQ_out_config;
extern const cy_stc_smartio_config_t SMARTIO_0_config;

void init_cycfg_pins(void);

#if defined(__cplusplus)
}
#endif


#endif /* CYCFG_PINS_H */
