#include "../includes/Dog.hpp"

Dog::Dog() : AAnimal("Dog"), brain (new Brain())
{
    std::cout << "Dog Constructed!" << std::endl;
}

Dog::Dog(const std::string name) : AAnimal(name), brain (new Brain())
{
	 std::cout << "Dog named " << name << " constructed.\n";
}

Dog::Dog(const Dog& autre) : AAnimal(autre), brain(new Brain(*autre.brain))
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
        AAnimal::operator=(autre);
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*autre.brain);
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof!\n";
}
