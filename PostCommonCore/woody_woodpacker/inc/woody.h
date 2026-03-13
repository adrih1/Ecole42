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

    uint64_t text_offset; // Cipher in the file 
    uint64_t text_vaddr;  // Inform shellcode where to decipher
    uint64_t text_size;   // Exact size of data to decipher
    uint8_t  key[8];
} t_woody;

// Shellcode defined in pyaload.c
extern const unsigned char g_shellcode[];
extern const size_t g_shellcode_size;

// --- elf_parser.c ---
int     check_elf(Elf64_Ehdr *header);
int     prepareHeader(Elf64_Ehdr *header, t_woody *data);
int     findTextSection(void *ptr, Elf64_Ehdr *header, t_woody *data);


// --- elf_patcher.c ---
void    patchSegment(Elf64_Phdr *phdr, size_t payloadSize);
void    patchEntryPoint(Elf64_Ehdr *header, t_woody *data);

// --- injector.c ---
void    injectPayload(void *ptr, t_woody *data);

// --- create_file.c ---
int     createWoodyFile(void *ptr, size_t size);

// --- crypto.c ---
void generate_key(t_woody *data);
void rc4_cipher(void *ptr, t_woody *data);


// --- utils.c ---
void    *ft_memcpy(void *dest, const void *src, size_t n);
int	    ft_strcmp(const char *s1, const char *s2);

#endif
