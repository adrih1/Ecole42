bits 64
default rel ; Use RIP-relative addressing by default

section .text
    global _start

_start:
    ; ==========================================================
    ; 1. SAUVEGARDE DES REGISTRES
    ; ==========================================================
    push rax
    push rdi
    push rsi
    push rdx
    push rcx
    push r8
    push r9
    push r10
    push r11
    push r12    ; On ajoute r12 car on va l'utiliser pour la clé

    ; ==========================================================
    ; 2. LA SIGNATURE : AFFICHER "....WOODY...."
    ; ==========================================================
    mov rax, 1                  ; syscall write
    mov rdi, 1                  ; stdout 
    lea rsi, [rel message]      ; message address
    mov rdx, 14                 ; message length
    syscall

    ; ==========================================================
    ; 3. TROUVER LE CODE CHIFFRÉ
    ; ==========================================================
    mov r8d, dword [rel text_size]        ; R8 = Taille du code à déchiffrer
    
    lea r9, [rel _start]                  ; R9 = Notre position actuelle
    movsxd r10, dword [rel text_distance] ; R10 = Distance vers le .text
    add r9, r10                           ; R9 = Adresse absolue du .text en RAM

    ; ==========================================================
    ; 4. CRÉATION DU TABLEAU RC4 SUR LA PILE
    ; ==========================================================
    sub rsp, 256                ; On creuse un trou de 256 octets (S[256])

    ; ==========================================================
    ; 5. KSA ÉTAPE 1 : INITIALISATION (S[i] = i)
    ; ==========================================================
    xor rcx, rcx                ; i = 0 

.init_loop:
    mov byte [rsp + rcx], cl    ; S[i] = i
    inc rcx                     ; i++
    cmp rcx, 256
    jl .init_loop

    ; ==========================================================
    ; 6. KSA ÉTAPE 2 : LE MÉLANGE AVEC LA CLÉ
    ; ==========================================================
    xor rcx, rcx                ; i = 0 
    xor r11, r11                ; j = 0 
    lea r12, [rel key]          ; R12 pointe sur notre clé secrète

.ksa_loop:
    mov rdx, rcx                
    and rdx, 7                  ; rdx = i % 8

    mov al, byte [rsp + rcx]    ; al = S[i] 
    mov dl, byte [r12 + rdx]    ; dl = key[i % 8] 

    add r11b, al                ; j += S[i]
    add r11b, dl                ; j += key[i % 8] (modulo 256 automatique)

    mov bl, byte [rsp + r11]    ; bl = S[j]
    mov byte [rsp + rcx], bl    ; S[i] = S[j]
    mov byte [rsp + r11], al    ; S[j] = ancien S[i]

    inc rcx
    cmp rcx, 256
    jl .ksa_loop

	; ==========================================================
    ; 6.5. LE HACK MPROTECT (Contourner la sécurité W^X)
    ; ==========================================================
    mov rax, 10                 ; syscall sys_mprotect
    mov rdi, r9                 ; rdi = Adresse du .text (notre cible)
    and rdi, -4096              ; Alignement strict sur la page mémoire (4096 bytes)
    mov rsi, r8                 ; rsi = Taille de la zone (text_size)
    add rsi, 4096               ; Marge de sécurité pour l'alignement
    mov rdx, 7                  ; 7 = PROT_READ | PROT_WRITE | PROT_EXEC
    syscall                     ; On déverrouille le code !

    ; ==========================================================
    ; 7. PRGA : LE DÉCHIFFREMENT (Génération et XOR)
    ; ==========================================================
    xor rcx, rcx                ; i = 0 (on réutilise cl)
    xor r11, r11                ; j = 0 (on réutilise r11b)
    xor r10, r10                ; k = 0 (compteur pour parcourir le fichier)

.prga_loop:
    cmp r10, r8                 ; Est-ce que k == text_size ?
    jge .end_prga               ; Si oui, on a tout déchiffré, on sort !

    ; a) i = (i + 1) % 256
    inc cl                      ; L'incrémentation d'un registre 8 bits fait le modulo toute seule !

    ; b) j = (j + S[i]) % 256
    mov al, byte [rsp + rcx]    ; al = S[i]
    add r11b, al                ; r11b = j + S[i]

    ; c) Swap S[i] et S[j]
    mov bl, byte [rsp + r11]    ; bl = S[j]
    mov byte [rsp + rcx], bl    ; S[i] = S[j]
    mov byte [rsp + r11], al    ; S[j] = ancien S[i]

    ; d) rnd = S[(S[i] + S[j]) % 256]
    mov dl, al                  ; dl = S[i]
    add dl, bl                  ; dl = (S[i] + S[j]) % 256
    movzx rdx, dl               ; On étend 'dl' sur 64 bits (rdx) pour s'en servir d'index proprement
    mov dl, byte [rsp + rdx]    ; dl = Notre octet magique !

    ; e) LE XOR SAUVEUR : text_ptr[k] = text_ptr[k] ^ rnd
    mov al, byte [r9 + r10]     ; On lit 1 octet du vrai programme chiffré
    xor al, dl                  ; BAM ! La collision XOR. L'octet est déchiffré.
    mov byte [r9 + r10], al     ; On réécrit l'octet déchiffré en mémoire

    inc r10                     ; k++
    jmp .prga_loop              ; On passe à l'octet suivant

.end_prga:
    ; ==========================================================
    ; 8. NETTOYAGE ET RESTAURATION
    ; ==========================================================
    add rsp, 256                ; TRÈS IMPORTANT : On détruit l'établi RC4 pour retrouver les registres

    pop r12                     ; /!\ Ordre strictement inverse des 'push' !
    pop r11
    pop r10
    pop r9
    pop r8
    pop rcx
    pop rdx
    pop rsi
    pop rdi
    pop rax

    ; ==========================================================
    ; 9. LE RELAIS : SAUT VERS LE PROGRAMME ORIGINAL
    ; ==========================================================
    db 0xe9, 0x00, 0x00, 0x00, 0x00


; ==========================================================
; --- LES VALISES (Remplies par le Packer C) ---
; ==========================================================
message:
    db "....WOODY....", 10, 0, 0   ; 16 octets pile

key:
    dq 0x0000000000000000            ; 8 octets

text_size:
    dd 0x00000000                    ; 4 octets

text_distance:
    dd 0x00000000                    ; 4 octets
