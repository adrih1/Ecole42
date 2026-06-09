extern malloc
extern ft_strcpy
extern ft_strlen
extern __errno_location

global ft_strdup

; RDI = source string
ft_strdup:
    push r12                ; Align stack   
    mov r12, rdi            ; Save source string because strlen can erase RDI
    call ft_strlen          ; RAX = strlen(src)    
    inc rax                 ; +1 for '\0'    
    mov rdi, rax            ; RDI = size for malloc 
    call malloc            
    test rax, rax
    jz .error    
    mov rdi, rax            ; DEST (return malloc)
    mov rsi, r12            ; SRC =  saved in r12
    call ft_strcpy          ; strcpy's return is the dest pointer in rax
    pop r12                 ; restore r12
    ret                     ; RAX holds the pointer to new string

.error:
    pop r12
    xor rax, rax
    ret