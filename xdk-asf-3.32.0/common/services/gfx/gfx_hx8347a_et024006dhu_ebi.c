/**
 * \file
 *
 * \brief Graphic service settings for the ET024006DHU panel using the HX8347A display controller over EBI
 *
 * This files includes the correct header files for the grapics service
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

/**
 * \ingroup gfx_hx8347a_et024006dhu_ebi
 * @{
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include "gfx.h"
#include "gfx_hx8347a_et024006dhu_ebi.h"
#include "et024006dhu.h"
#include "sysclk.h"
#include "ioport.h"

gfx_coord_t gfx_height, gfx_width;
gfx_coord_t gfx_min_x, gfx_min_y;
gfx_coord_t gfx_max_x, gfx_max_y;

void gfx_et024006dhu_set_orientation(uint8_t flags)
{
	/* Not implemented for this controller */
}

gfx_color_t gfx_et024006dhu_color(uint8_t r, uint8_t g, uint8_t b)
{
	return GFX_COLOR(r, g, b);
}

gfx_color_t gfx_et024006dhu_get_pixel(gfx_coord_t x, gfx_coord_t y)
{
#ifdef CONF_GFX_USE_CLIPPING
	if ((x < gfx_min_x) || (x > gfx_max_x) ||
			(y < gfx_min_y) || (y > gfx_max_y)) {
		return GFX_COLOR_INVALID;
	}
#endif

	return et024006_GetPixel(x, y);
}

void gfx_et024006dhu_draw_pixel(gfx_coord_t x, gfx_coord_t y, gfx_color_t color)
{
#ifdef CONF_GFX_USE_CLIPPING
	if ((x < gfx_min_x) || (x > gfx_max_x) ||
			(y < gfx_min_y) || (y > gfx_max_y)) {
		return;
	}
#endif

	et024006_DrawPixel(x, y, color);
}

void gfx_et024006dhu_draw_line_pixel(gfx_coord_t x, gfx_coord_t y,
		gfx_color_t color)
{
#ifdef CONF_GFX_USE_CLIPPING
	if ((x < gfx_min_x) || (x > gfx_max_x) ||
			(y < gfx_min_y) || (y > gfx_max_y)) {
		return;
	}
#endif

	et024006_DrawQuickPixel(x, y, color);
}

void gfx_et024006dhu_init(void)
{
	/* Initialize globals */
	gfx_width  = GFX_PANELWIDTH;
	gfx_height = GFX_PANELHEIGHT;

	et024006_Init(sysclk_get_cpu_hz(), sysclk_get_pbb_hz());
	
#if defined(ET024006DHU_BL_PIN)
	/* Turn on backlight if one has been configured */
	ioport_enable_pin(ET024006DHU_BL_PIN);
	ioport_set_pin_dir(ET024006DHU_BL_PIN, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(ET024006DHU_BL_PIN, true);
#endif

	/* Set clipping area to whole screen initially */
	gfx_set_clipping(0, 0, GFX_PANELWIDTH, GFX_PANELHEIGHT);

	gfx_draw_filled_rect(0, 0, GFX_PANELWIDTH, GFX_PANELHEIGHT,
			GFX_COLOR(0xFF, 0xFF, 0xFF));
}

/**
 *@}
 */
