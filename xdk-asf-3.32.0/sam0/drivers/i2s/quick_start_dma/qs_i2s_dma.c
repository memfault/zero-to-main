/**
 * \file
 *
 * \brief SAM I<SUP>2</SUP>S - Inter-IC Sound Controller DMA Quickstart
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
#include <conf_i2s_quick_start_dma.h>

static void _configure_i2s(void);

//! [module_inst]
struct i2s_module i2s_instance;
//! [module_inst]

//! [rx_variables]
uint16_t rx_values[4] = {0xEEEE, 0xEEEE, 0xEEEE, 0xEEEE};
//! [rx_dma_resource]
struct dma_resource rx_dma_resource;
//! [rx_dma_resource]
//! [rx_dma_descriptor]
COMPILER_ALIGNED(16) DmacDescriptor rx_dma_descriptor;
//! [rx_dma_descriptor]
//! [rx_variables]

//! [tx_variables]
uint16_t tx_values[4] = {0xF87F, 0x901F, 0, 0};
//! [tx_dma_resource]
struct dma_resource tx_dma_resource;
//! [tx_dma_resource]
//! [tx_dma_descriptor]
COMPILER_ALIGNED(16) DmacDescriptor tx_dma_descriptor;
//! [tx_dma_descriptor]
//! [tx_variables]


//! [config_dma_for_rx]
static void _config_dma_for_rx(void)
{
	//! [config_dma_resource_for_rx]
	//! [dma_setup_1]
	struct dma_resource_config config;
	//! [dma_setup_1]

	//! [dma_setup_2]
	dma_get_config_defaults(&config);
	//! [dma_setup_2]

	//! [dma_setup_3]
	config.trigger_action = DMA_TRIGGER_ACTION_BEAT;
	config.peripheral_trigger = CONF_RX_TRIGGER;
	//! [dma_setup_3]

	//! [dma_setup_4]
	dma_allocate(&rx_dma_resource, &config);
	//! [dma_setup_4]
	//! [config_dma_resource_for_rx]

	//! [config_dma_descriptor_for_rx]
	//! [dma_setup_5]
	struct dma_descriptor_config descriptor_config;
	//! [dma_setup_5]

	//! [dma_setup_6]
	dma_descriptor_get_config_defaults(&descriptor_config);
	//! [dma_setup_6]

	//! [dma_setup_7]
	descriptor_config.block_transfer_count = 4;
	descriptor_config.beat_size = DMA_BEAT_SIZE_HWORD;
	descriptor_config.step_selection = DMA_STEPSEL_SRC;
	descriptor_config.src_increment_enable = false;
	descriptor_config.destination_address =
			(uint32_t)rx_values + sizeof(rx_values);
	descriptor_config.source_address = (uint32_t)&CONF_I2S_MODULE->DATA[1];
	//! [dma_setup_7]

	//! [dma_setup_8]
	dma_descriptor_create(&rx_dma_descriptor, &descriptor_config);
	//! [dma_setup_8]

	//! [dma_setup_9]
	rx_dma_descriptor.DESCADDR.reg = (uint32_t)&rx_dma_descriptor;
	//! [dma_setup_9]
	//! [config_dma_descriptor_for_rx]

	//! [config_dma_job_for_rx]
	//! [dma_setup_10]
	dma_add_descriptor(&rx_dma_resource, &rx_dma_descriptor);
	//! [dma_setup_10]
	//! [dma_setup_11]
	dma_start_transfer_job(&rx_dma_resource);
	//! [dma_setup_11]
	//! [config_dma_job_for_rx]
}
//! [config_dma_for_rx]

//! [config_dma_for_tx]
static void _config_dma_for_tx(void)
{
	//! [config_dma_resource_for_tx]
	struct dma_resource_config config;
	dma_get_config_defaults(&config);
	config.trigger_action = DMA_TRIGGER_ACTION_BEAT;
	config.peripheral_trigger = CONF_TX_TRIGGER;
	dma_allocate(&tx_dma_resource, &config);
	//! [config_dma_resource_for_tx]

	//! [config_dma_descriptor_for_tx]
	struct dma_descriptor_config descriptor_config;

	dma_descriptor_get_config_defaults(&descriptor_config);

	descriptor_config.block_transfer_count = 4;
	descriptor_config.beat_size = DMA_BEAT_SIZE_HWORD;
	descriptor_config.dst_increment_enable = false;
	descriptor_config.source_address =
			(uint32_t)tx_values + sizeof(tx_values);
	descriptor_config.destination_address = (uint32_t)&CONF_I2S_MODULE->DATA[0];

	dma_descriptor_create(&tx_dma_descriptor, &descriptor_config);

	tx_dma_descriptor.DESCADDR.reg = (uint32_t)&tx_dma_descriptor;
	//! [config_dma_descriptor_for_tx]

	//! [config_dma_job_for_tx]
	dma_add_descriptor(&tx_dma_resource, &tx_dma_descriptor);
	dma_start_transfer_job(&tx_dma_resource);
	//! [config_dma_job_for_tx]
}
//! [config_dma_for_tx]

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

	//! [setup_serializer_change_config_rx]
	config_serializer.loop_back = true;
	config_serializer.mode = I2S_SERIALIZER_RECEIVE;
	config_serializer.data_size = I2S_DATA_SIZE_16BIT;
	//! [setup_serializer_change_config_rx]

	//! [setup_serializer_change_config_pin_rx]
	config_serializer.data_pin.enable = false;
	//! [setup_serializer_change_config_pin_rx]

	//! [setup_serializer_set_config_rx]
	i2s_serializer_set_config(&i2s_instance, I2S_SERIALIZER_1,
			&config_serializer);
	//! [setup_serializer_set_config_rx]

	//! [setup_enable]
	i2s_enable(&i2s_instance);
	i2s_clock_unit_enable(&i2s_instance, I2S_CLOCK_UNIT_0);
	i2s_serializer_enable(&i2s_instance, I2S_SERIALIZER_1);
	i2s_serializer_enable(&i2s_instance, I2S_SERIALIZER_0);
	//! [setup_enable]
}
//! [setup]

int main(void)
{
	system_init();

	//! [setup_init]
	//! [setup_dma]
	_config_dma_for_rx();
	_config_dma_for_tx();
	//! [setup_dma]
	_configure_i2s();
	//! [setup_init]

//! [main]
	//! [main_loop]
	while (true) {
		/* Infinite loop */
	}
	//! [main_loop]
//! [main]
}
