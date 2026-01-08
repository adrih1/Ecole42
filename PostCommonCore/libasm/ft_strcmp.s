global ft_strcmp

ft_strcmp:
.loop:
    mov al, [rdi]      ; byte from s1
    mov dl, [rsi]      ; byte from s2 (caller-saved)
    cmp al, dl
    jne .diff
    cmp al, 0
    je .equal
    inc rdi
    inc rsi
    jmp .loop

.diff:
    movsx rax, al      ; signed extend s1
    movsx rdx, dl      ; signed extend s2
    sub rax, rdx       ; rax = s1 - s2
    ret

.equal:
    xor rax, rax
    ret
