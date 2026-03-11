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


int findLoadHeader(Elf64_Ehdr *header)
{
    int num_segments = header->e_phnum;

    Elf64_Phdr *phdr = (Elf64_Phdr *)((char *)header + header->e_phoff);

    printf("Number of segments: %d\n", num_segments);

    for (int i = 0; i < num_segments; i++)
    {
        // Look for segment of type LOAD (PT_LOAD = 1)
        if (phdr[i].p_type == PT_LOAD)
        {
            // And executable (PF_X = 1)
            if (phdr[i].p_flags & PF_X)
            {
                printf("Segment LOAD Executable found (index %d) :\n", i);
                printf("  Offset file : 0x%lx\n", phdr[i].p_offset);
                printf("  Address Virtual : 0x%lx\n", phdr[i].p_vaddr);
                printf("  Size in the file: %ld bytes\n", phdr[i].p_filesz);
                
                // C'est ici que tu peux calculer la "cave"
                // cave_start = phdr[i].p_offset + phdr[i].p_filesz;
            }
        }
    }
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
    if (fd < 0) return (1);


    struct stat st; // Define in sys/stat (holds the meta data of a file)
    fstat(fd, &st); // Fills st with file info from read file

    void *ptr = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0); // Links memory zone directly to file content
    if (ptr == MAP_FAILED) return  (1);

    Elf64_Ehdr *header = (Elf64_Ehdr *)ptr;
    findLoadHeader(header);

    if(check_elf(header) != 1)
        printf("It is a ELF64 file\n");
    else 
    {
        printf("It is not a ELF64 file\n");
        exit (EXIT_FAILURE);
    }    

    munmap(ptr,st.st_size); // Free of mmap
    close(fd);
    return(0);
}
