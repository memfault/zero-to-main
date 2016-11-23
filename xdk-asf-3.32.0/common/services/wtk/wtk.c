/**
 * \file
 *
 * \brief Graphical Widget toolkit
 *
 * Copyright (c) 2014-2015 Atmel Corporation. All rights reserved.
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

#include <stdint.h>
#include <stdlib.h>
#include <membag.h>
#include <string.h>
#include <wtk.h>

/**
 * \weakgroup wtk_group
 * @{
 */

/**
 * \brief Rescale 8-bit value.
 * \internal
 *
 * This function is used by, e.g., the slider widget for computing the slider
 * knob position from a given value and vice versa. It returns a value with the
 * same data width as the input, meaning \a value cannot exceed \a from_scale,
 * or overflows will occur.\par
 *
 * The formula is: \code new_value = (value / from_scale) * to_scale \endcode
 *
 * \param value Value to rescale.
 * \param from_scale Maximum of old scale for value.
 * \param to_scale Maximum of scale for new value.
 *
 * \return Rescaled 8-bit value.
 */
uint8_t wtk_rescale_value(uint8_t value, uint8_t from_scale, uint8_t to_scale)
{
	uint16_t new_value;

	Assert(to_scale > 0);
	Assert(from_scale > 0);
	Assert(value <= from_scale);

	new_value = value;
	new_value *= to_scale;
	new_value /= from_scale;

	return new_value;
}

/**
 * This function copies the string contents, including the zero terminator,
 * from source to destination. The caller is responsible for providing
 * memory for the destination string, either on the stack, static, or
 * dynamically allocated.
 *
 * \param dest Destination string.
 * \param source Source string, zero terminated.
 */
void wtk_copy_string(char *dest, char const *source)
{
	Assert(dest);
	Assert(source);

	/* Copy characters, including zero-terminator. */
	while (*source != '\0') {
		*dest = *source;
		++dest;
		++source;
	}

	/* Copy the terminating zero. */
	*dest = *source;
}

/** @} */
