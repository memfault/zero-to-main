/**
 * \file
 *
 * \brief SAM SPI Flash Driver Quick Start for SAMB11
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

/**
 * \page asfdoc_samb_spi_flash_basic_use_case Quick Start Guide for SPI-Flash - Basic
 *
 * In this use case, the SPI-Flash module is configured for:
 *  \li Spi flash initial.
 *
 * This use case sets up the SPI-Flash to erase, write and read flash data via
 * defualt spi-flash gpio configration.
 *
 * \section asfdoc_samb_spi_flash_basic_use_case_setup Setup
 *
 * \subsection asfdoc_samb_spi_flash_basic_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_samb_spi_flash_basic_use_case_setup_code Code
 * The following must be added to the user application source file, outside
 * any functions:
 * Read and write buffer to operate spi-flash.
 * \snippet qs_spi_flash_basic.c buffer
 * A function for configuring the GPIO.
 * \snippet qs_spi_flash_basic.c configure_gpio
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_spi_flash_basic.c system_init
 * \snippet qs_spi_flash_basic.c run_config_gpio
 *
 * \snippet qs_spi_flash_basic.c setup_init
 *
 * \subsection asfdoc_samb_spi_flash_basic_use_case_setup_flow Workflow
 * -# Initialize write buffer with default values.
 *    \snippet qs_spi_flash_basic.c setup_1
 * -# Initialize spi-flash and enable.
 *    \snippet qs_spi_flash_basic.c setup_2
 *
 * \section asfdoc_samb_spi_flash_basic_use_case_use_main Use Case
 *
 * \subsection asfdoc_samb_spi_flash_basic_use_case_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_spi_flash_basic.c main_use_case
 *
 * \subsection asfdoc_samb_spi_flash_basic_use_case_flow Workflow
 * -# Erase spi-flash designated area. If failure, LED will flash quickly. If
 *    successful, it will continue.
 *    \snippet qs_spi_flash_basic.c main_1
 * -# Read spi-flash designated area.
 *    \snippet qs_spi_flash_basic.c main_2
 * -# Compare read data. If there is one data which isn't 0xFFFFFFFF, LED will
 *    flash quickly. If matched, it will continue.
 *    \snippet qs_spi_flash_basic.c main_3
 * -# Write spi-flash designated area.
 *    \snippet qs_spi_flash_basic.c main_4
 * -# Read spi-flash designated area.
 *    \snippet qs_spi_flash_basic.c main_5
 * -# Compare write in and read out data. If the data isn't matched, LED will
 *    flash quickly. If matched, it will continue.
 *    \snippet qs_spi_flash_basic.c main_6
 * -# Infinite loop. If all the operation is right, LED will flash slowly.
 *    \snippet qs_spi_flash_basic.c inf_loop
 */
