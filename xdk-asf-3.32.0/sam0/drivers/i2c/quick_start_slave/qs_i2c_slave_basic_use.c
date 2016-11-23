/**
 * \file
 *
 * \brief I2C Slave Quick Start Guide for SAMB
 *
 * Copyright (c) 2015-2016 Atmel Corporation. All rights reserved.
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

//! [packet_data]
#define DATA_LENGTH 10
static uint8_t write_buffer[DATA_LENGTH] = {
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09
};

static uint8_t read_buffer[DATA_LENGTH];
//! [packet_data]

//! [address]
#define SLAVE_ADDRESS 0x12
//! [address]

/* Init software module. */
//! [dev_inst]
struct i2c_slave_module i2c_slave_instance;
//! [dev_inst]

//! [initialize_i2c]
static void configure_i2c_slave(void)
{
	/* Initialize config structure and software module. */
	//! [init_conf]
	struct i2c_slave_config config_i2c_slave;
	i2c_slave_get_config_defaults(&config_i2c_slave);
	//! [init_conf]
	/* Change address and address_mode. */
	//! [conf_changes]
	config_i2c_slave.address = SLAVE_ADDRESS;
	
	config_i2c_slave.pin_number_pad0 = PIN_LP_GPIO_14;
	config_i2c_slave.pin_number_pad1 = PIN_LP_GPIO_15;
	config_i2c_slave.pinmux_sel_pad0 = MUX_LP_GPIO_14_I2C1_SDA;
	config_i2c_slave.pinmux_sel_pad1 = MUX_LP_GPIO_15_I2C1_SCL;
	
	//! [conf_changes]
	/* Initialize and enable device with config, and enable i2c. */
	//! [init_module]
	while(i2c_slave_init(&i2c_slave_instance, I2C1, &config_i2c_slave)     \
			!= STATUS_OK);
	//! [init_module]
	//! [enable_module]
	i2c_enable(i2c_slave_instance.hw);
	//! [enable_module]
	//! [enable_interurpt]
	i2c_slave_rx_interrupt(i2c_slave_instance.hw, true);
	i2c_slave_tx_interrupt(i2c_slave_instance.hw, true);
	//! [enable_interurpt]
}
//! [initialize_i2c]

int main(void)
{
	
	//! [init]
	system_clock_config(CLOCK_RESOURCE_XO_26_MHZ, CLOCK_FREQ_26_MHZ);
	
	configure_i2c_slave();

	//! [packet]
	struct i2c_slave_packet packet = {
		.data_length = DATA_LENGTH,
		.data        = write_buffer,
	};
	//! [packet]

	//! [init]
	//! [while]
	while (true) {
		packet.data = read_buffer;
		i2c_slave_read_packet_wait(&i2c_slave_instance, &packet);
		packet.data = write_buffer;
		i2c_slave_write_packet_wait(&i2c_slave_instance, &packet);
	}
	//! [while]
}
