#include "../includes/Animal.hpp"

<<<<<<< HEAD
Animal::Animal() : type("Animal")
{
	std::cout << "Default Animal constructor called" << std::endl;
};
=======
Animal::Animal() 
{
    std::cout << "Default Animal - Constructor called!" << std::endl;
}
>>>>>>> 412540f22a7ac7f3ee42edc048d78652fad56b73

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal of type " << type << " constructed" << std::endl;
};

<<<<<<< HEAD
Animal::Animal(const Animal &src) : type(src.type)
{
	std::cout << "Animal copied" << std::endl;
=======
Animal::Animal(const Animal& autre) : type(autre.type)
{
    std::cout << "Animal - Copy constructor called for " << this->type << std::endl;
>>>>>>> 412540f22a7ac7f3ee42edc048d78652fad56b73
}

Animal::~Animal()
{
<<<<<<< HEAD
	std::cout << "Animal destructed.\n";
}

Animal &Animal::operator=(const Animal &src)
{
	if (this != &src)
		this->type = src.type;
	std::cout << "Assignation constructor called" << std::endl;
	return *this;
};

void Animal::makeSound() const
{
	std::cout << "Some generic animal sound" << std::endl;
};
=======
    std::cout << "Animal destroyed !" << std::endl;
}



Animal& Animal::operator=(const Animal& autre) 
{
    std::cout << "Animal - Copy assignment operator called." << std::endl;
    if (this != &autre) 
        this->type = autre.type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Some generic animal sound." << std::endl;
}
>>>>>>> 412540f22a7ac7f3ee42edc048d78652fad56b73

std::string Animal::getType() const
{
	return this->type;
}