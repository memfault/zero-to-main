/**
 * \file
 *
 * \brief Example application for GFX Monochrome System Font (sysfont)
 *
 * Copyright (c) 2011-2015 Atmel Corporation. All rights reserved.
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
/**
 * \page asfdoc_common2_gfx_mono_sysfont_example GFX Mono Font Example
 *
 * \section asfdoc_common2_sysfont_example_intro Introduction
 * This is an example application for the \ref asfdoc_common2_gfx_mono_font. It will print a
 * string, with line break, on the screen and scroll it.
 *
 * \section files Main Files
 * - \ref example_sysfont.c
 * - \ref conf_board.h
 * - \ref conf_clocks.h
 * - \ref conf_ssd1306.h
 * - \ref conf_sysfont.h
 *
 * \section asfdoc_common2_sysfont_example_device_info Device Info
 * This example has been tested with the following setup:
 * - SAM D20 Xplained Pro
 * - SAM D21 Xplained Pro
 * - SAM R21 Xplained Pro
 * - SAM D11 Xplained Pro
 * - SAM L21 Xplained Pro
 * - SAM L22 Xplained Pro
 *
 * \section asfdoc_common2_sysfont_example_description Description of the example application
 * The example application will upon power up display several text strings on the
 * display; "PASSION...".
 *
 * \section asfdoc_common2_sysfont_example_dependencies Dependencies
 * Relevant module dependencies for this application are:
 * - \ref asfdoc_common2_gfx_mono_font
 *
 * \section asfdoc_common2_sysfont_example_compinfo Compilation info
 * This software was written for the GNU GCC and IAR. Other compilers
 * may or may not work.
 *
 * \section asfdoc_common2_sysfont_example_contactinfo Contact Information
 * For further information, visit <a href="http://www.atmel.com/">Atmel</a>.\n
 */

#define LINES 8

char string[LINES][24] = {
	{"          PASSION   \r\n"},
	{"    INTEGRITY       \r\n"},
	{"        TEAMWORK    \r\n"},
	{"   ACHIEVEMENT      \r\n"},
	{" ACCOUNTABILITY     \r\n"},
	{"                    \r\n"},
	{"                    \r\n"},
	{"                    \r\n"},
};

/**
 * \brief Main entry of example application
 */
int main(void)
{
	/**
	 * Starts off by initializing the system clock before configuring the
	 * board and the monochrome graphical system.
	 */
	system_init();
	gfx_mono_init();

	uint8_t start_line_address = 0;
	uint8_t scroll = 0;
	uint32_t line = 0;

	/**
	 * After initialization the example will write the Star Wars opening scrolling text.
	 * Use the system font sysfont. Afterwards the text will be scrolled forever.
	 */

	while (true) {
		if (++start_line_address%8 == 0) {
			scroll = 1;
			gfx_mono_draw_string(string[line%LINES],0, ((line)%8)*8, &sysfont);
			line++;
		} else if (start_line_address % 7 != 0) {
			delay_ms(100);
		}

		if ( scroll != 0 ) {
			ssd1306_set_display_start_line_address(start_line_address-8);
		} else {
			gfx_mono_draw_string(string[line%LINES],0, ((line)%8)*8, &sysfont);
			line++;
		}
	}
}
