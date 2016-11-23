/**
 * \file
 *
 * \brief Configurations for the graphical window system
 *
 * Copyright (C) 2014-2015 Atmel Corporation. All rights reserved.
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
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#ifndef CONF_WIN_H
#define CONF_WIN_H

/**
 * \weakgroup win_group
 * @{
 */

#include <stdint.h>

/** Datatype holding button state mask for pointer input devices. */
typedef uint8_t win_button_mask_t;

/** Datatype holding the key "scan" code for keyboard input devices. */
typedef uint8_t win_keycode_t;

/** Datatype holding sizes for the event queue. */
typedef uint8_t win_event_queue_size_t;

/**
 * \brief Custom data, can be used as a data pointer or data depending on
 * the application.
 */
typedef void *win_command_t;

/** Data type holding timestamp for events */
typedef uint16_t clock_jiffy_t;

/** Background color of root window, ie. the desktop. */
#define WIN_ROOT_COLOR GFX_COLOR(0, 0, 0)

/** Screen background color used when root window is hidden. */
#define WIN_SCREEN_COLOR GFX_COLOR(0, 0, 0)

/** Size of event queue, holding both input and command events. */
#define WIN_EVENT_QUEUE_SIZE 10

/** Button mask for touch screens. */
#define WIN_TOUCH_BUTTON (1 << 0)

/** @} */

#endif /* CONF_WIN_H */
