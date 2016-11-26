# Bootstrapping C (and rust) applications on Cortex-M MCUs

Quick explorations of different ways to bootstrap a GNU C (or rust) application on a cortex-M
based MCU.

While the concepts apply broadly, these examples run on an Arduino M0 Pro (they
should work fine on an Arduino Zero as well).

I chose the M0 Pro because:
  1. It was available at my local electronics shop
  2. It comes with an integrated SWD debugger (Atmel EDBG)
  3. It sports a cortex-M mcu (cortex-M0+)
  4. It is reasonably cheap ($40)

An STM32-based Nucleo or an mbed board would do just as well.

In my experience, many of the techniques highlighted here are often glossed
over, poorly documented, and rarely understood. Most people rely on startup
files and linker scripts bundled with their vendor's BSP that they tweak
haphazardly as their needs evolve.

The following scenarios are currently covered:
  * `default`: simple LED blink using the default startup file & linker script
    from the BSP
  * `minimal`: a bare minimum LED blink app with a pared down script, startup,
    and no libc
  * `with-libc`: builds on `minimal` to add newlib support, including printf
  * `reloc`: builds on `with-libc` to add functions relocated to RAM as well as
    ROM
  * `bootload`: splits the code into two applications, a bootloader and an
    application. The bootloader simply starts the applications
  * `bootload-reloc`: builds on `bootload` but runs the applications entirely in
    RAM. The bootloader thus needs to copy it over first.
  * `rust`: barebones rust app

More to come, and blog posts will follow.

### Dependencies
  * A unix-like environment
  * A version of openOCD that works with your board (in my case I used the
  [Arduino fork](https://github.com/arduino/OpenOCD)).
  * GNU Make
  * [GNU ARM embedded toolchain](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm)

### Building

`make` builds all apps, the resulting elfs and bins are in their respective folders under
`build`

`make <app-name>` builds a specific app. E.g. `make bootload-reloc`

### Flashing

`make flash-<app-name>` flashes a specific app (it needs to have been built
first)

### Credits

* https://github.com/cbiffle/minimal-embedded-rust/ - A minimal embedded rust
  app on cortex-M MCU by @cbiffle

