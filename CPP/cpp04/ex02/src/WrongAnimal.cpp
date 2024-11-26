#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "Default constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << "WrongAnimal of type " << type << " constructed" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &src) : type(src.type)
{
    std::cout << "WrongAnimal copied" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructed.\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    if (this != &src)
        this->type = src.type;
    std::cout << "Assignation constructor called" << std::endl;
    return *this;
};

void WrongAnimal::makeSound() const
{
    std::cout << "Some generic wrong animal sound" << std::endl;
};

std::string WrongAnimal::getType() const
{
    return this->type;
}