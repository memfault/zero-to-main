/**
 * \file
 *
 * \brief SAM TSENS Quick Start
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

#include <asf.h>

//! [result]
int32_t tsens_result;
//! [result]

//! [module_inst]
struct tsens_module tsens_instance;
//! [module_inst]

//! [job_complete_callback]
volatile bool tsens_read_done = false;

static void tsens_complete_callback(enum tsens_callback i)
{
	tsens_read_done = true;
}
//! [job_complete_callback]

//! [setup]
static void configure_tsens(void)
{
//! [setup_config]
	struct tsens_config config_tsens;
//! [setup_config]
//! [setup_config_defaults]
	tsens_get_config_defaults(&config_tsens);
//! [setup_config_defaults]

//! [setup_set_config]
	tsens_init(&config_tsens);
//! [setup_set_config]

//! [setup_enable]
	tsens_enable();
//! [setup_enable]
}

static void configure_tsens_callbacks(void)
{
//! [setup_register_callback]
	tsens_register_callback(&tsens_instance,
			tsens_complete_callback, TSENS_CALLBACK_RESULT_READY);
//! [setup_register_callback]
//! [setup_enable_callback]
	tsens_enable_callback(TSENS_CALLBACK_RESULT_READY);
//! [setup_enable_callback]
}
//! [setup]

int main(void)
{
	system_init();

//! [setup_init]
	configure_tsens();
	configure_tsens_callbacks();
//! [setup_init]

//! [main]
//! [enable_interrupts]
	system_interrupt_enable(SYSTEM_INTERRUPT_MODULE_TSENS);
	system_interrupt_enable_global();
//! [enable_interrupts]

//! [start_tsens_job]
	tsens_read_job(&tsens_instance, &tsens_result);
//! [start_tsens_job]

//! [job_complete_poll]
	while (tsens_read_done == false) {
		/* Wait for asynchronous TSENS read to complete */
	}
//! [job_complete_poll]

//! [inf_loop]
	while (1) {
		/* Infinite loop */
	}
//! [inf_loop]
//! [main]
}
