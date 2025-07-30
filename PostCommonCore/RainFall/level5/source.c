#include <stdio.h>
#include <stdlib.h>

void o()
{
    system("/bin/sh"); 
    _exit(1); // --> Direct exit (no emptying of the buffers)
}

void n(void)
{
    char buffer[512]; 

    fgets(buffer, 512, stdin); 
    printf(buffer); 
    exit(1); // --> Empties buffers and exits
}

int main(void)
{
    n();
    return (0); 
}