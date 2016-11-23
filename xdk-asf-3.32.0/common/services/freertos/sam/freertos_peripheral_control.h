/**
 * \file
 *
 * \brief FreeRTOS Peripheral Control API Functions
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

#ifndef FREERTOS_PERIPHERAL_CONTROL_INCLUDED
#define FREERTOS_PERIPHERAL_CONTROL_INCLUDED

/**
 * \defgroup freertos_service_group FreeRTOS Peripheral Control
 *
 * ASF specific FreeRTOS functionality that integrates ASF driver libraries with
 * FreeRTOS services to provide a set of highly efficient peripheral interface
 * functions.
 *
 * The FreeRTOS ASF functions use the peripheral DMA controller (PDC) to send
 * and receive data with practically no processing overhead, and use the
 * FreeRTOS multi-tasking services to ensure the microcontroller can continue
 * executing application code at all times, even when one thread of execution
 * has to wait for a transmit or receive to complete.
 *
 * Peripherals can be initialized to execute is standard mode or fully
 * asynchronous mode.  In standard mode, the API functions used to transmit to
 * or receive from a peripheral do not return until the entire transmit or
 * receive operation has completed.  Other FreeRTOS tasks exeucte while the data
 * transfer is in progress.  In fully asynchronous mode, the API functions used
 * to transmit to or receive from a peripheral return immediately, which may be
 * while the data transfer is still in progress - the task calling the
 * transmit or receive function is then notified by FreeRTOS when the data
 * transfer has completed.
 *
 * The FreeRTOS ASF drivers are supported by an application note, executable
 * examples within the ASF distribution, and example use cases in this
 * documentation set.
 *
 * The following functions are provided for the USART peripheral
 *
 * - freertos_usart_serial_init()
 * - freertos_usart_write_packet()
 * - freertos_usart_write_packet_async()
 * - freertos_usart_serial_read_packet()
 *
 * See \ref freertos_usart_peripheral_control_quick_start
 *
 * The following functions are provided for the UART peripheral
 *
 * - freertos_uart_serial_init()
 * - freertos_uart_write_packet()
 * - freertos_uart_write_packet_async()
 * - freertos_uart_serial_read_packet()
 *
 * See \ref freertos_uart_peripheral_control_quick_start
 *
 * The following functions are provided for the TWI peripheral
 *
 * - freertos_twi_master_init()
 * - freertos_twi_write_packet()
 * - freertos_twi_write_packet_async()
 * - freertos_twi_read_packet()
 * - freertos_twi_read_packet_async()
 *
 * See \ref freertos_twi_peripheral_control_quick_start
 *
 * The following functions are provided for the TWIHS peripheral
 *
 * - freertos_twihs_master_init()
 * - freertos_twihs_write_packet()
 * - freertos_twihs_write_packet_async()
 * - freertos_twihs_read_packet()
 * - freertos_twihs_read_packet_async()
 *
 * See \ref freertos_twihs_peripheral_control_quick_start
 *
 * The following functions are provided for the SPI peripheral
 *
 * - freertos_spi_master_init()
 * - freertos_spi_write_packet()
 * - freertos_spi_write_packet_async()
 * - freertos_spi_read_packet()
 * - freertos_spi_read_packet_async()
 *
 * See \ref freertos_spi_peripheral_control_quick_start
 *
 */
#if SAMG55
#include <conf_board.h>
#endif

#include "status_codes.h"
#include "pdc.h"

