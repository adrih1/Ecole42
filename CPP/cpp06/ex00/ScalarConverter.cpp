#include "ScalarConverter.hpp"


// Constructors | Destructors
ScalarConverter::ScalarConverter() {};
ScalarConverter::ScalarConverter(const ScalarConverter &src)  { *this = src; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return *this;
}
ScalarConverter::~ScalarConverter(){}


//Determine Type
bool ScalarConverter::isCharacter(const std::string &input)
{
	return (input.length() == 1 && !std::isdigit(input[0])); 
}

bool ScalarConverter::isInteger(const std::string &input)
{
	char *endPtr; 
	errno = 0;
	long value = std::strtol(input.c_str(), &endPtr, 10);
	return (*endPtr == '\0' && errno == 0 && value >= INT_MIN && value <+ INT_MAX);
}

bool ScalarConverter::isFloat(const std::string &input)
{
	if (input == "nanf" || input== "+inff" || input == "-inff")
		return (true);
	char *endPtr; 
	errno = 0;
	std::strtof(input.c_str(), &endPtr);
	return (*endPtr == 'f' && *(endPtr + 1) == '\0' && errno == 0);
}

bool ScalarConverter::isDouble(const std::string &input)
{
	if (input == "nanf" || input== "+inff" || input == "-inff")
		return (true);
	char *endPtr; 
	errno = 0;
	std::strtod(input.c_str(), &endPtr);
	return (*endPtr == '\0' && errno == 0);
}

bool ScalarConverter::isPseudoLiteral(const std::string &input)
{
	return (input == "+inf" || input== "-inf" || input == "+inff" || input == "-inff");
}

//Conversions
void ScalarConverter::processChar(const std::string &input)
{
	char c = input[0];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;

	float f = static_cast<float>(c);
	std::cout << "float: " << f;
	if (f == std::floor(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	double d = static_cast<double>(c);
	std::cout << "double: " << d;
	if (d == std::floor(d))
		std::cout << ".0";
	std::cout << std::endl;
}


void ScalarConverter::processInt(const std::string &input)
{
	int i = std::atoi(input.c_str());

	if (i >= 32 && i <= 126)
		std::cout << "char : " << static_cast<char>(i) << std::endl; 
	else if (i >= 0 && i < 256)
		std::cout << "char: Non displayale" << std::endl;
	else 
		std::cout << "char: impossible" << std::endl;
	
	std::cout << "int : " << i << std::endl;

	float f = static_cast<float>(i);
	std::cout << "float: " << f;
	if (f == std::floor(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	double d = static_cast<double>(i);
	std::cout << "double: " << d;
	if (d == std::floor(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::processFloat(const std::string &input)
{
	float f = std::strtof(input.c_str(), NULL);

	if (f >= 0 && f <= 127 && std::isprint(static_cast<char>(f)))
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else if (f >= 0 && f < 256)
		std::cout << "char: Non displayable" << std::endl; 
	else 
		std::cout << "char: impossible" << std::endl;
	
	if (f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX) && !std::isnan(f) && !std::isinf(f))
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else 
		std::cout << "int: impossible" << std::endl;

	std::cout << "float: " << f;
	if (f == std::floor(f))
		std::cout << ".0";
	std::cout << std::endl;

	double d = static_cast<double>(f);
	std::cout << "double: " << d;
	if (d == std::floor(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::processDouble(const std::string &input)
{
	double d = std::strtod(input.c_str(), NULL);

	if (d >= 0 && d <= 127 && std::isprint(static_cast<char>(d)))
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else if (d >= 0 && d < 256)
		std::cout << "char: Non displayable" << std::endl; 
	else 
		std::cout << "char: impossible" << std::endl;

	if (d >= static_cast<double>(INT_MIN) && d <= static_cast<double>(INT_MAX) && !std::isnan(d) && !std::isinf(d))
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	float f = static_cast<float>(d);
	std::cout << "float: " << f;
	if (f == std::floor(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << d;
	if (d == std::floor(d))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::processInfinity(const std::string &input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	if (input == "nanf" || input == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (input == "+inff" || input == "+inf")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (input == "-inff" || input == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}


void ScalarConverter::handleInvalidInput()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convert(const std::string &input)
{
	if (input.empty())
	{
		std::cerr << "Error: Empty input provided." << std::endl;
		return;
	}

	DataCategory category = CATEGORY_ERROR;

	if (isCharacter(input))
		category = CATEGORY_CHARACTER;
	else if (isInteger(input))
		category = CATEGORY_INTEGER;
	else if (isFloat(input))
		category = CATEGORY_FLOATING;
	else if (isDouble(input))
		category = CATEGORY_DOUBLE_PRECISION;
	else if (isPseudoLiteral(input))
		category = CATEGORY_INFINITY;

	switch (category)
	{
	case CATEGORY_CHARACTER:
		processChar(input);
		break;
	case CATEGORY_INTEGER:
		processInt(input);
		break;
	case CATEGORY_FLOATING:
		processFloat(input);
		break;
	case CATEGORY_DOUBLE_PRECISION:
		processDouble(input);
		break;
	case CATEGORY_INFINITY:
		processInfinity(input);
		break;
	default:
		handleInvalidInput();
		break;
	}
}