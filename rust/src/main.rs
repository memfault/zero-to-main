#![feature(lang_items,start)]
#![no_std]
#![no_main]

/******************************************************************************/

// Items required by some part of core or the runtime.

/// This will be invoked on `panic!`.  We don't currently panic, and there are
/// some pieces missing to enable it (particularly `abort`), but the compiler
/// looks for this when `no_std` is enabled so we have to provide it.
#[lang = "panic_fmt"]
pub extern fn panic_fmt(_msg: core::fmt::Arguments,
                        _file: &'static str,
                        _line: u32) -> ! {
    loop {}
}

/******************************************************************************/

// Application environment.

extern {
    /// This symbol is exported by the linker script, and defines the initial
    /// stack pointer.
    static __STACK_BASE: u32;
}

/// ARMvx-M interrupt and exception handlers are merely functions conforming to
/// the C ABI.
pub type Handler = extern "C" fn();

/// Represents an ARMvx-M exception table.  This is the common table of vectors
/// used for handling interrupts and initializing the processor on -M
/// processors.
///
/// Vectors are described using the `Handler` type, which is merely a function
/// reference.  Most vectors in the table are modeled as `Option<Handler>`,
/// relying on the null pointer optimization to store zero for `None`.
/// Applications that don't use a particular vector can thus omit it.
///
/// Note that processors will typically have a *two-part* vector table: first
/// come the exception vectors (described here), immediately followed by
/// vendor-specific interrupt vectors handled through the NVIC.  We model such
/// tables in two parts, and concatenate them at link time.  Thus, you will not
/// find vendor-specific vectors here.
#[repr(C, packed)]
pub struct ExceptionTable {
    /// ARMvx-M processors load their initial stack pointer from the first word
    /// of the vector table.  This will be the contents of `sp` on entry to
    /// `reset` below.
    ///
    /// Remember that ARM uses a "full descending" stack, so `sp` points to the
    /// most recently *used* cell of the stack.  Thus, the initial `sp` when the
    /// stack is empty often points just past the end of RAM.  We model it here
    /// as a `const` pointer to discourage such an invalid address from being
    /// dereferenced.
    pub initial_stack: *const u32,

    /// Reset vector.  At reset, the processor loads its stack pointer from
    /// `initial_stack` (above) and then enters this function using the ARM
    /// AAPCS C ABI.
    ///
    /// If the function implementing the reset vector returns, we get
    /// architecturally undefined behavior.  We can conveniently model this in
    /// Rust by describing the function as diverging.
    pub reset: unsafe extern "C" fn() -> !,

    // Architecturally defined exception vectors (i.e. those that are
    // vendor-independent) begin here.  The architectural vector table includes
    // five reserved entries.  We model them here as `pub` because certain
    // naughty vendors (looking at you, NXP) have a loose interpretation of the
    // term "reserved" and stuff things into them anyway.

    pub nmi:          Option<Handler>,
    pub hard_fault:   Option<Handler>,
    pub mm_fault:     Option<Handler>,
    pub bus_fault:    Option<Handler>,
    pub usage_fault:  Option<Handler>,
    pub _reserved0:   Option<Handler>,
    pub _reserved1:   Option<Handler>,
    pub _reserved2:   Option<Handler>,
    pub _reserved3:   Option<Handler>,
    pub sv_call:      Option<Handler>,
    pub debug_mon:    Option<Handler>,
    pub _reserved4:   Option<Handler>,
    pub pend_sv:      Option<Handler>,
    pub sys_tick:     Option<Handler>,
}

/// Most programs will have at least one `ExceptionTable` `static`: the one that
/// gets deposited into ROM and read at processor startup.
///
/// To support a `static` `ExceptionTable`, the type must be `Sync`.  It is
/// *almost* `Sync` out of the box.  The exception: the pointer used for the
/// `initial_stack` item.
///
/// To hack around this, we stamp `ExceptionTable` as `Sync`.  This is probably
/// not the right solution.
unsafe impl Sync for ExceptionTable {}


/******************************************************************************/

// Application.

/// This function will be "called" by the processor at reset.  Note that none of
/// the C or Rust environment has been established --- in particular, this
/// function is responsible for initializing any global data it might need!
/// I've currently punted on this for simplicity.
pub unsafe extern fn reset_handler() -> ! {
    loop {}
}

/// For predictability, I've mapped all architectural vectors to this routine.
/// Since we aren't enabling peripherals or faults, we can technically only take
/// NMI and HardFault --- but if someone builds on this code, they might trigger
/// something else.
extern "C" fn trap() { loop {} }

/// The ROM vector table.  This is marked as the program entry point in the
/// linker script, ensuring that any object reachable from this table is
/// preserved in the output binary.
///
/// This is placed in ROM by the linker script because of its assigned
/// `link_section`.  Note that it is not `mut`.
///
/// The `no_mangle` attribute is currently necessary for two reasons:
///
/// 1. To give the table an easily predictable name for use in the linker
///    script.
/// 2. Because `no_mangle` appears to, currently, be the only way to ensure that
///    this symbol is left visible to the linker.
#[no_mangle]
#[link_section=".isr_vector"]
pub static ISR_VECTORS : ExceptionTable = ExceptionTable {
    initial_stack: unsafe { &__STACK_BASE },  // unsafe ref-to-ptr conversion
    reset: reset_handler,

    nmi: Some(trap),
    hard_fault: Some(trap),
    mm_fault: Some(trap),
    bus_fault: Some(trap),
    usage_fault: Some(trap),
    _reserved0: None,
    _reserved1: None,
    _reserved2: None,
    _reserved3: None,
    sv_call: Some(trap),
    debug_mon: Some(trap),
    _reserved4: None,
    pend_sv: Some(trap),
    sys_tick: Some(trap),
};
