#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Cat  : public Animal
{
    private:
        Brain* brain;

    public:
        Cat();
        Cat(std::string name); 
        Cat(const Cat& autre);
        Cat& operator=(const Cat& autre);

        ~Cat();

        void makeSound() const;
};

#endif
