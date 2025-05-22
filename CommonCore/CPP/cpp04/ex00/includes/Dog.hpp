#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"


class Dog  : public Animal
{
public:
    Dog();
    Dog(std::string name); 
    Dog(const Dog& autre);
    Dog& operator=(const Dog& autre);
    ~Dog(); 

    void makeSound() const;
};

#endif
