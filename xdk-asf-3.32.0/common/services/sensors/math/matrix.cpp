/**
 * \file
 *
 * \brief This module defines a collection of matrix classes.
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

#include "matrix.h"

namespace {

/** \name Aliases to matrix elements _m(i,j); row 'i', column 'j'. */
/** @{ */
#define _m11  (C[0][0])
#define _m12  (C[1][0])
#define _m13  (C[2][0])
#define _m14  (C[3][0])

#define _m21  (C[0][1])
#define _m22  (C[1][1])
#define _m23  (C[2][1])
#define _m24  (C[3][1])

#define _m31  (C[0][2])
#define _m32  (C[1][2])
#define _m33  (C[2][2])
#define _m34  (C[3][2])

#define _m41  (C[0][3])
#define _m42  (C[1][3])
#define _m43  (C[2][3])
#define _m44  (C[3][3])
/** @} */

const scalar zero_matrix[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


/**
 * \brief calculate the inverse of a matrix
 *
 * Calculate the caller's inverse matrix.  If 'A' and 'B' are square
 * matrices of the same size such that 'AB = BA = I' (where 'I' is the
 * identity matrix), then 'A' is 'invertible' and 'B' is an 'inverse' of
 * 'A'.  If no such matrix 'B' exists, then 'A' is 'singular'.
 *
 * \internal
 * Calculating the matrix inverse using its adjoint is problematic.  The
 * determinant may be a number so close to zero that it is virtually zero
 * in the machine representation.  The range of det(A) might be checked
 * using some radius epsilon about zero such that values within this
 * interval can be classified as zero.  One could then test the sanity of
 * det(A) in a manner similar to the following:
 *
 * \code
 *     if (fabs (det(A)) < EPSILON)
 *         return SINGULAR_MATRIX;  // the matrix has no inverse
 * \endcode
 *
 * \retval
 * The inverse of the invoking matrix (if nonsingular), else the zero matrix
 * if not invertible (singular).
 */
template <typename matrix_t>
inline const matrix_t inverse (const matrix_t & m)
{
	scalar const detm (m.determinant ());

	if (0 != detm) {
		return ((1.0 / detm) * (m.adjoint ()));
	}

	return matrix_t (zero_matrix);
}

}


