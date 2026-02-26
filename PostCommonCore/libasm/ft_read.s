global ft_read
extern __errno_location 

ft_read:
    ; RDI = fd, RSI = buffer, RDX = count
    mov rax, 0              ; syscall is 0 for read in 64 bits
    syscall                 ; if syscall succeeds, rax will hold the number of bytes read, if not it will hold -erno
    cmp rax, 0
    jl error                ; jump if less than 0 
    ret

error:
    neg rax                 ; transforming negative rax (-erno) value into positive
    push rax
    call __errno_location   ; rax = &errno
    pop rdi
    mov [rax], edi
    mov rax, -1             ; return -1 if error occured in rax
    ret