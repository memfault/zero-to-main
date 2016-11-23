/**
 * \file
 *
 * \brief SAM CRC32 Driver Quick Start
 *
 * Copyright (C) 2016 Atmel Corporation. All rights reserved.
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
#include <asf.h>

COMPILER_ALIGNED(4)
static const uint32_t crc_data[10] = {
	0x00000000, 0x11111111, 0x22222222, 0x33333333, 0x44444444,
	0x55555555, 0x66666666, 0x77777777, 0x88888888,0x99999999
};
const uint32_t expected_crc = 0xf8ee400b;
static 	uint32_t crc_result;

int main(void)
{
	enum status_code status;

	system_init();
	system_peripheral_unlock(SYSTEM_PERIPHERAL_ID(DSU),
			~SYSTEM_PERIPHERAL_ID(DSU));

	dsu_crc32_init();

	crc_result = 0xFFFFFFFF;
	status = dsu_crc32_cal((const uint32_t)crc_data,sizeof(crc_data),&crc_result);
	if (status != STATUS_OK) {
		while (1);
	}

	crc_result = ~crc_result;

	if (crc_result != expected_crc) {
		while (1);
	}

	while (1) {
	}
}
