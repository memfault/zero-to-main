/**
 *
 * \file
 *
 * \brief SAM SLCD Driver Quick Start
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

/** \page asfdoc_sam0_slcd_basic_use_case Quick Start Guide for SLCD
 *
 * The supported board list:
 *    - SAM L22 Xplained Pro B
 *
 * The TSLCD1 Xplained Pro extension board must be connected to extension
 * header 5 on the SAM L22 Xplained Pro B.
 *
 * This example demonstrates how to use the SLCD driver, it covers the following cases:
 * - Display Memory Mapping(Direct Access and Indirect Access)
 * - Character Mapping
 * - Blinking
 *
 * Upon startup, the program uses the USART driver to display application
 * output message.
 *
 * \section asfdoc_sam0_slcd_basic_use_case_setup Quick Start
 *
 * \subsection asfdoc_sam0_slcd_basic_use_case_prereq Prerequisites
 * There are no prerequisites for this use case.
 *
 * \subsection asfdoc_sam0_slcd_basic_use_case_setup_code Code
 *
 * Add to the main application source file, outside of any functions:
 * \snippet quick_start.c slcd_data
 *
 * Add to the main application source file, outside of any functions:
 * \snippet quick_start.c slcd_var

 * Copy-paste the following setup code to your user application:
 * \snippet quick_start.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet quick_start.c setup_init
 *
 * \subsection asfdoc_sam0_slcd_basic_use_case_setup_flow Workflow
 * -# Define charactor map data.
 *    \snippet quick_start.c slcd_data
 *
 * -# Create related module variable and software instance structure.
 *    \snippet quick_start.c slcd_var
 *
 * -# Configure, initialize, and enable slcd module.
 *  -# Configuration slcd struct, which can be filled out to
 *     adjust the configuration of a physical slcd peripheral.
 *     \snippet quick_start.c setup_config
 *  -# Enable the slcd module.
 *     \snippet quick_start.c module_enable
 *
 *
 * \section asfdoc_sam0_slcd_basic_use_case_main Use Case
 *
 * \subsection asfdoc_sam0_slcd_basic_use_case_main_code Code
 * Copy-paste the following code to your user application:
 * \snippet quick_start.c  use_cases
 *
 * \subsection asfdoc_sam0_slcd_basic_use_case_main_flow Workflow
 * -# Display all case.
 *    \snippet quick_start.c use_cases_1
 * -# Display icon.
 *    \snippet quick_start.c use_cases_2
 * -# Character map case.
 *    \snippet quick_start.c use_cases_3
 * -# Didital map case.
 *    \snippet quick_start.c use_cases_4
 * -# SLCD blinking.
 *    \snippet quick_start.c use_cases_5
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
