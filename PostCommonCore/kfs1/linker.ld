ENTRY(_start)                /* Définit le point de départ du programme. */

SECTIONS
{
    /* On commence à 1 Mo. C'est le standard pour éviter les zones BIOS. */
    . = 1M;

    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.multiboot)       /* On place le Header Multiboot TOUT EN HAUT. */
        *(.text)            /* Puis tout le code. */
    }

    .rodata BLOCK(4K) : ALIGN(4K) { *(.rodata) } /* Données en lecture seule. */
    .data   BLOCK(4K) : ALIGN(4K) { *(.data)   } /* Données initialisées. */
    .bss    BLOCK(4K) : ALIGN(4K) { *(.bss) *(COMMON) } /* Données non-initialisées. */
}