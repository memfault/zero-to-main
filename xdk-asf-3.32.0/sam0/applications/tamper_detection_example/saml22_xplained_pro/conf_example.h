/**
 * \file
 *
 * \brief SAML22 RTC Tamper Detection Example
 *
 * Copyright (C) 2015 Atmel Corporation. All rights reserved.
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

#ifndef EXAMPLE_H
#define EXAMPLE_H

/* set the value to zero*/
#define SET_TO_ZERO                    0

/*Set the baud rate*/
#define SET_BAUD_RATE                  38400

/* define slcd blink speed*/
#define SLCD_BLINK_SPEED               2500

/* define the tamper input*/
#define TAMPER_INPUT_PIN               4

/* turn off lcd backlight*/
#define LCD_BACKLIGHT_OFF              LED_On(LED_0_PIN)

/* turn on lcd backlight*/
#define LCD_BACKLIGHT_ON               LED_Off(LED_0_PIN)

/*maximum characters displayed on LCD */
#define XPRO_LCD_MAX_CHAR                 5
/*the alpha-numerical character starts with segment 4*/
#define XPRO_LCD_TXT_SEG_INDEX_S          4

/*frame count overflow value*/
#define FRAME_COUNT_OVERFLOW           0x2

/*Set LCD contrast*/
#define SLCD_CONTRAST                  0xf

/* error message on SLCD during wake mode*/
#define ERROR_STRING                  "TAMPR"

/*segment for PM display*/
#define SEGMENT_FOR_PM                 3

/*segment for AM display*/
#define SEGMENT_FOR_AM                 2

/*segment for colon display*/
#define SEGMENT_FOR_COLON              1

/*common terminal for colon display*/
#define COM_FOR_COLON                  3

/*common terminal for colon display*/
#define COM_FOR_TIME                   0

/*segment line number*/
#define SEGMENT_LINE_NUMBER            3

/*segment length for a character*/
#define SEGMENT_LENGTH                 4

/*macros for different user input*/
#define DISABLE_TAMPER                'a'
#define ENABLE_TAMPER_IN_WAKE_MODE    'b'
#define ENABLE_TAMPER_IN_CAPTURE_MODE 'c'
#define READ_TAMPER_HISTORY           'd'
#define ERASE_TAMPER_HISTORY          'e'

/* Define current time*/
#define YEAR                           2012
#define MONTH                          12
#define DAY                            31 
#define HOUR                           11
#define MINUTE                         59
#define SECOND                         50
#define TIME_PM                        false     

/* Define the length of the structure time*/
#define LENGTH_OF_TIME_STRUCT          7         

/* Define the length of the memory index*/
#define LENGTH_OF_MEMORY_INDEX         2  

#define EEPROM_EMPTY_CHAR              0xFFFF

/*maximum entries stored on RWW EEPROM section*/
#define MAXIMUM_ENTRIES_STORED         128

/*alarm time in seconds after tamper detection*/
#define SET_ALARM_TIME                 4

/*enum for defining mode*/
enum 
{		
	SET_TO_DISABLE = 0,
	SET_TO_WAKE  = 1,
	SET_TO_CAPTURE = 2
}mode, previous_mode;
	

/*Function prototypes for SLCD  */
static void configure_usart(void);
static void display_menu(void);
void lcd_init(void);
static void config_slcd(void);
status_code_genare_t xpro_lcd_init(void);
void xpro_lcd_show_text(const char *data);
void lcd_display_time(void);

/*Function prototypes for DMA */
void config_dma(void);
void configure_dma_resource(struct dma_resource *resource);
void setup_transfer_descriptor(DmacDescriptor *descriptor);

/*Function prototypes for RTC */
void rtc_match_callback(void);
void configure_rtc_callbacks(void);
void configure_rtc_calendar(void);
void configure_tamper_off_mode(void);
void configure_tamper_capture_mode(void);
void configure_tamper_wake_mode(void);
void rtc_tamper_callback(void);
void configure_rtc_calender_time(void);

/*Function prototypes for TCC */
void configure_tcc(void);
void configure_tcc_callbacks(void);
void tcc_callback_to_toggle_led(struct tcc_module *const module_inst);

/*Function prototypes for RWW EEPROM */
void configure_eeprom(void);
void write_tamper_data(void);
void read_tamper_history(void);
void erase_tamper_history(void);
void memory_index_init(void);
void enable_tamper(void);

/*lookup table with segment values for displaying different character in LCD */
uint16_t DIGI_LUT[] = {
	
	0x0000, //32 - Space
	0x0000, //33 - !
	0x0000, //34 - "
	0x0000, //35 - #
	0x0000, //36 - $
	0x0000, //37 - %
	0x0000, //38 - &
	0x0000, //39 - '
	0x0000, //40 - (
	0x0000, //41 - )
	0x99D9, //42 - *
	0x8181, //43 - +
	0x0000, //44 - ,
	0x0100, //45 - -
	0x0000, //46 - .
	0x0810, //47 - /
	0x2E74, //48 - 0
	0x0440, //49 - 1
	0x23C4, //50 - 2
	0x25C4, //51 - 3
	0x05E0, //52 - 4
	0x25A4, //53 - 5
	0x27A4, //54 - 6
	0x0444, //55 - 7
	0x27E4, //56 - 8
	0x25E4, //57 - 9
	0x0000, //58 - :
	0x0000, //59 - ;
	0x1010, //60 - <
	0x0000, //61 - =
	0x0808, //62 - >
	0x0000, //63 - ?
	0x0000, //64 - @
	0x07E4, //65 - A
	0xA545, //66 - B
	0x2224, //67 - C
	0xA445, //68 - D
	0x23A4, //69 - E
	0x03A4, //70 - F
	0x2724, //71 - G
	0x07E0, //72 - H
	0xA005, //73 - I
	0x2640, //74 - J
	0x12B0, //75 - K
	0x2220, //76 - L
	0x0678, //77 - M
	0x1668, //78 - N
	0x2664, //79 - O
	0x03E4, //80 - P
	0x3664, //81 - Q
	0x13E4, //82 - R
	0x25A4, //83 - S
	0x8005, //84 - T
	0x2660, //85 - U
	0x0A30, //86 - V
	0x1E60, //87 - W
	0x1818, //88 - X
	0x8018, //89 - Y
	0x2814, //90 - Z
};
#endif