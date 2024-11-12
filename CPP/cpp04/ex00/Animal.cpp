#include "Animal.hpp"

Animal::Animal() 
{
    std::cout << " Animal - Constructor called!" << std::endl;
}

Animal::~Animal()
{
    std::cout << this->type << " destroyed !" << std::endl;
}

Animal::Animal(const Animal& autre)
{
    std::cout << "Animal - Copy constructor called for " << this->type << std::endl;
}

Animal& Animal::operator=(const Animal& autre) 
{
    std::cout << "Animal - Copy assignment operator called." << std::endl;
    if (this != &autre) 
        this->type = autre.type;
    return *this;
}

void makeSound(std::string type)
{
    if (type == "Cat")
        std::cout << "Miaow" << std::endl;
    else if (type == "Dog")
        std::cout << "Woof" << std::endl;
    else 
        std::cout << "Weoroegwioh..." << std::endl;
}
