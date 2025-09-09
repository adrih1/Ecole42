global ft_write

ft_write:
    ; RDI = fd, RSI = buffer, RDX = count
    mov rax, 0 ; syscall is 0 for read in 64 bits
    syscall
    ret