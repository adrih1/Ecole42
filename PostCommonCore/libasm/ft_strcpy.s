global ft_strcpy

ft_strcpy:
    ; RDI = dest, RSI = src
    mov rax, rdi

.loop
    mov dl, BYTE[rsi]
    mov BYTE[rdi], dl
    inc rsi
    inc rdi
    test dl, dl
    jnz .loop  ; jump if non zero, name is counterintuitive it actually doesn't jump if ZF = 1
    ret