/*
 * Pretty minimal linker script for Rust on STM32F4.
 *
 * Derived from my C++ script and the linker script from Zinc (http://zinc.rs).
 */

/*
 * Mark the Rust-defined ISR_VECTORS table as our entry point.  This defines
 * the root of the linker's reachability analysis for `--gc-sections` and
 * ensures that our code is not eliminated during GC.
 */
ENTRY(ISR_VECTORS)

/*
 * Memory layout for the larger STM32F407 parts.  We pretend that SRAM1/2 are
 * a contiguous region for now.  For information on why you might want to change
 * this, see: http://cliffle.com/article/2015/06/11/matrix/
 */
MEMORY
{
  rom      (rx)  : ORIGIN = 0x00000000, LENGTH = 0x00040000
  ram      (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00008000
}


/*
 * Output section layout.
 */
SECTIONS {
    /* Vector tables */
    .vector : ALIGN(4) {
        /* Reduces writes to NAND flash, which erases to 0xFF. */
        FILL(0xff)

        KEEP(*(.isr_vector))
        KEEP(*(.isr_vector_nvic))
    } > rom

    /* Program code and read-only data. */
    .text : ALIGN(4) {
        FILL(0xff)
        *(.text*)
        *(.rodata .rodata.*)
    } > rom

    /*
     * Initialized data.  Initialized data lives in two places: its LOADADDR
     * is in ROM, but it is accessed at a different address in RAM.  It is
     * the responsibility of runtime startup code to copy the initialization
     * image from the LOADADDR to the ADDR; see _data_load, below.
     */
    .data : ALIGN(4) {
        /* Start of data, for reference by the runtime. */
        _data = .;

        /* Actual data symbols.  Sorting by alignment packs them tighter. */
        *(SORT_BY_ALIGNMENT(.data*))
        /* Round up to a word boundary, so the runtime can use word copies. */
        . = ALIGN(4);

        /* End of data to initialize, for the runtime. */
        _edata = .;
    } > ram AT>rom = 0xff

    /*
     * Uninitialized data.  This should be zeroed by the runtime startup code
     * before use.
     */
    .bss : ALIGN(4) {
        /* Start of area to zero, for reference by the runtime. */
        _bss = .;

        *(.bss*)
        *(COMMON)  /* Not clear that Rust generates COMMON data, but. */
        /* Round up to a word boundary, so the runtime can write whole words. */
        . = ALIGN(4);

        /* End of area to zero, for the runtime. */
        _ebss = .;
    } > ram

    .stack (NOLOAD):
    {
        . = ALIGN(8);
        . = . + 0x2000;
        . = ALIGN(8);
        /* Used by the Rust-defined vector table to determine the initial SP. */
        __STACK_BASE = .;
    }

    /* Explicitly discard sections that we don't need. */
    /DISCARD/ :
    {
        *(.glue_7*)  /* arm-thumb interworking */
        *(.v4_bx)  /* ARMv4 interworking fixup for missing BX */
        *(.vfp11_veneer)  /* VFP11 bugfixes s.a. http://sourceware.org/ml/binutils/2006-12/msg00196.html */
        *(.iplt .igot.plt)  /* STT_GNU_IFUNC symbols */
        *(.rel.*)  /* dynamic relocations */
        *(.ARM.exidx*) /* index entries for section unwinding */
        *(.ARM.extab*) /* exception unwinding information */
    }
}


/* The start of the data initialization image in ROM, for the runtime. */
_data_load = LOADADDR(.data);
