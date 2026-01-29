global ft_read
extern __errno_location 

ft_read:
    ; RDI = fd, RSI = buffer, RDX = count
    mov rax, 0; syscall is 0 for read in 64 bits
    syscall ; if syscall succeeds, rax will hold the number of bytes read, if not it will hold -erno
    cmp rax, 0
    jl error ; jump if less than 0 
    ret

error:
    neg rax                 ; transforming negative rax (-erno) value into positive
    mov rdi, rax            ; rdi serves as a bufer because rax will take the return of erno location
    call __errno_location  ; returns a pointer to erno
    mov [rax], rdi          ; rax holds the adres of erno so we are putting rdi in erno
    mov rax, -1             ; putting the correct value oif -1 in a write return
    ret