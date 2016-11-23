/**
 * \file
 *
 * \brief SAM4L-EK board configuration template
 *
 * Copyright (C) 2012-2015 Atmel Corporation. All rights reserved.
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
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#ifndef CONF_BOARD_H_INCLUDED
#define CONF_BOARD_H_INCLUDED

/* Keep watchdog at board initialization */
//#define CONF_BOARD_KEEP_WATCHDOG_AT_INIT

/* Initialize the USART pins for the RS485 interface */
#define CONF_BOARD_RS485

/* Initialize the push button PB0 as an External Interrupt pin */
#define CONF_BOARD_EIC

/* Initialize the LCD Backlight */
#define CONF_BOARD_BL

/* Initialize the SAM4L pins for the USB SAM4L plug */
#define CONF_BOARD_USB_PORT
#define CONF_BOARD_USB_ID_DETECT           /* ID detect enabled,  uncomment it if jumper PB05/USB set */
#define CONF_BOARD_USB_VBUS_CONTROL        /* Host VBUS control enabled,  uncomment it if jumper PC08/USB set */
#define CONF_BOARD_USB_VBUS_ERR_DETECT     /* Host VBUS error detect NOT enabled,  uncomment it if jumper PC07/USB set */

/* Initialize the USART pins for the COM PORT interface with the JLink OB
module that acts as a USB CDC gateway over the USB JLink plug. */
#define CONF_BOARD_COM_PORT

/* Initialize the USART pins that interface with the Board Monitor(BM) */
#define CONF_BOARD_BM_USART

/* Initialize the SPI pins for use with the on-board serial flash or with the
 * WIRELESS connector or with the Sensors Xplained extension board. */
#define CONF_BOARD_SPI

/* Initialize the SPI CS for the WIRELESS connector. */
#define CONF_BOARD_SPI_NPCS0

/* Initialize the SPI CS for the on-board serial flash. */
#define CONF_BOARD_SPI_NPCS2

/* Initialize the SPI CS for the Sensors Xplained extension board. */
#define CONF_BOARD_SPI_NPCS3

/* Initialize the DACC VOUT pin */
#define CONF_BOARD_DACC_VOUT

#endif // CONF_BOARD_H_INCLUDED
