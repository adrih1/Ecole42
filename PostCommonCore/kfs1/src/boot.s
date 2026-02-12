; --- CONSTANTES MULTIBOOT ---
; Ces valeurs sont définies par le standard Multiboot pour que GRUB nous reconnaisse.
MAGIC       equ 0x1BADB002        ; Le "Magic Number" que GRUB cherche.
ALIGN_PAGE  equ 1 << 0            ; Demande à GRUB d'aligner notre kernel en RAM.
MEM_INFO    equ 1 << 1            ; Demande à GRUB de nous donner une carte de la RAM.
FLAGS       equ ALIGN_PAGE | MEM_INFO ; On combine les options.
CHECKSUM    equ -(MAGIC + FLAGS)  ; La somme MAGIC+FLAGS+CHECKSUM doit valoir 0.

; --- SECTION MULTIBOOT ---
section .multiboot
    align 4             ; Le header doit être aligné sur 32 bits.
    dd MAGIC            ; dd (Define Doubleword) écrit 4 octets.
    dd FLAGS
    dd CHECKSUM

; --- RÉSERVATION DE LA PILE (STACK) ---
section .bss
    align 16            ; La pile doit être alignée sur 16 octets pour le standard x86.
stack_bottom:
    resb 16384          ; On réserve 16 Ko pour la pile.
stack_top:              ; Le pointeur vers le haut de la pile (elle descend vers le bas).

; --- CODE ---
section .text
global _start           ; On expose le point d'entrée au linker.
extern kernel_main      ; On déclare que la fonction kernel_main est dans un autre fichier.

_start:
    mov esp, stack_top  ; On configure le registre de pile. C'est VITAL avant d'appeler du C.
    call kernel_main    ; On saute dans le C.

.halt:                  ; Si kernel_main s'arrête :
    cli                 ; On désactive les interruptions.
    hlt                 ; On met le processeur en pause.
    jmp .halt           ; Boucle de sécurité.