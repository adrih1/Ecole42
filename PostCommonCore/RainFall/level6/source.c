#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void n(void)
{
    system("/bin/cat/ /honme/user/level7/.pass");
    return;
}

void m(void)
{
    puts("Nope");
    return;
}

int main(int ac, char **av)
{
    char *str;
    func_ptr    *func;

    str = (char *)malloc(64);
    func = malloc(4);
    *func = (void *)m;
    strcpy(str, av[1]);
    (**func)();
    return (0);
}