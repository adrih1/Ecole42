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

int findTextSection(void *ptr, Elf64_Ehdr *header, t_woody *data)
{
    // Section Headers
    Elf64_Shdr *shdr = (Elf64_Shdr *)((char *)ptr + header->e_shoff);

    // Shdr[i] doesn't show section name we have to get the string table which itself is a section
    // String Table (dictionnary of names)
    char *strtab = (char *)ptr + shdr[header->e_shstrndx].sh_offset; // shstrdnx (Section Header String Table Index)

    // Loop on all sections
    for (int i = 0; i < header->e_shnum; i++)
    {
        if (ft_strcmp(&strtab[shdr[i].sh_name], ".text") == 0)
        {
            data->text_offset = shdr[i].sh_offset;
            data->text_vaddr = shdr[i].sh_addr;
            data->text_size = shdr[i].sh_size; 

            printf("Section .text found ! Offset: 0x%lx, Vaddr: 0x%lx, Taille: 0x%lx bytes\n", data->text_offset, data->text_vaddr, data->text_size);
            return (0);
        }
    }
    return (-1);
}
