global ft_write
extern __errno_location 

ft_write:
    ; RDI = fd, RSI = buffer, RDX = count
    mov rax, 1; syscall is 1 for write in 64 bits
    syscall
    cmp rax, 0
    jl error
    ret

error:
    neg rax                 ; RAX = erno positif
    mov rdi, rax            ; rdi serves as a bufer because rax will take the return of erno location
    call __errno_location   ; returns a pointer to erno
    mov [rax], rdi          ; rax holds the address of erno so we are putting rdi in erno
    mov rax, -1             ; putting the correct value oif -1 in a write return
    ret