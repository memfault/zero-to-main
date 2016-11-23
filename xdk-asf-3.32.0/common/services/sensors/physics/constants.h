/**
 * \file
 *
 * \brief ASF Sensor API Physics Constants
 *
 * This module defines commonly used physical constants and conversions in
 * standard units.
 *
 * \todo
 *
 * Investigate replacing numerical library, including constants in this
 * header, with the GNU Scientific Library (GSL) and select pieces of the
 * Boost C++ math and numerics libraries for feature rich application layer
 * code.
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

#ifndef _SENSOR_CONSTANTS_H_
#define _SENSOR_CONSTANTS_H_

#ifdef __cplusplus
extern "C" {
#endif

/** \name Physical Constants */
/** @{ */

/** \brief molar mass of dry air \f$\frac{kg}{mol}\f$ */
#define CONST_AIR_MOLAR_MASS    (0.0289644)

/** \brief Boltzmann constant \f$\frac{m^{2} kg}{s^{2} K}\f$ */
#define CONST_BOLTZMANN         (1.2806503e-23)

/** \brief standard atmospheric pressure \f$\frac{N}{m^{2}}\f$ */
#define CONST_STANDARD_ATM      (1.01325e5)

/** \brief dry atmospheric air gas constant \f$\frac{m^{2}}{s^{2} K}\f$ */
#define CONST_REAL_GAS          (287.04)

/** \brief standard gravity \f$\frac{m}{s^{2}}\f$ */
#define CONST_STANDARD_GRAVITY  (9.80665)

/** \brief ideal gas constant \f$\frac{J}{K mol}\f$ */
#define CONST_UNIVERSAL_GAS     (8.31447215)

/** \brief universal gravitational constant \f$\frac{m^{3}}{s^{2} kg}\f$ */
#define CONST_UNIVERSAL_GRAVITY (6.673e-11)

/** @} */

/** \name General Purpose Conversion Constants */
/** @{ */

#ifndef M_PI
#   define M_PI                     (3.14159265358979323846264338327)
#endif

#define RAD_TO_DEG                  (180 / M_PI) /**< radians to degrees */
#define DEG_TO_RAD                  (M_PI / 180) /**< degrees to radians */

#define GAUSS_TO_MICRO_TESLA        (100)        /**< \f$1 Gauss = 100 \mu T\f$ */

#define KELVIN_TO_CELSIUS(K)        ((K)-273.15)
#define CELSIUS_TO_KELVIN(C)        ((C)+273.15)

#define FAHRENHEIT_TO_CELSIUS(F)    (((5 * ((F)-32)) / 9) + 0.5)
#define CELSIUS_TO_FAHRENHEIT(C)    ((((9 * (C)) / 5) + 32) + 0.5)

/** @} */

#ifdef __cplusplus
}
#endif

#endif
