#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Constructed!" << std::endl;
}

Dog::Dog(const std::string name) : Animal(name)
{
	 std::cout << "Dog named " << name << " constructed.\n";
}

Dog::Dog(const Dog& autre) : Animal(autre)
{
    std::cout << "Dog copied" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destroyed !" << std::endl;
}


Dog& Dog::operator=(const Dog& autre) 
{
    std::cout << "Dog - Copy assignment operator called." << std::endl;
    if (this != &autre) 
        this->type = autre.type;
    return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof!\n";
}