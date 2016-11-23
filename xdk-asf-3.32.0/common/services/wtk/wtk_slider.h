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
#ifndef WTK_SLIDER_H
#define WTK_SLIDER_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup wtk_group
 *
 * \defgroup wtk_slider_group Slider widget
 * @{
 */

/**
 * \defgroup wtk_slider_options_group Slider widget options
 * These options can be ORed together to specify the behaviour of a
 * slider widget when creating it with \ref wtk_slider_create
 * @{
 */

/**
 * \name Slider widget command event configuration options.
 * For use with the option parameter of \ref wtk_slider_create
 * @{
 */

/** Never issue command events. (Default option) */
#define WTK_SLIDER_CMD_NONE             (0 << 0)
/** Issue command event whenever slider value is updated. */
#define WTK_SLIDER_CMD_MOVE             (1 << 0)
/** Issue command event whenever slider is released. */
#define WTK_SLIDER_CMD_RELEASE          (1 << 1)

/** @} */

/**
 * \name Slider widget orientation configuration options.
 * For use with the option parameter of \ref wtk_slider_create
 * @{
 */

/** Slider is horizontally oriented. (Default option) */
#define WTK_SLIDER_HORIZONTAL           (0 << 0)
/** Slider is vertically oriented. */
#define WTK_SLIDER_VERTICAL             (1 << 2)

/** @} */

/**
 * \name Slider widget invert configuration options.
 * For use with the option parameter of \ref wtk_slider_create
 * @{
 */
 
/** Slider value is inverted. */
#define WTK_SLIDER_INVERT               (1 << 3)

/** @} */

/** @} */

struct wtk_slider;

struct wtk_slider *wtk_slider_create(struct win_window *parent,
		struct win_area const *area, uint8_t maximum, uint8_t value,
		uint8_t option, win_command_t command_data);
struct win_window *wtk_slider_as_child(struct wtk_slider *slider);
win_command_t wtk_slider_get_command(struct wtk_slider *slider);
bool wtk_slider_is_moving(struct wtk_slider const *slider);
uint8_t wtk_slider_get_value(struct wtk_slider const *slider);
bool wtk_slider_set_value(struct wtk_slider *slider, uint8_t value);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
