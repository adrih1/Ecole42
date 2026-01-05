global ft_strcpy

ft_strcpy:
    ; RDI = dest, RSI = src
    mov rax, rdi        ; sauvegarder dest pour le retour
.loop:
    mov bl, BYTE [rsi]  ; lire un octet de src
    mov BYTE [rdi], bl  ; copier dans dest
    inc rsi
    inc rdi
    cmp bl, 0
    jne .loop
    ret                  ; rax contient toujours dest
