/**
 * \file
 *
 * \brief SAM B11 CSP Xplained Pro board definition
 *
 * Copyright (c) 2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef SAMB11CSP_XPLAINED_PRO_H_INCLUDED
#define SAMB11CSP_XPLAINED_PRO_H_INCLUDED

#include <conf_board.h>
#include <compiler.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup group_common_boards
 * \defgroup samb11csp_xplained_pro_group SAM B11 CSP Xplained Pro board
 *
 * @{
 */

void system_board_init(void);

/**
 * \defgroup samb11csp_xplained_pro_features_group Features
 *
 * Symbols that describe features and capabilities of the board.
 *
 * @{
 */

/** Name string macro */
#define BOARD_NAME                "SAMB11CSP_XPLAINED_PRO"

/** \name Resonator definitions
 *  @{ */
#define BOARD_FREQ_SLCK_XTAL      (32768U)
#define BOARD_FREQ_SLCK_BYPASS    (32768U)
#define BOARD_FREQ_MAINCK_XTAL    0 /* Not Mounted */
#define BOARD_FREQ_MAINCK_BYPASS  0 /* Not Mounted */
#define BOARD_MCK                 CHIP_FREQ_CPU_MAX
#define BOARD_OSC_STARTUP_US      15625
/** @} */

/** \name LED0 definitions
 *  @{ */
#define LED0_PIN                  PIN_AO_GPIO_0
#define LED0_ACTIVE               false
#define LED0_INACTIVE             !LED0_ACTIVE
/** @} */

/** \name SW0 definitions
 *  @{ */
#define SW0_PIN                   PIN_LP_GPIO_1
#define SW0_ACTIVE                false
#define SW0_INACTIVE              !SW0_ACTIVE
#define SW0_EIC_PIN               
#define SW0_EIC_MUX                         
#define SW0_EIC_LINE              
/** @} */

/**
 * \name LED #0 definitions
 *
 * Wrapper macros for LED0, to ensure common naming across all Xplained Pro
 * boards.
 *
 *  @{ */
#define LED_0_NAME                "LED0 (yellow)"
#define LED_0_PIN                 LED0_PIN
#define LED_0_ACTIVE              LED0_ACTIVE
#define LED_0_INACTIVE            LED0_INACTIVE
#define LED0_GPIO                 LED0_PIN
#define LED0                      LED0_PIN

#define LED_0_PWM4CTRL_MODULE     TCC0
#define LED_0_PWM4CTRL_CHANNEL    0
#define LED_0_PWM4CTRL_OUTPUT     0
#define LED_0_PWM4CTRL_PIN        
#define LED_0_PWM4CTRL_MUX           
/** @} */

/** Number of on-board LEDs */
#define LED_COUNT                 1

/**
 * \name Serialflash definitions
 *
 * On board Serialflash definitions.
 *
 *  @{ */
#define SERIALFLASH_SPI_MODULE      
#define SERIALFLASH_SPI_MUX_SETTING
#define SERIALFLASH_SPI_PIN_PAD0
#define SERIALFLASH_SPI_PIN_PAD1
#define SERIALFLASH_SPI_PIN_PAD2
#define SERIALFLASH_SPI_PIN_PAD3 
#define SERIALFLASH_SPI_MUX_PAD0 
#define SERIALFLASH_SPI_MUX_PAD1 
#define SERIALFLASH_SPI_MUX_PAD2 
#define SERIALFLASH_SPI_MUX_PAD3 
#define SERIALFLASH_SPI_CS
/** @} */

/**
 * \name Button #0 definitions
 *
 * Wrapper macros for SW0, to ensure common naming across all Xplained Pro
 * boards.
 *
 *  @{ */
