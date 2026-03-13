#include "woody.h"

// UTILITY FUNCTIONS
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t	i;

    i = 0;
    while (i < n)
    {
        ((char *)dest)[i] = ((char *)src)[i];
        i++;
    }
    return (dest);
}

// WOODY CODE 

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


int createWoodyFile(void *ptr, size_t size)
{
    int out_fd = open("woody", O_CREAT | O_WRONLY | O_TRUNC, 0755);
    if (out_fd < 0)
        return (-1);
    if (write(out_fd,ptr, size) != (ssize_t)size)
    {
        close(out_fd);
        return (-1);
    }
    close(out_fd);
    return (0);
}

void patchSegment(Elf64_Phdr *phdr, size_t payloadSize)
{
    phdr->p_filesz += payloadSize;
    phdr->p_memsz += payloadSize;

}

void patchEntryPoint(Elf64_Ehdr *header, t_woody *data)
{
    header->e_entry = data->cave_vaddr;
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
            if (data->cave_size < sizeof(g_shellcode))
                return (-1);
           
            // Adapt Size for futute injection of shellcode in cave
            patchSegment(&phdr[i], sizeof(g_shellcode));

            // Save entry point and edit to new one
            patchEntryPoint(header, data);
            return (0);
        }
    }
    return (1);
}

void injectPayload(void *ptr, t_woody *data)
{
    // Copy shellcode in cave
    ft_memcpy((char *)ptr + data->cave_offset,g_shellcode ,sizeof(g_shellcode));

    // Calculate offset for jump
    uint32_t jmp_offset = (uint32_t)(data->old_entry - (data->cave_vaddr + sizeof(g_shellcode) - 14));

    // Create pointer that targets 4 last elements of our shellcode
    uint32_t *jmp_ptr = (uint32_t *)((char *)ptr + data->cave_offset + sizeof(g_shellcode) - 18);

    // Writing distance to jump  at the end of our shellcode 
    *jmp_ptr = jmp_offset;

}


int main(int ac, char **av)
{
    if (ac != 2) return (printf("Usage: ./woody_woodpacker <file>\n"), 1);

    int fd = open(av[1], O_RDONLY);
    if (fd < 0) return (perror("Error: Invalid File\n"), 1);

    struct stat st; // Defined in sys/stat (holds the meta data of a file)
    fstat(fd, &st); // Fills st with file info from read file

    void *ptr = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0); // Links memory zone directly to file content
    if (ptr == MAP_FAILED) return (close(fd), 1);

    if(check_elf((Elf64_Ehdr *)ptr) != 0)
    {
        printf("Error: Not a valid ELF64 file\n");
        munmap(ptr, st.st_size); // Free of mmap
        close(fd);
        return (1);
    }

    t_woody data;
    if(prepareHeader((Elf64_Ehdr *)ptr, &data) != 0)
    {
        printf("Error: Could not find executable segment\n");
        munmap(ptr, st.st_size); // Free of mmap
        close(fd);
        return (1);

    }
    
    injectPayload(ptr, &data);

    if (createWoodyFile(ptr, st.st_size) != 0)
    {
        printf("Error: Could not create Woody file\n");
        return(0);
    }
    
    munmap(ptr, st.st_size);
    close(fd);
    return(0);
}
