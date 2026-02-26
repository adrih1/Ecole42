global ft_write
extern __errno_location 

; RDI = fd, RSI = buffer, RDX = count
ft_write:
    mov rax, 1
    syscall
    cmp rax, 0
    jl error
    ret

error:
    neg rax                 ; RAX = erno positif
    push rax
    call __errno_location   ; returns a pointer to erno in rax 
    pop rdi
    mov [rax], rdi          ; rax holds the address of erno so we are putting rdi in erno
    mov rax, -1             ; putting the correct value oif -1 in a write return
    ret