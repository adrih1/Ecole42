#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cmath>

enum DataCategory
{
    CATEGORY_ERROR, 
    CATEGORY_CHARACTER, 
    CATEGORY_INTEGER, 
    CATEGORY_FLOATING, 
    CATEGORY_DOUBLE_PRECISION, 
    CATEGORY_INFINITY
};

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter &operator=(const ScalarConverter &other);
    
    ~ScalarConverter();

    static bool isCharacter(const std::string& input);
    static bool isInteger(const std::string& input);
    static bool isFloat(const std::string& input);
    static bool isDouble(const std::string& input);
    static bool isPseudoLiteral(const std::string &input);


    static void processChar(const std::string &input);
    static void processInt(const std::string &input);
    static void processFloat(const std::string &input);
    static void processDouble(const std::string &input);
    static void processInfinity(const std::string &input);


    static void handleInvalidInput();


public:
    static void convert(const std::string &input);
};

#endif