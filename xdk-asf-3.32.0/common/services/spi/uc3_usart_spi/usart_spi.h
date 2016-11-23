/**
 * \file
 *
 * \brief UC3 USART in SPI mode driver functions.
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

#ifndef _USART_SPI_H_
#define _USART_SPI_H_

#include "compiler.h"
#include "usart.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/*! \name USART in SPI mode Management Configuration.
 */
//! @{
#include "conf_usart_spi.h"

//! Default Configuration of SPI Master Dummy Field
#ifndef CONFIG_USART_SPI_DUMMY
	#define CONFIG_USART_SPI_DUMMY              0xFF
#endif
//! @}

/** Clock phase. */
#define SPI_CPHA	(1 << 0)

/** Clock polarity. */
#define SPI_CPOL	(1 << 1)

/** SPI mode definition. */
#define SPI_MODE_0	(SPI_CPHA)
#define SPI_MODE_1	0
#define SPI_MODE_2	(SPI_CPOL | SPI_CPHA)
#define SPI_MODE_3	(SPI_CPOL)

#ifndef SPI_TYPE_DEFS
#define SPI_TYPE_DEFS
//! SPI Flags Definition
typedef uint8_t spi_flags_t;

//! Board SPI Select Id Definition
typedef uint32_t board_spi_select_id_t;
#endif

typedef uint8_t port_pin_t; 

//! \brief Polled SPI device definition.
struct usart_spi_device {
	/* Board specific select id. */
	port_pin_t	id;
};

void usart_spi_init(volatile avr32_usart_t *p_usart);
void usart_spi_setup_device(volatile avr32_usart_t *p_usart, struct usart_spi_device *device,
     spi_flags_t flags, unsigned long baud_rate, board_spi_select_id_t sel_id);
void usart_spi_write_single(volatile avr32_usart_t *p_usart, uint8_t data);
uint32_t usart_spi_write_packet(volatile avr32_usart_t *p_usart, const uint8_t *data, size_t len);
void usart_spi_read_single(volatile avr32_usart_t *p_usart, uint8_t *data);
uint32_t usart_spi_read_packet(volatile avr32_usart_t *p_usart, uint8_t *data, size_t len);
void usart_spi_select_device(volatile avr32_usart_t *p_usart, struct usart_spi_device *device);
void usart_spi_deselect_device(volatile avr32_usart_t *p_usart, struct usart_spi_device *device);
uint32_t usart_spi_is_tx_empty(volatile avr32_usart_t *p_usart);
uint32_t usart_spi_is_rx_ready(volatile avr32_usart_t *p_usart);
uint32_t usart_spi_is_tx_ready(volatile avr32_usart_t *p_usart);
uint32_t usart_spi_is_rx_full(volatile avr32_usart_t *p_usart);

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif  /* _USART_SPI_H_ */
