/**
 * \file
 *
 * \brief SAM PAC Quick Start
 *
 * Copyright (C) 2012-2015 Atmel Corporation. All rights reserved.
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
 * \page asfdoc_sam0_pac_basic_use_case Quick Start Guide for PAC - Basic
 *
 * In this use case, the peripheral-lock will be used to lock and unlock the
 * PORT peripheral access, and show how to implement the PAC module when the
 * PORT registers needs to be altered. The PORT will be set up as follows:
 * - One pin in input mode, with pull-up and falling edge-detect
 * - One pin in output mode
 *
 * \section asfdoc_sam0_pac_basic_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_pac_basic_use_case_setup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_sam0_pac_basic_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_pac_basic.c pin_setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_pac_basic.c init
 *
 * \section asfdoc_sam0_pac_basic_use_case_use_main Use Case
 *
 * \subsection asfdoc_sam0_pac_basic_use_case_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_pac_basic.c main
 *
 * \subsection asfdoc_sam0_pac_basic_use_case_flow Workflow
 * -# Configure some GPIO port pins for input and output.
 *    \snippet qs_pac_basic.c init
 * -# Lock peripheral access for the PORT module; attempting to update the
 *    module while it is in a protected state will cause a CPU exception.
 *    For SAM D20/D21/D10/D11/R21/DA0/DA1, it is Hard Fault exception;
 *    For SAM L21/C21, it is system exception, see \ref SYSTEM_Handler().
 *    \snippet qs_pac_basic.c init_lock
 * -# Enable global interrupts.
 *    \snippet qs_pac_basic.c enable_interrupts
 * -# Loop to wait for a button press before continuing.
 *    \snippet qs_pac_basic.c button_press
 * -# Enter a critical section, so that the PAC module can be unlocked safely
 *    and the peripheral manipulated without the possibility of an interrupt
 *    modifying the protected module's state.
 *    \snippet qs_pac_basic.c disable_interrupts
 * -# Unlock the PORT peripheral registers.
 *    \snippet qs_pac_basic.c unlock_perph
 * -# Toggle pin 11, and clear edge detect flag.
 *    \snippet qs_pac_basic.c alter_config
 * -# Lock the PORT peripheral registers.
 *    \snippet qs_pac_basic.c lock_perph
 * -# Exit the critical section to allow interrupts to function normally again.
 *    \snippet qs_pac_basic.c enable_interrupts_2
 * -# Enter an infinite while loop once the module state has been modified
 *    successfully.
 *    \snippet qs_pac_basic.c inf_loop
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */










