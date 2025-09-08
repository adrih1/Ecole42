global ft_strcmp

ft_strcmp:
    ; RAX return value
    ; RDI = 1st argument , RSI = 2e argmuent
.loop
    mov al, byte[rdi]
    mov bl, byte[rsi]
    cmp al, bl
    jne .diff ; if different calculate difference
    test al, al ; check if end of string
    je equal ; si "\0" s1 == s2
    inc rdi
    inc rsi
    jmp .loop


.diff
    movsx rax, al ; extend char into signed integer 64 bits
    movsx rbx, bl ; extend char into signed integer 64 bits
    sub rax, rbx
    ret

.equal
    xor rax,rax
    ret

    ;   • a negative value if s1 is less than s2;
    ;   • a positive value if s1 is greater than s2.

