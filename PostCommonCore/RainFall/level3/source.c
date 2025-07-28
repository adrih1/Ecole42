#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m = 0;
char *s = "/bin/sh";
char *msg = "Wait what?!\n";

void v(void) {
    char buffer[520];

    fgets(buffer, 512, stdin);
    printf(buffer);

    if (m == 64) {
        fwrite(msg, 1, 12, stdout);
        system(s);
    }
}

int main(void) {
    v();
    return (0);
}
