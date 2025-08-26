bits 64
default rel

SECTION .data
    string_test db "salut", 0xA, 0

SECTION .text
    global main
    global strlen
    extern printf

strlen:
    push rbp
    mov rbp, rsp

    mov rdx, 

main:
    ; prologue
    push rbp
    mov rbp, rsp

    ; appel de printf("Hello World!\n");
    lea rdi, [rel msg]   ; 1er argument (format string)
    xor eax, eax         ; printf variadique => RAX doit être 0
    call strlen

    ; appel de exit(0) via syscall
    mov rax, 60          ; numéro du syscall: exit
    xor rdi, rdi         ; code retour = 0
    syscall
