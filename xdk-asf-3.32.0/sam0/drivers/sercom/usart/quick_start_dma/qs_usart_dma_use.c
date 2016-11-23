/**
 * \file
 *
 * \brief SAM Sercom Usart driver with DMA quick start
 *
 * Copyright (C) 2014-2016 Atmel Corporation. All rights reserved.
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

//! [module_inst]
struct usart_module usart_instance;
//! [module_inst]

//! [dma_resource]
struct dma_resource usart_dma_resource_rx;
struct dma_resource usart_dma_resource_tx;
//! [dma_resource]

//! [usart_buffer]
#define BUFFER_LEN    8
static uint16_t string[BUFFER_LEN];
//! [usart_buffer]

//! [transfer_descriptor]
COMPILER_ALIGNED(16)
DmacDescriptor example_descriptor_rx SECTION_DMAC_DESCRIPTOR;
DmacDescriptor example_descriptor_tx SECTION_DMAC_DESCRIPTOR;
//! [transfer_descriptor]

//! [setup]
//! [transfer_done_rx]
static void transfer_done_rx(struct dma_resource* const resource )
{
	dma_start_transfer_job(&usart_dma_resource_tx);
}
//! [transfer_done_rx]

//! [transfer_done_tx]
static void transfer_done_tx(struct dma_resource* const resource )
{
	dma_start_transfer_job(&usart_dma_resource_rx);
}
//! [transfer_done_tx]

//! [config_dma_resource_rx]
static void configure_dma_resource_rx(struct dma_resource *resource)
{
//! [setup_rx_1]
	struct dma_resource_config config;
//! [setup_rx_1]

//! [setup_rx_2]
	dma_get_config_defaults(&config);
//! [setup_rx_2]

//! [setup_rx_3]
	config.peripheral_trigger = EDBG_CDC_SERCOM_DMAC_ID_RX;
	config.trigger_action = DMA_TRIGGER_ACTION_BEAT;
//! [setup_rx_3]

//! [setup_rx_4]
	dma_allocate(resource, &config);
//! [setup_rx_4]
}
//! [config_dma_resource_rx]

//! [setup_dma_transfer_rx_descriptor]
static void setup_transfer_descriptor_rx(DmacDescriptor *descriptor)
{
//! [setup_rx_5]
	struct dma_descriptor_config descriptor_config;
//! [setup_rx_5]

//! [setup_rx_6]
	dma_descriptor_get_config_defaults(&descriptor_config);
//! [setup_rx_6]

//! [setup_rx_7]
	descriptor_config.beat_size = DMA_BEAT_SIZE_HWORD;
	descriptor_config.src_increment_enable = false;
	descriptor_config.block_transfer_count = BUFFER_LEN;
	descriptor_config.destination_address =
			(uint32_t)string + sizeof(string);
	descriptor_config.source_address =
			(uint32_t)(&usart_instance.hw->USART.DATA.reg);
//! [setup_rx_7]

//! [setup_rx_8]
	dma_descriptor_create(descriptor, &descriptor_config);
//! [setup_rx_8]
}
//! [setup_dma_transfer_rx_descriptor]

//! [config_dma_resource_tx]
static void configure_dma_resource_tx(struct dma_resource *resource)
{
//! [setup_tx_1]
	struct dma_resource_config config;
//! [setup_tx_1]

//! [setup_tx_2]
	dma_get_config_defaults(&config);
//! [setup_tx_2]

//! [setup_tx_3]
	config.peripheral_trigger = EDBG_CDC_SERCOM_DMAC_ID_TX;
	config.trigger_action = DMA_TRIGGER_ACTION_BEAT;
//! [setup_tx_3]

//! [setup_tx_4]
	dma_allocate(resource, &config);
//! [setup_tx_4]
}
//! [config_dma_resource_tx]

//! [setup_dma_transfer_tx_descriptor]
static void setup_transfer_descriptor_tx(DmacDescriptor *descriptor)
{
//! [setup_tx_5]
	struct dma_descriptor_config descriptor_config;
//! [setup_tx_5]

//! [setup_tx_6]
	dma_descriptor_get_config_defaults(&descriptor_config);
//! [setup_tx_6]

//! [setup_tx_7]
	descriptor_config.beat_size = DMA_BEAT_SIZE_HWORD;
	descriptor_config.dst_increment_enable = false;
	descriptor_config.block_transfer_count = BUFFER_LEN;
	descriptor_config.source_address = (uint32_t)string + sizeof(string);
	descriptor_config.destination_address =
		(uint32_t)(&usart_instance.hw->USART.DATA.reg);
//! [setup_tx_7]

//! [setup_tx_8]
	dma_descriptor_create(descriptor, &descriptor_config);
//! [setup_tx_8]
}
//! [setup_dma_transfer_tx_descriptor]

//! [setup_usart]
static void configure_usart(void)
{
//! [setup_config]
	struct usart_config config_usart;
//! [setup_config]
//! [setup_config_defaults]
	usart_get_config_defaults(&config_usart);
//! [setup_config_defaults]

//! [setup_change_config]
	config_usart.baudrate    = 9600;
	config_usart.mux_setting = EDBG_CDC_SERCOM_MUX_SETTING;
	config_usart.pinmux_pad0 = EDBG_CDC_SERCOM_PINMUX_PAD0;
	config_usart.pinmux_pad1 = EDBG_CDC_SERCOM_PINMUX_PAD1;
	config_usart.pinmux_pad2 = EDBG_CDC_SERCOM_PINMUX_PAD2;
	config_usart.pinmux_pad3 = EDBG_CDC_SERCOM_PINMUX_PAD3;
//! [setup_change_config]

//! [setup_set_config]
	while (usart_init(&usart_instance,
			EDBG_CDC_MODULE, &config_usart) != STATUS_OK) {
	}
//! [setup_set_config]

//! [setup_enable]
	usart_enable(&usart_instance);
//! [setup_enable]
}
//! [setup_usart]
//! [setup]

int main(void)
{
	system_init();

//! [setup_init]
//! [setup_usart]
	configure_usart();
//! [setup_usart]

//! [setup_dma_resource]
	configure_dma_resource_rx(&usart_dma_resource_rx);
	configure_dma_resource_tx(&usart_dma_resource_tx);
//! [setup_dma_resource]

//! [setup_transfer_descriptor]
	setup_transfer_descriptor_rx(&example_descriptor_rx);
	setup_transfer_descriptor_tx(&example_descriptor_tx);
//! [setup_transfer_descriptor]

//! [add_descriptor_to_resource]
	dma_add_descriptor(&usart_dma_resource_rx, &example_descriptor_rx);
	dma_add_descriptor(&usart_dma_resource_tx, &example_descriptor_tx);
//! [add_descriptor_to_resource]

//! [setup_callback_register]
	dma_register_callback(&usart_dma_resource_rx, transfer_done_rx,
			DMA_CALLBACK_TRANSFER_DONE);
	dma_register_callback(&usart_dma_resource_tx, transfer_done_tx,
			DMA_CALLBACK_TRANSFER_DONE);
//! [setup_callback_register]

//! [setup_enable_callback]
	dma_enable_callback(&usart_dma_resource_rx,
			DMA_CALLBACK_TRANSFER_DONE);
	dma_enable_callback(&usart_dma_resource_tx,
			DMA_CALLBACK_TRANSFER_DONE);
//! [setup_enable_callback]
//! [setup_init]

//! [main]
//! [main_1]
	dma_start_transfer_job(&usart_dma_resource_rx);
//! [main_1]

//! [endless_loop]
	while (true) {
	}
//! [endless_loop]
//! [main]
}
