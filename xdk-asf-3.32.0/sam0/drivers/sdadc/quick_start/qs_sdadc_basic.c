/**
 * \file
 *
 * \brief SAM SDADC Quick Start
 *
 * Copyright (C) 2015 Atmel Corporation. All rights reserved.
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

void configure_sdadc(void);

//! [module_inst]
struct sdadc_module sdadc_instance;
//! [module_inst]

//! [setup]
void configure_sdadc(void)
{
//! [setup_config]
	struct sdadc_config config_sdadc;
//! [setup_config]
//! [setup_config_defaults]
	sdadc_get_config_defaults(&config_sdadc);
//! [setup_config_defaults]

//! [setup_set_config]
	sdadc_init(&sdadc_instance, SDADC, &config_sdadc);
//! [setup_set_config]

//! [setup_enable]
	sdadc_enable(&sdadc_instance);
//! [setup_enable]
}
//! [setup]

int main(void)
{
	system_init();

//! [setup_init]
	configure_sdadc();
//! [setup_init]

//! [main]
//! [start_conv]
	sdadc_start_conversion(&sdadc_instance);
//! [start_conv]

//! [get_res]
	int32_t result;

	do {
		/* Wait for conversion to be done and read out result */
	} while (sdadc_read(&sdadc_instance, &result) == STATUS_BUSY);
//! [get_res]

//! [inf_loop]
	while (1) {
		/* Infinite loop */
	}
//! [inf_loop]
//! [main]
}
