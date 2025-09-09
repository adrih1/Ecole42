extern malloc
extern ft_strcpy

section .text
    global ft_strdup


ft_strdup:
    ; RDI = s, RAX = new_string
    ; return pointer to a new string which is the copy of the passed string
    mov rax, rdi

.loop
    mov dl, BYTE[rdi]
    mov BYTE[rdi], dl
    inc rsi
    inc rdi
    test dl, dl