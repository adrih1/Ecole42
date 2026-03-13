#include "woody.h"

void injectPayload(void *ptr, t_woody *data)
{
    // Copy shellcode in cave
    ft_memcpy((char *)ptr + data->cave_offset,g_shellcode ,g_shellcode_size);

    // Calculate offset for jump
    uint32_t jmp_offset = (uint32_t)(data->old_entry - (data->cave_vaddr + g_shellcode_size - 14));

    // Create pointer that targets 4 last elements of our shellcode
    uint32_t *jmp_ptr = (uint32_t *)((char *)ptr + data->cave_offset + g_shellcode_size - 18);

    // Writing distance to jump  at the end of our shellcode 
    *jmp_ptr = jmp_offset;

}
