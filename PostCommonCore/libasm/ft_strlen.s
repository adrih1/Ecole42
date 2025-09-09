global ft_strlen

ft_strlen:
    xor rcx, rcx ; We can also do mov rax, 0  but xor is shorter to encode

.loop
    cmp BYTE[rdi + rcx], 0;
    je .done 
    inc rcx
    jmp .loop

.done:
    mov rax, rcx
    ret
