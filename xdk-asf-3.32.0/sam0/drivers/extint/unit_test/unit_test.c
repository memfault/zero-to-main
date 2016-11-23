/**
 * \file
 *
 * \brief SAM External Interrupt Unit test
 *
 * Copyright (C) 2013-2016 Atmel Corporation. All rights reserved.
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

/**
 * \mainpage SAM EXTINT Unit Test
 * See \ref appdoc_main "here" for project documentation.
 * \copydetails appdoc_preface
 *
 *
 * \page appdoc_preface Overview
 * This unit test carries out tests for the External Interrupt driver.
 * It consists of test cases for the following functionalities:
 *      - Test for polled mode detection of external interrupt.
 *      - Test for callback mode detection of external interrupt.
 */

/**
 * \page appdoc_main SAM EXTINT Unit Test
 *
 * Overview:
 * - \ref appdoc_sam0_extint_unit_test_intro
 * - \ref appdoc_sam0_extint_unit_test_setup
 * - \ref appdoc_sam0_extint_unit_test_usage
 * - \ref appdoc_sam0_extint_unit_test_compinfo
 * - \ref appdoc_sam0_extint_unit_test_contactinfo
 *
 * \section appdoc_sam0_extint_unit_test_intro Introduction
 * \copydetails appdoc_preface
 *
 * Tests will be performed for rising and falling edges of the external signal.
 *
 * The following kit is required for carrying out the test:
 *  - SAM D20/D21/R21/L21/L22/DA1/C21/R30 Xplained Pro board
 *
 * \section appdoc_sam0_extint_unit_test_setup Setup
 * The following connections has to be made using wires:
 * - SAM D21/DA1/D20 Xplained Pro
 *  - EXT1 \b Pin 9 (PB04) <-----> Pin 11 (PA08)
 * - SAM R21 Xplained Pro
 *  - EXT1 \b Pin 3 (PA06) <-----> EXT3 Pin 10 (PA08)
 * - SAM L21 Xplained Pro
 *  - EXT1 \b Pin 9 (PB04) <-----> EXT3 Pin 5 (PB30)
 * - SAM L22 Xplained Pro
 *  - EXT1 \b Pin 9 (PC02) <-----> EXT3 Pin 5 (PC16)
 * - SAM C21 Xplained Pro
 *  - EXT1 \b Pin 9 (PB14) <-----> EXT1 Pin 10 (PB15)
 * - SAM R30 Xplained Pro
 *  - EXT1 \b Pin 5 (PA13) <-----> EXT1 Pin 8 (PA19)
 *
 * To run the test:
 *  - Connect the SAM Xplained Pro board to the computer using a
 *    micro USB cable.
 *  - Open the virtual COM port in a terminal application.
 *    \note The USB composite firmware running on the Embedded Debugger (EDBG)
 *          will enumerate as debugger, virtual COM port and EDBG data
 *          gateway.
 *  - Build the project, program the target and run the application.
 *    The terminal shows the results of the unit test.
 *
 * \section appdoc_sam0_extint_unit_test_usage Usage
 *  - The unit test configures external interrupt on PB04 pin (channel 4)
 *    to detect falling edge.
 *  - Logic level on PB05 is changed from high to low (falling edge) and the
 *    channel is checked for interrupt detection.
 *  - The test is repeated for rising edge and with callback enabled.
 *
 * \section appdoc_sam0_extint_unit_test_compinfo Compilation Info
 * This software was written for the GNU GCC and IAR for ARM.
 * Other compilers may or may not work.
 *
 * \section appdoc_sam0_extint_unit_test_contactinfo Contact Information
 * For further information, visit
 * <a href="http://www.atmel.com">http://www.atmel.com</a>.
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <asf.h>
#include <stdio_serial.h>
#include <string.h>
#include "conf_test.h"

/* Structure for UART module connected to EDBG (used for unit test output) */
struct usart_module cdc_uart_module;
/* Structure for pin configuration */
struct port_config pin_conf;
/* Structure for external interrupt channel configuration */
struct extint_chan_conf eic_conf;
/* Flag for test result used during polling test */
volatile bool result = false;
/* Interrupt flag used during callback test */
volatile bool interrupt_flag = false;

/**
 * \internal
 * \brief External interrupt callback function
 *
 * Called by external interrupt driver on interrupt detection.
 *
 */
static void extint_user_callback(void)
{
	interrupt_flag = true;
}

