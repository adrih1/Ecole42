#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
<<<<<<< HEAD
	std::cout << "Dog constructed.\n";
}


=======
    std::cout << "Dog Constructed!" << std::endl;
}

>>>>>>> 412540f22a7ac7f3ee42edc048d78652fad56b73
Dog::Dog(const std::string name) : Animal(name)
{
	 std::cout << "Dog named " << name << " constructed.\n";
}

<<<<<<< HEAD
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
=======
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
>>>>>>> 412540f22a7ac7f3ee42edc048d78652fad56b73
    return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof!\n";
}