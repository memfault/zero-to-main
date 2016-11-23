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
#ifndef WTK_H
#define WTK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <win.h>
#include <sysfont.h>
#include <wtk_basic_frame.h>
#include <wtk_frame.h>
#include <wtk_button.h>
#include <wtk_check_box.h>
#include <wtk_radio_button.h>
#include <wtk_slider.h>
#include <wtk_label.h>
#include <wtk_progress_bar.h>
#include <wtk_icon.h>
#include <wtk_plot.h>
#include "conf_wtk.h"

/**
 * \ingroup gfx_group
 * \defgroup wtk_group Widget toolkit
 *
 * The Widget toolkit implements many common widgets for use on a graphical
 * display using the functionality of \ref win_group "Window system"
 * and \ref gfx_group "Graphics library".
 *
 * \image html WTK.jpg
 *
 * The following widgets are implemented:
 * - \ref wtk_basic_frame_group
 * - \ref wtk_button_group
 * - \ref wtk_check_box_group
 * - \ref wtk_frame_group
 * - \ref wtk_icon_group
 * - \ref wtk_plot_group
 * - \ref wtk_progress_bar_group
 * - \ref wtk_radio_button_group
 * - \ref wtk_slider_group
 * - \ref wtk_label_group
 *
 * \section wtk_dependencies_sec Dependencies
 * This component driver depends on the following modules:
 * - \ref win_group "Window system"
 * - \ref gfx_group "Graphics library"
 *
 * @{
 */

uint8_t wtk_rescale_value(uint8_t value, uint8_t from_scale, uint8_t to_scale);
void wtk_copy_string(char *dest, char const *source);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* WTK_H */
