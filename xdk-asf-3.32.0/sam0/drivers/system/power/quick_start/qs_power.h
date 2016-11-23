/**
 * \file
 *
 * \brief SAM Power Driver Quick Start
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
 *
 */

 /** \page asfdoc_sam0_power_basic_use_case Quick Start Guide for Power Driver
 *
 * List of supported boards:
 *    - SAM L21 Xplained Pro
 *    - SAM L22 Xplained Pro
 *    - SAM L22 Xplained Pro B
 *
 * This example demonstrates how to use the power driver. BUTTON0 is used to
 * wake up the system from the standby sleep mode and as an external wakeup pin
 * to wake up the system from the backup sleep mode. The wakeup pin level is low.
 * The I/O pins PB22/PB23 are used as GCLK0/GCLK1 outputs so that an oscilloscope
 * can be used to monitor the clock frequencies.
 *
 * After power-on-reset (POR), GCLK0 and GCLK1 runs at 4MHz and LED0 is turned on.
 * After one second, LED0 is turned off and the system enters standby sleep mode.
 * BUTTON0 can then be used to wake up the system. After the system wakeup, LED0
 * is turned on, the performance level is switched to PL2, and the GCLK0 is increased
 * to 48MHz. Further LED0 toggles two times and is turned off before the system
 * enters BACKUP.
 *
 * When BUTTON0 pushes, it connects to low level, system wakes up from the backup
 * sleep mode, LED0 toggles four times. GCLK0/GCLK1 are running at 4MHz.
 *
 * \section asfdoc_sam0_power_basic_use_case_setup Quick Start
 *
 * \subsection asfdoc_sam0_power_basic_use_case_prereq Prerequisites
 * There are no prerequisites for this use case.
 *
 * \subsection asfdoc_sam0_power_basic_use_case_setup_code Code
 *
 * Copy-paste the following setup code to your user application:
 * \snippet quick_start/qs_power.c setup
 *
 * \subsection asfdoc_sam0_power_basic_use_case_setup_flow Workflow
 * -# Switch performance level to PL2.
 *    \snippet quick_start/qs_power.c switch_pl
 *
 * -# Configure GCLK0/GCLK1 output pin and extwakeup pin.
 *    \snippet quick_start/qs_power.c pin_mux
 *
 * -# Config external interrupt.
 *    \snippet quick_start/qs_power.c config_extint
 *
 * \section asfdoc_sam0_power_basic_use_case_main Use Case
 *
 * \subsection asfdoc_sam0_power_basic_use_case_main_code Code
 * Copy-paste the following code to your user application:
 * \snippet quick_start/qs_power.c  setup_init
 *
 * \subsection asfdoc_sam0_power_basic_use_case_main_flow Workflow
 * -# Check if the RESET is caused by external wakeup pin.
 *    \snippet quick_start/qs_power.c ext_wakeup
 * -# Check the standby mode and the backup sleep mode.
 *    \snippet quick_start/qs_power.c backup_stanby_mode
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
