#include "../includes/Animal.hpp"

Animal::Animal() 
{
    std::cout << "Default Animal - Constructor called!" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal of type " << type << " constructed" << std::endl;
};

Animal::Animal(const Animal& autre) : type(autre.type)
{
    std::cout << "Animal - Copy constructor called for " << this->type << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destroyed !" << std::endl;
}



Animal& Animal::operator=(const Animal& autre) 
{
    std::cout << "Animal - Copy assignment operator called." << std::endl;
    if (this != &autre) 
        this->type = autre.type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Some generic animal sound." << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}