/**
 * \file
 *
 * \brief SAM Divide and Square Root Accelerator (DIVAS) Driver Quick Start
 *
 * Copyright (c) 2015-2016 Atmel Corporation. All rights reserved.
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

/**
 * \page asfdoc_sam0_divas_basic_use_case Quick Start Guide for DIVAS - No Overload
 *
 * In this use case, the Divide and Square Root Accelerator (DIVAS) module is 
 * used.
 *
 * This use case will calculate the data in No Overload mode. If all the 
 * calculation results are the same as the desired results, the board LED will be  
 * lighted. Otherwise, the board LED will be flashing. The variable "result" 
 * can indicate which calculation is wrong.
 *
 * \section asfdoc_sam0_divas_basic_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_divas_basic_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_sam0_divas_basic_use_case_setup_code Code
 * The following must be added to the user application source file, outside
 * any function:
 
 * The signed and unsigned dividend: 
 * \snippet qs_divas_basic.c buffer

 * Copy-paste the following function code to your user application:
 * \snippet qs_divas_basic.c calculate
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_divas_basic.c setup_init
 *
 * \section asfdoc_sam0_divas_basic_use_case_imp Implementation
 *
 * \subsection asfdoc_sam0_trng_basic_use_case_imp_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_divas_basic.c main
 *
 * \subsection asfdoc_sam0_divas_basic_use_case_imp_flow Workflow
 * -# Signed division calculation.
 *    \snippet qs_divas_basic.c main_1
 * -# Unsigned division calculation.
 *    \snippet qs_divas_basic.c main_2
 * -# Signed reminder calculation.
 *    \snippet qs_divas_basic.c main_3
 * -# Unsigned reminder calculation.
 *    \snippet qs_divas_basic.c main_4
 * -# Square root calculation.
 *    \snippet qs_divas_basic.c main_5
 * -# Infinite loop.
 *    \snippet qs_divas_basic.c main_6
 */

