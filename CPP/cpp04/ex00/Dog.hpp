#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"


class Dog  : public Animal{
private:
    std::string type;

public:
    Dog();
    Dog(std::string name); 
    Dog(const Dog& autre);
    ~Dog();
    Dog& operator=(const Dog& autre);

};

#endif
