#include "lcd_task.h"
#include "stdio.h"
#include "uart_debug.h"
#include "math.h"

const TickType_t xDelay = 1 / portTICK_PERIOD_MS; // 1msec
UG_RESULT _HW_FillFrame( UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR color);
void _lcd_redraw(void);
void lcdTask(void *arg){
	(void)arg;

	spi_init();
	jdi_lcd_init();

	CyDelay(100);

	UG_Init(&gui, (void(*)(UG_S16,UG_S16,UG_COLOR)) pset,176+1,176+1);
	UG_DriverRegister(DRIVER_FILL_FRAME, (void*)_HW_FillFrame);
	CyDelayUs(10);

	while(1){
		CyDelay(1000);
		UG_FillScreen(C_RED);
		CyDelay(1000);
		UG_FillScreen(C_GREEN);
		CyDelay(1000);
		UG_FillScreen(C_BLUE);
		CyDelay(1000);
		UG_FillScreen(C_PURPLE);
		CyDelay(1000);
		UG_FillScreen(C_WHITE);

	UG_FontSelect(&FONT_24X40);
	UG_SetBackcolor(C_WHITE);
	UG_SetForecolor(C_RED);
	UG_PutString(1,1,"HELLO world....!!");
	_lcd_redraw();
	CyDelay(1000);
	}
	while(1);
	//pset(10, 10, C_RED);
}

void spi_init(void){
	Cy_SCB_SPI_Init(SPI_0_HW, &SPI_0_config, &SPI_0_context);
	Cy_SCB_SPI_Enable(SPI_0_HW);
}



// uGUI instances
void pset(UG_S16 x,UG_S16 y,UG_COLOR color){

	char color4b = 0;
    char r,g,b,buf;
    char mod_x;
    r = (color >> 16) & 0x80;
    g = (color >> 8) & 0x80;
    b = (color) & 0x80;
    y = (1 > y)?1:y;
    // color:R8+G8+B8 -> R1+G1+B1+DUMY1
    mod_x = x % 2;
    x = x / 2;
    color4b = r + (g >> 1) + (b >> 2);

    buf = lcd_buf[(y*88)+x];
    if(!mod_x){
        buf = (buf & 0x0F) + color4b;
    }else{
        buf = (buf & 0xF0) + (color4b >> 4);
    }
    lcd_buf[(y*88)+x] = buf;

    return;
}

UG_RESULT _HW_FillFrame( UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2, UG_COLOR color ){
	if(x1 > x2)return UG_RESULT_FAIL;
	if(y1 > y2)return UG_RESULT_FAIL;

	char color4b = 0;
	char r,g,b,buf;
	char mod_x, cal_x;

	r = (color >> 16) & 0x80;
	g = (color >> 8) & 0x80;
	b = (color) & 0x80;
	y1 = (1 > y1)?1:y1;
	y2 = (1 > y2)?1:y2;

	// color:R8+G8+B8 -> R1+G1+B1+DUMY1
	color4b = r + (g >> 1) + (b >> 2);

	for (int y = y1; y < (y2 + 1); y++){
		for(int x = x1; x < x2; x++){
			mod_x = x % 2;
			cal_x = x / 2;
			buf = lcd_buf[(y*88)+cal_x];
			if(!mod_x){
				buf = (buf & 0x0F) + color4b;
			}else{
				buf = (buf & 0xF0) + (color4b >> 4);
			}
			lcd_buf[(y*88) + cal_x] = buf;
		}
	}
	Cy_GPIO_Set(LCD_nCS_PORT,LCD_nCS_PIN); //scs.high();
	CyDelayUs(6);

	for (int y = y1; y < (y2 + 1); y++){
		spi_send(0x90, 1UL);
		spi_send(y, 1UL);
		for (int i = 0;i<88;i++) spi_send(lcd_buf[(y*88+i)], 1UL);
	}
	spi_send(0x00, 1UL);
	spi_send(0x00, 1UL);

	CyDelayUs(6);
	Cy_GPIO_Clr(LCD_nCS_PORT,LCD_nCS_PIN); //scs.low();

	return UG_RESULT_OK;
}


void spi_send(void *tx, uint32_t length){

	Cy_SCB_SPI_WriteArrayBlocking(SPI_0_HW, &tx, length);
	while (!Cy_SCB_SPI_IsTxComplete(SPI_0_HW));

}

void jdi_lcd_init(void){

	char txbuf[2]={0x20,0x00}; //All Reset

    Cy_GPIO_Clr(LCD_nCS_PORT,LCD_nCS_PIN);
    CyDelayUs(6);//10);
    Cy_GPIO_Set(LCD_nCS_PORT,LCD_nCS_PIN);
    CyDelayUs(6);//10);
    spi_send(txbuf,2UL);

    CyDelayUs(6);//10);
    Cy_GPIO_Clr(LCD_nCS_PORT,LCD_nCS_PIN);
}

void _lcd_redraw(void){
	Cy_GPIO_Set(LCD_nCS_PORT,LCD_nCS_PIN); //scs.high();
	CyDelayUs(6);
	for (int y = 1; y < 177; y++){
		spi_send(0x90, 1UL);
		spi_send(y, 1UL);
		for (int i = 0;i<88;i++) spi_send(lcd_buf[(y*88+i)], 1UL);
	}
	spi_send(0x00, 1UL);
	spi_send(0x00, 1UL);
	Cy_GPIO_Clr(LCD_nCS_PORT,LCD_nCS_PIN); //scs.low();
	CyDelayUs(6);
}
