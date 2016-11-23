/**
 * \file
 *
 * \brief GPIO Quick Start Guide with Callbacks for SAMB11
 *
 * Copyright (C) 2016 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
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
 * \page asfdoc_samb_gpio_callback_use_case Quick Start Guide for GPIO - Callback
 *
 * In this use case, the GPIO module is configured for:
 *  \li One pin in input mode, with pull-up enabled
 *  \li One pin in output mode
 *
 * This use case sets up the AON GPIO to wakeup the MCU in low power sleep mode, if user
 * want to use in the ULP mode, must add platform driver related API: acquire_sleep_lock(),
 * release_sleep_lock(), register_resume_callback(cb).
 *
 * \subsection asfdoc_samb_gpio_callback_use_case_setup_code Code
 * Copy-paste the following setup code to your user application:
 * \snippet qs_gpio_callback.c setup
 *
 * Add to user application initialization (typically the start of \c main()):
 * \snippet qs_gpio_callback.c setup_init
 *
 * \subsection asfdoc_samb_gpio_callback_use_case_setup_flow Workflow
 * -# Create a UART module configuration struct.
 *    \snippet qs_gpio_callback.c setup_uart_1
 * -# Initialize the config_uart configuration struct with the module's default values.
 *    \snippet qs_gpio_callback.c setup_uart_2 
 *    \note This should always be performed before using the configuration
 *          struct to ensure that all values are initialized to known default
 *          settings.
 *
 * -# Adjust the configuration struct to request setting.
 *    \snippet qs_gpio_callback.c setup_uart_3
 *
 * -# Configure UART with the initialized configuration struct, to enable
 *    the driver.
 *    \snippet qs_gpio_callback.c setup_uart_4
 *
 * -# Create a GPIO module pin configuration struct. Initialize the pin configuration
 *    struct with the module's default values.
 *    \snippet qs_gpio_callback.c setup_gpio_1
 *    \note This should always be performed before using the configuration
 *          struct to ensure that all values are initialized to known default
 *          settings.
 *
 * -# Adjust the configuration struct to request an input pin and enable AON wakeup.
 *    \snippet qs_gpio_callback.c setup_gpio_2
 *
 * -# Configure AON GPIO pin with the initialized pin configuration struct.
 *    \snippet qs_gpio_callback.c setup_gpio_3
 *
 * -# Ini AON GPIO pin with the initialized pin configuration struct.
 *    \snippet qs_gpio_callback.c setup_gpio_3
 *
 * -# Initialize callback function.
 *    \snippet qs_gpio_callback.c callback_init
 *
 * -# Register callback function.
 *    \snippet qs_gpio_callback.c callback_reg
 * -# Enable callback function.
 *    \snippet qs_gpio_callback.c callback_en 
 * 
 * \section asfdoc_samb_gpio_callback_use_case_use_main Use Case
 *
 * \subsection asfdoc_samb_gpio_callback_use_case_code Code
 * Copy-paste the following code to your user application:
 * \snippet qs_gpio_callback.c main
 *
 * \subsection asfdoc_samb_gpio_callback_use_case_flow Workflow
 * -# Infinit loop.
 *    \snippet qs_gpio_callback.c main
 */