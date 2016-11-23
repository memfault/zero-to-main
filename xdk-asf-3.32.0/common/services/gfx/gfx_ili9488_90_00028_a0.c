/**
 * \file
 *
 * \brief Graphic service settings for the 90-00028-A0 panel using the ILI9488
 * display controller
 *
 * This files includes the correct header files for the graphics service
 *
 * Copyright (c) 2015 Atmel Corporation. All rights reserved.
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

/**
 * \ingroup gfx_ili9488_90_00028_a0
 * @{
 */

#include "gfx.h"
#include "gfx_ili9488_90_00028_a0.h"
#include "ili9488.h"

gfx_coord_t gfx_height, gfx_width;
gfx_coord_t gfx_min_x, gfx_min_y;
gfx_coord_t gfx_max_x, gfx_max_y;

void gfx_ili9488_set_orientation(uint8_t flags)
{
	ili9488_set_orientation(flags);

	/* Switch width and height if XY is switched. */
	if ((flags & GFX_SWITCH_XY) != 0x00) {
		gfx_width = ILI9488_SWITCH_XY_WIDTH;
		gfx_height = ILI9488_SWITCH_XY_HEIGHT;
	} else {
		gfx_width = ILI9488_LCD_WIDTH;
		gfx_height = ILI9488_LCD_HEIGHT;
	}

#ifdef CONF_GFX_USE_CLIPPING
	/* Reset clipping region. */
	gfx_set_clipping(0, 0, gfx_width - 1, gfx_height - 1);
#endif
}

gfx_color_t gfx_ili9488_color(uint8_t r, uint8_t g, uint8_t b)
{
	return GFX_COLOR(r, g, b);
}

gfx_color_t gfx_ili9488_get_pixel(gfx_coord_t x, gfx_coord_t y)
{
	gfx_color_t color;

#ifdef CONF_GFX_USE_CLIPPING
	if ((x < gfx_min_x) || (x > gfx_max_x) ||
			(y < gfx_min_y) || (y > gfx_max_y)) {
		return GFX_COLOR_INVALID;
	}
#endif

	/* Set up draw area and read the three bytes of pixel data. */
	gfx_set_limits(x, y, x, y);
	color = ili9488_read_gram();

	return color;
}

void gfx_ili9488_draw_pixel(gfx_coord_t x, gfx_coord_t y, gfx_color_t color)
{
#ifdef CONF_GFX_USE_CLIPPING
	if ((x < gfx_min_x) || (x > gfx_max_x) ||
			(y < gfx_min_y) || (y > gfx_max_y)) {
		return;
	}
#endif

	/* Set up draw area and write the two bytes of pixel data. */
	gfx_set_limits(x, y, x, y);
	ili9488_write_gram(color);
}

void gfx_ili9488_draw_line_pixel(gfx_coord_t x, gfx_coord_t y,
		gfx_color_t color)
{
#ifdef CONF_GFX_USE_CLIPPING
	if ((x < gfx_min_x) || (x > gfx_max_x) ||
			(y < gfx_min_y) || (y > gfx_max_y)) {
		return;
	}
#endif

	/* Set up top left corner of area and write the two bytes of */
	/* pixel data.  Bottom left corner is already set to max_x/y. */
	gfx_set_top_left_limit(x, y);
	ili9488_write_gram(color);
}

void gfx_ili9488_init(void)
{
	struct ili9488_opt_t g_ili9488_display_opt;

	/* initialize globals */
	gfx_width = ILI9488_LCD_WIDTH;
	gfx_height = ILI9488_LCD_HEIGHT;

	/* Initialize display parameter */
	g_ili9488_display_opt.ul_width= ILI9488_LCD_WIDTH;
	g_ili9488_display_opt.ul_height = ILI9488_LCD_HEIGHT;
	g_ili9488_display_opt.foreground_color= COLOR_BLACK;
	g_ili9488_display_opt.background_color = COLOR_WHITE;

	ili9488_init(&g_ili9488_display_opt);
	ili9488_display_on();

	/* Set clipping area to whole screen initially */
	gfx_set_clipping(0, 0, gfx_width, gfx_height);

	gfx_draw_filled_rect(0, 0, gfx_width, gfx_height,
			GFX_COLOR_BLACK);
}

/**
 *@}
 */
