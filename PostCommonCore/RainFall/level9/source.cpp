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

    // Appel indirect simulé — en réalité dans le binaire, il se fait via EDX
    // Ici, on ne peut pas le faire sans assembler ou hack, donc on s'arrête là.

    return (0); 
}