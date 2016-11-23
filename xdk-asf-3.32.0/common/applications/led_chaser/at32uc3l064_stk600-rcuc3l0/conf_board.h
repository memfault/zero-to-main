/**
 * \file
 *
 * \brief Board configuration for clock example 1
 *
 * Copyright (c) 2010-2015 Atmel Corporation. All rights reserved.
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
#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED

/* Use the external 32 kHz clock generator on STK600 */
#define BOARD_OSC32_HZ          32768
#define BOARD_OSC32_STARTUP_US  71000
#define BOARD_OSC32_IS_XTAL     false

/* Make sure we have 8 LEDs enabled */
#undef  LED_COUNT
#define LED_COUNT 8


/* Because the LED pins are defined statically in the board setup,
 * we have to undefine them before they can be moved to the port used
 * by this example.
 */
#undef LED0_GPIO
#undef LED1_GPIO
#undef LED2_GPIO
#undef LED3_GPIO
#undef LED4_GPIO
#undef LED5_GPIO
#undef LED6_GPIO
#undef LED7_GPIO

#define LED0_GPIO   AVR32_PIN_PB00  // STK600.PORTD.PD0 -> STK600.LEDS.LED0
#define LED1_GPIO   AVR32_PIN_PB01  // STK600.PORTD.PD1 -> STK600.LEDS.LED1
#define LED2_GPIO   AVR32_PIN_PB02  // STK600.PORTD.PD2 -> STK600.LEDS.LED2
#define LED3_GPIO   AVR32_PIN_PB03  // STK600.PORTD.PD3 -> STK600.LEDS.LED3
#define LED4_GPIO   AVR32_PIN_PB04  // STK600.PORTD.PD4 -> STK600.LEDS.LED4
#define LED5_GPIO   AVR32_PIN_PB05  // STK600.PORTD.PD5 -> STK600.LEDS.LED5
#define LED6_GPIO   AVR32_PIN_PB06  // STK600.PORTD.PD6 -> STK600.LEDS.LED6
#define LED7_GPIO   AVR32_PIN_PB07  // STK600.PORTD.PD7 -> STK600.LEDS.LED7

/* Buttons are not in use in this example, and the default mapping overlaps
 * with where we want to output the LEDs. So we move the buttons out of the way.
 */

#undef GPIO_PUSH_BUTTON_SW0
#undef GPIO_PUSH_BUTTON_SW1
#undef GPIO_PUSH_BUTTON_SW2
#undef GPIO_PUSH_BUTTON_SW3
#undef GPIO_PUSH_BUTTON_SW4
#undef GPIO_PUSH_BUTTON_SW5
#undef GPIO_PUSH_BUTTON_SW6
#undef GPIO_PUSH_BUTTON_SW7

#define GPIO_PUSH_BUTTON_SW0   AVR32_PIN_PA00
#define GPIO_PUSH_BUTTON_SW1   AVR32_PIN_PA00
#define GPIO_PUSH_BUTTON_SW2   AVR32_PIN_PA00
#define GPIO_PUSH_BUTTON_SW3   AVR32_PIN_PA00
#define GPIO_PUSH_BUTTON_SW4   AVR32_PIN_PA00
#define GPIO_PUSH_BUTTON_SW5   AVR32_PIN_PA00
#define GPIO_PUSH_BUTTON_SW6   AVR32_PIN_PA00
#define GPIO_PUSH_BUTTON_SW7   AVR32_PIN_PA00


#endif /* CONF_BOARD_H_INCLUDED */
