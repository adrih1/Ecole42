global ft_strlen;

ft_strlen:
    xor rax, rax  ; init rax to 0 shorter than mov 0, rax 

.loop:
    cmp byte [rdi + rax], 0
    je  .done
    inc rax
    jmp .loop

.done:
    ret
