global ft_write

ft_write:
    ; RDI = fd, RSI = buffer, RDX = count
    mov rax, 1 ; syscall is 1 for write in 64 bits
    syscall
    ret 