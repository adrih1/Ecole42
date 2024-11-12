#include "Dog.hpp"

Dog::Dog() 
{
    std::cout << " Dog - Constructor called!" << std::endl;
}

Dog::~Dog()
{
    std::cout << this->type << " destroyed !" << std::endl;
}

Dog::Dog(const Dog& autre)
{
    std::cout << "Dog - Copy constructor called for " << this->type << std::endl;
}

Dog& Dog::operator=(const Dog& autre) 
{
    std::cout << "Dog - Copy assignment operator called." << std::endl;
    if (this != &autre) 
        this->type = autre.type;
    return *this;
}