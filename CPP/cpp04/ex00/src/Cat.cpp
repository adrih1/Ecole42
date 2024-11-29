#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
<<<<<<< HEAD
    std::cout << "Cat constructed.\n";
=======
    std::cout << "Cat constructed!" << std::endl;
>>>>>>> 412540f22a7ac7f3ee42edc048d78652fad56b73
}

Cat::Cat(const std::string name) : Animal(name)
{
    std::cout << "Cat named " << name << " constructed.\n";
}

<<<<<<< HEAD
Cat::Cat(const Cat &src) : Animal(src)
{
    std::cout << "Cat copied.\n";
=======
Cat::Cat(const Cat& autre) : Animal(autre)
{
    std::cout << "Cat - Copy constructor called for " << this->type << std::endl;
>>>>>>> 412540f22a7ac7f3ee42edc048d78652fad56b73
}

Cat::~Cat()
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 412540f22a7ac7f3ee42edc048d78652fad56b73
