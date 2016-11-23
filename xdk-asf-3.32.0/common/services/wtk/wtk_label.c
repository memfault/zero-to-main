/**
 * \file
 *
 * \brief Label widget implementation
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
 * \ingroup wtk_label_group
 * @{
 */

/**
 * This is the label control struct. It contains references to the windows
 * composing the label, as well as non-window information required.
 *
 * \note Structure fields are only internally accessible, only pointers to
 *       structure is needed externally.
 */
struct wtk_label {
	/** Container, ultimate widget parent. */
	struct win_window *container;
	/** Copy of caption string. */
	char *caption;
	/** True if text should be right aligned. */
	bool align_right;
	/** Foreground color of the label text. */
	gfx_color_t text_color;
};

/**
 * This function returns a reference to the window that should be used when
 * managing the widget, such as move, resize, destroy and reparenting.
 *
 * \param label Label widget to manage.
 *
 * \return Window to be used for managing the label.
 */
struct win_window *wtk_label_as_child(struct wtk_label *label)
{
	Assert(label);
	return label->container;
}

/** Set new caption for label, return false if out of mem. */
bool wtk_label_change(struct wtk_label *label, const char *caption)
{
	Assert(label);
	Assert(caption);

	uint8_t new_len = strlen(caption);
	uint8_t old_len = 0;

	if (caption) {
		old_len = strlen(label->caption);
	}

	/* Only free old memory if new length is longer than the
	 * previous label.
	 */
	if (new_len > old_len) {
		/* Free old caption, if present. */
		if (caption) {
			membag_free(label->caption);
		}

		/* Allocate memory for caption string, and copy text. */
		label->caption = membag_alloc((new_len + 1) * sizeof(char));
		if (!label->caption) {
			goto outofmem_caption;
		}
	}

	wtk_copy_string(label->caption, caption);

	/* Redraw if visible. */
	win_redraw(label->container);

	return true;

outofmem_caption:
	return false;
}

/**
 * This function is the window event handler for label widgets.
 * It handles all events sent to the windows composing the widget.
 *
 * \param win Window receiving the event.
 * \param type The event type.
 * \param data Custom data, depending on event type.
 *
 * \return True if the event was recognized and accepted.
 */
static bool wtk_label_handler(struct win_window *win,
		enum win_event_type type, void const *data)
{
	/* Custom data for windows of a widget points back to the widget itself. */
	struct wtk_label *label = (struct wtk_label *)win_get_custom_data(win);

	switch (type) {
	case WIN_EVENT_DRAW:
	{
		/* There should not be other windows in this widget. */
		Assert(win == label->container);

		/* For DRAW events, the data parameter points to the
		 * clipping region.
		 */
		struct win_clip_region const *clip
			= (struct win_clip_region const *)data;
		struct win_area const *area = win_get_area(win);

		if (label->align_right == false) {
			/* Draw caption string. */
			gfx_draw_string(label->caption,
					clip->origin.x,
					clip->origin.y,
					&sysfont,
					GFX_COLOR_TRANSPARENT,
					label->text_color);
		} else {
			/* Get string size and draw the caption text right
			 * aligned. */
			gfx_coord_t width;
			gfx_coord_t height;

			gfx_get_string_bounding_box(label->caption,
					&sysfont, &width, &height);

			gfx_draw_string(label->caption,
					clip->origin.x + area->size.x -
					width, clip->origin.y, &sysfont,
					GFX_COLOR_TRANSPARENT,
					label->text_color);
		}

		/* Always accept DRAW events, as the return value is
		 * ignored anyway for that event type.
		 */
		return true;
	}

	case WIN_EVENT_DESTROY:
		/* There should not be other windows in this widget. */
		Assert(win == label->container);

		/* Memory allocated for windows will be automatically destroyed
		 * by the window system. We must destroy other allocations.
		 */
		membag_free(label->caption);
		membag_free(label);

		/* Always accept DESTROY events, as the return value is ignored
		 * anyway for that event type.
		 */
		return true;

	default:
		/* Reject unknown event types. */
		return false;
	}
}

/**
 * \brief Get minimum widget size
 *
 * This function returns the minimum size that is required for showing
 * the full widget and the caption.
 *
 * \retval size   Suggested size for the widget
 * \param caption Pointer to caption string to use for widget.
 */
void wtk_label_size_hint(struct win_point *size, const char *caption)
{
	Assert(size);
	Assert(caption);

	gfx_get_string_bounding_box(caption, &sysfont, &size->x, &size->y);
}

/**
 * This function creates a new label widget. It allocates required memory
 * and intializes necessary windows to create the widget. If there is not enough
 * memory, the function returns NULL.
 *
 * To destroy the widget and all its contents, and free its memory, call
 * win_destroy() on the label's child reference, given by
 * wtk_label_as_child(),
 * like this: "win_destroy(wtk_label_as_child(myStaticTextPtr));".
 * Usually it will be destroyed automatically when it's parent is destroyed.
 *
 * \param parent Parent window, possibly wtk_frame_as_parent(myFramePtr).
 * \param area Area of the internal contents.
 * \param caption Pointer to caption string. Will be copied into widget.
 * \param text_color Foreground color of the text when drawn.
 * \param background Background of the label.
 * \param align_right True if caption is to be aligned to the right,
 *                    false otherwise.
 * \return Pointer to label, or NULL if failed.
 */
struct wtk_label *wtk_label_create(struct win_window *parent,
		struct win_area const *area, char const *caption,
		gfx_color_t text_color, struct gfx_bitmap *background,
		bool align_right)
{
	struct win_attributes attr;
	struct wtk_label *label;

	Assert(area);
	Assert(caption);
	Assert(parent);

	/* Allocate memory for label control data. */
	label = membag_alloc(sizeof(struct wtk_label));
	if (!label) {
		goto outofmem_label;
	}

	label->text_color = text_color;
	label->align_right = align_right;

	/* Allocate memory for caption string, and copy text. */
	label->caption = membag_alloc((strlen(caption) + 1) * sizeof(char));
	if (!label->caption) {
		goto outofmem_caption;
	}

	wtk_copy_string(label->caption, caption);
	
	/* Handling information. */
	attr.event_handler = wtk_label_handler;
	attr.custom = label;

	/* Prepare container frame. */
	attr.area = *area;
	
	/* Set background for label. */
	if (background) {
		attr.background = background;
		attr.behavior = 0;
	} else {
		attr.background = NULL;
		attr.behavior = WIN_BEHAVIOR_REDRAW_PARENT;
	}
	
	label->container = win_create(parent, &attr);
	if (!label->container) {
		goto outofmem_container;
	}

	return label;

outofmem_container:
	membag_free(label->caption);

outofmem_caption:
	membag_free(label);

outofmem_label:
	return NULL;
}

/** @} */
