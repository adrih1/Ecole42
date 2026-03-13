#include "woody.h"

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
