#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

// Déclarations des fonctions assembleur
size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dest, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);

int main(void)
{
    char buffer[100];
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello, world!";
    const char *str3 = "Hello, 42!";

    printf("=== Testing ft_strlen ===\n");
    printf("ft_strlen(\"%s\") = %zu\n", str1, ft_strlen(str1));
    printf("strlen(\"%s\")    = %zu\n\n", str1, strlen(str1));

    printf("=== Testing ft_strcpy ===\n");
    ft_strcpy(buffer, str1);
    printf("ft_strcpy result: %s\n\n", buffer);

    printf("=== Testing ft_strcmp ===\n");
    printf("ft_strcmp(\"%s\", \"%s\") = %d\n", str1, str2, ft_strcmp(str1, str2));
    printf("strcmp(\"%s\", \"%s\")    = %d\n", str1, str2, strcmp(str1, str2));
    printf("ft_strcmp(\"%s\", \"%s\") = %d\n", str1, str3, ft_strcmp(str1, str3));
    printf("strcmp(\"%s\", \"%s\")    = %d\n\n", str1, str3, strcmp(str1, str3));

    printf("=== Testing ft_write ===\n");
    const char *msg = "This is a test of ft_write.\n";
    ssize_t n = ft_write(1, msg, ft_strlen(msg));
    if (n == -1)
        perror("ft_write failed");
    else
        printf("ft_write wrote %zd bytes\n", n);

    return 0;
}
