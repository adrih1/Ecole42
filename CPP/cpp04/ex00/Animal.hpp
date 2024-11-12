#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>
using namespace std;


class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(std::string type); 
    Animal(const Animal& autre);
    ~Animal();
    Animal& operator=(const Animal& autre);

    void makeSound(std::string type);
};

#endif