#define BUTTON_0_NAME             "SW0"
#define BUTTON_0_PIN              SW0_PIN
#define BUTTON_0_ACTIVE           SW0_ACTIVE
#define BUTTON_0_INACTIVE         SW0_INACTIVE
#define BUTTON_0_EIC_PIN          SW0_EIC_PIN
#define BUTTON_0_EIC_MUX          SW0_EIC_MUX
#define BUTTON_0_EIC_LINE         SW0_EIC_LINE
/** @} */

/** Number of on-board buttons */
#define BUTTON_COUNT 1

/** \name Extension header #1 pin definitions
 *  @{
 */
#define EXT1_PIN_3                
#define EXT1_PIN_4                
#define EXT1_PIN_5                
#define EXT1_PIN_6                
#define EXT1_PIN_7
#define EXT1_PIN_8
#define EXT1_PIN_9                
#define EXT1_PIN_10               
#define EXT1_PIN_11               
#define EXT1_PIN_12               
#define EXT1_PIN_13               
#define EXT1_PIN_14               
#define EXT1_PIN_15               
#define EXT1_PIN_16               
#define EXT1_PIN_17               
#define EXT1_PIN_18               
/** @} */

/** \name Extension header #1 pin definitions by function
 *  @{
 */
#define EXT1_PIN_ADC_0            EXT1_PIN_3
#define EXT1_PIN_ADC_1            EXT1_PIN_4
#define EXT1_PIN_GPIO_0           EXT1_PIN_5
#define EXT1_PIN_GPIO_1           EXT1_PIN_6
#define EXT1_PIN_PWM_0            EXT1_PIN_7
#define EXT1_PIN_PWM_1            EXT1_PIN_8
#define EXT1_PIN_IRQ              EXT1_PIN_9
#define EXT1_PIN_I2C_SDA          EXT1_PIN_11
#define EXT1_PIN_I2C_SCL          EXT1_PIN_12
#define EXT1_PIN_UART_RX          EXT1_PIN_13
#define EXT1_PIN_UART_TX          EXT1_PIN_14
#define EXT1_PIN_SPI_SS_1         EXT1_PIN_10
#define EXT1_PIN_SPI_SS_0         EXT1_PIN_15
#define EXT1_PIN_SPI_MOSI         EXT1_PIN_16
#define EXT1_PIN_SPI_MISO         EXT1_PIN_17
#define EXT1_PIN_SPI_SCK          EXT1_PIN_18
/** @} */

/** \name Extension header #1 ADC definitions
 *  @{
 */
#define EXT1_ADC_MODULE           
#define EXT1_ADC_0_CHANNEL        8
#define EXT1_ADC_0_PIN            
#define EXT1_ADC_0_MUX            
         
#define EXT1_ADC_1_CHANNEL        9
#define EXT1_ADC_1_PIN            
#define EXT1_ADC_1_MUX      
/** @} */

/** \name Extension header #1 PWM definitions
 *  @{
 */
#define EXT1_PWM_MODULE           
#define EXT1_PWM_0_CHANNEL        0
#define EXT1_PWM_0_PIN            
#define EXT1_PWM_0_MUX            
         
#define EXT1_PWM_1_CHANNEL        1
#define EXT1_PWM_1_PIN            
#define EXT1_PWM_1_MUX
/** @} */

/** \name Extension header #1 IRQ/External interrupt definitions
 *  @{
 */
#define EXT1_IRQ_MODULE           
#define EXT1_IRQ_INPUT            4
#define EXT1_IRQ_PIN              
#define EXT1_IRQ_MUX
/** @} */

/** \name Extension header #1 I2C definitions
 *  @{
 */
#define EXT1_I2C_MODULE  
#define EXT1_I2C_SERCOM_PIN_PAD0
#define EXT1_I2C_SERCOM_PIN_PAD1            
#define EXT1_I2C_SERCOM_MUX_PAD0  
#define EXT1_I2C_SERCOM_MUX_PAD1  
#define EXT1_I2C_SERCOM_DMAC_ID_TX   
#define EXT1_I2C_SERCOM_DMAC_ID_RX   
/** @} */

