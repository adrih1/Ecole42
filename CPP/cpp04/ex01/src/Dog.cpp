#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog"), brain (new Brain())
{
    std::cout << "Dog Constructed!" << std::endl;
}

Dog::Dog(const std::string name) : Animal(name), brain (new Brain())
{
	 std::cout << "Dog named " << name << " constructed.\n";
}

Dog::Dog(const Dog& autre) : Animal(autre), brain(new Brain(*autre.brain))
{
    std::cout << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
    std::cout << "Dog destroyed !" << std::endl;
}


Dog& Dog::operator=(const Dog& autre) 
{
    std::cout << "Dog - Copy assignment operator called." << std::endl;
    if (this != &autre) 
        Animal::operator=(autre);
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*autre.brain);
    std::cout << "Dog - Copy assignement called" << std::endl;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof!\n";
}
