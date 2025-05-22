#include "../includes/AAnimal.hpp"

AAnimal::AAnimal() 
{
    std::cout << "Default AAnimal - Constructor called!" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
	std::cout << "AAnimal of type " << type << " constructed" << std::endl;
};

AAnimal::AAnimal(const AAnimal& autre) : type(autre.type)
{
    std::cout << "AAnimal - Copy constructor called for " << this->type << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destroyed !" << std::endl;
}



AAnimal& AAnimal::operator=(const AAnimal& autre) 
{
    std::cout << "AAnimal - Copy assignment operator called." << std::endl;
    if (this != &autre) 
        this->type = autre.type;
    return *this;
}

void AAnimal::makeSound() const
{
    std::cout << "Some generic animal sound." << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type;
}