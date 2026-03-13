#include "woody.h"

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


