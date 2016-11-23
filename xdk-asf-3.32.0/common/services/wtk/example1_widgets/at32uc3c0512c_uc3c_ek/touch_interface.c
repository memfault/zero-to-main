/**
 * \file
 *
 * \brief Touch screen interface functions for the UC3C-EK
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
#include <asf.h>
#include "touch_interface.h"

/** Flag to indicate that a new touch event is ready to be processed */
static bool touch_event_ready = false;

/**
 * \brief Handler for the touchscreen touch event callback
 *
 * Callback function from the touchscreen driver when a new touch event has
 * been generated.
 *
 * \param event  Event generated from the touchscreen driver
 */
static void touch_event_handler(rtouch_event_t const *event)
{
	touch_event_ready = true;
}

/**
 * \brief Convert touch events from the touchscreen into window pointer events
 *
 * Reads touch events in from the touchscreen and converts them into a
 * Window Manager pointer event, for enqueuing into the window event queue.
 *
 * \return Boolean \c true if a touch event was read, false if no touch event
 *         or a corrupt touch event was received
 */
bool touch_interface_read(struct win_pointer_event *win_touch_event)
{
	rtouch_event_t touch_event;
	
	if (touch_event_ready == false) {
		return false;
	}	

	irqflags_t irq_flags = cpu_irq_save();
	rtouch_get_event(&touch_event);
	touch_event_ready = false;
	cpu_irq_restore(irq_flags);

	switch (touch_event.type)
	{
		case RTOUCH_NO_EVENT:
			return false;
		case RTOUCH_PRESS:
			win_touch_event->type = WIN_POINTER_PRESS;
			break;
		case RTOUCH_RELEASE:
			win_touch_event->type = WIN_POINTER_RELEASE;
			break;
		case RTOUCH_MOVE:
			win_touch_event->type = WIN_POINTER_MOVE;
			break;			
	}

	/* Indicate the touch event is a non-relative movement with the virtual
	 * touch button pressed
	 */
	win_touch_event->is_relative = false;
	win_touch_event->buttons = WIN_TOUCH_BUTTON;

	/* Translate the touch X and Y position into a screen coordinate */
	win_touch_event->pos.x = touch_event.panelX;
	win_touch_event->pos.y = touch_event.panelY;

	return true;
}

/**
 * \brief Determine if the display is currently being touched
 *
 * Checks if the user is currently touching the display, with debouncing.
 *
 * \return Boolean \c true if the display is being touched, \c false otherwise.
 */
static bool touch_interface_is_touched(void)
{
	uint8_t steady_samples = 0;
	bool touch_state = false;
	
	/* Debounce touches to the display */
	while (steady_samples < 5) {
		steady_samples++;
		
		/* Sample is different to previous state, touch is bouncing */
		if (touch_state != rtouch_is_touched()) {
			touch_state	= rtouch_is_touched();
			steady_samples = 0;
		}

		delay_ms(10);
	}
	
	return touch_state;
}

/**
 * \brief Waits until a full display touch event has completed
 *
 * Reads touch events in from the touchscreen and waits for a full touch and
 * release event before continuing.
 */
static void touch_interface_wait_touch(void)
{
	while (touch_interface_is_touched() == false) {
		/* Wait for debounced touch of the display */
	};

	while (touch_interface_is_touched() == true) {
		/* Wait for end of debounced touch of the display */
	};
}

/**
 * \brief Prompts and stores a single calibration point on the display
 *
 * Prompts the user for a single calibration point on the display at the
 * nominated coordinates, and saves the resulting raw touch point.
 *
 * \param point  Calibration point structure to fill with a touch coordinate
 */
static void touch_interface_get_calibration_point(
		rtouch_calibration_point_t* point)
{
	rtouch_event_t event;

	gfx_draw_circle(
		point->panelX, point->panelY,
		4, GFX_COLOR_BLUE, GFX_WHOLE);
	
	touch_interface_wait_touch();

	rtouch_get_event(&event);
	point->rawX = event.rawX;
	point->rawY = event.rawY;
	
	gfx_draw_filled_circle(
		point->panelX, point->panelY, 4, GFX_COLOR_BLUE, GFX_WHOLE);
}

/**
 * \brief Calibrates the touchscreen on the display
 *
 * Runs a full calibration with user prompts of the display.
 */
static void touch_interface_calibrate(void)
{
	static rtouch_calibration_matrix_t matrix;
	rtouch_calibration_points_t points;

	/* Create a three-point calibration coordinate list */
	points.point1.panelX = 30;
	points.point1.panelY = 30;
	points.point2.panelX = 170;
	points.point2.panelY = 220;
	points.point3.panelX = 300;
	points.point3.panelY = 120;

	/* Show calibration prompt to the user */
	gfx_draw_string_aligned(
			"Screen calibration\n"
			"Touch circles to continue",
			gfx_get_width() / 2,
			gfx_get_height() / 2,
			&sysfont, GFX_COLOR_TRANSPARENT, GFX_COLOR_RED,
			TEXT_POS_CENTER, TEXT_ALIGN_CENTER);

	/* Get calibraton touch points from the user */
	touch_interface_get_calibration_point(&points.point1);
	touch_interface_get_calibration_point(&points.point2);
	touch_interface_get_calibration_point(&points.point3);

	/* Compute and set the touchscreen calibration matrix */
	rtouch_compute_calibration_matrix(&points, &matrix);
	rtouch_set_calibration_matrix(&matrix);	
}

/**
 * \brief Initializes the touchscreen, ready to detect user input
 *
 * Performs and initialization and calibration of the touchscreen, so that it
 * is ready for use.
 */
void touch_interface_init(void)
{
	rtouch_init();
	rtouch_enable();
	touch_interface_calibrate();
	rtouch_set_event_handler(touch_event_handler);
}

