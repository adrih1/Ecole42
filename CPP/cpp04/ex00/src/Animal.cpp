#include "../includes/Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Default Animal constructor called" << std::endl;
};

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal of type " << type << " constructed" << std::endl;
};

Animal::Animal(const Animal &src) : type(src.type)
{
	std::cout << "Animal copied" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructed.\n";
}

Animal &Animal::operator=(const Animal &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << "Assignation constructor called" << std::endl;
	return *this;
};

void Animal::makeSound() const
{
	std::cout << "Some generic animal sound" << std::endl;
};

std::string Animal::getType() const
{
	return this->type;
}