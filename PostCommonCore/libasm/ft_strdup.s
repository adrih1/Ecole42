extern malloc
extern ft_strcpy
extern ft_strlen
extern __errno_location
%define ENOMEM 12

global ft_strdup

ft_strdup:
    call ft_strlen  ; rax = ft_strlen(s)
    push rdi        ; rdi contains *s so push to stack to use it later
    inc rax         ; +1 for "\0"
    mov rdi, rax    ; store the len that was in rax into rdi
    call malloc     ; malloc reads the len from rdi, returns a pointer in rax
    cmp rax, 0      ; check rax to see if malloc fails
    jz error        ; if fail we jump to exit
    mov rdi, rax    ; we store rax in rdi because strcpy uses rdi as its *dest
    pop rsi         ; we know that strcpy takes rsi as the *src string, so we put *s into rsi 
    call ft_strcpy
    ret

error:
    pop rsi                 ; restore original s
    mov rdi, ENOMEM         ; errno code
    call __errno_location   ; returns a pointer to erno
    mov [rax], rdi          ; rax holds the adres of erno so we are putting rdi in erno
    mov rax, -1             ; putting the correct value of -1 in a write return
    ret