namespace math {

/**
 * \brief calculate the adjoint of a 3x3 matrix
 *
 * Calculate the caller's adjoint matrix.  Given a square matrix 'A', where
 * 'C[i,j]' is the cofactor of 'a[i,j]', then the matrix:
 *
 *  \f[ \left[ \begin{array}{cccc}
 *    C_{11} & C_{12} & ... & C_{1n}\\
 *    C_{21} & C_{22} & ... & C_{2n}\\
 *    : & : & & :\\
 *    C_{n1} & C_{n2} & ... & C_{nn}
 *    \end{array} \right] \f]
 *
 * is the 'matrix of cofactors from  A'.  The transpose of this matrix
 * is the 'adjoint of A'.
 *
 * \retval math::matrix3d The adjoint of the invoking object.
 */
const matrix3d matrix3d::adjoint () const
{
	scalar const adj [] = {
		det (_m22, _m23, _m32, _m33),
		-det (_m12, _m13, _m32, _m33),
		 det (_m12, _m13, _m22, _m23),

		-det (_m21, _m23, _m31, _m33),
		 det (_m11, _m13, _m31, _m33),
		-det (_m11, _m13, _m21, _m23),

		 det (_m21, _m22, _m31, _m32),
		-det (_m11, _m12, _m31, _m32),
		 det (_m11, _m12, _m21, _m22)
	};

	return matrix3d (adj);
}

/**
 * \brief calculate the inverse of a 3x3 matrix
 *
 * Calculate the caller's inverse matrix.  If 'A' and 'B' are square
 * matrices of the same size such that 'AB = BA = I' (where 'I' is the
 * identity matrix), then 'A' is 'invertible' and 'B' is an 'inverse' of
 * 'A'.  If no such matrix 'B' exists, then 'A' is 'singular'.
 *
 * \retval math::matrix3d
 * The inverse of the invoking matrix (if nonsingular), else the zero matrix
 * if not invertible (singular).
 */
const matrix3d matrix3d::inverse () const
{
	return ::inverse<matrix3d> (*this);
}

/**
 * \brief calculate the adjoint of a 4x4 matrix
 *
 * Calculate the caller's adjoint matrix.  Given a square matrix 'A', where
 * 'C[i,j]' is the cofactor of 'a[i,j]', then the matrix:
 *
 *  \f[ \left[ \begin{array}{cccc}
 *    C_{11} & C_{12} & ... & C_{1n}\\
 *    C_{21} & C_{22} & ... & C_{2n}\\
 *    : & : & & :\\
 *    C_{n1} & C_{n2} & ... & C_{nn}
 *    \end{array} \right] \f]
 *
 * is the 'matrix of cofactors from  A'.  The transpose of this matrix
 * is the 'adjoint of A'.
 *
 * \retval math::matrix4d The adjoint of the invoking object.
 */
const matrix4d matrix4d::adjoint () const
{
	scalar const adj [] = {
		 det (_m22, _m23, _m24, _m32, _m33, _m34, _m42, _m43, _m44),
	   - det (_m12, _m13, _m14, _m32, _m33, _m34, _m42, _m43, _m44),
		 det (_m12, _m13, _m14, _m22, _m23, _m24, _m42, _m43, _m44),
	   - det (_m12, _m13, _m14, _m22, _m23, _m24, _m32, _m33, _m34),

	   - det (_m21, _m23, _m24, _m31, _m33, _m34, _m41, _m43, _m44),
		 det (_m11, _m13, _m14, _m31, _m33, _m34, _m41, _m43, _m44),
	   - det (_m11, _m13, _m14, _m21, _m23, _m24, _m41, _m43, _m44),
		 det (_m11, _m13, _m14, _m21, _m23, _m24, _m31, _m33, _m34),

		 det (_m21, _m22, _m24, _m31, _m32, _m34, _m41, _m42, _m44),
	   - det (_m11, _m12, _m14, _m31, _m32, _m34, _m41, _m42, _m44),
		 det (_m11, _m12, _m14, _m21, _m22, _m24, _m41, _m42, _m44),
	   - det (_m11, _m12, _m14, _m21, _m22, _m24, _m31, _m32, _m34),

	   - det (_m21, _m22, _m23, _m31, _m32, _m33, _m41, _m42, _m43),
		 det (_m11, _m12, _m13, _m31, _m32, _m33, _m41, _m42, _m43),
	   - det (_m11, _m12, _m13, _m21, _m22, _m23, _m41, _m42, _m43),
		 det (_m11, _m12, _m13, _m21, _m22, _m23, _m31, _m32, _m33)
	};

	return matrix4d(adj);
}

/**
 * \brief calculate the determinant of a 4x4 matrix
 *
 * Calculate the caller's determinant via minors with cofactor expansion
 * along the first row.  The determinant of a square matrix 'A' can be
 * computed by multiplying the entries in any row or column by their
 * cofactors and adding the resulting products.  For each 1 <= i <= n
 * and 1 <= j <= n, cofactor expansion on the jth column is:
 *
 * \f[
 *     det(A) = a_{1j} C_{1j} + a_{2j} C_{2j} + ... + a_{nj} C_{nj}
 * \f]
 *
 * and cofactor expansion on the ith row is:
 *
 * \f[
 *     det(A) = a_{i1} C_{i1} + a_{i2} C_{i2} + ... + a_{in} C_{in}
 * \f]
 *
 * \retval scalar The real-valued determinant of the invoking object.
 */
const scalar matrix4d::determinant () const
{
	// minor entries of A

	scalar const M_11
		(det (_m22, _m23, _m24, _m32, _m33, _m34, _m42, _m43, _m44));

	scalar const M_12
		(det (_m21, _m23, _m24, _m31, _m33, _m34, _m41, _m43, _m44));

	scalar const M_13
		(det (_m21, _m22, _m24, _m31, _m32, _m34, _m41, _m42, _m44));

	scalar const M_14
		(det (_m21, _m22, _m23, _m31, _m32, _m33, _m41, _m42, _m43));

	// return cofactor expansion along the first row of 'A'

	return ((_m11 * M_11) - (_m12 * M_12) + (_m13 * M_13) - (_m14 * M_14));
}

/**
 * \brief calculate the inverse of a 4x4 matrix
 *
 * Calculate the caller's inverse matrix.  If 'A' and 'B' are square
 * matrices of the same size such that 'AB = BA = I' (where 'I' is the
 * identity matrix), then 'A' is 'invertible' and 'B' is an 'inverse' of
 * 'A'.  If no such matrix 'B' exists, then 'A' is 'singular'.
 *
 * \retval math::matrix4d
 * The inverse of the invoking matrix (if nonsingular), else the zero matrix
 * if not invertible (singular).
 */
const matrix4d matrix4d::inverse () const
{
	return ::inverse<matrix4d> (*this);
}

}
