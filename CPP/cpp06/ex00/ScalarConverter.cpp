#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>


ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &){}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}
