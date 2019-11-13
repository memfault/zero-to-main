MEMORY
{
  rom      (rx)  : ORIGIN = 0x00000000, LENGTH = 0x00040000
  ram      (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00008000
}

STACK_SIZE = 0x2000;

/* Section Definitions */
SECTIONS
{
    .text :
    {
        KEEP(*(.vectors .vectors.*))
        *(.text.*)
        *(.rodata.*)
        _etext = .;
    } > rom

    .gnu_build_id :
    {
        PROVIDE(g_gnu_build_id = .);
        *(.note.gnu.build-id)
    } > rom

    /* .bss section which is used for uninitialized data */
    .bss (NOLOAD) :
    {
        _sbss = . ;
        *(.bss .bss.*)
        *(COMMON)
        _ebss = . ;
    } > ram

    .data :
    {
        _sdata = .;
        *(.data*);
        _edata = .;
    } > ram AT >rom

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
