/**
 * \file
 *
 * \brief ASF Sensor API fixed point data type
 *
 * This header defines a fixed-point data type and associated arithmetic
 * operations.  The \ref fixed type approximates fractional quantities using
 * a pair of integers, designated as the mantissa and exponent, such that
 * \f$ n2^{-q} \f$ given integer exponent \a q and integer mantissa \a n
 *
 * Because exponent \a q is a power of 2 it can also be understood as the
 * number of binary digits into \a n where the binary point is placed.  And
 * since mantissa \a n is a factor of a power of two, it is only necessary
 * to store the mantissa and the number of fractional bits.  This is also
 * known as \a Q number format.
 *
 * The mantissa is stored and operated on as a signed two's complement
 * number, where \a Q specifies the number of fractional bits  and, by
 * implication, the location of a virtual fixed decimal point within the
 * mantissa.
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

#include "fixed.h"

namespace math {

/** \brief Round up a math::fixed object value.
 *
 * Returns the smallest integral value that is not less than the invoking
 * object of type math::fixed.
 *
 * \retval  math::fixed     The smallest integral value not less than *this.
 */
fixed fixed::ceil () const
{
	return (val % (1L << Q)) ? (floor() + 1) : (*this);
}

/** \brief Round down a math::fixed object value.
 *
 * Returns the largest integral value that is not greater than the
 * invoking object of type math::fixed.
 *
 * \retval  math::fixed     The largest integral value not greater than *this.
 */
fixed fixed::floor () const
{
	fixed result (*this);

	const int32_t remainder (val % (1L << Q));

	if (remainder) {
		result.val -= remainder;

		if (val < 0) {
			result -= 1;
		}
	}

	return result;
}

/** \brief Compute the square root of a math::fixed object value.
 *
 * Returns the square root of the invoking object of type <fixed>.
 * If the argument is negative, a domain error occurs, setting the
 * global errno to the value EDOM.
 *
 * \retval  math::fixed     The square root of *this.
 */
fixed fixed::sqrt () const
{
	fixed root (*this);

	root.val = fixed_sqrt(val, Q);

	return root;
}

}
