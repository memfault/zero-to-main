/**
 * \file
 *
 * \brief Common Sensor Service Compass Calibration Example
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

/**
 * \mainpage
 *
 * \section intro Introduction
 *
 * This application performs a multi-step manual calibration on a compass
 * (magnetometer) sensor device.  The device must be physically manipulated
 * during the calibration process, between individual steps.  The user
 * presses the button on the processor board to move to the next calibration
 * step.
 *
 * \section contactinfo Contact Information
 * For further information, visit
 * <a href="http://www.atmel.com/avr">Atmel AVR</a>.\n
 * Support and FAQ: http://www.atmel.com/design-support/
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */

#include <stdio.h>
#include <asf.h>
#include <led.h>

/* Switch and LED definitions */
#define SWITCH_PRESSED   gpio_pin_is_low(GPIO_PUSH_BUTTON_0)

#if (BOARD == UC3_L0_XPLAINED)
#  define NUM_BLINK_LEDS   (4)
#  define ALL_LEDS         (LED1 | LED2 | LED3 | LED4)
#  define PROMPT_LED       LED4 /* Blink while waiting for user input */
static const uint32_t led_array[NUM_BLINK_LEDS] = {LED1, LED2, LED3, LED4};
#else
#  define NUM_BLINK_LEDS   (4)
#  define ALL_LEDS         (LED0 | LED1 | LED2 | LED3)
#  define PROMPT_LED       LED0 /* Blink while waiting for user input */
static const uint32_t led_array[NUM_BLINK_LEDS] = {LED0, LED1, LED2, LED3};
#endif


/** \brief User prompt routine
 *
 * This routine prompts the user to press the button and then waits
 * for him to do so.
 */
static void prompt_user(char *prompt_string)
{
	/* Output prompt string */
	printf("%s\r\n", prompt_string);

	/* Wait for user to push button before continuing */
	LED_Off(ALL_LEDS);

	/* Just blink LED until button is pushed */
	while (!SWITCH_PRESSED) {
		LED_Toggle(PROMPT_LED);
		delay_ms(100);
	}

	LED_Off(PROMPT_LED);

	/* Wait until button is released */
	while (SWITCH_PRESSED) {
	}
}

/** \brief Compass / magnetometer calibration application
 *
 * This application illustrates the use of the sensor_calibrate() function
 * for compass/magnetometer calibration.  It prompts the user (via serial
 * output) to manipulate the sensor board and press a button to continue.
 *
 * The calibration process is used to correct for fixed magnetic forces
 * present on the board where the compass is mounted.  If uncorrected, these
 * fixed forces will prevent accurate measurement of the actual external
 * magnetic forces (e.g. magnetic North).
 *
 * The calibration sequence requires three steps.  During each step, the
 * board is placed in a specific orientation, and the user presses the button
 * on the board to trigger a compass sensor reading.
 *
 * The three orientations are:
 *   -#  Board lying flat (on a table, for example).
 *   -#  Board rotated 180 degrees (end-for-end), still lying flat.
 *   -#  Board flipped (inverted) so that the opposite side is facing up.
 *
 * After Step 3 is completed, the calibration values for the sensor are
 * calculated and are written to non-volatile (flash) memory on the
 * microcontroller.  These values will continue to be used for future
 * compass heading readings.
 */
int main(void)
{
	sensor_t compass_dev;           /* Compass/magnetometer device */
	sensor_data_t compass_data;     /* Compass data */

	/* Initialize hardware & sensor interfaces */
	sensor_platform_init();

	LED_On(ALL_LEDS);              

	/* Wait for user to press button to start */
	prompt_user("Press button to start");
	
	/* Attach descriptor and initialize the compass device */
	sensor_attach(&compass_dev, SENSOR_TYPE_COMPASS, 0, 0);

	/* Set sensor data output formats (for display after calibration
	 * is complete)
	 */
	compass_data.scaled = true;

	/* Perform calibration sequence */

	/* Step 1 */
	prompt_user("Lay board flat & press button");
	(void)sensor_calibrate(&compass_dev, MANUAL_CALIBRATE, 1, NULL);

	/* Step 2 */
	prompt_user("Rotate 180 degrees & press button");
	(void)sensor_calibrate(&compass_dev, MANUAL_CALIBRATE, 2, NULL);

	/* Step 3 */
	prompt_user("Flip board & press button");
	if (sensor_calibrate(&compass_dev, MANUAL_CALIBRATE, 3, NULL) == false) {
		if (compass_dev.err == SENSOR_ERR_IO) {
			printf("Calibration failure: write error\n\r");
		} else {
			printf("Unknown error while calibrating device\n\r");
		}

		while (true) {
			/* Error occurred, loop forever */
		}
	}

	/* Once the calibration is complete, the magnetic heading is
	 * continuously
	 * calculated and displayed.
	 */

	while (true) {
		static uint8_t led_num = 0;

		/* Change LED display */
		LED_Toggle(led_array[led_num++]);
		if (led_num >= NUM_BLINK_LEDS) {
			led_num = 0;
		}

		/* Sample compass and display heading values */
		sensor_get_heading(&compass_dev, &compass_data);

		printf("Direction = %d, Inclination = %d, Strength = %d uT\r\n",
				(int)compass_data.heading.direction,
				(int)compass_data.heading.inclination,
				(int)compass_data.heading.strength);

		delay_ms(100);
	}

	return 0;
}
