global outb
global inb

; outb(port, data)
; Envoie un octet (data) vers un port matériel.
outb:
    mov edx, [esp + 4]    ; Récupère le numéro du port (1er argument)
    mov al, [esp + 8]     ; Récupère la donnée (2ème argument)
    out dx, al            ; Instruction processeur magique
    ret

; inb(port) -> renvoie l'octet lu
inb:
    mov edx, [esp + 4]    ; Port
    xor eax, eax          ; On vide EAX
    in al, dx             ; On lit l'octet du port vers AL
    ret
