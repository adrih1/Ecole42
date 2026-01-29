; --- Multiboot Constants ---
MULTIBOOT_MAGIC    equ 0x1BADB002 ; Standard value defined by the multiboot protocol (GRUB looks for that)
MULTIBOOT_PAGE_ALGN equ 1 << 0 ; Alignement
MULTIBOOT_MEM_INFO equ 1 << 1 ; Memory Info
MULTIBOOT_FLAGS    equ MULTIBOOT_PAGE_ALGN | MULTIBOOT_MEM_INFO
MULTIBOOT_CHECKSUM equ -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)

; --- Section Header ---
section .multiboot
    align 4 ; Standard by multiboot must be aligned on 32 bits (4 bytes)
    dd MULTIBOOT_MAGIC
    dd MULTIBOOT_FLAGS
    dd MULTIBOOT_CHECKSUM

; --- Section Stack ---
section .bss
    align 16
    stack_bottom:
        resb 16384 ; 16 Ko for the stack
    stack_top:

; --- Section Code ---
section .text
    global _start       ; Linker Entry point
    extern kernel_main 

_start:
    ; 1. Initialize stack
    mov esp, stack_top

    ; 2. Push the infos from GRUB
    ; ebx holds the addres of the multiboot structure
    ; eax holds the magic number (0x2BADB002)
    push ebx
    push eax

    ; 3. Call the kernel
    call kernel_main

    ; 4. If kernel stops, we block the CPU in a infinite loop
    cli          ; Disables interruptions
.halt:
    hlt          ; Puts CPU in pause
    jmp .halt    ; If interruption wakes it up, we hit re-hlt