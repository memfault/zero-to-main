/**
 * \file
 *
 * \brief Peripheral I/O description for BTLC1000WLCSP
 *
 * Copyright (c) 2016 Atmel Corporation. All rights reserved.
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

#ifndef _BTLC1000WLCSP_PIO_
#define _BTLC1000WLCSP_PIO_

#define PIN_LP_GPIO_0                     0  /**< Pin Number for LP_GPIO_0 */
#define GPIO_LP_GPIO_0           (1ul <<  0) /**< GPIO Mask for LP_GPIO_0 */
#define PIN_LP_GPIO_1                     1  /**< Pin Number for LP_GPIO_1 */
#define GPIO_LP_GPIO_1           (1ul <<  1) /**< GPIO Mask for LP_GPIO_1 */
#define PIN_LP_GPIO_2                     2  /**< Pin Number for LP_GPIO_2 */
#define GPIO_LP_GPIO_2           (1ul <<  2) /**< GPIO Mask for LP_GPIO_2 */
#define PIN_LP_GPIO_3                     3  /**< Pin Number for LP_GPIO_3 */
#define GPIO_LP_GPIO_3           (1ul <<  3) /**< GPIO Mask for LP_GPIO_3 */
#define PIN_LP_GPIO_8                     8  /**< Pin Number for LP_GPIO_8 */
#define GPIO_LP_GPIO_8           (1ul <<  8) /**< GPIO Mask for LP_GPIO_8 */
#define PIN_LP_GPIO_9                     9  /**< Pin Number for LP_GPIO_9 */
#define GPIO_LP_GPIO_9           (1ul <<  9) /**< GPIO Mask for LP_GPIO_9 */
#define PIN_LP_GPIO_10                   10  /**< Pin Number for LP_GPIO_10 */
#define GPIO_LP_GPIO_10          (1ul << 10) /**< GPIO Mask for LP_GPIO_10 */
#define PIN_LP_GPIO_11                   11  /**< Pin Number for LP_GPIO_11 */
#define GPIO_LP_GPIO_11          (1ul << 11) /**< GPIO Mask for LP_GPIO_11 */
#define PIN_LP_GPIO_12                   12  /**< Pin Number for LP_GPIO_12 */
#define GPIO_LP_GPIO_12          (1ul << 12) /**< GPIO Mask for LP_GPIO_12 */
#define PIN_LP_GPIO_13                   13  /**< Pin Number for LP_GPIO_13 */
#define GPIO_LP_GPIO_13          (1ul << 13) /**< GPIO Mask for LP_GPIO_13 */
#define PIN_AO_GPIO_0                    31  /**< Pin Number for AO_GPIO_0 */
#define GPIO_AO_GPIO_0           (1ul << 15) /**< GPIO Mask for AO_GPIO_0 */
#define PIN_GPIO_MS1                     47  /**< Pin Number for GPIO_MS1 */
#define GPIO_GPIO_MS1            (1ul << 15) /**< GPIO Mask for GPIO_MS1 */

/* PinMux definitions                                               */
/* Mux values for LP_GPIO_0 */
#define MUX_LP_GPIO_0_GPIO                     0x0
#define MUX_LP_GPIO_0_MEGAMUX                  0x1
#define MUX_LP_GPIO_0_SWD_CLK                  0x2
#define MUX_LP_GPIO_0_TEST_OUT_0               0x7
/* Mux values for LP_GPIO_1 */
#define MUX_LP_GPIO_1_GPIO                     0x0
#define MUX_LP_GPIO_1_SWD_IO                   0x2
#define MUX_LP_GPIO_1_MEGAMUX                  0x1
#define MUX_LP_GPIO_1_TEST_OUT_1               0x7
/* Mux values for LP_GPIO_2 */
#define MUX_LP_GPIO_2_MEGAMUX                  0x1
#define MUX_LP_GPIO_2_SPI_FLASH0_SCK           0x6
#define MUX_LP_GPIO_2_TEST_OUT_2               0x7
#define MUX_LP_GPIO_2_UART0_RXD                0x2
#define MUX_LP_GPIO_2_GPIO                     0x0
#define MUX_LP_GPIO_2_SPI0_SCK                 0x5
/* Mux values for LP_GPIO_3 */
#define MUX_LP_GPIO_3_UART0_TXD                0x2
#define MUX_LP_GPIO_3_SPI0_MOSI                0x5
#define MUX_LP_GPIO_3_MEGAMUX                  0x1
#define MUX_LP_GPIO_3_SPI_FLASH0_TXD           0x6
#define MUX_LP_GPIO_3_TEST_OUT_3               0x7
#define MUX_LP_GPIO_3_GPIO                     0x0
/* Mux values for LP_GPIO_8 */
#define MUX_LP_GPIO_8_MEGAMUX                  0x1
#define MUX_LP_GPIO_8_SPI0_SSN                 0x5
#define MUX_LP_GPIO_8_SPI_FLASH0_SSN           0x6
#define MUX_LP_GPIO_8_GPIO                     0x0
#define MUX_LP_GPIO_8_I2C0_SDA                 0x2
#define MUX_LP_GPIO_8_TEST_OUT_8               0x7
/* Mux values for LP_GPIO_9 */
#define MUX_LP_GPIO_9_SPI_FLASH0_RXD           0x6
#define MUX_LP_GPIO_9_MEGAMUX                  0x1
#define MUX_LP_GPIO_9_SPI0_MISO                0x5
#define MUX_LP_GPIO_9_I2C0_SCL                 0x2
#define MUX_LP_GPIO_9_GPIO                     0x0
#define MUX_LP_GPIO_9_TEST_OUT_9               0x7
/* Mux values for LP_GPIO_10 */
#define MUX_LP_GPIO_10_GPIO                    0x0
#define MUX_LP_GPIO_10_MEGAMUX                 0x1
#define MUX_LP_GPIO_10_TEST_OUT_10             0x7
#define MUX_LP_GPIO_10_SPI_FLASH0_SCK          0x6
#define MUX_LP_GPIO_10_SPI0_SCK                0x2
/* Mux values for LP_GPIO_11 */
#define MUX_LP_GPIO_11_SPI0_MOSI               0x2
#define MUX_LP_GPIO_11_GPIO                    0x0
#define MUX_LP_GPIO_11_MEGAMUX                 0x1
#define MUX_LP_GPIO_11_SPI_FLASH0_TXD          0x6
#define MUX_LP_GPIO_11_TEST_OUT_11             0x7
/* Mux values for LP_GPIO_12 */
#define MUX_LP_GPIO_12_SPI_FLASH0_SSN          0x6
#define MUX_LP_GPIO_12_GPIO                    0x0
#define MUX_LP_GPIO_12_SPI0_SSN                0x2
#define MUX_LP_GPIO_12_MEGAMUX                 0x1
#define MUX_LP_GPIO_12_TEST_OUT_12             0x7
/* Mux values for LP_GPIO_13 */
#define MUX_LP_GPIO_13_GPIO                    0x0
#define MUX_LP_GPIO_13_SPI_FLASH0_RXD          0x6
#define MUX_LP_GPIO_13_MEGAMUX                 0x1
#define MUX_LP_GPIO_13_SPI0_MISO               0x2
#define MUX_LP_GPIO_13_TEST_OUT_13             0x7

