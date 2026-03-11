global outb
global inb

; outb(port, data)
; Send one byte data to a port 
outb:
    mov edx, [esp + 4]    ; Gets port number (1st argument) 
    mov al, [esp + 8]     ; Gets data (2nd argument) 
    out dx, al            ; Instruction processor 
    ret

; inb(port) -> send the read byte
inb:
    mov edx, [esp + 4]    ; Port
    xor eax, eax          ; Empty EAX
    in al, dx             ; Read  port byte towards AL
    ret
