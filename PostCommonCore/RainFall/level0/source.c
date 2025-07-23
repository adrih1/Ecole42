#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "string.h"
#include <sys/types.h>

int main(int ac, char **av)
{
    int number = atoi(av[1]);
    char **args;
    uid_t uid;
    gid_t gid;

    if (number == 423)
    {
        tab[0] = strdup("/bin/sh");
        tab[1] = 0;
        gid = getgid();
        uid = getuid();
        setresgid(gid, gid, gid);
        setresuid(uid, uid, uid);
        execv("/bin/sh", args);
    }
    else
        fwrite("No !\n", 1, 5, stderr);
    return (0);
}
