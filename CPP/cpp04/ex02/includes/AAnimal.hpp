#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>


class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(std::string type); 
    AAnimal(const AAnimal& autre);

    AAnimal& operator=(const AAnimal& autre);

    virtual ~AAnimal();
    virtual void makeSound() const = 0;

    std::string getType() const;
};

#endif
