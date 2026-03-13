#ifndef WOODY_H
# define WOODY_H

# include <elf.h>
# include <stdint.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_woody {
    uint64_t cave_offset; // Offset physique dans le fichier
    uint64_t cave_vaddr;  // Adresse virtuelle pour le CPU
    uint64_t cave_size;   // Cave Size check if shellcode can fit 
    uint64_t old_entry;   // Entry point d'origine pour le saut final
} t_woody;

// Shellcode optimisé : Write "....WOODY...." + JMP relatif
// woody.h
static const unsigned char g_shellcode[] = {
    0x50, 0x57, 0x56, 0x52,                   // push rax, rdi, rsi, rdx
    0x48, 0xc7, 0xc0, 0x01, 0x00, 0x00, 0x00, // mov rax, 1 (syscall write)
    0x48, 0xc7, 0xc7, 0x01, 0x00, 0x00, 0x00, // mov rdi, 1 (stdout)
    
    // LEA RSI, [RIP + 0x12] -> Pointe pile sur le premier '.' du message
    0x48, 0x8d, 0x35, 0x12, 0x00, 0x00, 0x00, 
    
    0x48, 0xc7, 0xc2, 0x0e, 0x00, 0x00, 0x00, // mov rdx, 14 (longueur message)
    0x0f, 0x05,                               // syscall
    
    0x5a, 0x5e, 0x5f, 0x58,                   // pop rdx, rsi, rdi, rax
    
    0xe9, 0x00, 0x00, 0x00, 0x00,             // jmp relatif (sera écrasé par ton code C)
    
    // --- LE MESSAGE ---
    '.', '.', '.', '.', 'W', 'O', 'O', 'D', 'Y', '.', '.', '.', '.', '\n'
};
#endif
