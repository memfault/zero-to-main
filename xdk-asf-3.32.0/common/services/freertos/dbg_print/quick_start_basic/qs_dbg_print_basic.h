/**
 * \file
 *
 * \brief Debug print basic quick start guide
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

/**
 * \page asfdoc_common_freertos_dbg_print_basic_use_case Quick Start Guide for Debug Print Service for FreeRTOS
 *
 * In this use case, the Debug Print service is configured with the following
 * settings:
 * - 128-byte print buffer
 * - output via the SERCOM UART connected to Embedded Debugger (EDBG) on an
 *    Xplained Pro board
 * - 9600 baud transfer rate
 *
 * A FreeRTOS task is created which every second prints a constant string and
 * a string containing an incrementing 32-bit hexadecimal integer.
 *
 *
 * \section asfdoc_common_freertos_dbg_print_basic_use_setup Setup
 *
 * \subsection asfdoc_common_freertos_dbg_print_basic_use_setup_prereq Prerequisites
 *
 * FreeRTOS must be added to the project, and the clock driver must be
 * configured to initialize GCLK 0 to 48 MHz. Note that FreeRTOS also has a
 * setting for the system clock frequency which must be updated.
 *
 *
 * \subsection asfdoc_common_freertos_dbg_print_basic_use_setup_code Code
 *
 * The following must be added to the file conf_dbg_print.h:
 * \snippet conf_dbg_print.h  config_include
 * \snippet conf_dbg_print.h  config_buffer
 * \snippet conf_dbg_print.h  config_sercom
 *
 *
 * \section asfdoc_common_freertos_dbg_print_basic_use_setup_workflow Workflow
 *
 * -# Include board definition to get settings for output to EDBG:
 *    \snippet conf_dbg_print.h  config_include
 * -# Set buffer size to 128 byte:
 *    \snippet conf_dbg_print.h  config_buffer
 * -# Use SERCOM connected to EDBG CDC for output at 9600 baud:
 *    \snippet conf_dbg_print.h  config_sercom
 *
 *
 * \section asfdoc_common_freertos_dbg_print_basic_use Use Case
 *
 * \subsection asfdoc_common_freertos_dbg_print_basic_use_code Code
 *
 * Add the following to your main application C file:
 * \snippet qs_dbg_print_basic.c  main_task_data
 * \snippet qs_dbg_print_basic.c  main_task
 *
 * Add the following to your application's \c main() function:
 * \snippet qs_dbg_print_basic.c  init_calls
 * \snippet qs_dbg_print_basic.c  main_task_create
 * \snippet qs_dbg_print_basic.c  freertos_start
 *
 *
 * \subsection asfdoc_common_freertos_dbg_print_basic_use_workflow Workflow
 *
 * -# Define debug variables to print out:
 *    \snippet qs_dbg_print_basic.c  main_task_data
 * -# Define a FreeRTOS task for printing debug data forever:
 *    \snippet qs_dbg_print_basic.c  main_task_open
 * -# Print a constant string at the start of the task-loop:
 *    \snippet qs_dbg_print_basic.c  main_task_1
 * -# Write a hexadecimal integer into a string and print it:
 *    \snippet qs_dbg_print_basic.c  main_task_2
 *    \note \ref dbg_sprint_hexint() does not write the \c 0x prefix, only the
 *      hexadecimal digits.
 * -# Add a 1 sec delay at the of the task-loop and close the task definition:
 *    \snippet qs_dbg_print_basic.c main_task_close
 * -# In \c main(), initialize the system and debug print service:
 *    \snippet qs_dbg_print_basic.c  init_calls
 * -# Create an instance of the debug printing task:
 *    \snippet qs_dbg_print_basic.c  main_task_create
 * -# Start the FreeRTOS scheduler:
 *    \snippet qs_dbg_print_basic.c  freertos_start
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
