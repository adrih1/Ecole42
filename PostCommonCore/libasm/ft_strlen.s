global ft_strlen;

ft_strlen:
    mov rax, 0  ; init rax to 0
    jmp loop_count ; jump to loop_countfunction

loop_count:
    cmp BYTE [rdi + rax], 0
    je  exit                ; je = rdi[rax] == 0- -> exit
    inc rax                 ; increment 
    jmp loop_count

exit: 
    ret                     ; return rax
    xor rcx, rcx ; We can also do mov rax, 0  but xor is shorter to encode

.loop
    cmp BYTE[rdi + rcx], 0;
    je .done 
    inc rcx
    jmp .loop

.done:
    mov rax, rcx
    ret
