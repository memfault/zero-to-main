/**
 * \file
 *
 * \brief SAM BOD Driver Quick Start
 *
 * Copyright (C) 2014-2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
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
#include <asf.h>

//! [setup]
static void configure_bod33(void)
{
//! [setup_config]
	struct bod33_config config_bod33;
//! [setup_config]
//! [setup_config_defaults]
	bod33_get_config_defaults(&config_bod33);
//! [setup_config_defaults]

//! [setup_set_config]
	bod33_set_config(&config_bod33);
//! [setup_set_config]

//! [setup_enable]
	bod33_enable();
//! [setup_enable]
}

static void configure_bod12(void)
{
	struct bod12_config config_bod12;
	bod12_get_config_defaults(&config_bod12);

	bod12_set_config(&config_bod12);

	bod12_enable();
}
//! [setup]

int main(void)
{
	/* Configure the BOD 3.3V module */
//! [setup_init_33]
	configure_bod33();
//! [setup_init_33]

	/* Configure the BOD 1.2V module */
//! [setup_init_12]
	configure_bod12();
//! [setup_init_12]

//! [main]
//! [main_loop]
	while (true) {
		/* Infinite loop */
	}
//! [main_loop]
//! [main]
}