#include "FreeRTOS.h"
#include "semphr.h"

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
extern "C" {
#endif
/**INDENT-ON**/
/// @endcond

/**
 * \ingroup freertos_service_group
 * Bit definition used in the options_flags member of a
 * freertos_peripheral_options_t structure passed as a parameter to an 
 * initialization function to indicate that writes to the
 * peripheral being initialized must be thread aware.  When this bit is set the
 * FreeRTOS peripheral driver will use a binary semphore (internally within the driver) to
 * ensure only one FreeRTOS task can perform a write to the peripheral at any
 * one time.  Examples use cases are provided in the FreeRTOS peripheral control 
 * examples that are included in the Atmel ASF distribution, in the application
 * not that accompanies the FreeRTOS peripheral control drivers, and in the 
 * quick start references for the FreeRTOS peripheral control initialization 
 * functions in this online documentation.
 */
#define USE_TX_ACCESS_SEM		0x01

/**
 * \ingroup freertos_service_group
 * Bit definition used in the options_flags member of a
 * freertos_peripheral_options_t structure passed as a parameter to an 
 * initialization function to indicate that reads from the peripheral being 
 * initialized must be thread aware.  When this bit is set the
 * FreeRTOS peripheral driver will use a mutex (internally within the driver) to
 * ensure only one FreeRTOS task can perform a read from the peripheral at any
 * one time.  Examples use cases are provided in the FreeRTOS peripheral control 
 * examples that are included in the Atmel ASF distribution, in the application
 * not that accompanies the FreeRTOS peripheral control drivers, and in the 
 * quick start references for the FreeRTOS peripheral control initialization 
 * functions in this online documentation.
 */
#define USE_RX_ACCESS_MUTEX		0x02

/**
 * \ingroup freertos_service_group
 * Bit definition used in the options_flags member of a
 * freertos_peripheral_options_t structure passed as a parameter to an 
 * initialization function to indicate that a task writing to the peripheral
 * must be held in the FreeRTOS Blocked state until the write has completed.
 * FreeRTOS peripheral write functions often have two version, one where the 
 * function name ends with '_async', and one where the '_async' is omitted.  
 * This bit must be clear to use the _async version, and set to use the version 
 * where _async omitted.  See the documentation for the FreeRTOS peripheral 
 * write functions for more information.  Examples use cases are provided 
 * in the FreeRTOS peripheral control examples that are included in the Atmel 
 * ASF distribution, in the application not that accompanies the FreeRTOS 
 * peripheral control drivers, and in the quick start references for the 
 * FreeRTOS peripheral control initialization functions in this online 
 * documentation.
 */
#define WAIT_TX_COMPLETE		0x04

/**
 * \ingroup freertos_service_group
 * Bit definition used in the options_flags member of a
 * freertos_peripheral_options_t structure passed as a parameter to an 
 * initialization function to indicate that a task reading from the peripheral
 * must be held in the FreeRTOS Blocked state until the read has completed.
 * FreeRTOS peripheral read functions often have two version, one where the 
 * function name ends with '_async', and one where the '_async' is omitted.  
 * This bit must be clear to use the _async version, and set to use the version 
 * where _async omitted.  See the documentation for the FreeRTOS peripheral 
 * read functions for more information.  Examples use cases are provided 
 * in the FreeRTOS peripheral control examples that are included in the Atmel 
 * ASF distribution, in the application not that accompanies the FreeRTOS 
 * peripheral control drivers, and in the quick start references for the 
 * FreeRTOS peripheral control initialization functions in this online 
 * documentation.
 */
#define WAIT_RX_COMPLETE		0x08

/**
 * \ingroup freertos_service_group
 * Defines the operating modes that can be specified in a 
 * freertos_peripheral_options_t structure. 
 */
enum peripheral_operation_mode {
	//! Valid only for USART peripheral.
	USART_RS232 = 0,

	//! Valid only for UART peripheral.
	UART_RS232,

	//! Valid only for the SPI peripheral.
	SPI_MASTER,			

	//! Valid only for the TWI peripheral.
	TWI_I2C_MASTER,

	//! Valid only for the TWIHS peripheral.
	TWIHS_I2C_MASTER,

	//! No other values can be used.
	NOT_SUPPORTED
};

/**
 * \ingroup freertos_service_group
 * Define the behaviour of FreeRTOS ASF read and write functions for a 
 * peripheral.
 */
typedef struct freertos_peripheral_options {
	/**
	 * A pointer to a buffer into which the PDC will write received data.  This 
	 * parameter is, at the time of writing, only required by the USART/UART driver,
	 * and is ignored by other drivers.
	 */
	uint8_t *receive_buffer; 
	
	/**
	 * The size, in bytes, of the buffer pointed to by the receive_buffer 
	 * member.  This parameter is, at the time of writing, only required by the 
	 * USART/UART driver, and is ignored by other drivers.
	 */
	uint32_t receive_buffer_size; 

	/**
	 * Sets the priority of the interrupt generated by the PDC, which MUST be
	 * between the lowest possible priority and 
	 * configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY.  PDC interrupts 
	 * are configured and processed by the FreeRTOS ASF drivers.  
	 * The application writer does not need to concern themselves with 
	 * installing or handling interrupts.  The interrupt priority must not be 
	 * set above configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY, as defined in 
	 * FreeRTOSConfig.h.  Invalid priority values are trapped by an assert() in 
	 * the driver code, but only if configASSERT() is defined in 
	 * FreeRTOSConfig.h.
	 */
	uint32_t interrupt_priority; 
	
	/**
	 * operation_mode is included to allow future FreeRTOS ASF driver versions 
	 * to support multiple modes of operation on a single peripheral.
	 */
	enum peripheral_operation_mode operation_mode; 
	
	/**
	 * Individual bits in the options_flags value configure an aspect of the 
	 * driver's behavior, where valid bits (which are documented as part of the
	 * \ref freertos_service_group documentation) are USE_TX_ACCESS_SEM, 
	 * USE_RX_ACCESS_MUTEX, WAIT_TX_COMPLETE, WAIT_RX_COMPLETE.
	 */
	uint8_t options_flags; 
} freertos_peripheral_options_t;

/// @cond 0
/**INDENT-OFF**/
#ifdef __cplusplus
}
#endif
/**INDENT-ON**/
/// @endcond

#endif /* FREERTOS_PERIPHERAL_CONTROL_INCLUDED */
