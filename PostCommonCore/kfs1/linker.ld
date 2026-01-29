/* We define the entry point for the binary. */
/* It corresponds to the '_start' label we declared in boot.s */
ENTRY(_start)

SECTIONS
{
    /* 1. Loading address */
    /* We start at 1 Mo (0x100000). Standard for x86 kernels */
    /* to avoid memory adresses saved for BIOS below. */
    . = 1M;

    .text BLOCK(4K) : ALIGN(4K)
    {
        /* The header Multiboot must be at the very beginning */
        /* so that GRUB can find itr in the first 8Ko. */
        *(.multiboot)
        *(.text)
    }

    /* 3. Initialised data (ex: global variables) */
    .data BLOCK(4K) : ALIGN(4K)
    {
        *(.data)
    }

    /* 4. Uninitialized data (ex: our stack) */
    .bss BLOCK(4K) : ALIGN(4K)
    {
        *(COMMON)
        *(.bss)
    }
}