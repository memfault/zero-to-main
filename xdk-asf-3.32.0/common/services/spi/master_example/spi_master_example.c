/*****************************************************************************
 *
 * \file
 *
 * \brief Example of usage of the SPI Master Mode Basic Services.
 *
 ******************************************************************************/

/**
 * Copyright (c) 2010-2015 Atmel Corporation. All rights reserved.
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
/*! \mainpage
 * \section intro Introduction
 * This example demonstrates how to use the SPI Master Mode Basic Services.
 *
 * \section files Main Files
 * - spi_master_example.c: port drivers example application.
 * - conf_board.h: board initialization process configuration
 * - conf_spi_master_example.h: board-specific mapping of resources used by this example
 * - spi_master.c: Part Specific SPI Master Mode Implementation
 *
 * \section spiapiinfo services/basic/spi API
 * The spi API can be found \ref spi_master.h "here".
 *
 * \section deviceinfo Device Info
 * All AVR devices can be used. This example has been tested
 * with the following setup:
 *   - Evaluation kits with a dataflash connecting through a SPI interface.
 * To make this example work on STK600 define AT45DB041 in config file.
 *
 * \section exampledescription Description of the example
 *   - Send "Read Status" command to the dataflash.
 *   - Read back the status of the dataflash.
 *   - If status "ok", both \ref SPI_EXAMPLE_LED_PIN_EXAMPLE_1 and \ref SPI_EXAMPLE_LED_PIN_EXAMPLE_2 are 'on'
 *     else \ref SPI_EXAMPLE_LED_PIN_EXAMPLE_1 is 'on' and \ref SPI_EXAMPLE_LED_PIN_EXAMPLE_2 is 'off'.
 *
 * \section compinfo Compilation Info
 * This software was written for the GNU GCC and IAR for AVR.
 * Other compilers may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.atmel.com/">Atmel</A>.\n
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */


#include "compiler.h"
#include "preprocessor.h"
#include "board.h"
#include "gpio.h"
#include "sysclk.h"
#include "spi_master.h"
#include "conf_spi_master_example.h"


uint16_t status; // Status value for dataflash.

/*! \name AT45DBX Group C Commands
 */
//! @{
//! Status Register Read (Serial/8-bit Mode).
#define AT45DBX_CMDC_RD_STATUS_REG        0xD7
//! @}

/*! \name Bit-Masks and Values for the Status Register
 */
//! @{
#define AT45DBX_MSK_DENSITY               0x3C      //!< Device density bit-mask
#ifdef AT45DB041
#define AT45DBX_DENSITY                   0x1C      //!< Device density value.
#else
#define AT45DBX_DENSITY                   0x3C      //!< Device density value.
#endif
//! @}

//! First Status Command Register - Second Dummy Data
uint8_t data[1] = {AT45DBX_CMDC_RD_STATUS_REG};

struct spi_device SPI_DEVICE_EXAMPLE = {
	//! Board specific select id
	.id = SPI_DEVICE_EXAMPLE_ID
};

static bool spi_at45dbx_mem_check(void)
{
	// Select the DF memory to check.
	spi_select_device(SPI_EXAMPLE,&SPI_DEVICE_EXAMPLE);

	// Send the Status Register Read command following by a dummy data.
	spi_write_packet(SPI_EXAMPLE, data, 1);

	// Receive status.
	spi_read_packet(SPI_EXAMPLE, data,1);

	// Extract the status.
	status = data[0];

	// Deselect the checked DF memory.
	spi_deselect_device(SPI_EXAMPLE,&SPI_DEVICE_EXAMPLE);

	// Unexpected device density value.
	if ((status & AT45DBX_MSK_DENSITY) < AT45DBX_DENSITY) return false;
	else return true;
}


/*! \brief Main function.
 */
int main(void)
{
	sysclk_init();

	/* Initialize the board.
	 * The board-specific conf_board.h file contains the configuration of
	 * the board initialization.
	 */
	board_init();
	spi_master_init(SPI_EXAMPLE);
	spi_master_setup_device(SPI_EXAMPLE, &SPI_DEVICE_EXAMPLE, SPI_MODE_0,
			SPI_EXAMPLE_BAUDRATE, 0);
	spi_enable(SPI_EXAMPLE);
	status = spi_at45dbx_mem_check();
	while (true)
	{
		if (status==false)
		{
			gpio_set_pin_low(SPI_EXAMPLE_LED_PIN_EXAMPLE_1);
			gpio_set_pin_high(SPI_EXAMPLE_LED_PIN_EXAMPLE_2);
		}
		else
		{
			gpio_set_pin_low(SPI_EXAMPLE_LED_PIN_EXAMPLE_1);
			gpio_set_pin_low(SPI_EXAMPLE_LED_PIN_EXAMPLE_2);
		}
	}
}

