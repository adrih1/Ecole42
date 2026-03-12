#include "woody.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <elf.h>
#include <stdlib.h>

int check_elf(Elf64_Ehdr *header)
{
    if (header->e_ident[EI_MAG0] != ELFMAG0 ||
        header->e_ident[EI_MAG1] != ELFMAG1 ||
        header->e_ident[EI_MAG2] != ELFMAG2 ||
        header->e_ident[EI_MAG3] != ELFMAG3)
        {
            return (1); 
            exit(EXIT_FAILURE);
        }
    return (0);
}


int findLoadHeader(Elf64_Ehdr *header, t_woody *data)
{
    int num_segments = header->e_phnum;
    
    // Header (start of file) going to Program Table 
    Elf64_Phdr *phdr = (Elf64_Phdr *)((char *)header + header->e_phoff);  // Cast char to force byte by byte calculation 

    // Save old entry
    data->old_entry = header->e_entry;

    for (int i = 0; i < num_segments; i++)
    {
        // Look for segment of type LOAD (PT_LOAD = 1) and executable (PF_X = 1)
        if (phdr[i].p_type == PT_LOAD && (phdr[i].p_flags & PF_X))
        {
            // Physical Point where we will write shellcode 
            data->cave_offset = phdr[i].p_offset + phdr[i].p_filesz;

            // Virtual Adress where CPU finds shellcode
            data->cave_vaddr = pdhr[i].p_vaddr + phdr[i].p_filesz;

            printf("Cave found at Offset: 0x%lx, VirtAddr: 0x%lx\n", data->cave_offset, data->cave_vaddr);
            return (0);
        }
    }
    return (1);

}

int createWoodyFile(void *ptr, size_t size)
{
    int out_fd;

    out_fd = open("woody", O_CREAT | O_WRONLY | O_TRUNC, 0755);
    if (out_fd < 0)
    {
        perror("Open Woddy");
        return (-1);
    }

    if (write(out_fd,ptr, size) != (ssize_t)size)
    {
        perror("Could not write to Woody file");
        close(out_fd);
        return (-1);
    }
    close(out_fd);
    printf("Created Woody successfully\n");
    return (0);

}

int main(int ac, char **av)
{
    if (ac != 2) 
    {
        printf("Incorrect number of arguments\n");
        return (1);
    }

    int fd = open(av[1], O_RDONLY);
    if (fd < 0) 
    {
        printf("Invalid File\n");
        return (1);
    }

    t_woody data;
    struct stat st; // Defined in sys/stat (holds the meta data of a file)
    fstat(fd, &st); // Fills st with file info from read file

    void *ptr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0); // Links memory zone directly to file content
    if (ptr == MAP_FAILED) return  (1);

    Elf64_Ehdr *header = (Elf64_Ehdr *)ptr;

    if(check_elf(header) != 0)
    {
        printf("It is not a ELF64 file\n");
        munmap(ptr, st.st_size); // Free of mmap
        close(fd);
        return (1);
    }
    printf("It is an ELF64 file\n");
    
    if(findLoadHeader(header, &data) != 0)
    {
        printf("Error: Could not find executable segment\n");
    }
    
    if (createWoodyFile(ptr, st.st_size) != 0)
    {
        munmap(ptr,st.st_size); // Free of mmap
        close(fd);
        return(0);
    }
}
