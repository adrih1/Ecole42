global ft_strcpy

ft_strcpy:
    ; RDI = dest, RSI = src
    xor rcx, rcx
    mov rax, rdi

.loop
    mov al, BYTE[rsi + rcx]
    mov BYTE[rdi + rcx], al
    inc rcx
    cmp al, 0
    jne .loop
    ret