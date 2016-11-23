/*****************************************************************************
 *
 * \file
 *
 * \brief Example of usage of the TWI Master Mode Basic Services.
 *
 * Copyright (c) 2009-2015 Atmel Corporation. All rights reserved.
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
 ******************************************************************************/

/*! \mainpage
 * \section intro Introduction
 * This is the documentation for the data structures, functions, variables,
 * defines, enums, and typedefs for the TWI master mode basic services example.
 *
 * \section files Main Files
 * - twi_master_example.c: example application.
 * - conf_board.h: board configuration
 * - conf_twim.h: TWI master configuration used in this example
 * - twi_master.h: Part Specific TWI Master Mode Implementation
 *
 * \section twiapiinfo services/basic/twi API
 * The TWI API can be found \ref twi_master.h "here".
 *
 * \section deviceinfo Device Info
 * All AVR or SAM devices can be used. When use the example in Xplained Pro
 * Kits, we need connect an IO1 Xplained Pro board to the proper EXT port. For
 * information of the IO1Xplained Pro board, visit
 * <A href="http://www.atmel.com/tools/ATIO1-XPRO.aspx">IO1 web link.</A>
 * This example has been tested with the following setup:
 *   - access to the TWI signals.
 *
 * \section exampledescription Description of the example
 * The given example uses one kit as a TWI master:
 *    - the TWI master performs a write access to the TWI slave,
 *    - the TWI master performs a read access of what it just wrote to the TWI slave,
 *    - the read data are compared with the originally written data.
 *
 * LED0 gives the result of the test:
 *  If FAILED: LED0 is off.
 *  If PASS: LED0 is on at the end of the test.
 *
 * \section compinfo Compilation Info
 * This software was written for the GNU GCC and IAR for AVR or SAM.
 * Other compilers may or may not work.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <A href="http://www.atmel.com/">Atmel</A>.\n
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include "board.h"
#include "sysclk.h"
#include "twi_master.h"
#include "led.h"

#include "conf_board.h"

#if SAM
#include "conf_twi_master.h"
#include <string.h>
#endif

//! \name Local Configuration Constants
//@{
#ifndef EEPROM_BUS_ADDR
#define EEPROM_BUS_ADDR       0x50        //!< TWI slave bus address
#endif
#define EEPROM_MEM_ADDR       0xaa        //!< TWI slave memory address
#define TWI_SPEED             50000       //!< TWI data transfer rate

//@}


//! \name Slave EEPROM memory Test Pattern Constants
//@{

#define PATTERN_TEST_LENGTH     sizeof(test_pattern)
const uint8_t test_pattern[] = {
   0x55,
   0xA5,
   0x5A,
   0x77,
   0x99};

//@}


/*! \brief TWI Master Example Main
 *
 * The master example begins by initializing required board resources.  The
 * system clock, basic GPIO pin mapping, and interrupt vectors are established.
 *
 * A memory location on a TWI slave is written with a fixed test pattern which
 * is then read back into a separate buffer.  As a basic sanity check, the
 * original write-buffer values are compared with values read from the slave to
 * a separate buffer.  An LED on the development board is illuminated when there
 * is a match between the written and read data.
 *
 * \return Nothing.
 */
int main(void)
{
  /* Initialize the common clock service, board-specific initialization, and
   * interrupt vector support prior to using the TWI master interfaces.
   */
  sysclk_init();

  board_init();

#if (!SAM && !MEGA)
  irq_initialize_vectors();
#endif // SAM

  // TWI master initialization options.

  twi_master_options_t opt;
#if SAM
  memset((void *)&opt, 0, sizeof(opt));
#endif
  opt.speed = TWI_SPEED;
#if (!SAM4L)
  opt.chip  = EEPROM_BUS_ADDR;
#endif

  // Initialize the TWI master driver.

  twi_master_setup(TWI_EXAMPLE, &opt);

  // Initialize the platform LED's.
#if defined(sam4cek)
  LED_Off(LED0);
#elif defined(sam4cmpdb) || defined(sam4cmsdb)
  LED_Off(LED4);
#else
  LED_Off(LED0_GPIO);
#endif

  twi_package_t packet = {
/**
 * The SAM3X_EK, SAM3X Arduino board and SAM4C_EK use two bytes length internal
 * address EEPROM.
 */
#if defined(sam3xek) || defined(arduinoduex) || defined(sam4cek) || defined(sam4cmpdb) || defined(sam4cmsdb)
    .addr[0]      = EEPROM_MEM_ADDR >> 8, // TWI slave memory address data MSB
    .addr[1]      = EEPROM_MEM_ADDR,      // TWI slave memory address data LSB
    .addr_length  = sizeof (uint16_t),    // TWI slave memory address data size
#else
    .addr[0]      = EEPROM_MEM_ADDR,      // TWI slave memory address data MSB
    .addr_length  = sizeof (uint8_t),     // TWI slave memory address data size
#endif
    .chip         = EEPROM_BUS_ADDR,      // TWI slave bus address
    .buffer       = (void *)test_pattern, // transfer data source buffer
    .length       = PATTERN_TEST_LENGTH   // transfer data size (bytes)
  };

  // Perform a multi-byte write access then check the result.
  while (twi_master_write(TWI_EXAMPLE, &packet) != TWI_SUCCESS);

  uint8_t data_received[PATTERN_TEST_LENGTH] = {0};

  twi_package_t packet_received = {
#if defined(sam3xek) || defined(arduinoduex) || defined(sam4cek) || defined(sam4cmpdb) || defined(sam4cmsdb)
    .addr[0]      = EEPROM_MEM_ADDR >> 8, // TWI slave memory address data MSB
    .addr[1]      = EEPROM_MEM_ADDR,      // TWI slave memory address data LSB
    .addr_length  = sizeof (uint16_t),    // TWI slave memory address data size
#else
    .addr[0]      = EEPROM_MEM_ADDR,      // TWI slave memory address data MSB
    .addr_length  = sizeof (uint8_t),     // TWI slave memory address data size
#endif
    .chip         = EEPROM_BUS_ADDR,      // TWI slave bus address
    .buffer       = data_received,        // transfer data destination buffer
    .length       = PATTERN_TEST_LENGTH   // transfer data size (bytes)
  };

  // Perform a multi-byte read access then check the result.
  while (twi_master_read(TWI_EXAMPLE, &packet_received) != TWI_SUCCESS);

  // Verify that the received data matches the sent data.
  for (uint32_t i = 0 ; i < PATTERN_TEST_LENGTH; ++i) {

    if (data_received[i] != test_pattern[i]) {
      // Error
      while(1);
    }
  }

  //test PASS
#if SAM4C
  LED_On(LED0);
#elif defined(sam4cmpdb) || defined(sam4cmsdb)
  LED_On(LED4);
#else
  LED_On(LED0_GPIO);
#endif

  while(1);
}
