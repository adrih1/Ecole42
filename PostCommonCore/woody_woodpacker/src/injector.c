#include "woody.h"

void injectPayload(void *ptr, t_woody *data)
{
    // 1. On copie le shellcode brut dans la cave
    ft_memcpy((char *)ptr + data->cave_offset, g_shellcode, g_shellcode_size);

    // 2. On pointe exactement sur nos valises vides (calcul absolu depuis la fin)
    uint32_t *jmp_ptr      = (uint32_t *)((char *)ptr + data->cave_offset + g_shellcode_size - 36);
    uint8_t  *key_ptr      = (uint8_t  *)((char *)ptr + data->cave_offset + g_shellcode_size - 16);
    uint32_t *size_ptr     = (uint32_t *)((char *)ptr + data->cave_offset + g_shellcode_size - 8);
    int32_t  *distance_ptr = (int32_t  *)((char *)ptr + data->cave_offset + g_shellcode_size - 4);

    // A. Le saut de retour (Ancien point d'entrée - Adresse de l'instruction qui suit le JMP)
    // L'instruction qui suit le JMP est notre "message", qui commence à -32 octets de la fin.
    *jmp_ptr = (uint32_t)(data->old_entry - (data->cave_vaddr + g_shellcode_size - 32));

    // B. La Clé RC4 (Copie de 8 octets)
    ft_memcpy(key_ptr, data->key, 8);

    // C. La Taille du .text (Cast en uint32_t sur 4 octets)
    *size_ptr = (uint32_t)data->text_size;

    // D. La Distance (Le chemin pour aller de notre shellcode jusqu'au code chiffré)
    // On cast en int32_t (signé) car on va reculer en mémoire : text_vaddr est avant cave_vaddr !
    *distance_ptr = (int32_t)(data->text_vaddr - data->cave_vaddr);
}
