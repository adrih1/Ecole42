#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructed!" << std::endl;
}

Cat::Cat(const std::string name) : Animal(name)
{
    std::cout << "Cat named " << name << " constructed.\n";
}

Cat::Cat(const Cat& autre) : Animal(autre)
{
    std::cout << "Cat - Copy constructor called for " << this->type << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed !" << std::endl;
}

Cat& Cat::operator=(const Cat& autre) 
{
    std::cout << "Cat - Copy assignment operator called." << std::endl;
    if (this != &autre) 
        this->type = autre.type;
    return *this;
}

void Cat::makeSound() const 
{
    std::cout << "Meow meow" << std::endl;
}