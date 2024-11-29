#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog constructed.\n";
}


Dog::Dog(const std::string name) : Animal(name)
{
	 std::cout << "Dog named " << name << " constructed.\n";
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog copied.\n";
}

Dog::~Dog() {
    std::cout << "Dog destructed.\n";
}

Dog& Dog::operator=(const Dog &src) {
    if (this != &src) {
        Animal::operator=(src);
    }
    std::cout << "Dog assigned.\n";
    return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof!\n";
}