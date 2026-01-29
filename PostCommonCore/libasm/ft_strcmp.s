global ft_strcmp

; RDI = 1st arg | RSI = 2nd arg
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
    ; movsx fills the empty bits with bit signed so that rax only contains the relevant 8 bits of al 
    movsx rax, al      ; move with sign extension s1 
    movsx rdx, dl      ; move with sign extension s2
    sub rax, rdx       ; rax = s1 - s2
    ret

.equal:
    xor rax, rax
    ret
