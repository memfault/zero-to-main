/**
 * \file
 *
 * \brief SAM D21 TCC RAMP2 DMA operation with circular buffer Example Application
 *
 * Copyright (C) 2015 Atmel Corporation. All rights reserved.
 *
 * \license
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
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include <asf.h>
#include "conf_example.h"


/* ---------------------------------------------------------------------------*/

static struct tcc_module tcc_instance;
static struct dma_resource tcc_ramp_a_dma_resource; 
static COMPILER_ALIGNED(16) DmacDescriptor tcc_ramp_a_dma_descriptor;

/*
	New cycle A TCC value
*/
static uint32_t tcc_cycle_a_val[1] = {120};
/*
	status code
*/	
static enum status_code stat       = STATUS_OK;

/*
	configure DMA
*/
static void config_dma_for_tcc_ramp2a(void)
{
	struct dma_resource_config config;

	dma_get_config_defaults(&config);

	/* select beat transfer */
	config.trigger_action = DMA_TRIGGER_ACTION_BEAT;

	config.peripheral_trigger = TCC0_DMAC_ID_MC_0;

	dma_allocate(&tcc_ramp_a_dma_resource, &config);

	struct dma_descriptor_config descriptor_config;

	dma_descriptor_get_config_defaults(&descriptor_config);

	descriptor_config.block_transfer_count = 1;
	descriptor_config.beat_size = DMA_BEAT_SIZE_WORD;
	
	/* Disable auto increment for source and destination */
	descriptor_config.src_increment_enable = false;
	descriptor_config.dst_increment_enable = false;
	
	/* define source and destination address */
	descriptor_config.source_address = (uint32_t) tcc_cycle_a_val;
	descriptor_config.destination_address =	(uint32_t) &TCC0->CCB[0];

	/* fill the descriptor with descriptor_config parameters */
	dma_descriptor_create(&tcc_ramp_a_dma_descriptor, &descriptor_config);

	/* add to descriptor chain */
	dma_add_descriptor(&tcc_ramp_a_dma_resource, &tcc_ramp_a_dma_descriptor);

	dma_start_transfer_job(&tcc_ramp_a_dma_resource);
}

/*
	Trigger configuration
*/
static void configure_trigger(void)
{
	struct port_config pin_conf;
	
	port_get_config_defaults(&pin_conf);
	
	pin_conf.direction = PORT_PIN_DIR_OUTPUT;
	port_pin_set_config(TRIGGER_PIN, &pin_conf);
	
	port_pin_set_output_level(TRIGGER_PIN, false);
}

/*
	configure TCC
*/
static void configure_tcc_ramp2a_mode(void)
{
	/* Structure used to store the TCC configuration parameters */
	struct tcc_config config_tcc;

	/* Fill the Structure with the default values */
	tcc_get_config_defaults(&config_tcc, TCC0);
	
	/* Configure the single slope PWM waveform generation for waveform output */
	config_tcc.compare.wave_generation = TCC_WAVE_GENERATION_SINGLE_SLOPE_PWM;
	
	/* Configure the TCC clock source and its divider value */
	config_tcc.counter.clock_source    = GLCK_SOURCE;
	config_tcc.counter.clock_prescaler = TCC_CLOCK_DIVIDER;

	/* Configure the value for TOP value */
	config_tcc.counter.period = PER_Value;

	/* CC0 will be included to generate ramp output */
	config_tcc.pins.enable_wave_out_pin[0] = true;
	config_tcc.pins.wave_out_pin[0]        = PIN_PA04E_TCC0_WO0;
	config_tcc.pins.wave_out_pin_mux[0]    = MUX_PA04E_TCC0_WO0;
	
	/* Set up polarity output ramp */
	config_tcc.compare.wave_polarity[1] = 1;
	config_tcc.compare.wave_polarity[0] = 1;

	/* CC1 is always included to generate ramp output */
	/* Configure the TCC Waveform Output pins for waveform generation output */
	config_tcc.pins.enable_wave_out_pin[1] = true;
	config_tcc.pins.wave_out_pin[1]        = PIN_PA05E_TCC0_WO1;
	
	/* Configure the Alternate function of GPIO pins for TCC functionality */
	config_tcc.pins.wave_out_pin_mux[1] = MUX_PA05E_TCC0_WO1;

	/* Configure the RAMP mode operation as RAMP2 mode */
	config_tcc.compare.wave_ramp = TCC_RAMP_RAMP2A;

	/* Initialize the TCC0 channel and define the its registers with 
		configuration defined in the config_tcc */
	stat = tcc_init(&tcc_instance, TCC0, &config_tcc);


	/* CC0 is included to generate ramp output
	   PER & PERB build the circular PER pair */
	stat = tcc_set_double_buffer_compare_values(&tcc_instance, 
				TCC_MATCH_CAPTURE_CHANNEL_0, CC0_Value, CCB0_Value);
				
	stat = tcc_enable_circular_buffer_compare(&tcc_instance, 
				TCC_MATCH_CAPTURE_CHANNEL_0);
	
	/* Load the PER and PERB values respectively 
		for the circular buffer operation */
	stat = tcc_set_double_buffer_top_values(&tcc_instance, 
			PER_Value, PERB_Value);
			
	/* Enable the Circular Buffer feature for the Period */
	tcc_enable_circular_buffer_top(&tcc_instance);

	/* Enable the TCC module */
	tcc_enable(&tcc_instance);
}


void trigger_generation(void)
{
#define TRIGGER_FLAGS (TCC_INTFLAG_OVF)
	if (tcc_instance.hw->INTFLAG.reg & TRIGGER_FLAGS) {
		
		tcc_instance.hw->INTFLAG.reg = TRIGGER_FLAGS;
		
		/* Toggle the trigger pin */
		port_pin_toggle_output_level(TRIGGER_PIN);

	}
}

/*configure ramp2 DMA controller*/
void config_ramp2_dma(void)
{
	config_dma_for_tcc_ramp2a();
	configure_trigger();
	configure_tcc_ramp2a_mode();	
}

