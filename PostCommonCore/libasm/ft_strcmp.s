global ft_strcmp

; RDI = 1st arg | RSI = 2nd arg
ft_strcmp:

.loop:
    mov al, [rdi]
    mov dl, [rsi]
    cmp al, dl
    jne .diff
    test al,al
    jz .equal
    inc rdi
    inc rsi
    jmp .loop

.diff:
    movzx rax, al      
    movzx rdx, dl
    sub rax, rdx
    ret

.equal:
    xor rax, rax
    ret
