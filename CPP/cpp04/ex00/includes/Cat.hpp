#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"


class Cat  : public Animal
{
public:
    Cat();
    Cat(std::string name); 
    Cat(const Cat& autre);
    Cat& operator=(const Cat& autre);

    ~Cat();

    void makeSound() const;

};

#endif
