/**
 * \file
 *
 * \brief SAM L22 Xplained Pro B test configuration.
 *
 * Copyright (c) 2015 Atmel Corporation. All rights reserved.
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

#ifndef CONF_TEST_H_INCLUDED
#define CONF_TEST_H_INCLUDED

#define CONF_STDIO_USART          EDBG_CDC_MODULE
#define CONF_STDIO_MUX_SETTING    EDBG_CDC_SERCOM_MUX_SETTING
#define CONF_STDIO_PINMUX_PAD0    EDBG_CDC_SERCOM_PINMUX_PAD0
#define CONF_STDIO_PINMUX_PAD1    EDBG_CDC_SERCOM_PINMUX_PAD1
#define CONF_STDIO_PINMUX_PAD2    EDBG_CDC_SERCOM_PINMUX_PAD2
#define CONF_STDIO_PINMUX_PAD3    EDBG_CDC_SERCOM_PINMUX_PAD3
#define CONF_STDIO_BAUDRATE       38400

/* SERCOM SPI pin-out defines for SPI slave */
#define CONF_SPI_SLAVE_MODULE              SERCOM5
#define CONF_SPI_SLAVE_SPI_MUX             SPI_SIGNAL_MUX_SETTING_E
#define CONF_SPI_SLAVE_DATA_IN_PIN_MUX     PINMUX_PB02D_SERCOM5_PAD0
#define CONF_SPI_SLAVE_DATA_OUT_PIN_MUX    PINMUX_PB21D_SERCOM5_PAD1
#define CONF_SPI_SLAVE_SCK_PIN_MUX         PINMUX_PB00D_SERCOM5_PAD2
#define CONF_SPI_SLAVE_SS_PIN_MUX          PINMUX_PB01D_SERCOM5_PAD3
/* SERCOM SPI pin-out defines for SPI master */
#define CONF_SPI_MASTER_MODULE             EXT2_SPI_MODULE
#define CONF_SPI_MASTER_SPI_MUX            EXT2_SPI_SERCOM_MUX_SETTING
#define CONF_SPI_MASTER_DATA_IN_PIN_MUX    EXT2_SPI_SERCOM_PINMUX_PAD0
#define CONF_SPI_MASTER_DATA_OUT_PIN_MUX   EXT2_SPI_SERCOM_PINMUX_PAD2
#define CONF_SPI_MASTER_SCK_PIN_MUX        EXT2_SPI_SERCOM_PINMUX_PAD3
#define CONF_SPI_SLAVE_SS_PIN              EXT2_PIN_SPI_SS_0

#endif /* CONF_TEST_H_INCLUDED */
