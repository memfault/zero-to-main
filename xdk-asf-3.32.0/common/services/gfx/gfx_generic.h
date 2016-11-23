/**
 * \file
 *
 * \brief Generic graphic primitive routines
 *
 * This files includes the correct header files for the graphics service
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
#ifndef GFX_GENERIC_H_INCLUDED
#define GFX_GENERIC_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \ingroup gfx_group
 * \defgroup gfx_generic Generic Implementation of Graphics Primitives
 *
 * This is a library of generic implementations of various graphics
 * primitives. They are meant to simplify the implementation of the
 * low-level graphics driver by providing generic implementations of
 * primitives that aren't directly supported by the hardware.
 *
 * @{
 */

/**
 * \brief Valid bitmap types
 */
enum gfx_bitmap_type {
	/*! Solid color bitmap */
	GFX_BITMAP_SOLID,
	/*! Bitmap stored in SRAM */
	GFX_BITMAP_RAM,
	/*! Bitmap stored in progmem */
	GFX_BITMAP_PROGMEM,
	/*! Draw bitmap through extended interface */
	GFX_BITMAP_EXT,
};

/**
 * \brief Storage structure for bitmap pixel data and metadata
 */
struct gfx_bitmap {
	/*! Width of bitmap */
	gfx_coord_t width;
	/*! Height of bitmap */
	gfx_coord_t height;
	/*! Bitmap type */
	enum gfx_bitmap_type type;
	union {
		/*! Color for solid color bitmaps */
		gfx_color_t color;
		/*! Pointer to pixels for bitmap stored in SRAM */
		gfx_color_t *pixmap;
		/*! Pointer to pixels for bitmap stored in progmem */
		gfx_color_t PROGMEM_PTR_T progmem;
		/*! External interface custom data */
		void* custom;
	} data;
};

/**
 * \brief Function pointer type for external bitmap draw handlers.
 *
 * \param bmp Pointer to the bitmap.
 * \param map_x Start pos x.
 * \param map_y Start pos y.
 * \param x Width length.
 * \param y Height length.
 */
typedef void (*gfx_ext_draw_handler_t)(
	struct gfx_bitmap const *bmp,
	gfx_coord_t map_x, gfx_coord_t map_y,
	gfx_coord_t x, gfx_coord_t y);

/*! Generic implementation of gfx_draw_line(). */
void gfx_generic_draw_line(gfx_coord_t x1, gfx_coord_t y1,
		gfx_coord_t x2, gfx_coord_t y2,
		gfx_color_t color);

/*! Generic implementation of gfx_draw_filled_rect(). */
void gfx_generic_draw_filled_rect(gfx_coord_t x, gfx_coord_t y,
		gfx_coord_t width, gfx_coord_t height,
		gfx_color_t color);

/*! Generic implementation of gfx_draw_circle(). */
void gfx_generic_draw_circle(gfx_coord_t x, gfx_coord_t y,
		gfx_coord_t radius, gfx_color_t color,
		uint8_t octant_mask);

/*! Generic implementation of gfx_draw_filled_circle(). */
void gfx_generic_draw_filled_circle(gfx_coord_t x, gfx_coord_t y,
		gfx_coord_t radius, gfx_color_t color,
		uint8_t quadrant_mask);

/*! Generic implementation of gfx_get_pixmap(). */
void gfx_generic_get_pixmap(gfx_color_t *pixmap, gfx_coord_t map_width,
		gfx_coord_t map_x, gfx_coord_t map_y,
		gfx_coord_t x, gfx_coord_t y,
		gfx_coord_t width, gfx_coord_t height);

/*! Generic implementation of gfx_put_pixmap(). */
void gfx_generic_put_pixmap(const gfx_color_t *pixmap, gfx_coord_t map_width,
		gfx_coord_t map_x, gfx_coord_t map_y,
		gfx_coord_t x, gfx_coord_t y,
		gfx_coord_t width, gfx_coord_t height);

/*! Generic implementation of gfx_put_bitmap(). */
void gfx_generic_put_bitmap(const struct gfx_bitmap *bmp,
		gfx_coord_t map_x, gfx_coord_t map_y,
		gfx_coord_t x, gfx_coord_t y,
		gfx_coord_t width, gfx_coord_t height);

/*! Generic implementation of gfx_draw_bitmap_tiled(). */
void gfx_generic_draw_bitmap_tiled(const struct gfx_bitmap *bmp, gfx_coord_t x1,
		gfx_coord_t y1, gfx_coord_t x2, gfx_coord_t y2,
		gfx_coord_t tile_origin_x, gfx_coord_t tile_origin_y);

/*! Generic implementation of setting external bitmap draw interface. */
void gfx_generic_set_ext_handler(gfx_ext_draw_handler_t gfx_ext_draw);

/*! Generic implementation of gfx_draw_horizontal_line(). */
__always_inline static void gfx_generic_draw_horizontal_line(
		gfx_coord_t x, gfx_coord_t y, gfx_coord_t length,
		gfx_color_t color)
{
	gfx_draw_filled_rect(x, y, length, 1, color);
}

/*! Generic implementation of gfx_draw_vertical_line(). */
__always_inline static void gfx_generic_draw_vertical_line(gfx_coord_t x,
		gfx_coord_t y, gfx_coord_t length, gfx_color_t color)
{
	gfx_draw_filled_rect(x, y, 1, length, color);
}

/*! Generic implementation of gfx_draw_rect(). */
__always_inline static void gfx_generic_draw_rect(gfx_coord_t x,
		gfx_coord_t y, gfx_coord_t width, gfx_coord_t height,
		gfx_color_t color)
{
	gfx_draw_horizontal_line(x, y, width, color);
	gfx_draw_horizontal_line(x, y + height - 1, width, color);
	gfx_draw_vertical_line(x, y, height, color);
	gfx_draw_vertical_line(x + width - 1, y, height, color);
}

/*! Generic implementation of gfx_draw_bitmap(). */
__always_inline static void gfx_generic_draw_bitmap(
		const struct gfx_bitmap *bmp, gfx_coord_t x,
		gfx_coord_t y)
{
	gfx_put_bitmap(bmp, 0, 0, x, y, bmp->width, bmp->height);
}

/*! Generic implementation of gfx_sync(). */
__always_inline static void gfx_generic_sync(
		void)
{
	
}

/*! @} */

#ifdef __cplusplus
}
#endif

#endif /* GFX_GENERIC_H_INCLUDED */
