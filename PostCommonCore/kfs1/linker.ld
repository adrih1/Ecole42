ENTRY(_start)

SECTIONS
{
    /* Start at 1Mo. Standard to avoid BIOS areas. */
    . = 1M;

    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.multiboot)       /* Header Multiboot is placed at the very top. */
        *(.text)
    }

    .rodata BLOCK(4K) : ALIGN(4K) { *(.rodata) } /* REad-only data. */
    .data   BLOCK(4K) : ALIGN(4K) { *(.data)   } /* Initialized data. */
    .bss    BLOCK(4K) : ALIGN(4K) { *(.bss) *(COMMON) } /* Uninitialized data. */
}