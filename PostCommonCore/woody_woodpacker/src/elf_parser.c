#include "woody.h"

int check_elf(Elf64_Ehdr *header)
{
    if (header->e_ident[EI_MAG0] != ELFMAG0 ||
            header->e_ident[EI_MAG1] != ELFMAG1 ||
            header->e_ident[EI_MAG2] != ELFMAG2 ||
            header->e_ident[EI_MAG3] != ELFMAG3)
        return (1); 
    if (header->e_ident[EI_CLASS] != ELFCLASS64)
        return (1);
    return (0);
}

int prepareHeader(Elf64_Ehdr *header, t_woody *data)
{
    Elf64_Phdr *phdr = (Elf64_Phdr *)((char *)header + header->e_phoff);  // Cast char to force byte by byte calculation 

    // Save old entry
    data->old_entry = header->e_entry;
    for (int i = 0; i < header->e_phnum; i++)
    {
        // Look for segment of type LOAD (PT_LOAD = 1) and executable (PF_X = 1)
        if (phdr[i].p_type == PT_LOAD && (phdr[i].p_flags & PF_X))
        {
            // Physical Point where we will write shellcode 
            data->cave_offset = phdr[i].p_offset + phdr[i].p_filesz;

            // Virtual Adress where CPU finds shellcode
            data->cave_vaddr = phdr[i].p_vaddr + phdr[i].p_filesz;

            // Get Cave size to later check if shellcode fits
            if (i + 1 < header->e_phnum)
                data->cave_size = phdr[i + 1].p_offset - data->cave_offset;
            if (data->cave_size < g_shellcode_size)
                return (-1);
           
            // Adapt Size for futute injection of shellcode in cave
            patchSegment(&phdr[i], g_shellcode_size);

            // Save entry point and edit to new one
            patchEntryPoint(header, data);
            return (0);
        }
    }
    return (1);
}
