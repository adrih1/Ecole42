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
    test rax, rax      ; check rax to see if malloc fails
    jz error        ; if fail we jump to exit
    mov rdi, rax    ; we store rax in rdi because ft_strcpy uses rdi as its *dest
    pop rsi         ; reads stack top value (=*s), writes it in RSI 
    call ft_strcpy
    ret

error:
    pop rsi                 ; clean stack
    mov rdi, ENOMEM         ; errno code
    call __errno_location   ; returns a pointer to erno
    mov [rax], rdi          ; rax holds the adres of erno so we are putting rdi in erno
    xor rax, rax
    ret
