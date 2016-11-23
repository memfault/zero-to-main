/**
 * \file
 *
 * \brief SAM Non Volatile Memory Driver Quick Start
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
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>

void configure_nvm(void);

//! [setup]
void configure_nvm(void)
{
//! [setup_1]
	struct nvm_config config_nvm;
//! [setup_1]

//! [setup_2]
	nvm_get_config_defaults(&config_nvm);
//! [setup_2]

//! [setup_3]
	config_nvm.manual_page_write = false;
//! [setup_3]

//! [setup_4]
	nvm_set_config(&config_nvm);
//! [setup_4]
}
//! [setup]

int main(void)
{
	//! [setup_init]
	configure_nvm();
	//! [setup_init]

//! [main]
	//! [main_1]
	uint8_t page_buffer[NVMCTRL_PAGE_SIZE];
	//! [main_1]

	//! [main_2]
	for (uint32_t i = 0; i < NVMCTRL_PAGE_SIZE; i++) {
		page_buffer[i] = i;
	}
	//! [main_2]

	//! [main_3]
	enum status_code error_code;
	//! [main_3]

	//! [main_4]
	do
	{
		error_code = nvm_erase_row(
				100 * NVMCTRL_ROW_PAGES * NVMCTRL_PAGE_SIZE);
	} while (error_code == STATUS_BUSY);
	//! [main_4]

	//! [main_5]
	do
	{
		error_code = nvm_write_buffer(
				100 * NVMCTRL_ROW_PAGES * NVMCTRL_PAGE_SIZE,
				page_buffer, NVMCTRL_PAGE_SIZE);
	} while (error_code == STATUS_BUSY);
	//! [main_5]

	//! [main_6]
	do
	{
		error_code = nvm_read_buffer(
				100 * NVMCTRL_ROW_PAGES * NVMCTRL_PAGE_SIZE,
				page_buffer, NVMCTRL_PAGE_SIZE);
	} while (error_code == STATUS_BUSY);
	//! [main_6]

//! [main]

	while (true) {
		/* Do nothing */
	}
}

