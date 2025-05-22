#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog  : public AAnimal
{
    private:
        Brain *brain;

    public:
        Dog();
        Dog(std::string name); 
        Dog(const Dog& autre);
        Dog& operator=(const Dog& autre);
        ~Dog(); 

        void makeSound() const;
};
#endif
