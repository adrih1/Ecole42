#include "woody.h"

void generate_key(t_woody *data)
{
    int fd  = open("/dev/urandom", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening /dev/urandom");
        exit(1);
    }
    if (read(fd, data->key, 8) != 8 )
    {
        perror("Error reading random bytes");
        close(fd);
        exit(1);
    }
    close(fd);

    printf("Key: 0x");
    for (int i = 0; i < 8; i++)
        printf("%02x", data->key[i]);
    printf("\n");

}

void rc4_cipher(void *ptr, t_woody *data)
{
    uint8_t S[256]; 

    for (int i = 0; i < 256; i++)
        S[i] = i;

    int j = 0;
    for (int i = 0; i < 256; i++)
    {
        j = (j + S[i] + data->key[i % 8]) % 256;
        uint8_t tmp = S[i];
        S[i] = S[j];
        S[j] = tmp;
    }

    int i = 0;
    j = 0;

    uint8_t *text_ptr = (uint8_t *)((char *)ptr + data->text_offset);
    for (size_t k = 0; k < data->text_size; k++)
    {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;

        uint8_t tmp = S[i];
        S[i] = S[j];
        S[j] = tmp;

        uint8_t rnd = S[(S[i] + S[j]) % 256];
        text_ptr[k] = text_ptr[k] ^ rnd;
    }
}
