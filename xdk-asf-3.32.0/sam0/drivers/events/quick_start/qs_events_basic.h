/**
 * \file
 *
 * \brief SAM Event System Driver Quick Start
 *
 * Copyright (C) 2013-2015 Atmel Corporation. All rights reserved.
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
 * \page asfdoc_sam0_events_basic_use_case Quick Start Guide for EVENTS - Basic
 *
 * In this use case, the EVENT module is configured for:
 *  \li Synchronous event path with rising edge detection on the input
 *  \li One user attached to the configured event channel
 *  \li No hardware event generator attached to the channel
 *
 * This use case allocates an event channel. This channel is not connected to any
 * hardware event generator, events are software triggered. One user is connected
 * to the allocated and configured event channel.
 *
 * \section asfdoc_sam0_events_basic_use_case_setup Setup
 *
 * \subsection asfdoc_sam0_events_basic_use_casesetup_prereq Prerequisites
 * There are no special setup requirements for this use-case.
 *
 * \subsection asfdoc_sam0_events_basic_use_casesetup_code Code
 * Add to the main application source file, before any functions, according to
 * the kit used:
 * - SAM D20 Xplained Pro:
 *   \snippet samd20_xplained_pro/conf_qs_events.h definition_event
 * - SAM D21 Xplained Pro:
 *   \snippet samd21_xplained_pro/conf_qs_events.h definition_event
 * - SAM R21 Xplained Pro:
 *   \snippet samr21_xplained_pro/conf_qs_events.h definition_event
 * - SAM D11 Xplained Pro:
 *   \snippet samd11_xplained_pro/conf_qs_events.h definition_event
 * - SAM L21 Xplained Pro:
 *   \snippet saml21_xplained_pro/conf_qs_events.h definition_event
 * - SAM L22 Xplained Pro:
 *   \snippet saml22_xplained_pro/conf_qs_events.h definition_event
 * - SAM DA1 Xplained Pro:
 *   \snippet samda1_xplained_pro/conf_qs_events.h definition_event
 * - SAM C21 Xplained Pro:
 *   \snippet samc21_xplained_pro/conf_qs_events.h definition_event
 *
 * Copy-paste the following setup code to your user application:
 * \snippet qs_events_basic.c setup
 *
 * Create an event resource struct and add to user application (typically the start of \c main()):
 * \snippet qs_events_basic.c events_resource_struct
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_events_basic.c setup_init
 *
 * \subsection asfdoc_sam0_events_basic_use_casesetup_flow Workflow
 * -# Create an event channel configuration struct, which can be filled out to
 *    adjust the configuration of a single event channel.
 *    \snippet qs_events_basic.c setup_1
 *    \br
 *
 * -# Initialize the event channel configuration struct with the module's
 *    default values.
 *    \snippet qs_events_basic.c setup_2
 *    \note This should always be performed before using the configuration
 *          struct to ensure that all values are initialized to known default
 *          settings.
 *
 * -# Adjust the configuration struct to request that the channel is to be attached
 *    to the specified event generator, that rising edges of the event signal is to
 *    be detected on the channel, and that the synchronous event path is to be used.
 *    \snippet qs_events_basic.c setup_3
 *    \br
 *
 * -# Allocate and configure the channel using the configuration structure.
 *    \snippet qs_events_basic.c setup_4
 *    \note The existing configuration struct may be re-used, as long as any
 *          values that have been altered from the default settings are taken
 *          into account by the user application.
 *
 * -# Attach a user to the channel.
 *    \snippet qs_events_basic.c setup_5
 *    \br
 *
 * \section asfdoc_sam0_events_basic_use_case_main Use Case
 *
 * \subsection asfdoc_sam0_events_basic_use_casecode_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_events_basic.c main
 *
 * \subsection events_basic_use_case_code_flow Workflow
 * -# Wait for the event channel to become ready to accept a new event trigger.
 *    \snippet qs_events_basic.c main_1
 * -# Perform a software event trigger on the configured event channel.
 *    \snippet qs_events_basic.c main_2
 */