/** \name Extension header #1 UART definitions
 *  @{
 */
#define EXT1_UART_MODULE              
#define EXT1_UART_SERCOM_MUX_SETTING
#define EXT1_UART_SERCOM_PIN_PAD0
#define EXT1_UART_SERCOM_PIN_PAD1
#define EXT1_UART_SERCOM_PIN_PAD2
#define EXT1_UART_SERCOM_PIN_PAD3  
#define EXT1_UART_SERCOM_MUX_PAD0  
#define EXT1_UART_SERCOM_MUX_PAD1  
#define EXT1_UART_SERCOM_MUX_PAD2  
#define EXT1_UART_SERCOM_MUX_PAD3  
#define EXT1_UART_SERCOM_DMAC_ID_TX   
#define EXT1_UART_SERCOM_DMAC_ID_RX   
/** @} */

/** \name Extension header #1 SPI definitions
 *  @{
 */
#define EXT1_SPI_MODULE              
#define EXT1_SPI_SERCOM_MUX_SETTING
#define EXT1_SPI_SERCOM_PIN_PAD0
#define EXT1_SPI_SERCOM_PIN_PAD1
#define EXT1_SPI_SERCOM_PIN_PAD2
#define EXT1_SPI_SERCOM_PIN_PAD3
#define EXT1_SPI_SERCOM_MUX_PAD0  
#define EXT1_SPI_SERCOM_MUX_PAD1  
#define EXT1_SPI_SERCOM_MUX_PAD2  
#define EXT1_SPI_SERCOM_MUX_PAD3  
#define EXT1_SPI_SERCOM_DMAC_ID_TX   
#define EXT1_SPI_SERCOM_DMAC_ID_RX   
/** @} */

/** \name Extension header #3 pin definitions
 *  @{
 */
#define EXT3_PIN_3                
#define EXT3_PIN_4                
#define EXT3_PIN_5                
#define EXT3_PIN_6
#define EXT3_PIN_7
#define EXT3_PIN_8
#define EXT3_PIN_9                
#define EXT3_PIN_10
#define EXT3_PIN_11               
#define EXT3_PIN_12               
#define EXT3_PIN_13               
#define EXT3_PIN_14               
#define EXT3_PIN_15               
#define EXT3_PIN_16               
#define EXT3_PIN_17               
#define EXT3_PIN_18               
/** @} */

/** \name Extension header #3 pin definitions by function
 *  @{
 */
#define EXT3_PIN_ADC_0            EXT3_PIN_3
#define EXT3_PIN_ADC_1            EXT3_PIN_4
#define EXT3_PIN_GPIO_0           EXT3_PIN_5
#define EXT3_PIN_GPIO_1           EXT3_PIN_6
#define EXT3_PIN_PWM_0            EXT3_PIN_7
#define EXT3_PIN_PWM_1            EXT3_PIN_8
#define EXT3_PIN_IRQ              EXT3_PIN_9
#define EXT3_PIN_I2C_SDA          EXT3_PIN_11
#define EXT3_PIN_I2C_SCL          EXT3_PIN_12
#define EXT3_PIN_UART_RX          EXT3_PIN_13
#define EXT3_PIN_UART_TX          EXT3_PIN_14
#define EXT3_PIN_SPI_SS_1         EXT3_PIN_10
#define EXT3_PIN_SPI_SS_0         EXT3_PIN_15
#define EXT3_PIN_SPI_MOSI         EXT3_PIN_16
#define EXT3_PIN_SPI_MISO         EXT3_PIN_17
#define EXT3_PIN_SPI_SCK          EXT3_PIN_18
/** @} */

/** \name Extension header #3 ADC definitions
 *  @{
 */
#define EXT3_ADC_MODULE           
#define EXT3_ADC_0_CHANNEL        0
#define EXT3_ADC_0_PIN            
#define EXT3_ADC_0_MUX            
         
#define EXT3_ADC_1_CHANNEL        1
#define EXT3_ADC_1_PIN            
#define EXT3_ADC_1_MUX        
/** @} */

/** \name Extension header #3 PWM for Control definitions
 *  @{
 */
#define EXT3_PWM4CTRL_MODULE      
#define EXT3_PWM4CTRL_0_CHANNEL   0
#define EXT3_PWM4CTRL_0_OUTPUT    0
#define EXT3_PWM4CTRL_0_PIN       
#define EXT3_PWM4CTRL_0_MUX       
    
#define EXT3_PWM4CTRL_1_CHANNEL   1
#define EXT3_PWM4CTRL_1_OUTPUT    1
#define EXT3_PWM4CTRL_1_PIN       
#define EXT3_PWM4CTRL_1_MUX   
/** @} */

/** \name Extension header #3 IRQ/External interrupt definitions
 *  @{
 */
#define EXT3_IRQ_MODULE           
#define EXT3_IRQ_INPUT            8
#define EXT3_IRQ_PIN              
#define EXT3_IRQ_MUX                        
/** @} */

/** \name Extension header #3 I2C definitions
 *  @{
 */
#define EXT3_I2C_MODULE  
#define EXT3_I2C_SERCOM_PIN_PAD0
#define EXT3_I2C_SERCOM_PIN_PAD1            
#define EXT3_I2C_SERCOM_MUX_PAD0  
#define EXT3_I2C_SERCOM_MUX_PAD1  
#define EXT3_I2C_SERCOM_DMAC_ID_TX   
#define EXT3_I2C_SERCOM_DMAC_ID_RX   
/** @} */

/** \name Extension header #3 UART definitions
 *  @{
 */
#define EXT3_UART_MODULE              
#define EXT3_UART_SERCOM_MUX_SETTING  
#define EXT3_UART_SERCOM_PIN_PAD0
#define EXT3_UART_SERCOM_PIN_PAD1
#define EXT3_UART_SERCOM_PIN_PAD2
#define EXT3_UART_SERCOM_PIN_PAD3
#define EXT3_UART_SERCOM_MUX_PAD0  
#define EXT3_UART_SERCOM_MUX_PAD1  
#define EXT3_UART_SERCOM_MUX_PAD2  
#define EXT3_UART_SERCOM_MUX_PAD3  
#define EXT3_UART_SERCOM_DMAC_ID_TX   
#define EXT3_UART_SERCOM_DMAC_ID_RX   
/** @} */

/** \name Extension header #3 SPI definitions
 *  @{
 */
#define EXT3_SPI_MODULE              
#define EXT3_SPI_SERCOM_MUX_SETTING 
#define EXT3_SPI_SERCOM_PIN_PAD0
#define EXT3_SPI_SERCOM_PIN_PAD1
#define EXT3_SPI_SERCOM_PIN_PAD2
#define EXT3_SPI_SERCOM_PIN_PAD3 
#define EXT3_SPI_SERCOM_MUX_PAD0  
#define EXT3_SPI_SERCOM_MUX_PAD1  
#define EXT3_SPI_SERCOM_MUX_PAD2  
#define EXT3_SPI_SERCOM_MUX_PAD3  
#define EXT3_SPI_SERCOM_DMAC_ID_TX   
#define EXT3_SPI_SERCOM_DMAC_ID_RX   
/** @} */

/** \name Embedded debugger GPIO interface definitions
 * @{
 */
#define EDBG_GPIO0_PIN            
#define EDBG_GPIO1_PIN            
#define EDBG_GPIO2_PIN            
#define EDBG_GPIO3_PIN            
/** @} */

/** \name Embedded debugger USART interface definitions
 * @{
 */
#define EDBG_UART_MODULE          -1 /* Not available on this board */
#define EDBG_UART_RX_PIN          -1 /* Not available on this board */
#define EDBG_UART_RX_MUX          -1 /* Not available on this board */

