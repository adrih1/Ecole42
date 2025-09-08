global _start
extern ft_strlen

section .data
    outbuf  db "0", 10       ; pour afficher un chiffre + saut de ligne

section .text
_start:
    mov     rbx, rsp         ; Sauver pointeur de pile
    mov     rdi, [rbx]       ; argc = [rsp]
    cmp     rdi, 1
    jle     .no_args         ; Si argc <= 1, pas d’argument → on sort

    mov     rsi, [rbx+16]    ; argv[1] = [rsp+16]
    mov     rdi, rsi         ; 1er argument dans RDI
    call    ft_strlen         ; longueur dans RAX

    ; Convertir longueur → ASCII (pour une seule chiffre)
    add     rax, '0'
    mov     [outbuf], al

    ; write(1, outbuf, 2)
    mov     rax, 1
    mov     rdi, 1
    lea     rsi, [rel outbuf]
    mov     rdx, 2
    syscall

.no_args:
    ; exit(0)
    mov     rax, 60
    xor     rdi, rdi
    syscall
