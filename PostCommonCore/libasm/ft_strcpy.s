global ft_strcpy

ft_strcpy:
    mov rax, rdi          ; save dest for return

.loop:
    mov dl, [rsi]         ; load byte from src
    mov [rdi], dl         ; store into dest
    inc rsi
    inc rdi
    test dl, dl           ; is byte == 0 ?
    jne .loop
    ret
