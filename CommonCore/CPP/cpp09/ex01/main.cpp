#include "RPN.hpp"


bool isInteger(double value)
{
    return std::floor(value) == value;
}

void printResult(double result)
{
    if (isInteger(result))
        std::cout << static_cast<int>(result) << std::endl;
    else
        std::cout << std::fixed << std::setprecision(2) << result << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2)
        return (1); 
    try
    {
        RPN rpn;
        double result; 
        result = rpn.evaluate(av[1]);
        printResult(result);
    }
    
    catch (const std::exception& e) 
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0); 
}