#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *auth = NULL; 
char *service = NULL; 

int main()
{
    char buffer[128];

    while (1)
    {
        printf("%p, %p\n", auth, service);

        if (!fgets(buffer, 128, stdin))
            return (0);
        
        if (strncmp(buffer, "auth", 5) == 0)
        {
            auth = malloc(4);
            *auth = 0; 
            if (strlen(buffer + 5) <= 30)
                strcpy(auth, buffer + 5);
        }
        else if (strncmp(buffer, "reset", 5) == 0)
            free(auth);
        else if (strncmp(buffer, "service", 8) == 0)
            service = strdup(buffer + 8);
        else if (strncmp(buffer, "login", 5) == 0) 
        {
            if (auth && *(auth + 0x20)) 
                system("/bin/sh");
            else
                fwrite("Password:\n", 1, 10, stdout);
        }
    }
}