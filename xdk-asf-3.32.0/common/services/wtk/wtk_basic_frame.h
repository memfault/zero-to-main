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
#ifndef WTK_BASIC_FRAME_H
#define WTK_BASIC_FRAME_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup wtk_group
 *
 * \defgroup wtk_basic_frame_group Basic frame widget
 *
 * Basic frame widget provides a frame with only a background color.
 * @{
 */

struct wtk_basic_frame;

/**
 * \brief Basic frame command event handler callback
 *
 * The basic frame command event handler callback is used to handle
 * command events from widgets inside the basic frame. Command events
 * are typically queued when the user has given some input to a widget.
 * Examples are pushing a button widget or checking a check box widget.
 *
 * \note The maximum stack usage can be affected by the implementation of the
 *       event handler. The handler will be called from within the event
 *       handling of the \ref win_group "window system". This event handling
 *       is done recursively to traverse all child windows connected to the
 *       \ref win_root "window root".
 *
 * \param basic_frame  Pointer to the basic frame which contains the widget that
 *                     generated the event.
 * \param command_data The command data that was set for the specific widget.
 *                     This is typically an ID for the widget or a pointer to
 *                     data needed by the widget. This is widget-specific.
 * \return             True if the basic frame and it's children should be
 *                     destroyed, false otherwise.
 */
typedef bool (*wtk_basic_frame_command_handler_t)(
	struct wtk_basic_frame *basic_frame, win_command_t command_data);

/**
 * \brief Basic frame draw event handler callback
 *
 * The basic frame draw event handler callback can be used to draw simple
 * graphical display elements without the need for implementing a custom
 * widget.
 * The handler is called to redraw the full or a subregion of basic frame
 * after the background for the widget has been drawn.
 *
 * If \ref CONFIG_GFX_USE_CLIPPING has been set the clipping region is set
 * before the handler is called.
 *
 * \note The maximum stack usage can be affected by the implementation of the
 *       event handler. The handler will be called from within the event
 *       handling of the \ref win_group "window system". This event handling
 *       is done recursively to traverse all child windows connected to the
 *       \ref win_root "window root".
 *
 * \param win  Pointer to the window of the basic frame widget to be drawn.
 * \param clip Region of the basic frame to be drawn in global display
 *             coordinates.
 */
typedef void (*wtk_basic_frame_draw_handler_t)(
	struct win_window *win, struct win_clip_region const *clip);

struct wtk_basic_frame *wtk_basic_frame_create(struct win_window *parent,
		const struct win_area *area, struct gfx_bitmap *background,
		wtk_basic_frame_draw_handler_t draw_handler,
		wtk_basic_frame_command_handler_t frame_handler,
		void *custom_data);
struct win_window *wtk_basic_frame_as_child(
		struct wtk_basic_frame *basic_frame);
void *wtk_basic_frame_get_custom_data(
		const struct wtk_basic_frame *basic_frame);

/** @} */

#ifdef __cplusplus
}
#endif

#endif
