/**
 * \file
 *
 * \brief Serial USART service configuration.
 *
 * Copyright (C) 2014-2015 Atmel Corporation. All rights reserved.
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

#ifndef CONF_USART_SERIAL_H
#define CONF_USART_SERIAL_H

#define OUT_BUFFER_LENGTH    2048

/** USART initialize with the CONFIG_PBA_HZ */
extern int usart_ready;

static inline int usart_write_char_buf(Usart *usart, int c)
{
	static int c_count;
	static uint8_t c_buf[OUT_BUFFER_LENGTH];
	static bool buf_output_flag = 0;
	int i;
	if (usart_ready != 1) {
		c_buf[c_count] = c;
		c_count++;
		if (c_count >= OUT_BUFFER_LENGTH) {
			c_count = 0;
		}

		return 1;
	}

	if ((usart_ready == 1) && !buf_output_flag) {
		buf_output_flag = 1;
		c_buf[c_count] = c;
		for (i = 0; i <= c_count; i++) {
			while (usart_write(usart, c_buf[i]) != 0) {
			}
		}
		return 1;
	}

	while (usart_write(usart, c) != 0) {
	}
	return 1;
}

#endif/* CONF_USART_SERIAL_H_INCLUDED */
