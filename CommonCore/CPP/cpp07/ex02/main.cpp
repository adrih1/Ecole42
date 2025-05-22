#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	std::cout << "Testing Array<int>:" << std::endl;
	Array<int> intArray(5);
	for (size_t i = 0; i < intArray.size(); ++i)
	{
		intArray[i] = static_cast<int>(i) * 10;
	}

	std::cout << "intArray elements: ";
	for (size_t i = 0; i < intArray.size(); ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	Array<int> copiedIntArray = intArray;

	intArray[0] = 100;

	std::cout << "After modifying intArray:" << std::endl;
	std::cout << "intArray elements: ";
	for (size_t i = 0; i < intArray.size(); ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "copiedIntArray elements: ";
	for (size_t i = 0; i < copiedIntArray.size(); ++i)
	{
		std::cout << copiedIntArray[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Testing Array<std::string>:" << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";

	std::cout << "strArray elements: ";
	for (size_t i = 0; i < strArray.size(); ++i)
	{
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;

	Array<std::string> assignedStrArray;
	assignedStrArray = strArray;

	assignedStrArray[1] = "C++";

	std::cout << "After modifying assignedStrArray:" << std::endl;
	std::cout << "strArray elements: ";
	for (size_t i = 0; i < strArray.size(); ++i)
	{
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "assignedStrArray elements: ";
	for (size_t i = 0; i < assignedStrArray.size(); ++i)
	{
		std::cout << assignedStrArray[i] << " ";
	}
	std::cout << std::endl
				 << std::endl;

	std::cout << "Testing empty Array<double>:" << std::endl;
	Array<double> emptyArray;
	std::cout << "emptyArray size: " << emptyArray.size() << std::endl;

	try
	{
		emptyArray[0] = 3.14;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Testing out-of-bounds access:" << std::endl;
	Array<int> smallArray(2);
	smallArray[0] = 1;
	smallArray[1] = 2;

	try
	{
		std::cout << "Accessing smallArray[2]: " << smallArray[2] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}