#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN & other): _stack(other._stack) {}

RPN & RPN::operator = (const RPN & other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN() {}


//Functions
bool RPN::isOperator(const std::string & token)
{
    return (token == "+" || token == "-" || token == "*" || token == "/"); 
}

double RPN::performOperation(const std::string & operation, double operand1, double operand2)
{
    if (operation == "+")
        return (operand1 + operand2);
    if (operation == "-")
        return (operand1 - operand2);
    if (operation == "*")
        return (operand1 * operand2);
    if (operation == "/")
    {
       if (operand2 == 0)
			throw std::runtime_error("Error: Division by zero.");
		return (operand1 / operand2);
	}
	throw std::runtime_error("Invalid operator.");
}

void RPN::validateExpression(const std::string & expression)
{
    if (expression.empty())
        throw std::invalid_argument("Error empty argument"); 
    if (isspace(expression[0]))
        throw std::invalid_argument("Error bad argument syntax"); 
    if (isspace(expression[expression.size() -1]))
        throw std::invalid_argument("Error bad argument syntax (trailing spaces)"); 

    size_t operandCount = 0; 
    size_t operatorCount = 0; 
    size_t spaceCount = 0; 

    for (size_t i = 0; i < expression.size(); i++)
    {
        char c = expression[i]; 

        if (!isdigit(c) && c != '.' && c != '+' && c != '-' && c != '*' && c != '/' && c != ' ')
            throw std::invalid_argument("Error bad argument syntax"); 
        if (isdigit(c))
        {
            size_t numLength = 0; 
            while (i + numLength < expression.size() && isdigit(expression[i + numLength]))
                numLength++;
            if (numLength > 1)
                throw std::invalid_argument("Error: Numbers greater than 9.");

            operandCount++; 
            i += numLength - 1; 
        }
        else if (isOperator(std::string(1, c)))
            operatorCount++;
        else if (isspace(c))
        {
            spaceCount++;
            if (i > 0 && isspace(expression[i - 1]))
                throw std::invalid_argument("Error: Bad argument syntax.");
        }
    }
    if (spaceCount != operandCount + operatorCount - 1)
        throw std::invalid_argument("Error: Bad argument syntax.");
    if (operandCount != operatorCount + 1 || operatorCount == 0)
        throw std::invalid_argument("Error: Operands/Operators.");    
}


double RPN::evaluate(const std::string & expression)
{
    validateExpression(expression); 
    std::istringstream iss(expression);
    std::string token; 

    while (iss >> token)
    {
        if (token.find(',') != std::string::npos)
            throw std::invalid_argument("Error: Invalid character ',' in expression. Use '.' for decimal points."); 

        if (isdigit(token[0]))
        {
            std::stringstream ss(token); 
            double number; 
            ss >> number; 
            _stack.push(number); 
        }
        else if (isOperator(token))
        {
            if (_stack.size() < 2 )
                throw std::invalid_argument("Error: Not enough operands for operation."); 
            double operand2 = _stack.top();
            _stack.pop(); 
            double operand1 = _stack.top(); 
            _stack.pop(); 
            double result = performOperation(token, operand1, operand2); 
            _stack.push(result); 
        }
        else
            throw std::invalid_argument("Error"); 
    }
    if (_stack.size() != 1)
        throw std::invalid_argument("Error: Too many operands left in the stack."); 
    return _stack.top(); 
}