global ft_strcmp

; RDI = 1st argument , RSI = 2e argmuent
ft_strcmp:

.loop:
    mov al, BYTE[rdi]
    mov bl, BYTE[rsi]
    cmp al, bl
    jne .diff ; if different calculate difference
    cmp al, 0 ; check if end of string
    je .equal ; si "\0" s1 == s2
    inc rdi
    inc rsi
    jmp .loop


.diff:
    movsx rax, al ; extend char into signed integer 64 bits
    movsx rbx, bl ; extend char into signed integer 64 bits
    sub rax, rbx
    ret

.equal:
    xor rax,rax
    ret