/**
 * \brief Initialize the USART for unit test
 *
 * Initializes the SERCOM USART (SERCOM4) used for sending the
 * unit test status to the computer via the EDBG CDC gateway.
 */
static void cdc_uart_init(void)
{
	struct usart_config usart_conf;

	/* Configure USART for unit test output */
	usart_get_config_defaults(&usart_conf);
	usart_conf.mux_setting = CONF_STDIO_MUX_SETTING;
	usart_conf.pinmux_pad0 = CONF_STDIO_PINMUX_PAD0;
	usart_conf.pinmux_pad1 = CONF_STDIO_PINMUX_PAD1;
	usart_conf.pinmux_pad2 = CONF_STDIO_PINMUX_PAD2;
	usart_conf.pinmux_pad3 = CONF_STDIO_PINMUX_PAD3;
	usart_conf.baudrate    = CONF_STDIO_BAUDRATE;

	stdio_serial_init(&cdc_uart_module, CONF_STDIO_USART, &usart_conf);
	usart_enable(&cdc_uart_module);
}

/**
 * \internal
 * \brief Setup function for polled mode test.
 *
 * This function sets up the GPIO pin and the external interrupt channel.
 *
 * \param test Current test case.
 */
static void setup_extint_polled_mode_test(const struct test_case *test)
{
	/* Configure the GPIO pin */
	port_get_config_defaults(&pin_conf);
	pin_conf.direction  = PORT_PIN_DIR_OUTPUT;
	pin_conf.input_pull = PORT_PIN_PULL_NONE;
	port_pin_set_config(GPIO_TEST_PIN_EXTINT, &pin_conf);
	port_pin_set_output_level(GPIO_TEST_PIN_EXTINT, true);

	/* Configure the external interrupt channel */
	extint_chan_get_config_defaults(&eic_conf);
	eic_conf.gpio_pin           = EIC_TEST_PIN;
	eic_conf.gpio_pin_mux       = EIC_TEST_PIN_MUX;
	eic_conf.gpio_pin_pull      = EXTINT_PULL_UP;
	eic_conf.detection_criteria = EXTINT_DETECT_FALLING;
	extint_chan_set_config(EIC_TEST_CHANNEL, &eic_conf);
}

/**
 * \internal
 * \brief Cleanup function for polled mode test.
 *
 * This function disables the external interrupt channel.
 *
 * \param test Current test case.
 */
static void cleanup_extint_polled_mode_test(const struct test_case *test)
{
	eic_conf.detection_criteria = EXTINT_DETECT_NONE;
	extint_chan_set_config(EIC_TEST_CHANNEL, &eic_conf);
}

/**
 * \internal
 * \brief Test for external interrupt detection by polling.
 *
 * This test changes the logic level of PB05 from high to low
 * so that the external interrupt channel detects the edge.
 *
 * Detection is tested for both rising and falling edges.
 *
 * \param test Current test case.
 */
static void run_extint_polled_mode_test(const struct test_case *test)
{
	/* Testing the falling edge detection */
	/* Generate falling edge */
	port_pin_set_output_level(GPIO_TEST_PIN_EXTINT, false);
	/* Wait for the pin level to stabilize */
	delay_ms(1);
	result = extint_chan_is_detected(EIC_TEST_CHANNEL);
	test_assert_true(test, result,
			"External interrupt falling edge detection by polling failed");
	extint_chan_clear_detected(EIC_TEST_CHANNEL);

	/* Testing the rising edge detection */
	result = false;
	eic_conf.detection_criteria = EXTINT_DETECT_RISING;
	extint_chan_set_config(EIC_TEST_CHANNEL, &eic_conf);
	/* Generate rising edge */
	port_pin_set_output_level(GPIO_TEST_PIN_EXTINT, true);
	/* Wait for the pin level to stabilize */
	delay_ms(1);
	result = extint_chan_is_detected(EIC_TEST_CHANNEL);
	test_assert_true(test, result,
			"External interrupt rising edge detection by polling failed");
	extint_chan_clear_detected(EIC_TEST_CHANNEL);
}

/**
 * \internal
 * \brief Setup function for callback mode test.
 *
 * This function sets up the GPIO pin, the external interrupt channel &
 * the callback function.
 *
 * \param test Current test case.
 */
