#include <unistd.h>
#include <cstring>

class N
{
public:
    int value; 
    char annotation[100]; 

    N (int val)
    {
        value = val; 
    }

    void setAnnotation(char *input)
    {
        memcpy(annotation, input, strlen(input)); 
    }

    int operator+(N& other)
    {
        return this->value + other.value;
    }

    int operator-(N& other)
    {
        return this->value -other.value;
    }
};

int main(int ac, char **av)
{
    if (ac < 3)
        return (1); 

    N a(5); 
    N b(6); 

    a.setAnnotation(av[1]);

    // Forced call on the operators to make sur the compiler doesn't get rid of them
    int r1 = a + b; 
    int r2 = a - b;

    // In the real program the call to our shellcode is made thorugh the EDX addres
    // In C++ we cannot simulate that behavior without assembler code
    // Which is why there isn't code corresponding to that
    return (0); 
}