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
#ifndef WTK_PROGRESS_BAR_H
#define WTK_PROGRESS_BAR_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup wtk_group
 *
 * \defgroup wtk_progress_bar_group Progress bar widget
 * @{
 */

/**
 * \defgroup wtk_progress_bar_options_group Progress bar widget options
 * These options can be ORed together to specify the behaviour of a
 * progress bar widget when creating it with \ref wtk_progress_bar_create
 * @{
 */

/**
 * \name Progress bar orientation configuration options.
 * For use with the option parameter of \ref wtk_progress_bar_create
 * @{
 */

/** Progress bar is horizontally oriented. */
#define WTK_PROGRESS_BAR_HORIZONTAL    (0 << 0)
/** Progress bar is vertically oriented. */
#define WTK_PROGRESS_BAR_VERTICAL      (1 << 0)

/** @} */

/**
 * \name Progress bar widget invert configuration options.
 * For use with the option parameter of \ref wtk_progress_bar_create
 * @{
 */

/** Progress bar is inverted. */
#define WTK_PROGRESS_BAR_INVERT        (1 << 1)

/** @} */

/** @} */

struct wtk_progress_bar;

struct wtk_progress_bar *wtk_progress_bar_create(struct win_window *parent,
		struct win_area const *area, uint8_t maximum, uint8_t value,
		gfx_color_t fill_color, gfx_color_t background_color,
		uint8_t option);
struct win_window *wtk_progress_bar_as_child(struct wtk_progress_bar *bar);
uint8_t wtk_progress_bar_get_value(struct wtk_progress_bar *bar);
bool wtk_progress_bar_set_value(struct wtk_progress_bar *bar, uint8_t value);
void wtk_progress_bar_set_colors(struct wtk_progress_bar *bar,
		gfx_color_t color1, gfx_color_t color2);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
