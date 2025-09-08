
global ft_strlen

ft_strlen:
    xor rax, rax ; We can also do mov rax, 0  but xor is shorter to encode
    jmp loop_count

loop_count:
    cmp BYTE[rdi + rax], 0;
    je exit 
    inc rax
    jmp loop_count

exit:
    ret