#define EDBG_UART_RX_SERCOM_PAD   -1 /* Not available on this board */
#define EDBG_UART_TX_PIN          -1 /* Not available on this board */
#define EDBG_UART_TX_MUX          -1 /* Not available on this board */
#define EDBG_UART_TX_SERCOM_PAD   -1 /* Not available on this board */
/** @} */

/** \name Embedded debugger I2C interface definitions
 * @{
 */
#define EDBG_I2C_MODULE 
#define EDBG_I2C_SERCOM_PIN_PAD0
#define EDBG_I2C_SERCOM_PIN_PAD1             
#define EDBG_I2C_SERCOM_MUX_PAD0  
#define EDBG_I2C_SERCOM_MUX_PAD1  
#define EDBG_I2C_SERCOM_DMAC_ID_TX   
#define EDBG_I2C_SERCOM_DMAC_ID_RX   
/** @} */

/** \name Embedded debugger SPI interface definitions
 * @{
 */
#define EDBG_SPI_MODULE              
#define EDBG_SPI_SERCOM_MUX_SETTING
#define EDBG_SPI_SERCOM_PIN_PAD0
#define EDBG_SPI_SERCOM_PIN_PAD1
#define EDBG_SPI_SERCOM_PIN_PAD2
#define EDBG_SPI_SERCOM_PIN_PAD3  
#define EDBG_SPI_SERCOM_MUX_PAD0  
#define EDBG_SPI_SERCOM_MUX_PAD1  
#define EDBG_SPI_SERCOM_MUX_PAD2  
#define EDBG_SPI_SERCOM_MUX_PAD3  
#define EDBG_SPI_SERCOM_DMAC_ID_TX   
#define EDBG_SPI_SERCOM_DMAC_ID_RX   
/** @} */

/** \name Embedded debugger CDC Gateway USART interface definitions
 * @{
 */
#define EDBG_CDC_MODULE              UART0
#define EDBG_CDC_MUX_SETTING 
#define EDBG_CDC_PIN_PAD0            PIN_LP_GPIO_2
#define EDBG_CDC_PIN_PAD1            PIN_LP_GPIO_3
#define EDBG_CDC_PIN_PAD2            PIN_LP_GPIO_8
#define EDBG_CDC_PIN_PAD3            PIN_LP_GPIO_9 
#define EDBG_CDC_MUX_PAD0            MUX_LP_GPIO_2_UART0_RXD
#define EDBG_CDC_MUX_PAD1            MUX_LP_GPIO_3_UART0_TXD
#define EDBG_CDC_MUX_PAD2            0 /* BTLC1000 has no flow control function. */
#define EDBG_CDC_MUX_PAD3            0 /* BTLC1000 has no flow control function. */
#define EDBG_CDC_DMAC_ID_TX   
#define EDBG_CDC_DMAC_ID_RX   
/** @} */

/** @} */

/**
 * \brief Turns off the specified LEDs.
 *
 * \param led_gpio LED to turn off (LEDx_GPIO).
 *
 * \note The pins of the specified LEDs are set to GPIO output mode.
 */
#define LED_Off(led_gpio)     gpio_pin_set_output_level(led_gpio,true)

/**
 * \brief Turns on the specified LEDs.
 *
 * \param led_gpio LED to turn on (LEDx_GPIO).
 *
 * \note The pins of the specified LEDs are set to GPIO output mode.
 */
#define LED_On(led_gpio)      gpio_pin_set_output_level(led_gpio,false)

/**
 * \brief Toggles the specified LEDs.
 *
 * \param led_gpio LED to toggle (LEDx_GPIO).
 *
 * \note The pins of the specified LEDs are set to GPIO output mode.
 */
#define LED_Toggle(led_gpio)  gpio_pin_toggle_output_level(led_gpio)

/** @} */

#ifdef __cplusplus
}
#endif

#endif  /* SAMB11CSP_XPLAINED_PRO_H_INCLUDED */
