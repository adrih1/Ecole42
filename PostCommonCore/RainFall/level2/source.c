#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void p() {
   
    char buffer[76]; // Declare a local buffer of 76 bytes (0x4C)

    fflush(stdout);  // Flush the output buffer to make sure everything is printed
    gets(buffer);
    void *ret_addr = __builtin_return_address(0);  // Get the return address of this function (location the function will return to)

    // Check if the return address starts with 0xB (mask 0xB0000000)
    if (((unsigned int)ret_addr & 0xB0000000) == 0xB0000000) {
        printf("Error: %p\n", ret_addr);
        _exit(1);
    }
    puts(buffer);   // Print the contents of the buffer (reprints user input)
    strdup(buffer); // This copies the buffer via malloc, which we exploit
}


int main()
{
    p();
    return (0);
}