/* MegaMux definitions                                              */
/* MegaMux values for LP_GPIO_0 */
#define MEGAMUX_LP_GPIO_0_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_0_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_0_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_0_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_0_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_0_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_0_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_0_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_0_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_0_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_0_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_0_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_0_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_0_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_0_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_0_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_0_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_0_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_0_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_0_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_0_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_0_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_0_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_0_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_0_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_0_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_0_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_0_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_0_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_0_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_0_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_1 */
#define MEGAMUX_LP_GPIO_1_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_1_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_1_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_1_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_1_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_1_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_1_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_1_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_1_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_1_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_1_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_1_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_1_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_1_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_1_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_1_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_1_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_1_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_1_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_1_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_1_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_1_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_1_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_1_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_1_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_1_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_1_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_1_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_1_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_1_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_1_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_2 */
#define MEGAMUX_LP_GPIO_2_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_2_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_2_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_2_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_2_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_2_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_2_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_2_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_2_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_2_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_2_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_2_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_2_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_2_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_2_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_2_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_2_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_2_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_2_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_2_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_2_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_2_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_2_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_2_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_2_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_2_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_2_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_2_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_2_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_2_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_2_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_3 */
#define MEGAMUX_LP_GPIO_3_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_3_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_3_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_3_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_3_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_3_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_3_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_3_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_3_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_3_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_3_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_3_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_3_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_3_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_3_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_3_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_3_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_3_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_3_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_3_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_3_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_3_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_3_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_3_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_3_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_3_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_3_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_3_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_3_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_3_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_3_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_8 */
#define MEGAMUX_LP_GPIO_8_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_8_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_8_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_8_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_8_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_8_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_8_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_8_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_8_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_8_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_8_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_8_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_8_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_8_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_8_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_8_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_8_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_8_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_8_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_8_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_8_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_8_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_8_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_8_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_8_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_8_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_8_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_8_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_8_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_8_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_8_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_9 */
#define MEGAMUX_LP_GPIO_9_I2C0_SCL                 0x9
#define MEGAMUX_LP_GPIO_9_UART1_CTS                0x6
#define MEGAMUX_LP_GPIO_9_COEX_BLE_MBSY            0x16
#define MEGAMUX_LP_GPIO_9_COEX_BLE_TX              0x13
#define MEGAMUX_LP_GPIO_9_UART0_RTS                0x3
#define MEGAMUX_LP_GPIO_9_UART0_RXD                0x0
#define MEGAMUX_LP_GPIO_9_32KHZ_CLK                0x10
#define MEGAMUX_LP_GPIO_9_COEX_BLE_IN_PROCESS      0x15
#define MEGAMUX_LP_GPIO_9_UART0_TXD                0x1
#define MEGAMUX_LP_GPIO_9_UART1_TXD                0x5
#define MEGAMUX_LP_GPIO_9_I2C1_SCL                 0xb
#define MEGAMUX_LP_GPIO_9_COEX_WLAN_RX             0x12
#define MEGAMUX_LP_GPIO_9_COEX_WLAN_TX             0x11
#define MEGAMUX_LP_GPIO_9_PWM1_OUT                 0xd
#define MEGAMUX_LP_GPIO_9_QUAD_DEC0_B              0x1e
#define MEGAMUX_LP_GPIO_9_UART1_RTS                0x7
#define MEGAMUX_LP_GPIO_9_UART0_CTS                0x2
#define MEGAMUX_LP_GPIO_9_UART1_RXD                0x4
#define MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_0           0x19
#define MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_1           0x1a
#define MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_2           0x1b
#define MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_3           0x1c
#define MEGAMUX_LP_GPIO_9_I2C1_SDA                 0xa
#define MEGAMUX_LP_GPIO_9_I2C0_SDA                 0x8
#define MEGAMUX_LP_GPIO_9_COEX_BLE_SYNC            0x17
#define MEGAMUX_LP_GPIO_9_QUAD_DEC2_A              0x21
#define MEGAMUX_LP_GPIO_9_QUAD_DEC2_B              0x22
#define MEGAMUX_LP_GPIO_9_COEX_BLE_RX              0x14
#define MEGAMUX_LP_GPIO_9_QUAD_DEC1_B              0x20
#define MEGAMUX_LP_GPIO_9_PWM3_OUT                 0xf
#define MEGAMUX_LP_GPIO_9_COEX_BLE_RXNTX           0x18
#define MEGAMUX_LP_GPIO_9_QUAD_DEC0_A              0x1d
#define MEGAMUX_LP_GPIO_9_PWM0_OUT                 0xc
#define MEGAMUX_LP_GPIO_9_QUAD_DEC1_A              0x1f
#define MEGAMUX_LP_GPIO_9_PWM2_OUT                 0xe
/* MegaMux values for LP_GPIO_10 */
#define MEGAMUX_LP_GPIO_10_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_10_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_10_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_10_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_10_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_10_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_10_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_10_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_10_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_10_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_10_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_10_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_10_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_10_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_10_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_10_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_10_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_10_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_10_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_10_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_10_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_10_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_10_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_10_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_10_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_10_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_10_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_10_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_10_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_10_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_10_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_11 */
#define MEGAMUX_LP_GPIO_11_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_11_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_11_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_11_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_11_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_11_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_11_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_11_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_11_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_11_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_11_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_11_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_11_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_11_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_11_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_11_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_11_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_11_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_11_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_11_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_11_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_11_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_11_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_11_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_11_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_11_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_11_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_11_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_11_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_11_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_11_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_12 */
#define MEGAMUX_LP_GPIO_12_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_12_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_12_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_12_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_12_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_12_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_12_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_12_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_12_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_12_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_12_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_12_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_12_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_12_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_12_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_12_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_12_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_12_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_12_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_12_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_12_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_12_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_12_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_12_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_12_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_12_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_12_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_12_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_12_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_12_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_12_PWM2_OUT                0xe
/* MegaMux values for LP_GPIO_13 */
#define MEGAMUX_LP_GPIO_13_I2C0_SCL                0x9
#define MEGAMUX_LP_GPIO_13_UART1_CTS               0x6
#define MEGAMUX_LP_GPIO_13_COEX_BLE_MBSY           0x16
#define MEGAMUX_LP_GPIO_13_COEX_BLE_TX             0x13
#define MEGAMUX_LP_GPIO_13_UART0_RTS               0x3
#define MEGAMUX_LP_GPIO_13_UART0_RXD               0x0
#define MEGAMUX_LP_GPIO_13_32KHZ_CLK               0x10
#define MEGAMUX_LP_GPIO_13_COEX_BLE_IN_PROCESS     0x15
#define MEGAMUX_LP_GPIO_13_UART0_TXD               0x1
#define MEGAMUX_LP_GPIO_13_UART1_TXD               0x5
#define MEGAMUX_LP_GPIO_13_I2C1_SCL                0xb
#define MEGAMUX_LP_GPIO_13_COEX_WLAN_RX            0x12
#define MEGAMUX_LP_GPIO_13_COEX_WLAN_TX            0x11
#define MEGAMUX_LP_GPIO_13_PWM1_OUT                0xd
#define MEGAMUX_LP_GPIO_13_QUAD_DEC0_B             0x1e
#define MEGAMUX_LP_GPIO_13_UART1_RTS               0x7
#define MEGAMUX_LP_GPIO_13_UART0_CTS               0x2
#define MEGAMUX_LP_GPIO_13_UART1_RXD               0x4
#define MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_0          0x19
#define MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_1          0x1a
#define MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_2          0x1b
#define MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_3          0x1c
#define MEGAMUX_LP_GPIO_13_I2C1_SDA                0xa
#define MEGAMUX_LP_GPIO_13_I2C0_SDA                0x8
#define MEGAMUX_LP_GPIO_13_COEX_BLE_SYNC           0x17
#define MEGAMUX_LP_GPIO_13_QUAD_DEC2_A             0x21
#define MEGAMUX_LP_GPIO_13_QUAD_DEC2_B             0x22
#define MEGAMUX_LP_GPIO_13_COEX_BLE_RX             0x14
#define MEGAMUX_LP_GPIO_13_QUAD_DEC1_B             0x20
#define MEGAMUX_LP_GPIO_13_PWM3_OUT                0xf
#define MEGAMUX_LP_GPIO_13_COEX_BLE_RXNTX          0x18
#define MEGAMUX_LP_GPIO_13_QUAD_DEC0_A             0x1d
#define MEGAMUX_LP_GPIO_13_PWM0_OUT                0xc
#define MEGAMUX_LP_GPIO_13_QUAD_DEC1_A             0x1f
#define MEGAMUX_LP_GPIO_13_PWM2_OUT                0xe

