extern malloc
extern ft_strcpy
extern ft_strlen

global ft_strdup

ft_strdup:
    call ft_strlen  ; strlen reads RDI and writes to rax 
    push rdi        ; rdi contains *s so we push it to the stack to use it later
    inc rax         ; rax contains the because of strlen so we increment it
    mov rdi, rax    ; store the len that was in rax into rdi
    call malloc     ; malloc reads the len from rdi, returns a pointer in rax
    cmp rax, 0      ; check rax to see if malloc fails
    jz error        ; if fail we jump to exit
    mov rdi, rax    ; we store rax in rdi because strcpy uses rdi as its *dest
    pop rsi         ; we know that strcpy takes rsi as the *src string, so we put *s into rsi 
    call ft_strcpy
    ret

error:
    neg rax                 ; RAX = erno positif
    mov rdi, rax            ; rdi serves as a bufer because rax will take the return of erno location
    call __errno_location   ; returns a pointer to erno
    mov [rax], rdi          ; rax holds the adres of erno so we are putting rdi in erno
    mov rax, -1             ; putting the correct value oif -1 in a write return
    ret