#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cmath>
#include <iomanip>

class RPN
{
private:
    std::stack<double> _stack;
    bool isOperator(const std::string & token);
    double performOperation(const std::string & operation, double operand1, double operand2);
    void validateExpression(const std::string & expression);

public:
    RPN();
    RPN(const RPN & other);
    RPN & operator = (const RPN & other);
    ~RPN();

    double evaluate(const std::string & expression);
};


#endif