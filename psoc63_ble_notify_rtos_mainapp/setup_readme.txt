Simple FreeRTOS-based application for the PSoC 6 Pioneer kits (CY8CKIT-062-*)
with a single task that blinks an LED at 1Hz.

Debug is enabled and platform clocks are set for high performance (144MHz
CLK_FAST for CM4 core and 72MHz CLK_SLOW for CM0+) but with a peripheral-
friendly CLK_PERI frequency (72MHz). In addition the user LEDs and switch,
KitProg3 UART and I2C bridges, and CapSense buttons and slider are configured.

The following is a summary of the PSoC configuration in this project. To modify
the settings, click "Configure device" in the Quick Panel or double-click on the
"design.modus" file in the _config project.

CLOCKS 

Platform clocks are set for high performance (144 MHz CLK_FAST for CM4 core
and 72 MHz CLK_SLOW for CM0+) but with a peripheral-friendly CLK_PERI
frequency (72 MHz).

FLL (Frequency-Locked Loop)       Disabled
PLL (Phase-Locked Loop)           Enabled
  Source:                         IMO (8 MHz)
  Frequency:                      144 MHz
CLK_HF0
  Source:                         CLK_PATH1 / PLL (144 MHz)
CLK_FAST (CM4 clock)
  Source:                         CLK_HF0 (144 MHz)
CLK_PERI (peripheral clock)
  Source:                         CLK_HF0 (144 MHz)
  Divider:                        2
  Frequency:                      72 MHz
CLK_SLOW (CM0+ clock)
  Source:                         CLK_PERI (72 MHz)


PINS 

The pins for the user LEDs and and button are configured (initially off).

User LED8 (orange)
  Pin:                            P1[5], "KIT_LED1"
  Drive Mode:                     CY_GPIO_DM_STRONG_IN_OFF
  Initial State:                  1

User LED9 (red)
  Pin:                            P13[7], "KIT_LED2"
  Drive Mode:                     CY_GPIO_DM_STRONG_IN_OFF
  Initial State:                  1

User RGB LED5
  Pins:                           P0[3], "KIT_RGB_R"
                                  P1[1], "KIT_RGB_G"
                                  P11[1], "KIT_RGB_B"
  Drive Mode:                     CY_GPIO_DM_STRONG_IN_OFF
  Initial State:                  1

User Button SW2
  Pin:                            P0[4], "KIT_BTN1"
  Drive Mode:                     CY_GPIO_DM_PULLUP
  Initial State:                  1
  Interrupt Trigger Type:         Falling Edge


PERIPHERALS 

The KitProg3 bridge channels for UART and I2C are configured, as well as the
CapSense slider and two button widgets.

UART Bridge
  Peripheral:                     SCB5
  Personality:                    UART, "KIT_UART"
  Baud Rate (bps):                115200 (actual 115384)
  Clock:                          16 bit Divider 0 (923.1kHz), "KIT_UART_Clock"
    Divider:                      78
  RX:                             P5[0], "KIT_UART_RX"
    Drive Mode:                   CY_GPIO_DM_HIGHZ
    Terminal(s):                  digital_inout
  TX:                             P5[1], "KIT_UART_TX"
    Drive Mode:                   CY_GPIO_DM_STRONG_IN_OFF
    Terminal(s):                  digital_inout

I2C Bridge
  Peripheral:                     SCB3
  Personality:                    EZI2C, "KIT_I2C"
  Data Rate (kbps):               100
  Clock:                          8 bit Divider 0 (12 MHz), "KIT_I2C_Clock"
    Divider:                      6
  SCL:                            P6[0], "KIT_I2C_SCL"
    Drive Mode:                   CY_GPIO_DM_OD_DRIVESLOW
    Terminal(s):                  digital_inout
  SDA:                            P6[1], "KIT_I2C_SDA"
    Drive Mode:                   CY_GPIO_DM_OD_DRIVESLOW
    Terminal(s):                  digital_inout

CapSense slider and two buttons (proximity can be set up on P8[0])
  Peripheral:                     CSD
  Personality:                    CSD, "CapSense"
  Clock:                          8 bit Divider 1, "CapSense_Clock"
    Divider:                      N/A (CapSense middleware sets the divider)
  Button 0:                       P8[1], "CapSense_Button0_Sns0"
  Button 1:                       P8[2], "CapSense_Button1_Sns0"
  LinearSlider:                   P8[3..7], "CapSense_LinearSlider0_Sns0..4"
  CMOD:                           P7[7], "CapSense_CMOD"


MIDDLEWARE
  Retarget I/O for stdio using Bridge_UART (SCB5)
  CapSense SoftFP
  FreeRTOS


