/**
 * \file
 *
 * \brief Utilities that convert pressure to altitude
 *
 * This is a collection of high-level utility functions that will convert a
 * given pressure to an altitude within the Earth's atmosphere using the
 * International Standard Atmosphere (ISA) model.  The ISA is an ideal model
 * of how pressure, temperature, density, and viscosity of the atmosphere
 * change with altitude.  The basic pressure_altitude_xxx() routines implement
 * ISA equations in a fairly straightforward fashion without additional
 * constraints.  For example, the temperature decrease with altitude (lapse
 * rate) is approximately -6.5 degrees Celsius per 1000 meters for standard
 * atmosphere, but the actual rate varies from day to day and throughout the
 * day.
 *
 * Copyright (c) 2011-2015 Atmel Corporation. All rights reserved.
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

#ifndef _SENSOR_PRESSURE_ALTITUDE_H_
#define _SENSOR_PRESSURE_ALTITUDE_H_

#include "physics.h"

/*! \brief Specify the (corrected) pressure-altitude sea level pressure.
 *
 * This routine will calculate a bias to correct the ISA standard pressure
 * at sea level (1 atm. = 101 325 Pa) for local variations in barometric
 * pressure at mean sea level (MSL).
 *
 * \param   P           The current local pressure (pascals) at sea level.
 * \return  Nothing.
 */
extern void   pressure_sea_level(scalar P = CONST_STANDARD_ATM);

/*! \brief Specify a pressure-altitude layer
 *
 * The routine sets the pressure_altitude() function to use a specified
 * "layer" in domain [0, 6].  By default layer 0 is assumed.  Calling
 * this routine without arguments will set the pressure_altitude() to
 * calculate barometric altitude assuming a pressure domain within ISA
 * layer zero (P < 22 632 pascals).
 *
 * \param   index   The atmospheric layer index, zero by default.
 *
 * \return  bool    True if a valid layer index is specified.
 */
extern bool   pressure_isa_layer(int index = 0);

/*! \brief Get an ISA pressure altitude
 *
 * Given atmospheric pressure "P" in pascals, this routine returns the
 * associated barometric altitude ("pressure altitude") using
 * International Standard Atmosphere (ISA) pressure model coefficients
 * and equations.
 *
 * \param   P       The current atmospheric pressure in pascals.
 *
 * \return  scalar  The altitude in meters.
 */
extern scalar pressure_altitude(scalar P);

#endif
