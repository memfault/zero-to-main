/**
 * \file
 *
 * \brief ASF Sensor API Numeric Precision
 *
 * This module defines numeric precision and the real-number representation
 * used in the Atmel Software Framework common sensor service.
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

#ifndef _MATH_PRECISION_H_
#define _MATH_PRECISION_H_

#include "fixed.h"

/**
 * \brief Scalar Value Format and Precision
 *
 * These types define a real number format and precision.  C/C++ source code
 * can be compiled with math libraries in single-precision floating point,
 * double-precision floating point, or fixed-point versions.
 *
 * The type \ref float_t always specifies a C/C++ floating-point type and is a
 * C99 standard type.  The \ref scalar type may be specified as a floating-point
 * or fixed-point type, where the available fixed-point types are \ref fixed_t
 * (C/C++) and type math::fixed (C++ only).
 *
 * Note that whenever the C++ math libraries - math::vector, math::matrix, &c.
 * - are built, \ref scalar must be an alias for float_t or math::fixed and
 * never \ref fixed_t.
 */

#if defined(__GNUC__) && !defined(FLT_EVAL_METHOD)
	typedef float float_t;          /**< clib (C99) floating-point format */
#endif

#if defined (MATH_FIXED_POINT)
# ifdef __cplusplus
	typedef math::fixed scalar;     /**< Fixed-point (C++) scalar type */
# else
	typedef fixed_t scalar;         /**< Fixed-point (C/C++) scalar type */
# endif
#else
	typedef float_t scalar;         /**< Floating-point scalar type */
#endif

typedef scalar scalar_t;

/** \brief scalar 3-dimensional vector */
typedef struct {
	scalar_t    x;
	scalar_t    y;
	scalar_t    z;
} vector3_t;

/** \brief Calculate a vector3_t dot-product */
static inline scalar_t vector3_dot_product(vector3_t const *v,
	vector3_t const *w)
{
	return ((v->x * w->x) + (v->y * w->y) + (v->z * w->z));
}

/** \brief Calculate a vector3_t magnitude */
static inline scalar_t vector3_magnitude(vector3_t const *v)
{
	return sqrt(vector3_dot_product(v,v));
}

/** \brief Scale a vector3_t value (scalar multiplication) */
static inline void vector3_scale(scalar_t s, vector3_t *v)
{
	v->x *= s; v->y *= s; v->z *= s;
}

#endif
