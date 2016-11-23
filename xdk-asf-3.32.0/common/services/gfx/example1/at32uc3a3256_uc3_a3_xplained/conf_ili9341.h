/**
 * \file
 *
 * \brief ILI9341 display controller configuration for the ILI9341 example
 *
 * Copyright (c) 2014-2015 Atmel Corporation. All rights reserved.
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
#include <board.h>

#ifndef CONF_ILI9341_H_INCLUDED
#define CONF_ILI9341_H_INCLUDED

/**
 * \brief Select the correct hardware interface
 *
 * Currently supported interfaces are the SPI interface and the USART Master SPI
 * interface.
 */
#if defined(MXT143E_XPLAINED_SPI)
#	define CONF_ILI9341_SPI           MXT143E_XPLAINED_SPI
#elif defined(MXT143E_XPLAINED_USART_SPI)
#	define CONF_ILI9341_USART_SPI     MXT143E_XPLAINED_USART_SPI
#endif

/**
 * \brief Select a SPI clock speed
 *
 * This selects the clock speed for the SPI clock used to communicate with the
 * display controller. Higher clock speeds allow for higher frame rates.
 * \note That the clock speed may be limited by the speed of the microcontroller
 * a normal limitation would be CPUclk/2. For more details please refer to the
 * device datasheet.
 */
#define CONF_ILI9341_CLOCK_SPEED   8000000UL

/** \brief Define what MCU pin the ILI9341 chip select pin is connected to */
#define CONF_ILI9341_CS_PIN        MXT143E_XPLAINED_CS

/** \brief Define what MCU pin the ILI9341 DC pin is connected to */
#define CONF_ILI9341_DC_PIN        MXT143E_XPLAINED_DC

/** \brief Define what MCU pin the ILI9341 back light pin is connected to */
#define CONF_ILI9341_BACKLIGHT_PIN MXT143E_XPLAINED_BACKLIGHT

/** \brief Define what MCU pin the ILI9341 reset is connected to */
#define CONF_ILI9341_RESET_PIN     MXT143E_XPLAINED_LCD_RESET

/** \brief Define what peripheral DMA channel to use for the display */
#define CONF_ILI9341_PDCA_CHANNEL  0

/** \brief Define what peripheral ID to use for the display output */
#define CONF_ILI9341_PDCA_PID      MXT143E_XPLAINED_PDCA_PID

#endif /* CONF_ILI9341_H_INCLUDED */
