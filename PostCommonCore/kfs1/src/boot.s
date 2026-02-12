; --- MULTIBOOT ---
; Values feined by the standard Multiboot so GRUB recognizes this as a boot.
MAGIC       equ 0x1BADB002
ALIGN_PAGE       equ 1 << 0     
MEMINFO     equ 1 << 1           
FLAGS       equ ALIGN_PAGE | MEMINFO 
CHECKSUM    equ -(MAGIC + FLAGS) 

; --- SECTION MULTIBOOT ---
section .multiboot
    align 4            ; Header must be aligned on 32 bits.
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

; --- STACK ---
section .bss
    align 16            ; Stack must be aligned on 16 bytes for standard x86.
stack_bottom:
    resb 16384          ; Save 16 Ko for stack.
stack_top:

; --- CODE ---
section .text
global _start           ; Entry point for the linker.
extern kernel_main

_start:
    mov esp, stack_top  ; Configurate Stack register.
    call kernel_main

.halt:                  ; If kernel_main stops :
    cli                 ; Remove interruptions.
    hlt                 ; Process is paused.
    jmp .halt           ; Safety loop.