#include <stdio.h>
#include <stdlib.h>

int		run(void)
{
	fwrite("Good... Wait what?\n", 19, 1, stdout);
	return (system("/bin/sh"));
}

int		main(void)
{
    // sub $0x50, %esp → on réserve 80 octets sur la pile pour les variables locales
    // 64 octets pour le buffer | 16 de padding
    // Or esp + 0x10, il reste 80 - 16 = 64  (0x50 - 0x10 = 64)
	char	buffer[64];   

	gets(buffer);
	return (0);
}