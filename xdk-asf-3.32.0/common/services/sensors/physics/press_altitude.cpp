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
 * Copyright (c) 2011-2012 Atmel Corporation. All rights reserved.
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

#include "press_altitude.h"

namespace {

/** ISA_LAYER - atmospheric layer parameters */
typedef struct {                
	scalar height_bottom;    /**< Height above sea level @ bottom of layer */
	scalar static_press;     /**< Static pressure at layer base */
	scalar standard_temp;    /**< Standard temperature at layer base */
	scalar lapse_rate;       /**< Layer lapse rate -dT/dz (T temp, z height) */
} ISA_LAYER;

const int layer_min (0);
const int layer_max (6);

const ISA_LAYER layer_table [] =
	{
	// International Standard Atmosphere, Mean Sea Level Conditions
	//
	// height above    static pressure    standard          temperature lapse
	// sea level (m)   (pascals)          temperature (K)   rate (K/m)
	//------------------------------------------------------------------------
	//
	{  0,              101325,            288.15,          -0.0065  },
	{  11000,          22632.1,           216.65,           0.0     },
	{  20000,          5474.89,           216.65,           0.001   },
	{  32000,          868.019,           228.65,           0.0028  },
	{  47000,          110.906,           270.65,           0.0     },
	{  51000,          66.9389,           270.65,          -0.0028  },
	{  71000,          3.95642,           214.65,          -0.002   }
	};

/** Barometric calculations use the layer table entry selected by this index. */
int layer = 0;

/** \name Layer table access convenience macros */
/** @{ */
#define Pb      (layer_table [(layer)].static_press)
#define Tb      (layer_table [(layer)].standard_temp)
#define Lb      (layer_table [(layer)].lapse_rate)
#define Hb      (layer_table [(layer)].height_bottom)
/** @} */

/** \name ISA pressure altitude precalculated constants */
/** @{ */
#define R_g0    (-1 * CONST_REAL_GAS / CONST_STANDARD_GRAVITY)

scalar RL_g0    (R_g0 * Lb);
scalar RT_g0    (R_g0 * Tb);

scalar P_bias   (0 /* current SL pressure(Pa) - 1 atm */);
/** @} */

}


/** \brief Specify the (corrected) pressure-altitude sea level pressure.
 *
 * This routine will calculate a bias to correct the ISA standard pressure
 * at sea level (1 atm. = 101 325 Pa) for local variations in barometric
 * pressure at mean sea level (MSL).
 *
 * \param   P           The current local pressure (pascals) at sea level.
 * \return  Nothing.
 */
void pressure_sea_level(scalar P)
{
	P_bias = P - Pb;
}

/** \brief Specify a pressure-altitude layer
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
bool pressure_isa_layer(int index)
{
	if ((layer_min <= index) && (index <= layer_max)) {

		layer = index;

		RL_g0 = (R_g0 * Lb);
		RT_g0 = (R_g0 * Tb);

		return true;
	}

	return false;
}

/** \brief Get an ISA pressure altitude
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
scalar pressure_altitude(scalar P)
{
	const scalar del ((P - P_bias) / Pb);  // pressure ratio

	if (Lb) {
		return (Hb + ((Tb / Lb) * (pow(del, RL_g0) - 1)));
	} else {
		return (Hb + (RT_g0 * log(del)));
	}
}
