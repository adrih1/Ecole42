#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>


class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(std::string type); 
    Animal(const Animal& autre);

    Animal& operator=(const Animal& autre);

    virtual ~Animal();
    virtual void makeSound() const = 0;

    std::string getType() const;
};

#endif
