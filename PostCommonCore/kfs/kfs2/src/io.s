global outb
global inb
global gdt_flush

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

; gdt_flush(&gdt_p)
; Load the GDT and reload every segment register with our selectors
gdt_flush:
    mov eax, [esp + 4]    ; Address of gdt_p (1st argument)
    lgdt [eax]            ; GDTR = {limit, base} -> CPU now uses our GDT
    jmp 0x08:.reload_cs   ; Far jump: only way to reload CS (0x08 = kernel code)
.reload_cs:
    mov ax, 0x10          ; 0x10 = kernel data
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ax, 0x18          ; 0x18 = kernel stack
    mov ss, ax
    ret
