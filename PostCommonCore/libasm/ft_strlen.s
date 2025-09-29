global ft_strlen

ft_strlen:
    mov rax, 0  ; init rax to 0
    jmp loop_count ; jump to loop_countfunction

loop_count:
    cmp BYTE [rdi + rax], 0 ;
    je  exit                ; je = rdi[rax] == 0- -> exit
    inc rax                 ; increment 
    jmp loop_count

exit: 
    ret                     ; return rax


