#
# Copyright (c) 2009-2010 Atmel Corporation. All rights reserved.
#
# \asf_license_start
#
# \page License
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# 3. The name of Atmel may not be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# 4. This software may only be redistributed and used in connection with an
#    Atmel microcontroller product.
#
# THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
# WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
# EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# \asf_license_stop
#

# Path to top level ASF directory relative to this project directory.
PRJ_PATH = ../../../../../..

# Target CPU architecture: ap, ucr1, ucr2 or ucr3
ARCH = ucr3

# Target part: none, ap7xxx or uc3xxxxx
PART = uc3l064

# Target device flash memory details (used by the avr32program programming
# tool: [cfi|internal]@address
FLASH = internal@0x80000000

# Clock source to use when programming; xtal, extclk or int
PROG_CLOCK = int

# Application target name. Given with suffix .a for library and .elf for a
# standalone application.
TARGET = sensors_unit_tests.elf

# List of C source files.
CSRCS = \
       avr32/boards/uc3_l0_xplained/init.c                \
       avr32/boards/uc3_l0_xplained/led.c                 \
       avr32/drivers/eic/eic.c                            \
       avr32/drivers/flashcdw/flashcdw.c                  \
       avr32/drivers/gpio/gpio.c                          \
       avr32/drivers/intc/intc.c                          \
       avr32/drivers/pm/pm_uc3l.c                         \
       avr32/drivers/pm/power_clocks_lib.c                \
       avr32/drivers/scif/scif_uc3l.c                     \
       avr32/drivers/twim/twim.c                          \
       avr32/drivers/usart/usart.c                        \
       common/boards/sensors_xplained/sensors_xplained.c  \
       common/services/clock/uc3l/dfll.c                  \
       common/services/clock/uc3l/osc.c                   \
       common/services/clock/uc3l/sysclk.c                \
       common/services/sensors/drivers/akm/ak8975.c       \
       common/services/sensors/drivers/bosch/bma020.c     \
       common/services/sensors/drivers/bosch/bma150.c     \
       common/services/sensors/drivers/bosch/bma180.c     \
       common/services/sensors/drivers/bosch/bma220.c     \
       common/services/sensors/drivers/bosch/bma222.c     \
       common/services/sensors/drivers/bosch/bma250.c     \
       common/services/sensors/drivers/bosch/bma_axis.inc.c \
       common/services/sensors/drivers/bosch/bmp.c        \
       common/services/sensors/drivers/honeywell/hmc5883l.c \
       common/services/sensors/drivers/invensense/imu3000.c \
       common/services/sensors/drivers/invensense/itg3200.c \
       common/services/sensors/drivers/kionix/kxtf9.c     \
       common/services/sensors/drivers/osram/sfh5712.c    \
       common/services/sensors/drivers/osram/sfh7770.c    \
       common/services/sensors/physics/physics.c          \
       common/services/sensors/sensor.c                   \
       common/services/sensors/sensor_bus.c               \
       common/services/sensors/sensor_nvram.c             \
       common/services/sensors/sensor_platform.c          \
       common/services/sensors/unit_tests/unit_tests.c    \
       common/services/serial/usart_serial.c              \
       common/services/sleepmgr/uc3/sleepmgr.c            \
       common/utils/stdio/read.c                          \
       common/utils/stdio/write.c                         \
       common/utils/unit_test/suite.c

# List of assembler source files.
ASSRCS = \
       avr32/drivers/intc/exception.S                     \
       avr32/utils/startup/startup_uc3.S                  \
       avr32/utils/startup/trampoline_uc3.S

# List of include paths.
INC_PATH = \
       avr32/boards                                       \
       avr32/boards/uc3_l0_xplained                       \
       avr32/drivers/cpu/cycle_counter                    \
       avr32/drivers/eic                                  \
       avr32/drivers/flashcdw                             \
       avr32/drivers/gpio                                 \
       avr32/drivers/intc                                 \
       avr32/drivers/pm                                   \
       avr32/drivers/scif                                 \
       avr32/drivers/twim                                 \
       avr32/drivers/usart                                \
       avr32/utils                                        \
       avr32/utils/preprocessor                           \
       common/boards                                      \
       common/services/clock                              \
       common/services/delay                              \
       common/services/sensors                            \
       common/services/sensors/module_config              \
       common/services/sensors/unit_tests/at32uc3l064_uc3_l0_xplained_inertial_1 \
       common/services/serial                             \
       common/services/serial/uc3_usart                   \
       common/services/sleepmgr                           \
       common/services/twi                                \
       common/utils                                       \
       common/utils/stdio/stdio_serial \
       common/services/sensors/unit_tests/at32uc3l064_uc3_l0_xplained_inertial_1/gcc

# Additional search paths for libraries.
LIB_PATH = 

# List of libraries to use during linking.
LIBS =  \
       m                                                 

# Path relative to top level directory pointing to a linker script.
LINKER_SCRIPT = avr32/utils/linker_scripts/at32uc3l/064/gcc/link_uc3l064.lds

# Additional options for debugging. By default the common Makefile.in will
# add -g3.
DBGFLAGS = 

# Application optimization used during compilation and linking:
# -O0, -O1, -O2, -O3 or -Os
OPTIMIZATION = -Os

# Extra flags to use when archiving.
ARFLAGS = 

# Extra flags to use when assembling.
ASFLAGS = 

# Extra flags to use when compiling.
CFLAGS = 

# Extra flags to use when preprocessing.
#
# Preprocessor symbol definitions
#   To add a definition use the format "-D name[=definition]".
#   To cancel a definition use the format "-U name".
#
# The most relevant symbols to define for the preprocessor are:
#   BOARD      Target board in use, see boards/board.h for a list.
#   EXT_BOARD  Optional extension board in use, see boards/board.h for a list.
CPPFLAGS = \
       -D BOARD=UC3_L0_XPLAINED                           \
       -D EXT_BOARD=SENSORS_XPLAINED_INERTIAL_1           \
       -D TEST_SUITE_DEFINE_ASSERT_MACRO                  \
       -D _ASSERT_ENABLE_

# Extra flags to use when linking
LDFLAGS = \
       -nostartfiles -Wl,-e,_trampoline

# Pre- and post-build commands
PREBUILD_CMD = 
POSTBUILD_CMD = 