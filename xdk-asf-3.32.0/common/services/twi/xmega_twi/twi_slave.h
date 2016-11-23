/*****************************************************************************
 *
 * \file
 *
 * \brief TWI Slave driver for AVR XMEGA.
 *
 * This file defines a useful set of functions for the TWI interface on AVR Xmega
 * devices.
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
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */


#ifndef _TWI_SLAVE_H_
#define _TWI_SLAVE_H_

#include "compiler.h"
#include "sysclk.h"
#include "status_codes.h"
#include "twis.h"

typedef TWI_t *twi_slave_t;
typedef twi_options_t twi_slave_options_t;

static inline void twi_slave_setup(twi_slave_t twi,
		twi_slave_options_t *opt, TWI_Slave_t *twiSlave,
		void (*processDataFunction) (void), uint8_t address,
		TWI_SLAVE_INTLVL_t intLevel)
{
	opt->speed_reg = TWI_BAUD(sysclk_get_cpu_hz(),opt->speed);

	sysclk_enable_peripheral_clock(twi);

	TWI_SlaveInitializeDriver(twiSlave, twi, processDataFunction);
	TWI_SlaveInitializeModule(twiSlave, address, intLevel);
}

#endif  // _TWI_SLAVE_H_


