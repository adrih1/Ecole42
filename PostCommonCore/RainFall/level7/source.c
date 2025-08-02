#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char c[100]; 


void m(void)
{
    printf("%s - %d\n", c, (int)time(0)); 
    return;
}

int main(int ac, char **av)
{
    void **str1 = malloc(8);  
    void **str2 = malloc(8);  
    FILE *pass;
    

    str1[0] = (void *)1;
    str1[1] = malloc(8);
    
    str2[0] = 2;
    str2[1] = malloc(8);

    strcpy((char *)str1[1], av[1]);
    strcpy((char *)str2[1], av[2]);


    pass = fopen("home/user/level8/.pass", "r");
    fgets(c, 68, pass);
    puts("~~");
    return (0);
}