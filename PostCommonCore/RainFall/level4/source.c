#include <stdio.h>
#include <stdlib.h>

int m = 0; 

int p(char *buffer)
{
    print(buffer); 
    return(0); 
}

int n(void)
{
    char buffer[512]; 

    fgets(buffer, 512, stdin);
    p(buffer); 
    if (m == 16930112)
        system("/bin/cat /home/user/level5/.pass"); 
    return(0); 
}

int main()
{
    n();
    return(0);
}