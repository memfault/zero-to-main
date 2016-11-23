/**
 * \file
 *
 * \brief SAM I<SUP>2</SUP>S - Inter-IC Sound Controller Callback Driver Quick Start
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
 *
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>
#include <conf_i2s_quick_start_callback.h>

static void _configure_i2s(void);
static void _configure_i2s_callbacks(void);


//! [module_inst]
struct i2s_module i2s_instance;
//! [module_inst]

//! [data_buffer]
uint16_t data_buffer[4] = {0xF87F, 0x901F, 0, 0};
//! [data_buffer]

//! [callback_funcs]
static void _i2s_callback_to_send_buffer(
		struct i2s_module *const module_inst)
{
	i2s_serializer_write_buffer_job(module_inst,
			I2S_SERIALIZER_0, data_buffer, 4);
}
//! [callback_funcs]

//! [setup]
static void _configure_i2s(void)
{
	//! [setup_i2s_init]
	i2s_init(&i2s_instance, CONF_I2S_MODULE);
	//! [setup_i2s_init]

	//! [setup_clock_unit_config]
	struct i2s_clock_unit_config config_clock_unit;
	//! [setup_clock_unit_config]
	//! [setup_clock_unit_config_defaults]
	i2s_clock_unit_get_config_defaults(&config_clock_unit);
	//! [setup_clock_unit_config_defaults]

	//! [setup_clock_unit_change_config]
	config_clock_unit.clock.gclk_src = GCLK_GENERATOR_0;

	config_clock_unit.clock.mck_src = I2S_MASTER_CLOCK_SOURCE_GCLK;
	config_clock_unit.clock.mck_out_enable = true;
	config_clock_unit.clock.mck_out_div = 2;

	config_clock_unit.clock.sck_src = I2S_SERIAL_CLOCK_SOURCE_MCKDIV;
	config_clock_unit.clock.sck_div = 4;

	config_clock_unit.frame.number_slots = 2;
	config_clock_unit.frame.slot_size = I2S_SLOT_SIZE_32_BIT;
	config_clock_unit.frame.data_delay = I2S_DATA_DELAY_0;

	config_clock_unit.frame.frame_sync.source = I2S_FRAME_SYNC_SOURCE_SCKDIV;
	config_clock_unit.frame.frame_sync.width = I2S_FRAME_SYNC_WIDTH_HALF_FRAME;
	//! [setup_clock_unit_change_config]

	//! [setup_clock_unit_change_pins]
	config_clock_unit.mck_pin.enable = true;
	config_clock_unit.mck_pin.gpio = CONF_I2S_MCK_PIN;
	config_clock_unit.mck_pin.mux = CONF_I2S_MCK_MUX;

	config_clock_unit.sck_pin.enable = true;
	config_clock_unit.sck_pin.gpio = CONF_I2S_SCK_PIN;
	config_clock_unit.sck_pin.mux = CONF_I2S_SCK_MUX;

	config_clock_unit.fs_pin.enable = true;
	config_clock_unit.fs_pin.gpio = CONF_I2S_FS_PIN;
	config_clock_unit.fs_pin.mux = CONF_I2S_FS_MUX;
	//! [setup_clock_unit_change_pins]

	//! [setup_clock_unit_set_config]
	i2s_clock_unit_set_config(&i2s_instance, I2S_CLOCK_UNIT_0,
			&config_clock_unit);
	//! [setup_clock_unit_set_config]

	//! [setup_serializer_config]
	struct i2s_serializer_config config_serializer;
	//! [setup_serializer_config]
	//! [setup_serializer_config_defaults]
	i2s_serializer_get_config_defaults(&config_serializer);
	//! [setup_serializer_config_defaults]

	//! [setup_serializer_change_config_tx]
	config_serializer.clock_unit = I2S_CLOCK_UNIT_0;
	config_serializer.mode = I2S_SERIALIZER_TRANSMIT;
	config_serializer.data_size = I2S_DATA_SIZE_16BIT;
	//! [setup_serializer_change_config_tx]

	//! [setup_serializer_change_config_pin_tx]
	config_serializer.data_pin.enable = true;
	config_serializer.data_pin.gpio = CONF_I2S_SD_PIN;
	config_serializer.data_pin.mux = CONF_I2S_SD_MUX;
	//! [setup_serializer_change_config_pin_tx]

	//! [setup_serializer_set_config_tx]
	i2s_serializer_set_config(&i2s_instance, I2S_SERIALIZER_0,
			&config_serializer);
	//! [setup_serializer_set_config_tx]

	//! [setup_enable]
	i2s_enable(&i2s_instance);
	i2s_clock_unit_enable(&i2s_instance, I2S_CLOCK_UNIT_0);
	i2s_serializer_enable(&i2s_instance, I2S_SERIALIZER_0);
	//! [setup_enable]
}

static void _configure_i2s_callbacks(void)
{
	//! [setup_register_callback]
	i2s_serializer_register_callback(
			&i2s_instance,
			I2S_SERIALIZER_0,
			_i2s_callback_to_send_buffer,
			I2S_SERIALIZER_CALLBACK_BUFFER_DONE);
	//! [setup_register_callback]

	//! [setup_enable_callback]
	i2s_serializer_enable_callback(&i2s_instance,
			I2S_SERIALIZER_0,
			I2S_SERIALIZER_CALLBACK_BUFFER_DONE);
	//! [setup_enable_callback]
}
//! [setup]

int main(void)
{
	system_init();

//! [setup_init]
	_configure_i2s();
	_configure_i2s_callbacks();
//! [setup_init]

//! [main]
	//! [enable_global_interrupts]
	system_interrupt_enable_global();
	//! [enable_global_interrupts]

//! [start_job]
	i2s_serializer_write_buffer_job(&i2s_instance,
			I2S_SERIALIZER_0, data_buffer, 4);
//! [start_job]

	//! [main_loop]
	while (true) {
	}
	//! [main_loop]
//! [main]
}
