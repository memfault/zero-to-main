/**
 * \file
 *
 * \brief SAM RTC Tamper DMA Quick Start
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

void configure_dma_resource(struct dma_resource *resource);
void setup_transfer_descriptor(DmacDescriptor *descriptor);

void rtc_tamper_callback(void);
void configure_rtc(void);
void configure_rtc_callbacks(void);

//! [rtc_module_instance]
struct rtc_module rtc_instance;
//! [rtc_module_instance]

//! [dma_resource]
struct dma_resource example_resource;
//! [dma_resource]

// [transfer_descriptor]
COMPILER_ALIGNED(16)
DmacDescriptor example_descriptor SECTION_DMAC_DESCRIPTOR;
// [transfer_descriptor]

static uint32_t buffer_rtc_tamper;

//! [callback]
void rtc_tamper_callback(void)
{
	//! [Tamper_act]
	/* Do something on RTC tamper capture here */
	LED_On(LED_0_PIN);
	//! [Tamper_act]
}
//! [callback]

//! [initialize_rtc]
void configure_rtc(void)
{
//! [init_rtc]
	struct rtc_count_config config_rtc_count;
	rtc_count_get_config_defaults(&config_rtc_count);
	config_rtc_count.prescaler = RTC_COUNT_PRESCALER_DIV_1;
	rtc_count_init(&rtc_instance, RTC, &config_rtc_count);
//! [init_rtc]

//! [set_tamper_config]
	struct rtc_tamper_config config_rtc_tamper;
	rtc_tamper_get_config_defaults(&config_rtc_tamper);
	config_rtc_tamper.dma_tamper_enable = true;
	config_rtc_tamper.in_cfg[0].level = RTC_TAMPER_LEVEL_RISING;
	config_rtc_tamper.in_cfg[0].action = RTC_TAMPER_INPUT_ACTION_CAPTURE;
	rtc_tamper_set_config(&rtc_instance, &config_rtc_tamper);
//! [set_tamper_config]

//! [enable]
	rtc_count_enable(&rtc_instance);
//! [enable]
}
//! [initialize_rtc]

//! [setup_callback]
void configure_rtc_callbacks(void)
{
	//! [reg_callback]
	rtc_count_register_callback(
			&rtc_instance, rtc_tamper_callback, RTC_COUNT_CALLBACK_TAMPER);
	//! [reg_callback]
	//! [en_callback]
	rtc_count_enable_callback(&rtc_instance, RTC_COUNT_CALLBACK_TAMPER);
	//! [en_callback]
}
//! [setup_callback]

//! [config_dma_resource]
void configure_dma_resource(struct dma_resource *resource)
{
//! [setup_dma_config]
	struct dma_resource_config config;
//! [setup_dma_config]

//! [setup_dma_set_config_default]
	dma_get_config_defaults(&config);
//! [setup_dma_set_config_default]

//! [setup_dma_set_config_extra]
	config.peripheral_trigger = RTC_DMAC_ID_TIMESTAMP;
	config.trigger_action = DMA_TRIGGER_ACTION_BEAT;
//! [setup_dma_set_config_extra]

//! [allocate_dma_resource]
	dma_allocate(resource, &config);
//! [allocate_dma_resource]
}
//! [config_dma_resource]

//! [setup_dma_transfer_descriptor]
void setup_transfer_descriptor(DmacDescriptor *descriptor)
{
//! [setup_dma_desc_config]
	struct dma_descriptor_config descriptor_config;
//! [setup_dma_desc_config]

//! [setup_dma_desc_config_set_default]
	dma_descriptor_get_config_defaults(&descriptor_config);
//! [setup_dma_desc_config_set_default]

//! [setup_dma_desc_config_set_extra]
	descriptor_config.beat_size = DMA_BEAT_SIZE_WORD;
	descriptor_config.dst_increment_enable = false;
	descriptor_config.src_increment_enable = false;
	descriptor_config.block_transfer_count = 1;
	descriptor_config.source_address = (uint32_t)(&rtc_instance.hw->MODE0.TIMESTAMP.reg);
	descriptor_config.destination_address = (uint32_t)(buffer_rtc_tamper);
	descriptor_config.next_descriptor_address = (uint32_t)descriptor;
//! [setup_dma_desc_config_set_extra]

//! [setup_dma_desc_config_create]
	dma_descriptor_create(descriptor, &descriptor_config);
//! [setup_dma_desc_config_create]
}
//! [setup_dma_transfer_descriptor]
//! [setup]

int main(void)
{
//! [main]
	/* Initialize system. Must configure conf_clocks.h first. */
//! [system_init]
	system_init();
//! [system_init]

	/* Configure and enable RTC */
//! [run_conf]
	configure_rtc();
//! [run_conf]

	/* Configure and enable callback */
//! [run_callback]
	configure_rtc_callbacks();
//! [run_callback]

//! [setup_dma_resource]
	configure_dma_resource(&example_resource);
//! [setup_dma_resource]

//! [setup_transfer_descriptor]
	setup_transfer_descriptor(&example_descriptor);
//! [setup_transfer_descriptor]

//! [add_descriptor_to_resource]
	dma_add_descriptor(&example_resource, &example_descriptor);
//! [add_descriptor_to_resource]

//! [while]
	while (true) {
		/* Infinite while loop */
	}
//! [while]
//! [main]
}
