#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>


// Déclarations des fonctions assembleur
size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
char    *ft_strdup(const char *s);
void test_ft_read(void);

void display_test_name(char *s)
{
    int total_width = 30;
    int len = strlen(s);
    int stars_total = total_width - len - 2; // espaces autour du texte
    int stars_left = stars_total / 2;
    int stars_right = stars_total - stars_left;

    printf("\n");
    for (int i = 0; i < total_width; i++)
        printf("*");
    printf("\n");

    for (int i = 0; i < stars_left; i++)
        printf("*");
    printf(" %s ", s);
    for (int i = 0; i < stars_right; i++)
        printf("*");
    printf("\n");

    for (int i = 0; i < total_width; i++)
        printf("*");
    printf("\n");
}

void test_ft_strlen(void)
{
    const char *tests[] = {
        "",
        "a",
        "Hello",
        "Bonjour le monde",
        "1234567890",
        "avec\0un null",
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit."
    };

    size_t i = 0;
    size_t ft_len;
    size_t lib_len;

    display_test_name("STRLEN");
    while (i < sizeof(tests) / sizeof(tests[0]))
    {
        ft_len = ft_strlen(tests[i]);
        lib_len = strlen(tests[i]);

        printf("Test %zu : \"%s\"\n", i + 1, tests[i]);
        printf("  ft_strlen = %zu\n", ft_len);
        printf("  strlen    = %zu\n", lib_len);

        if (ft_len == lib_len)
            printf("  ✅ OK\n\n");
        else
            printf("  ❌ KO\n\n");

        i++;
    }
}

void test_ft_strcpy(void)
{
    struct test_case {
        const char *dest;
        const char *src;
    } tests[] = {
        {"chaine vide", ""},
        {"chaine simple", "Hello"},
        {"chaine avec espaces", "Bonjour le monde"},
        {"chaine avec caracteres speciaux", "123!@#abcXYZ"},
        {"chaine longue", "Lorem ipsum dolor sit amet, consectetur adipiscing elit."},
        {"chaine avec un backslash 0", "Chaine\0 et la ca continue"}
    };

    size_t n_tests = sizeof(tests) / sizeof(tests[0]);

    display_test_name("STRCPY");
    for (size_t i = 0; i < n_tests; i++)
    {
        const char *src = tests[i].src;
        size_t len = strlen(src) + 1;

        char *dest_ft = malloc(len);
        char *dest_lib = malloc(len);

        if (!dest_ft || !dest_lib) {
            printf("Erreur malloc\n");
            return;
        }

        /* Copie avec ft_strcpy et strcpy */
        char *ret_ft = ft_strcpy(dest_ft, src);
        char *ret_lib = strcpy(dest_lib, src);

        printf("\nTest %zu : %s\n", i + 1, tests[i].dest);
        printf("Source: \"%s\"\n", src);
        printf("ft_strcpy: \"%s\"\n", dest_ft);
        printf("strcpy    : \"%s\"\n", dest_lib);

        /* Vérification du contenu */
        if (strcmp(dest_ft, dest_lib) == 0)
            printf("✅ Contenu OK\n");
        else
            printf("❌ Contenu KO\n");

        /* Vérification du retour de ft_strcpy */
        if (ret_ft == dest_ft)
            printf("✅ Retour OK\n");

        else
            printf("❌ Retour KO\n");

        free(dest_ft);
        free(dest_lib);
    }
}

void test_ft_strcmp(void)
{
    struct test_case {
        const char *desc;
        const char *s1;
        const char *s2;
    } tests[] = {
        {"chaînes vides", "", ""},
        {"chaîne identique", "Hello", "Hello"},
        {"différentes", "Hello", "World"},
        {"une est préfixe de l'autre", "Hello", "HelloWorld"},
        {"caractères spéciaux", "123!@#", "123!@#"},
        {"différence à la fin", "abcdx", "abcdz"},
        {"différence au début", "xbc", "abc"},
        {"longue chaîne identique", "Super longue chaine qui ne devrait pas casser normalement si tout se passe bien", "Super longue chaine qui ne devrait pas casser normalement si tout se passe bien"},
        {"longue chaîne différente", "Lorem ipsum dolor", "Lorem ipsum dolor sit a"}
    };

    size_t n_tests = sizeof(tests) / sizeof(tests[0]);

    display_test_name("STRCMP");

    for (size_t i = 0; i < n_tests; i++)
    {
        int ret_ft = ft_strcmp(tests[i].s1, tests[i].s2);
        int ret_lib = strcmp(tests[i].s1, tests[i].s2);

        /* strcmp peut renvoyer un positif ou négatif différent, on vérifie juste le signe */
        int ok = (ret_ft == 0 && ret_lib == 0) ||
                 (ret_ft < 0 && ret_lib < 0) ||
                 (ret_ft > 0 && ret_lib > 0);

        printf("\nTest %zu : %s\n", i + 1, tests[i].desc);
        printf("s1: \"%s\"\n", tests[i].s1);
        printf("s2: \"%s\"\n", tests[i].s2);
        printf("ft_strcmp : %d\n", ret_ft);
        printf("strcmp    : %d\n", ret_lib);
        printf("%s\n", ok ? "✅ OK" : "❌ KO");
    }
}

void test_write()
{
    struct test_case {
        const char *string;
        int fd;
    } tests[] = {
        {"", 1},                         // chaîne vide
        {"", 2},                         // chaîne vide sur stderr
        {"a", 1},                        // caractère simple
        {"Hello, world!", 1},            // chaîne classique
        {"Hello\nWorld\n", 1},           // avec retours à la ligne
        {"0123456789", 1},               // chiffres
        {"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 1},
        {"abcdefghijklmnopqrstuvwxyz", 1},
        {"!@#$%^&*()_+-=", 1},            // caractères spéciaux
        {"test stderr", 2},               // écriture sur stderr
        {NULL, 1},                        // pointeur NULL (doit fail)
    };


    
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);

    display_test_name("WRITE");

    for (size_t i = 0; i < n_tests; i++)
    {
        ssize_t ret_ft;
        ssize_t ret_sys;
        int errno_ft;
        int errno_sys;

        size_t len = tests[i].string ? strlen(tests[i].string) : 5;

        printf("Test %zu | fd=%d | string=%s\n",
               i,
               tests[i].fd,
               tests[i].string ? tests[i].string : "NULL");

        /* ft_write */
        errno = 0;
        printf("ft_write: ");
        fflush(stdout);
        ret_ft = ft_write(tests[i].fd, tests[i].string, len);
        errno_ft = errno;
        printf("\n");

        /* write */
        errno = 0;
        printf("write   : ");
        fflush(stdout);
        ret_sys = write(tests[i].fd, tests[i].string, len);
        errno_sys = errno;
        printf("\n");

        /* comparaison */
        if (ret_ft == ret_sys && errno_ft == errno_sys)
            printf("✅ OK  (ret=%zd, errno=%d)\n", ret_ft, errno_ft);
        else
            printf("❌ KO  ft(ret=%zd errno=%d) | write(ret=%zd errno=%d)\n",
                   ret_ft, errno_ft, ret_sys, errno_sys);

        printf("--------------------------------------------------\n");
    }
}



int main(void)
{
    char buffer[100];
    char buffer2[100];
    const char *str1 = "Hello, world!";
    const char *str2 = "Hello, world!";
    const char *str3 = "Hello, 42!";

    test_ft_strlen();
    test_ft_strcpy();
    test_ft_strcmp();
    test_write();
    test_ft_read();

    return 0;
}
