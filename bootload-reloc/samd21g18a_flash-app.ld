OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

MEMORY
{
  rom      (rx)  : ORIGIN = 0x00010000, LENGTH = 0x00030000
  ram      (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00004000
  eram      (rwx) : ORIGIN = 0x20004000, LENGTH = 0x00004000
}

STACK_SIZE = DEFINED(STACK_SIZE) ? STACK_SIZE : DEFINED(__stack_size__) ? __stack_size__ : 0x1000;

/* Section Definitions */
SECTIONS
{
    .text : AT (ORIGIN(rom))
    {
        . = ALIGN(4);
        _stext = .;
        KEEP(*(.vectors .vectors.*))
        *(.text .text.*)
        *(.rodata .rodata*)
        . = ALIGN(4);
    } > eram

    /* .ARM.exidx is sorted, so has to go in its own output section.  */
    .ARM.exidx : AT (ORIGIN(rom) + SIZEOF(.text))
    {
        PROVIDE_HIDDEN (__exidx_start = .);
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        . = ALIGN(4);
        PROVIDE_HIDDEN (__exidx_end = .);
    } > eram

    _etext = ORIGIN(rom) + SIZEOF(.text) + SIZEOF(.ARM.exidx);

    /* .bss section which is used for uninitialized data */
    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        _sbss = . ;
        *(.bss .bss.*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = . ;
    } > ram

    .data : AT (_etext)
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data .data.*);
        . = ALIGN(4);
        _edata = .;
    } > ram

    /* stack section */
    .stack (NOLOAD):
    {
        . = ALIGN(8);
        _sstack = .;
        . = . + STACK_SIZE;
        . = ALIGN(8);
        _estack = .;
    } > ram

    . = ALIGN(4);
    _end = . ;
}
