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
PRJ_PATH = ../../../../..

# Target CPU architecture: ap, ucr1, ucr2 or ucr3
ARCH = ucr2

# Target part: none, ap7xxx or uc3xxxxx
PART = uc3a3256

# Target device flash memory details (used by the avr32program programming
# tool: [cfi|internal]@address
FLASH = internal@0x80000000

# Clock source to use when programming; xtal, extclk or int
PROG_CLOCK = int

# Application target name. Given with suffix .a for library and .elf for a
# standalone application.
TARGET = mxt143e_xplained_calc_demo.elf

# List of C source files.
CSRCS = \
       avr32/boards/uc3_a3_xplained/init.c                \
       avr32/boards/uc3_a3_xplained/led.c                 \
       avr32/drivers/flashc/flashc.c                      \
       avr32/drivers/gpio/gpio.c                          \
       avr32/drivers/intc/intc.c                          \
       avr32/drivers/pdca/pdca.c                          \
       avr32/drivers/spi/spi.c                            \
       avr32/drivers/twim/twim.c                          \
       common/applications/mxt143e_xplained_calculator_demo/calculator.c \
       common/applications/mxt143e_xplained_calculator_demo/widget_gui.c \
       common/components/display/ili9341/ili9341.c        \
       common/components/touch/mxt/mxt_device.c           \
       common/services/clock/uc3a3_a4/sysclk.c            \
       common/services/gfx/gfx_generic.c                  \
       common/services/gfx/gfx_ili9341_sdt028atft.c       \
       common/services/gfx/gfx_text.c                     \
       common/services/gfx/sysfont.c                      \
       common/services/spi/uc3_spi/spi_master.c           \
       common/services/wtk/win.c                          \
       common/services/wtk/wtk.c                          \
       common/services/wtk/wtk_basic_frame.c              \
       common/services/wtk/wtk_button.c                   \
       common/services/wtk/wtk_check_box.c                \
       common/services/wtk/wtk_frame.c                    \
       common/services/wtk/wtk_icon.c                     \
       common/services/wtk/wtk_label.c                    \
       common/services/wtk/wtk_plot.c                     \
       common/services/wtk/wtk_progress_bar.c             \
       common/services/wtk/wtk_radio_button.c             \
       common/services/wtk/wtk_slider.c                   \
       common/utils/membag/membag.c

# List of assembler source files.
ASSRCS = \
       avr32/drivers/intc/exception.S                     \
       avr32/utils/startup/startup_uc3.S                  \
       avr32/utils/startup/trampoline_uc3.S

# List of include paths.
INC_PATH = \
       avr32/boards                                       \
       avr32/boards/uc3_a3_xplained                       \
       avr32/drivers/cpu/cycle_counter                    \
       avr32/drivers/flashc                               \
       avr32/drivers/gpio                                 \
       avr32/drivers/intc                                 \
       avr32/drivers/pdca                                 \
       avr32/drivers/spi                                  \
       avr32/drivers/twim                                 \
       avr32/utils                                        \
       avr32/utils/preprocessor                           \
       common/applications/mxt143e_xplained_calculator_demo \
       common/applications/mxt143e_xplained_calculator_demo/at32uc3a256_uc3_a3_xplained \
       common/boards                                      \
       common/components/display/ili9341                  \
       common/components/touch/mxt                        \
       common/services/clock                              \
       common/services/delay                              \
       common/services/gfx                                \
       common/services/ioport                             \
       common/services/spi                                \
       common/services/spi/uc3_spi                        \
       common/services/twi                                \
       common/services/wtk                                \
       common/utils                                       \
       common/utils/membag \
       common/applications/mxt143e_xplained_calculator_demo/at32uc3a256_uc3_a3_xplained/gcc

# Additional search paths for libraries.
LIB_PATH = 

# List of libraries to use during linking.
LIBS = 

# Path relative to top level directory pointing to a linker script.
LINKER_SCRIPT = avr32/utils/linker_scripts/at32uc3a3/256/gcc/link_uc3a3256.lds

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
       -D BOARD=UC3_A3_XPLAINED                           \
       -D CONF_GFX_ILI9341_SDT028ATFT=1

# Extra flags to use when linking
LDFLAGS = \
       -nostartfiles -Wl,-e,_trampoline

# Pre- and post-build commands
PREBUILD_CMD = 
POSTBUILD_CMD = 