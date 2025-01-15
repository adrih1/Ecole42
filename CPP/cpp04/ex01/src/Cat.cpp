#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
    std::cout << "Cat constructed!" << std::endl;
}

Cat::Cat(const std::string name) : Animal(name), brain(new Brain())
{
    std::cout << "Cat named " << name << " constructed.\n";
}

Cat::Cat(const Cat& autre) : Animal(autre), brain(new Brain(*autre.brain))
{
    std::cout << "Cat copied" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
    std::cout << "Cat destroyed !" << std::endl;
}

Cat& Cat::operator=(const Cat& autre) 
{
    std::cout << "Cat - Copy assignment operator called." << std::endl;
    if (this != &autre) 
        Animal::operator=(autre);
    if (this->brain)
		delete this->brain;
	this->brain = new Brain(*autre.brain);
    return *this;
}

void Cat::makeSound() const 
{
    std::cout << "Meow meow" << std::endl;
}