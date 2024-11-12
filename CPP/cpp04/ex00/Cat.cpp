#include "Cat.hpp"

Cat::Cat() 
{
    std::cout << " Cat - Constructor called!" << std::endl;
}

Cat::~Cat()
{
    std::cout << this->type << " destroyed !" << std::endl;
}

Cat::Cat(const Cat& autre)
{
    std::cout << "Cat - Copy constructor called for " << this->type << std::endl;
}

Cat& Cat::operator=(const Cat& autre) 
{
    std::cout << "Cat - Copy assignment operator called." << std::endl;
    if (this != &autre) 
        this->type = autre.type;
    return *this;
}