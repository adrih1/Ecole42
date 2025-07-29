#include <stdlib.h>
#include <stdio.h>

void n(void) 
{
    char buffer[512];

    fgets(buffer, 512, stdin);
    printf(buffer);
    exit(1);
}

int main()
{
    n(); 
    return(0); 
}
