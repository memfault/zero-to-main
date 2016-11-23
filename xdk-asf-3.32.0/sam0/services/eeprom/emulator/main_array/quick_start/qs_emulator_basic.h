/**
 * \file
 *
 * \brief SAM EEPROM Emulator Service Quick Start
 *
 * Copyright (C) 2012-2015 Atmel Corporation. All rights reserved.
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
 * \page asfdoc_sam0_eeprom_basic_use_case Quick Start Guide for the Emulated EEPROM Module - Basic Use Case
 *
 * In this use case, the EEPROM emulator module is configured and a sample page
 * of data read and written. The first byte of the first EEPROM page is toggled,
 * and a LED is turned on or off to reflect the new state. Each time the device
 * is reset, the LED should toggle to a different state to indicate correct
 * non-volatile storage and retrieval.
 *
 * \section asfdoc_sam0_eeprom_basic_use_case_prereq Prerequisites
 * The device's fuses must be configured to reserve a sufficient number of
 * FLASH memory rows for use by the EEPROM emulator service, before the service
 * can be used. That is: \c NVMCTRL_FUSES_EEPROM_SIZE has to be set to less
 * than 0x5 in the fuse setting, then there will be more than 8 pages size for
 * EEPROM. Atmel Studio can be used to set this fuse(Tools->Device Programming).
 *
 * \section asfdoc_sam0_eeprom_basic_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_eeprom_basic_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_sam0_eeprom_basic_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_emulator_basic.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_emulator_basic.c setup_init
 *
 * \subsection asfdoc_sam0_eeprom_basic_use_case_setup_flow Workflow
 * -# Attempt to initialize the EEPROM emulator service, storing the error code
 *    from the initialization function into a temporary variable.
 *    \snippet qs_emulator_basic.c init_eeprom_service
 * -# Check if the emulator failed to initialize due to the device fuses not
 *    being configured to reserve enough of the main FLASH memory rows for
 *    emulated EEPROM usage - abort if the fuses are mis-configured.
 *    \snippet qs_emulator_basic.c check_init_ok
 * -# Check if the emulator service failed to initialize for any other reason;
 *    if so assume the emulator physical memory is unformatted or corrupt and
 *    erase/re-try initialization.
 *    \snippet qs_emulator_basic.c check_re-init
 *
 * Config BOD to give an early warning, so that we could prevent data loss.
 * \snippet qs_emulator_basic.c setup_bod
 *
 * \section asfdoc_sam0_eeprom_basic_use_case_main Use Case
 *
 * \subsection asfdoc_sam0_eeprom_basic_use_case_main_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_emulator_basic.c main
 *
 * \subsection asfdoc_sam0_eeprom_basic_use_case_main_flow Workflow
 * -# Create a buffer to hold a single emulated EEPROM page of memory, and read
 *    out logical EEPROM page zero into it.
 *    \snippet qs_emulator_basic.c read_page
 * -# Toggle the first byte of the read page.
 *    \snippet qs_emulator_basic.c toggle_first_byte
 * -# Output the toggled LED state onto the board LED.
 *    \snippet qs_emulator_basic.c set_led
 * -# Write the modified page back to logical EEPROM page zero, flushing the
 *    internal emulator write cache afterwards to ensure it is immediately
 *    written to physical non-volatile memory.
 *    \snippet qs_emulator_basic.c write_page
 * -# Modify data and write back to logical EEPROM page zero.
 *    The data is not committed and should call \c eeprom_emulator_commit_page_buffer
 *    to ensure that any outstanding cache data is fully written to prevent data loss
 *    when detecting a BOD early warning.
 *    \snippet qs_emulator_basic.c write_page_not_commit
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