static void setup_extint_callback_mode_test(const struct test_case *test)
{
	/* Configure the GPIO pin */
	port_get_config_defaults(&pin_conf);
	pin_conf.direction  = PORT_PIN_DIR_OUTPUT;
	pin_conf.input_pull = PORT_PIN_PULL_NONE;
	port_pin_set_config(GPIO_TEST_PIN_EXTINT, &pin_conf);
	port_pin_set_output_level(GPIO_TEST_PIN_EXTINT, true);

	/* Configure the external interrupt channel */
	extint_chan_get_config_defaults(&eic_conf);
	eic_conf.gpio_pin           = EIC_TEST_PIN;
	eic_conf.gpio_pin_mux       = EIC_TEST_PIN_MUX;
	eic_conf.gpio_pin_pull      = EXTINT_PULL_UP;
	eic_conf.detection_criteria = EXTINT_DETECT_FALLING;
	extint_chan_set_config(EIC_TEST_CHANNEL, &eic_conf);
	/* Register and enable the callback function */
	extint_register_callback(extint_user_callback,
			EIC_TEST_CHANNEL,
			EXTINT_CALLBACK_TYPE_DETECT);
	extint_chan_enable_callback(EIC_TEST_CHANNEL,
			EXTINT_CALLBACK_TYPE_DETECT);
}

/**
 * \internal
 * \brief Cleanup function for callback mode test.
 *
 * This function disables the callback & external interrupt channel.
 *
 * \param test Current test case.
 */
static void cleanup_extint_callback_mode_test(const struct test_case *test)
{
	eic_conf.detection_criteria = EXTINT_DETECT_NONE;
	extint_chan_set_config(EIC_TEST_CHANNEL, &eic_conf);
	/* Unregister and disable the callback function */
	extint_unregister_callback(extint_user_callback,
			EIC_TEST_CHANNEL,
			EXTINT_CALLBACK_TYPE_DETECT);
	extint_chan_disable_callback(EIC_TEST_CHANNEL,
			EXTINT_CALLBACK_TYPE_DETECT);
}

/**
 * \internal
 * \brief Test for external interrupt detection using callback.
 *
 * This test changes the logic level of PB05 from high to low
 * so that the external interrupt channel detects the edge
 * and calls the callback function.
 *
 * Detection is tested for both rising and falling edges.
 *
 * \param test Current test case.
 */
static void run_extint_callback_mode_test(const struct test_case *test)
{
	uint16_t timeout_cycles;

	/* Testing the falling edge detection */
	interrupt_flag = false;
	timeout_cycles = 100;
	port_pin_set_output_level(GPIO_TEST_PIN_EXTINT, false);
	do {
		timeout_cycles--;
		if (interrupt_flag) {
			break;
		}
	} while (timeout_cycles != 0);
	test_assert_true(test, timeout_cycles > 0,
			"Timeout in interrupt detection");
	test_assert_true(test, interrupt_flag,
			"External interrupt falling edge detection failed");

	/* Testing the rising edge detection */
	eic_conf.detection_criteria = EXTINT_DETECT_RISING;
	extint_chan_set_config(EIC_TEST_CHANNEL, &eic_conf);
	interrupt_flag = false;
	timeout_cycles = 100;
	port_pin_set_output_level(GPIO_TEST_PIN_EXTINT, true);
	do {
		timeout_cycles--;
		if (interrupt_flag) {
			break;
		}
	} while (timeout_cycles != 0);
	test_assert_true(test, timeout_cycles > 0,
			"Timeout in interrupt detection");
	test_assert_true(test, interrupt_flag,
			"External interrupt rising edge detection failed");
}

/**
 * \brief Run External Interrupt unit tests
 *
 * Initializes the system and serial output, then sets up the
 * External Interrupt unit test suite and runs it.
 */
int main(void)
{
	system_init();
	delay_init();
	cdc_uart_init();

	/* Define Test Cases */
	DEFINE_TEST_CASE(extint_polled_mode_test,
			setup_extint_polled_mode_test,
			run_extint_polled_mode_test,
			cleanup_extint_polled_mode_test,
			"Testing external interrupt by polling");

	DEFINE_TEST_CASE(extint_callback_mode_test,
			setup_extint_callback_mode_test,
			run_extint_callback_mode_test,
			cleanup_extint_callback_mode_test,
			"Testing external interrupt using callback");

	/* Put test case addresses in an array */
	DEFINE_TEST_ARRAY(extint_tests) = {
		&extint_polled_mode_test,
		&extint_callback_mode_test,
	};

	/* Define the test suite */
	DEFINE_TEST_SUITE(extint_test_suite, extint_tests,
			"SAM External Interrupt driver test suite");

	/* Run all tests in the suite*/
	test_suite_run(&extint_test_suite);

	while (true) {
		/* Intentionally left empty */
	}
}
