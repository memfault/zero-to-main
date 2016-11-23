/**
 * \file
 *
 * \brief SAM USART LIN Quick Start
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
#include <asf.h>
#include <string.h>
#include <conf_lin.h>

//! [module_var]

//! [module_inst]
static struct usart_module cdc_instance,lin_instance;
//! [module_inst]

//! [lin_id]
#define LIN_ID_FIELD_VALUE 0x64
//! [lin_id]

//! [lin_buffer]
#define LIN_DATA_LEN 5
static uint8_t rx_buffer[LIN_DATA_LEN]={0};
const static uint8_t tx_buffer[LIN_DATA_LEN]={0x4a,0x55,0x93,0xe5,0xe6};
//! [lin_buffer]

//! [module_var]

//! [setup]

//! [CDC_setup]
static void configure_usart_cdc(void)
{

	struct usart_config config_cdc;
	usart_get_config_defaults(&config_cdc);
	config_cdc.baudrate	 = 115200;
	config_cdc.mux_setting = EDBG_CDC_SERCOM_MUX_SETTING;
	config_cdc.pinmux_pad0 = EDBG_CDC_SERCOM_PINMUX_PAD0;
	config_cdc.pinmux_pad1 = EDBG_CDC_SERCOM_PINMUX_PAD1;
	config_cdc.pinmux_pad2 = EDBG_CDC_SERCOM_PINMUX_PAD2;
	config_cdc.pinmux_pad3 = EDBG_CDC_SERCOM_PINMUX_PAD3;
	stdio_serial_init(&cdc_instance, EDBG_CDC_MODULE, &config_cdc);
	usart_enable(&cdc_instance);
}
//! [CDC_setup]

//! [lin_setup]
static void lin_read_callback(struct usart_module *const usart_module)
{

	uint8_t i = 0;

	if (CONF_LIN_NODE_TYPE == LIN_MASTER_NODE) {
		for(i = 0; i < LIN_DATA_LEN; i++){
			if(rx_buffer[i] != tx_buffer[i]) {
				printf("Data error\r\n");
				break;
			}
		}
		if(i == LIN_DATA_LEN){
			printf("Slave response: OK\r\n");
		}
	} else if (CONF_LIN_NODE_TYPE == LIN_SLAVE_NODE) {
		if(rx_buffer[0] == LIN_ID_FIELD_VALUE) {
			usart_enable_transceiver(&lin_instance,USART_TRANSCEIVER_TX);
			printf("Receive ID field from mater: OK \r\n");
			usart_write_buffer_job(&lin_instance,
				(uint8_t *)tx_buffer, LIN_DATA_LEN);
		}
	}
}
static void lin_read_error_callback(struct usart_module *const usart_module)
{
      printf("Data Read error\r\n");
}

static void configure_usart_lin(void)
{

	struct port_config pin_conf;
	port_get_config_defaults(&pin_conf);
	pin_conf.direction  = PORT_PIN_DIR_OUTPUT;
	port_pin_set_config(LIN_EN_PIN, &pin_conf);

	/* Enable LIN module*/
	port_pin_set_output_level(LIN_EN_PIN, 1);

	struct usart_config config_lin;
	usart_get_config_defaults(&config_lin);

	/* LIN frame format*/
	config_lin.lin_node = CONF_LIN_NODE_TYPE;
	config_lin.transfer_mode = USART_TRANSFER_ASYNCHRONOUSLY;
	config_lin.sample_rate = USART_SAMPLE_RATE_16X_FRACTIONAL;

	config_lin.baudrate = 115200;
	config_lin.mux_setting = LIN_USART_SERCOM_MUX_SETTING;
	config_lin.pinmux_pad0 = LIN_USART_SERCOM_PINMUX_PAD0;
	config_lin.pinmux_pad1 = LIN_USART_SERCOM_PINMUX_PAD1;
	config_lin.pinmux_pad2 = LIN_USART_SERCOM_PINMUX_PAD2;
	config_lin.pinmux_pad3 = LIN_USART_SERCOM_PINMUX_PAD3;

	/* Disable receiver and transmitter */
	config_lin.receiver_enable  = false;
	config_lin.transmitter_enable = false;

	if (CONF_LIN_NODE_TYPE == LIN_SLAVE_NODE) {
		config_lin.lin_slave_enable = true;
	}

	while (usart_init(&lin_instance,
		LIN_USART_MODULE, &config_lin) != STATUS_OK) {
	}

	usart_enable(&lin_instance);

	usart_register_callback(&lin_instance,
		lin_read_callback, USART_CALLBACK_BUFFER_RECEIVED);
	usart_enable_callback(&lin_instance, USART_CALLBACK_BUFFER_RECEIVED);
	  usart_register_callback(&lin_instance,
		lin_read_error_callback, USART_CALLBACK_ERROR);
	usart_enable_callback(&lin_instance, USART_CALLBACK_ERROR);
	system_interrupt_enable_global();
}
//! [lin_setup]

//! [setup]

int main(void)
{
//! [setup_init]
	system_init();
	configure_usart_cdc();
//! [setup_init]

//! [main_setup]
//! [configure_lin]
	configure_usart_lin();
//! [configure_lin]

//! [lin_master_cmd]
	if (CONF_LIN_NODE_TYPE == LIN_MASTER_NODE) {
		printf("LIN Works in Master Mode\r\n");
		if (lin_master_transmission_status(&lin_instance)) {
			usart_enable_transceiver(&lin_instance,USART_TRANSCEIVER_TX);
			lin_master_send_cmd(&lin_instance,LIN_MASTER_AUTO_TRANSMIT_CMD);
			usart_write_wait(&lin_instance,LIN_ID_FIELD_VALUE);
			usart_enable_transceiver(&lin_instance,USART_TRANSCEIVER_RX);
			while(1) {
				usart_read_buffer_job(&lin_instance,
				(uint8_t *)rx_buffer, 5);
			}
		}
	} else {
		printf("LIN Works in Slave Mode\r\n");
		usart_enable_transceiver(&lin_instance,USART_TRANSCEIVER_RX);
		while(1) {
			usart_read_buffer_job(&lin_instance,
			(uint8_t *)rx_buffer, 1);
		}
	}
//! [lin_master_cmd]

//! [main_setup]
}
