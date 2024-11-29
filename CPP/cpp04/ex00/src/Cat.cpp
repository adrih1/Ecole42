#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructed.\n";
}

Cat::Cat(const std::string name) : Animal(name)
{
    std::cout << "Cat named " << name << " constructed.\n";
}

Cat::Cat(const Cat &src) : Animal(src)
{
    std::cout << "Cat copied.\n";
}

Cat::~Cat()
{
    std::cout << "Cat destructed.\n";
}

Cat &Cat::operator=(const Cat &src)
{
    if (this != &src)
        Animal::operator=(src);
    std::cout << "Cat assigned.\n";
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow meow!\n";
}
