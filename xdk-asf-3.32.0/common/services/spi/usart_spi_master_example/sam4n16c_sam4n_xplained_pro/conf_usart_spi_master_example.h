/**
 * \file
 *
 * \brief USART SPI Master example configuration.
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

#ifndef CONF_USART_SPI_MASTER_EXAMPLE_H
#define CONF_USART_SPI_MASTER_EXAMPLE_H

#include "conf_board.h"
#include "sysclk.h"

/**
 * \defgroup usart_spi_master_example_pin_defs
 *  - <b> SAM4N Xplained Pro -- AT45DBX component </b>
 *   - 3V3 -- VCC
 *   - PA24(EXT1/PIN5) -- NCS
 *   - PA23(EXT1/PIN10) -- CLK
 *   - PA21(EXT1/PIN13) -- MISO
 *   - PA22(EXT1/PIN14) -- MOSI
 *   - GND -- GND
 */

/*! \name Configuration
 */
//! @{
#define USART_SPI_EXAMPLE                   USART1
#define USART_SPI_DEVICE_EXAMPLE_ID         1
#define USART_SPI_EXAMPLE_BAUDRATE          1000000
#define USART_SPI_EXAMPLE_LED_PIN_EXAMPLE_1 LED0_GPIO
//! @}

#endif  /* _CONF_USART_SPI_MASTER_EXAMPLE_H */
