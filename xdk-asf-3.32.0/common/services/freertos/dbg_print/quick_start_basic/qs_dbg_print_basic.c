/**
 * \file
 *
 * \brief Debug print basic quick start guide code
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

#include <asf.h>

//! [main_task_data]
uint32_t main_counter;
char main_string[] = "Main task iteration: 0x00000000\r\n";
//! [main_task_data]

//! [main_task]
//! [main_task_open]
static void main_task(void *params)
{
	do {
//! [main_task_open]
//! [main_task_1]
		dbg_print_str("Main task loop executing\r\n");
//! [main_task_1]

//! [main_task_2]
		// Update hexadecimal 32-bit integer in string, and print it
		dbg_sprint_hexint(&main_string[23], main_counter++);
		dbg_print_str(main_string);
//! [main_task_2]

//! [main_task_close]
		vTaskDelay(1000 / portTICK_RATE_MS);
	} while(1);
}
//! [main_task_close]
//! [main_task]


int main (void)
{
//! [init_calls]
	system_init();
	dbg_init();
//! [init_calls]

//! [main_task_create]
	xTaskCreate(&main_task,
		(const char *)"Main task",
		configMINIMAL_STACK_SIZE + 100,
		NULL,
		tskIDLE_PRIORITY + 2,
		NULL);
//! [main_task_create]

//! [freertos_start]
	vTaskStartScheduler();
//! [freertos_start]
}
