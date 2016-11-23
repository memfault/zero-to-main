/**
 * \file
 *
 * \brief The math::plane class models a plane in 3-dimensional space.
 *
 * This module implements a class modelling a plane in 3-dimensional space.
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


#ifndef _plane_h_
#define _plane_h_

#include "vector.h"

namespace math {

/** \brief 3-dimensional plane class declaration */
class plane {

public:

	typedef math::vector3d vector;

	/** \name Class construction and destruction */
	/** @{ */
	explicit plane (scalar a = 1, scalar b = 0, scalar c = 0, scalar d = 0)
		: n (vector (a, b, c)), d (d) {}

	plane (const vector & normal, scalar d = 0)
		: n (normal), d (d) {}

	plane (const vector & p1, const vector & p2, const vector & p3) {
		vector const v1 = p2 - p1;
		vector const v2 = p3 - p1;

		n = v1.cross (v2);
		d = -(n.dot (p1));
	}
	/** @} */

	/** \name Class public methods */
	/** @{ */
	const vector & normal () const { return n; }
	const scalar & shift () const  { return d; }

	const scalar distanceToPlane (const vector & p) const
		{ return std::fabs (n.dot (p) + d) / n.mag (); }

	const bool pointInPlane (const vector & p) const
		{ return (0 == distanceToPlane (p)); }
	/** @} */

private:

	vector n;     /**< A plane normal vector */
	scalar d;     /**< A plane-shift constant */
};

}

#endif
