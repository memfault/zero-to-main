/*****************************************************************************
 *
 * \file
 *
 * \brief SPI Master driver for AVR UC3.
 *
 * This file defines a useful set of functions for the SPI interface on AVR UC3
 * devices.
 *
 * Copyright (c) 2009-2015 Atmel Corporation. All rights reserved.
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
 ******************************************************************************/
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */


#include "spi_master.h"

#ifdef FREERTOS_USED

#include "FreeRTOS.h"
#include "semphr.h"

#endif

void spi_master_setup_device(volatile avr32_spi_t *spi,
		struct spi_device *device, spi_flags_t flags, uint32_t baud_rate,
		board_spi_select_id_t sel_id)
{
	spi_set_chipselect_delay_bct(spi,device->id,CONFIG_SPI_MASTER_DELAY_BCT);
	spi_set_chipselect_delay_bs(spi,device->id,CONFIG_SPI_MASTER_DELAY_BS);
	spi_set_bits_per_transfer(spi,device->id,
			CONFIG_SPI_MASTER_BITS_PER_TRANSFER);
	spi_set_baudrate_register(spi,device->id,
			getBaudDiv(baud_rate, sysclk_get_peripheral_bus_hz(spi)));
	spi_enable_active_mode(spi,device->id);
	spi_set_mode(spi,device->id,flags);

#ifdef FREERTOS_USED
	if (!xSPIMutex) {
		// Create the SPI mutex.
		vSemaphoreCreateBinary(xSPIMutex);
		if (!xSPIMutex) {
			while(1);
		}
	}
#endif
}

status_code_t spi_read_packet(volatile avr32_spi_t *spi,
		uint8_t *data, size_t len)
{
	unsigned int timeout = SPI_TIMEOUT;
	uint8_t val;
	size_t i=0;
	while(len) {
		timeout = SPI_TIMEOUT;
		while (!spi_is_tx_ready(spi)) {
			if (!timeout--) {
				return ERR_TIMEOUT;
			}
		}
		spi_write_single(spi,CONFIG_SPI_MASTER_DUMMY);
		timeout = SPI_TIMEOUT;
		while (!spi_is_rx_ready(spi)) {
			if (!timeout--) {
				return ERR_TIMEOUT;
			}
		}
		spi_read_single(spi,&val);
		data[i] = val;
		i++;
		len--;
	}
	return STATUS_OK;
}

status_code_t spi_write_packet(volatile avr32_spi_t *spi, const uint8_t *data,
		size_t len)
{
	unsigned int timeout = SPI_TIMEOUT;
	size_t i=0;
	uint8_t val;
	while(len) {
		timeout = SPI_TIMEOUT;
		while (!spi_is_tx_ready(spi)) {
			if (!timeout--) {
				return ERR_TIMEOUT;
			}
		}
		val = data[i];
		spi_write_single(spi,val);
		i++;
		len--;
	}
	return STATUS_OK;
}

//! @}