/* PinMux macros for LP_GPIO_0 */
#define PINMUX_LP_GPIO_0_GPIO                     ( PIN_LP_GPIO_0<<16 | MUX_LP_GPIO_0_GPIO )
#define PINMUX_LP_GPIO_0_M_I2C0_SCL               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_I2C0_SCL<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART1_CTS              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART1_CTS<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_TX            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_TX<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART0_RTS              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART0_RTS<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART0_RXD              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART0_RXD<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_32KHZ_CLK              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_32KHZ_CLK<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART0_TXD              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART0_TXD<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART1_TXD              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART1_TXD<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_I2C1_SCL               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_I2C1_SCL<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_WLAN_RX           ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_WLAN_RX<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_WLAN_TX           ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_WLAN_TX<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_PWM1_OUT               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_PWM1_OUT<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_QUAD_DEC0_B            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_QUAD_DEC0_B<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART1_RTS              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART1_RTS<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART0_CTS              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART0_CTS<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_UART1_RXD              ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_UART1_RXD<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_I2C1_SDA               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_I2C1_SDA<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_I2C0_SDA               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_I2C0_SDA<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_QUAD_DEC2_A            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_QUAD_DEC2_A<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_QUAD_DEC2_B            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_QUAD_DEC2_B<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_RX            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_RX<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_QUAD_DEC1_B            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_QUAD_DEC1_B<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_PWM3_OUT               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_PWM3_OUT<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_QUAD_DEC0_A            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_QUAD_DEC0_A<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_PWM0_OUT               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_PWM0_OUT<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_QUAD_DEC1_A            ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_QUAD_DEC1_A<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_M_PWM2_OUT               ( PIN_LP_GPIO_0<<16 | MEGAMUX_LP_GPIO_0_PWM2_OUT<<8 | MUX_LP_GPIO_0_MEGAMUX )
#define PINMUX_LP_GPIO_0_SWD_CLK                  ( PIN_LP_GPIO_0<<16 | MUX_LP_GPIO_0_SWD_CLK )
#define PINMUX_LP_GPIO_0_TEST_OUT_0               ( PIN_LP_GPIO_0<<16 | MUX_LP_GPIO_0_TEST_OUT_0 )
/* PinMux macros for LP_GPIO_1 */
#define PINMUX_LP_GPIO_1_GPIO                     ( PIN_LP_GPIO_1<<16 | MUX_LP_GPIO_1_GPIO )
#define PINMUX_LP_GPIO_1_SWD_IO                   ( PIN_LP_GPIO_1<<16 | MUX_LP_GPIO_1_SWD_IO )
#define PINMUX_LP_GPIO_1_M_I2C0_SCL               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_I2C0_SCL<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART1_CTS              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART1_CTS<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_TX            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_TX<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART0_RTS              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART0_RTS<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART0_RXD              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART0_RXD<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_32KHZ_CLK              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_32KHZ_CLK<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART0_TXD              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART0_TXD<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART1_TXD              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART1_TXD<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_I2C1_SCL               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_I2C1_SCL<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_WLAN_RX           ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_WLAN_RX<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_WLAN_TX           ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_WLAN_TX<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_PWM1_OUT               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_PWM1_OUT<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_QUAD_DEC0_B            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_QUAD_DEC0_B<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART1_RTS              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART1_RTS<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART0_CTS              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART0_CTS<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_UART1_RXD              ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_UART1_RXD<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_I2C1_SDA               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_I2C1_SDA<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_I2C0_SDA               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_I2C0_SDA<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_QUAD_DEC2_A            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_QUAD_DEC2_A<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_QUAD_DEC2_B            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_QUAD_DEC2_B<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_RX            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_RX<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_QUAD_DEC1_B            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_QUAD_DEC1_B<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_PWM3_OUT               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_PWM3_OUT<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_QUAD_DEC0_A            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_QUAD_DEC0_A<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_PWM0_OUT               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_PWM0_OUT<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_QUAD_DEC1_A            ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_QUAD_DEC1_A<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_M_PWM2_OUT               ( PIN_LP_GPIO_1<<16 | MEGAMUX_LP_GPIO_1_PWM2_OUT<<8 | MUX_LP_GPIO_1_MEGAMUX )
#define PINMUX_LP_GPIO_1_TEST_OUT_1               ( PIN_LP_GPIO_1<<16 | MUX_LP_GPIO_1_TEST_OUT_1 )
/* PinMux macros for LP_GPIO_2 */
#define PINMUX_LP_GPIO_2_M_I2C0_SCL               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_I2C0_SCL<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART1_CTS              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART1_CTS<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_TX            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_TX<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART0_RTS              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART0_RTS<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART0_RXD              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART0_RXD<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_32KHZ_CLK              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_32KHZ_CLK<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART0_TXD              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART0_TXD<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART1_TXD              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART1_TXD<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_I2C1_SCL               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_I2C1_SCL<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_WLAN_RX           ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_WLAN_RX<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_WLAN_TX           ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_WLAN_TX<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_PWM1_OUT               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_PWM1_OUT<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_QUAD_DEC0_B            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_QUAD_DEC0_B<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART1_RTS              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART1_RTS<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART0_CTS              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART0_CTS<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_UART1_RXD              ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_UART1_RXD<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_I2C1_SDA               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_I2C1_SDA<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_I2C0_SDA               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_I2C0_SDA<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_QUAD_DEC2_A            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_QUAD_DEC2_A<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_QUAD_DEC2_B            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_QUAD_DEC2_B<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_RX            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_RX<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_QUAD_DEC1_B            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_QUAD_DEC1_B<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_PWM3_OUT               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_PWM3_OUT<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_QUAD_DEC0_A            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_QUAD_DEC0_A<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_PWM0_OUT               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_PWM0_OUT<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_QUAD_DEC1_A            ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_QUAD_DEC1_A<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_M_PWM2_OUT               ( PIN_LP_GPIO_2<<16 | MEGAMUX_LP_GPIO_2_PWM2_OUT<<8 | MUX_LP_GPIO_2_MEGAMUX )
#define PINMUX_LP_GPIO_2_SPI_FLASH0_SCK           ( PIN_LP_GPIO_2<<16 | MUX_LP_GPIO_2_SPI_FLASH0_SCK )
#define PINMUX_LP_GPIO_2_TEST_OUT_2               ( PIN_LP_GPIO_2<<16 | MUX_LP_GPIO_2_TEST_OUT_2 )
#define PINMUX_LP_GPIO_2_UART0_RXD                ( PIN_LP_GPIO_2<<16 | MUX_LP_GPIO_2_UART0_RXD )
#define PINMUX_LP_GPIO_2_GPIO                     ( PIN_LP_GPIO_2<<16 | MUX_LP_GPIO_2_GPIO )
#define PINMUX_LP_GPIO_2_SPI0_SCK                 ( PIN_LP_GPIO_2<<16 | MUX_LP_GPIO_2_SPI0_SCK )
/* PinMux macros for LP_GPIO_3 */
#define PINMUX_LP_GPIO_3_UART0_TXD                ( PIN_LP_GPIO_3<<16 | MUX_LP_GPIO_3_UART0_TXD )
#define PINMUX_LP_GPIO_3_SPI0_MOSI                ( PIN_LP_GPIO_3<<16 | MUX_LP_GPIO_3_SPI0_MOSI )
#define PINMUX_LP_GPIO_3_M_I2C0_SCL               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_I2C0_SCL<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART1_CTS              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART1_CTS<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_TX            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_TX<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART0_RTS              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART0_RTS<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART0_RXD              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART0_RXD<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_32KHZ_CLK              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_32KHZ_CLK<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART0_TXD              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART0_TXD<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART1_TXD              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART1_TXD<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_I2C1_SCL               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_I2C1_SCL<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_WLAN_RX           ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_WLAN_RX<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_WLAN_TX           ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_WLAN_TX<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_PWM1_OUT               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_PWM1_OUT<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_QUAD_DEC0_B            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_QUAD_DEC0_B<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART1_RTS              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART1_RTS<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART0_CTS              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART0_CTS<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_UART1_RXD              ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_UART1_RXD<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_I2C1_SDA               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_I2C1_SDA<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_I2C0_SDA               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_I2C0_SDA<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_QUAD_DEC2_A            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_QUAD_DEC2_A<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_QUAD_DEC2_B            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_QUAD_DEC2_B<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_RX            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_RX<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_QUAD_DEC1_B            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_QUAD_DEC1_B<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_PWM3_OUT               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_PWM3_OUT<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_QUAD_DEC0_A            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_QUAD_DEC0_A<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_PWM0_OUT               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_PWM0_OUT<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_QUAD_DEC1_A            ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_QUAD_DEC1_A<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_M_PWM2_OUT               ( PIN_LP_GPIO_3<<16 | MEGAMUX_LP_GPIO_3_PWM2_OUT<<8 | MUX_LP_GPIO_3_MEGAMUX )
#define PINMUX_LP_GPIO_3_SPI_FLASH0_TXD           ( PIN_LP_GPIO_3<<16 | MUX_LP_GPIO_3_SPI_FLASH0_TXD )
#define PINMUX_LP_GPIO_3_TEST_OUT_3               ( PIN_LP_GPIO_3<<16 | MUX_LP_GPIO_3_TEST_OUT_3 )
#define PINMUX_LP_GPIO_3_GPIO                     ( PIN_LP_GPIO_3<<16 | MUX_LP_GPIO_3_GPIO )
/* PinMux macros for LP_GPIO_8 */
#define PINMUX_LP_GPIO_8_M_I2C0_SCL               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_I2C0_SCL<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART1_CTS              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART1_CTS<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_TX            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_TX<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART0_RTS              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART0_RTS<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART0_RXD              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART0_RXD<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_32KHZ_CLK              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_32KHZ_CLK<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART0_TXD              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART0_TXD<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART1_TXD              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART1_TXD<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_I2C1_SCL               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_I2C1_SCL<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_WLAN_RX           ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_WLAN_RX<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_WLAN_TX           ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_WLAN_TX<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_PWM1_OUT               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_PWM1_OUT<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_QUAD_DEC0_B            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_QUAD_DEC0_B<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART1_RTS              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART1_RTS<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART0_CTS              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART0_CTS<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_UART1_RXD              ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_UART1_RXD<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_I2C1_SDA               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_I2C1_SDA<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_I2C0_SDA               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_I2C0_SDA<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_QUAD_DEC2_A            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_QUAD_DEC2_A<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_QUAD_DEC2_B            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_QUAD_DEC2_B<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_RX            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_RX<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_QUAD_DEC1_B            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_QUAD_DEC1_B<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_PWM3_OUT               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_PWM3_OUT<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_QUAD_DEC0_A            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_QUAD_DEC0_A<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_PWM0_OUT               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_PWM0_OUT<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_QUAD_DEC1_A            ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_QUAD_DEC1_A<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_M_PWM2_OUT               ( PIN_LP_GPIO_8<<16 | MEGAMUX_LP_GPIO_8_PWM2_OUT<<8 | MUX_LP_GPIO_8_MEGAMUX )
#define PINMUX_LP_GPIO_8_SPI0_SSN                 ( PIN_LP_GPIO_8<<16 | MUX_LP_GPIO_8_SPI0_SSN )
#define PINMUX_LP_GPIO_8_SPI_FLASH0_SSN           ( PIN_LP_GPIO_8<<16 | MUX_LP_GPIO_8_SPI_FLASH0_SSN )
#define PINMUX_LP_GPIO_8_GPIO                     ( PIN_LP_GPIO_8<<16 | MUX_LP_GPIO_8_GPIO )
#define PINMUX_LP_GPIO_8_I2C0_SDA                 ( PIN_LP_GPIO_8<<16 | MUX_LP_GPIO_8_I2C0_SDA )
#define PINMUX_LP_GPIO_8_TEST_OUT_8               ( PIN_LP_GPIO_8<<16 | MUX_LP_GPIO_8_TEST_OUT_8 )
/* PinMux macros for LP_GPIO_9 */
#define PINMUX_LP_GPIO_9_SPI_FLASH0_RXD           ( PIN_LP_GPIO_9<<16 | MUX_LP_GPIO_9_SPI_FLASH0_RXD )
#define PINMUX_LP_GPIO_9_M_I2C0_SCL               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_I2C0_SCL<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART1_CTS              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART1_CTS<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_MBSY          ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_TX            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_TX<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART0_RTS              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART0_RTS<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART0_RXD              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART0_RXD<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_32KHZ_CLK              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_32KHZ_CLK<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_IN_PROCESS    ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART0_TXD              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART0_TXD<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART1_TXD              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART1_TXD<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_I2C1_SCL               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_I2C1_SCL<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_WLAN_RX           ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_WLAN_RX<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_WLAN_TX           ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_WLAN_TX<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_PWM1_OUT               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_PWM1_OUT<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_QUAD_DEC0_B            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_QUAD_DEC0_B<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART1_RTS              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART1_RTS<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART0_CTS              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART0_CTS<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_UART1_RXD              ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_UART1_RXD<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_PTI_0         ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_PTI_1         ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_PTI_2         ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_PTI_3         ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_I2C1_SDA               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_I2C1_SDA<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_I2C0_SDA               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_I2C0_SDA<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_SYNC          ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_QUAD_DEC2_A            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_QUAD_DEC2_A<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_QUAD_DEC2_B            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_QUAD_DEC2_B<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_RX            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_RX<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_QUAD_DEC1_B            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_QUAD_DEC1_B<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_PWM3_OUT               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_PWM3_OUT<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_COEX_BLE_RXNTX         ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_QUAD_DEC0_A            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_QUAD_DEC0_A<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_PWM0_OUT               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_PWM0_OUT<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_QUAD_DEC1_A            ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_QUAD_DEC1_A<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_M_PWM2_OUT               ( PIN_LP_GPIO_9<<16 | MEGAMUX_LP_GPIO_9_PWM2_OUT<<8 | MUX_LP_GPIO_9_MEGAMUX )
#define PINMUX_LP_GPIO_9_SPI0_MISO                ( PIN_LP_GPIO_9<<16 | MUX_LP_GPIO_9_SPI0_MISO )
#define PINMUX_LP_GPIO_9_I2C0_SCL                 ( PIN_LP_GPIO_9<<16 | MUX_LP_GPIO_9_I2C0_SCL )
#define PINMUX_LP_GPIO_9_GPIO                     ( PIN_LP_GPIO_9<<16 | MUX_LP_GPIO_9_GPIO )
#define PINMUX_LP_GPIO_9_TEST_OUT_9               ( PIN_LP_GPIO_9<<16 | MUX_LP_GPIO_9_TEST_OUT_9 )
/* PinMux macros for LP_GPIO_10 */
#define PINMUX_LP_GPIO_10_GPIO                    ( PIN_LP_GPIO_10<<16 | MUX_LP_GPIO_10_GPIO )
#define PINMUX_LP_GPIO_10_M_I2C0_SCL              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_I2C0_SCL<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART1_CTS             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART1_CTS<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_MBSY         ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_TX           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_TX<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART0_RTS             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART0_RTS<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART0_RXD             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART0_RXD<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_32KHZ_CLK             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_32KHZ_CLK<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_IN_PROCESS   ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART0_TXD             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART0_TXD<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART1_TXD             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART1_TXD<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_I2C1_SCL              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_I2C1_SCL<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_WLAN_RX          ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_WLAN_RX<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_WLAN_TX          ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_WLAN_TX<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_PWM1_OUT              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_PWM1_OUT<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_QUAD_DEC0_B           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_QUAD_DEC0_B<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART1_RTS             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART1_RTS<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART0_CTS             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART0_CTS<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_UART1_RXD             ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_UART1_RXD<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_PTI_0        ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_PTI_1        ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_PTI_2        ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_PTI_3        ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_I2C1_SDA              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_I2C1_SDA<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_I2C0_SDA              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_I2C0_SDA<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_SYNC         ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_QUAD_DEC2_A           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_QUAD_DEC2_A<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_QUAD_DEC2_B           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_QUAD_DEC2_B<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_RX           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_RX<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_QUAD_DEC1_B           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_QUAD_DEC1_B<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_PWM3_OUT              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_PWM3_OUT<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_COEX_BLE_RXNTX        ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_QUAD_DEC0_A           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_QUAD_DEC0_A<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_PWM0_OUT              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_PWM0_OUT<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_QUAD_DEC1_A           ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_QUAD_DEC1_A<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_M_PWM2_OUT              ( PIN_LP_GPIO_10<<16 | MEGAMUX_LP_GPIO_10_PWM2_OUT<<8 | MUX_LP_GPIO_10_MEGAMUX )
#define PINMUX_LP_GPIO_10_TEST_OUT_10             ( PIN_LP_GPIO_10<<16 | MUX_LP_GPIO_10_TEST_OUT_10 )
#define PINMUX_LP_GPIO_10_SPI_FLASH0_SCK          ( PIN_LP_GPIO_10<<16 | MUX_LP_GPIO_10_SPI_FLASH0_SCK )
#define PINMUX_LP_GPIO_10_SPI0_SCK                ( PIN_LP_GPIO_10<<16 | MUX_LP_GPIO_10_SPI0_SCK )
/* PinMux macros for LP_GPIO_11 */
#define PINMUX_LP_GPIO_11_SPI0_MOSI               ( PIN_LP_GPIO_11<<16 | MUX_LP_GPIO_11_SPI0_MOSI )
#define PINMUX_LP_GPIO_11_GPIO                    ( PIN_LP_GPIO_11<<16 | MUX_LP_GPIO_11_GPIO )
#define PINMUX_LP_GPIO_11_M_I2C0_SCL              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_I2C0_SCL<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART1_CTS             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART1_CTS<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_MBSY         ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_TX           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_TX<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART0_RTS             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART0_RTS<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART0_RXD             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART0_RXD<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_32KHZ_CLK             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_32KHZ_CLK<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_IN_PROCESS   ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART0_TXD             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART0_TXD<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART1_TXD             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART1_TXD<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_I2C1_SCL              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_I2C1_SCL<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_WLAN_RX          ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_WLAN_RX<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_WLAN_TX          ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_WLAN_TX<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_PWM1_OUT              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_PWM1_OUT<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_QUAD_DEC0_B           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_QUAD_DEC0_B<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART1_RTS             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART1_RTS<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART0_CTS             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART0_CTS<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_UART1_RXD             ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_UART1_RXD<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_PTI_0        ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_PTI_1        ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_PTI_2        ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_PTI_3        ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_I2C1_SDA              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_I2C1_SDA<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_I2C0_SDA              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_I2C0_SDA<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_SYNC         ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_QUAD_DEC2_A           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_QUAD_DEC2_A<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_QUAD_DEC2_B           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_QUAD_DEC2_B<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_RX           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_RX<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_QUAD_DEC1_B           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_QUAD_DEC1_B<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_PWM3_OUT              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_PWM3_OUT<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_COEX_BLE_RXNTX        ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_QUAD_DEC0_A           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_QUAD_DEC0_A<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_PWM0_OUT              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_PWM0_OUT<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_QUAD_DEC1_A           ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_QUAD_DEC1_A<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_M_PWM2_OUT              ( PIN_LP_GPIO_11<<16 | MEGAMUX_LP_GPIO_11_PWM2_OUT<<8 | MUX_LP_GPIO_11_MEGAMUX )
#define PINMUX_LP_GPIO_11_SPI_FLASH0_TXD          ( PIN_LP_GPIO_11<<16 | MUX_LP_GPIO_11_SPI_FLASH0_TXD )
#define PINMUX_LP_GPIO_11_TEST_OUT_11             ( PIN_LP_GPIO_11<<16 | MUX_LP_GPIO_11_TEST_OUT_11 )
/* PinMux macros for LP_GPIO_12 */
#define PINMUX_LP_GPIO_12_SPI_FLASH0_SSN          ( PIN_LP_GPIO_12<<16 | MUX_LP_GPIO_12_SPI_FLASH0_SSN )
#define PINMUX_LP_GPIO_12_GPIO                    ( PIN_LP_GPIO_12<<16 | MUX_LP_GPIO_12_GPIO )
#define PINMUX_LP_GPIO_12_SPI0_SSN                ( PIN_LP_GPIO_12<<16 | MUX_LP_GPIO_12_SPI0_SSN )
#define PINMUX_LP_GPIO_12_M_I2C0_SCL              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_I2C0_SCL<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART1_CTS             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART1_CTS<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_MBSY         ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_TX           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_TX<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART0_RTS             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART0_RTS<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART0_RXD             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART0_RXD<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_32KHZ_CLK             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_32KHZ_CLK<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_IN_PROCESS   ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART0_TXD             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART0_TXD<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART1_TXD             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART1_TXD<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_I2C1_SCL              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_I2C1_SCL<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_WLAN_RX          ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_WLAN_RX<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_WLAN_TX          ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_WLAN_TX<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_PWM1_OUT              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_PWM1_OUT<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_QUAD_DEC0_B           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_QUAD_DEC0_B<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART1_RTS             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART1_RTS<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART0_CTS             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART0_CTS<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_UART1_RXD             ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_UART1_RXD<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_PTI_0        ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_PTI_1        ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_PTI_2        ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_PTI_3        ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_I2C1_SDA              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_I2C1_SDA<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_I2C0_SDA              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_I2C0_SDA<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_SYNC         ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_QUAD_DEC2_A           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_QUAD_DEC2_A<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_QUAD_DEC2_B           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_QUAD_DEC2_B<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_RX           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_RX<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_QUAD_DEC1_B           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_QUAD_DEC1_B<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_PWM3_OUT              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_PWM3_OUT<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_COEX_BLE_RXNTX        ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_QUAD_DEC0_A           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_QUAD_DEC0_A<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_PWM0_OUT              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_PWM0_OUT<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_QUAD_DEC1_A           ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_QUAD_DEC1_A<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_M_PWM2_OUT              ( PIN_LP_GPIO_12<<16 | MEGAMUX_LP_GPIO_12_PWM2_OUT<<8 | MUX_LP_GPIO_12_MEGAMUX )
#define PINMUX_LP_GPIO_12_TEST_OUT_12             ( PIN_LP_GPIO_12<<16 | MUX_LP_GPIO_12_TEST_OUT_12 )
/* PinMux macros for LP_GPIO_13 */
#define PINMUX_LP_GPIO_13_GPIO                    ( PIN_LP_GPIO_13<<16 | MUX_LP_GPIO_13_GPIO )
#define PINMUX_LP_GPIO_13_SPI_FLASH0_RXD          ( PIN_LP_GPIO_13<<16 | MUX_LP_GPIO_13_SPI_FLASH0_RXD )
#define PINMUX_LP_GPIO_13_M_I2C0_SCL              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_I2C0_SCL<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART1_CTS             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART1_CTS<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_MBSY         ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_MBSY<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_TX           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_TX<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART0_RTS             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART0_RTS<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART0_RXD             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART0_RXD<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_32KHZ_CLK             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_32KHZ_CLK<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_IN_PROCESS   ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_IN_PROCESS<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART0_TXD             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART0_TXD<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART1_TXD             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART1_TXD<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_I2C1_SCL              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_I2C1_SCL<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_WLAN_RX          ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_WLAN_RX<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_WLAN_TX          ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_WLAN_TX<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_PWM1_OUT              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_PWM1_OUT<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_QUAD_DEC0_B           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_QUAD_DEC0_B<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART1_RTS             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART1_RTS<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART0_CTS             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART0_CTS<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_UART1_RXD             ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_UART1_RXD<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_PTI_0        ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_0<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_PTI_1        ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_1<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_PTI_2        ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_2<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_PTI_3        ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_PTI_3<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_I2C1_SDA              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_I2C1_SDA<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_I2C0_SDA              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_I2C0_SDA<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_SYNC         ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_SYNC<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_QUAD_DEC2_A           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_QUAD_DEC2_A<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_QUAD_DEC2_B           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_QUAD_DEC2_B<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_RX           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_RX<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_QUAD_DEC1_B           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_QUAD_DEC1_B<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_PWM3_OUT              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_PWM3_OUT<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_COEX_BLE_RXNTX        ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_COEX_BLE_RXNTX<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_QUAD_DEC0_A           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_QUAD_DEC0_A<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_PWM0_OUT              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_PWM0_OUT<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_QUAD_DEC1_A           ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_QUAD_DEC1_A<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_M_PWM2_OUT              ( PIN_LP_GPIO_13<<16 | MEGAMUX_LP_GPIO_13_PWM2_OUT<<8 | MUX_LP_GPIO_13_MEGAMUX )
#define PINMUX_LP_GPIO_13_SPI0_MISO               ( PIN_LP_GPIO_13<<16 | MUX_LP_GPIO_13_SPI0_MISO )
#define PINMUX_LP_GPIO_13_TEST_OUT_13             ( PIN_LP_GPIO_13<<16 | MUX_LP_GPIO_13_TEST_OUT_13 )

#endif /* _BTLC1000WLCSP_PIO_ */
