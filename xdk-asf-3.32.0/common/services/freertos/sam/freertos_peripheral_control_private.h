/**
 *
 * \file
 *
 * \brief Generic FreeRTOS peripheral control functions
 *
 *
 * Copyright (c) 2012-2016 Atmel Corporation. All rights reserved.
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

#ifndef FREERTOS_PRIVATE_PERIPHERAL_CONTROL_INCLUDED
#define FREERTOS_PRIVATE_PERIPHERAL_CONTROL_INCLUDED

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/* Contains the information needed to control circular buffer reception using
the PDC. */
typedef struct freertos_pdc_rx_control {
	uint32_t rx_buffer_start_address;		/*< The start of the buffer used to store received bytes. */
	uint32_t past_rx_buffer_end_address;	/*< One byte past the end of the valid Rx buffer region. */
	pdc_packet_t rx_pdc_parameters;			/*< Defines the section of the receive buffer currently being used by the PDC. */
	xSemaphoreHandle rx_event_semaphore;	/*< Used to indicate the possible presence of unread data in the Rx buffer. */
	xSemaphoreHandle rx_access_mutex;		/*< Used for mutual exclusion to the Rx buffer.  Optional. */
	uint8_t *next_byte_to_read;				/*< Pointer to the next byte that will be read out of the Rx buffer. */
} freertos_pdc_rx_control_t;

/* Contains the information needed to interface a PDC controlled zero copy
transmit function with a multi-tasking application. */
typedef struct freertos_dma_tx_control {
	xSemaphoreHandle transaction_complete_notification_semaphore;	/*< Used to indicate the end of a DMA controlled transaction. */
	xSemaphoreHandle peripheral_access_sem;						    /*< Used for mutual exclusion to the DMA.  Optional. */
} freertos_dma_event_control_t;

/* Contains identification information required for accessing a peripheral. */
typedef struct freertos_peripheral_parameters {
	void *peripheral_base_address;			/*< The base address of the peripheral. */
	Pdc *pdc_base_address;					/*< The address of the PDC registers within the peripheral register set. */
	uint32_t peripheral_id;					/*< The ID of the peripheral required for the setup of the peripheral, for example calls to pmc_enable_periph_clk(). */
	enum IRQn peripheral_irq;				/*< The position of the peripheral's interrupt vector. */
} freertos_pdc_peripheral_parameters_t;

/* The following functions are for internal use only.  They are described where
they are implemented. */
#define freertos_start_pdc_tx(dma_event_control, data, len, pdc_base_address, notification_semaphore) freertos_start_pdc_transfer(dma_event_control, data, len, pdc_base_address, notification_semaphore, true)
#define freertos_start_pdc_rx(dma_event_control, data, len, pdc_base_address, notification_semaphore) freertos_start_pdc_transfer(dma_event_control, data, len, pdc_base_address, notification_semaphore, false)

void freertos_start_pdc_transfer(
		freertos_dma_event_control_t *dma_event_control,
		const uint8_t *data, size_t len, void *pdc_base_address,
		xSemaphoreHandle notification_semaphore,
		bool is_transmitting);
portBASE_TYPE get_pdc_peripheral_details(
		const freertos_pdc_peripheral_parameters_t peripheral_array[],
		size_t array_size, void *peripheral_to_find);
bool check_requested_operating_mode(
		const enum peripheral_operation_mode requested_operation_mode,
		const enum peripheral_operation_mode valid_operating_modes[],
		portBASE_TYPE num_valid_operating_modes);
uint32_t freertos_copy_bytes_from_pdc_circular_buffer(
		freertos_pdc_rx_control_t *p_rx_buffer_details,
		uint32_t next_byte_to_be_written, uint8_t *buf,
		uint32_t bytes_to_read);
status_code_t freertos_obtain_peripheral_access_semphore(
		freertos_dma_event_control_t *dma_event_control,
		portTickType *max_block_time_ticks);
status_code_t freertos_optionally_wait_transfer_completion(
		freertos_dma_event_control_t *dma_event_control,
		xSemaphoreHandle notification_semaphore,
		portTickType max_block_time_ticks);
void create_peripheral_control_semaphores(const uint8_t options_flags,
		freertos_dma_event_control_t *tx_dma_control,
		freertos_dma_event_control_t *rx_dma_control);
void configure_interrupt_controller(const enum IRQn peripheral_irq,
		uint32_t interrupt_priority);

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* FREERTOS_PRIVATE_PERIPHERAL_CONTROL_INCLUDED */
