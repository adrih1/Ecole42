#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data originalData;
	originalData.value = 42;

	std::cout << "Original Data address: " << &originalData << std::endl;

	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "Serialized uintptr_t value: " << serialized << std::endl;

	Data *deserializedPtr = Serializer::deserialize(serialized);
	std::cout << "Deserialized Data address: " << deserializedPtr << std::endl;

	if (deserializedPtr == &originalData)
	{
		std::cout << "Success: Deserialized pointer matches the original pointer." << std::endl;
	}
	else
	{
		std::cout << "Error: Deserialized pointer does not match the original pointer." << std::endl;
	}

	std::cout << "Original Data value: " << originalData.value << std::endl;
	std::cout << "Deserialized Data value: " << deserializedPtr->value << std::endl;

	return 0;
}