/* Include guard */
#ifndef LCD_TASK_H
#define LCD_TASK_H

/* Header file includes */
#include "cy_device_headers.h"
#include "cycfg.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "ugui.h"
cy_stc_scb_spi_context_t SPI_0_context;

UG_GUI gui;
char lcd_buf[93*176];
void spi_init(void);
void pset(UG_S16 x,UG_S16 y,UG_COLOR color);
void spi_send(void *tx, uint32_t length);
void jdi_lcd_init(void);
void lcdTask(void *arg);

#endif
