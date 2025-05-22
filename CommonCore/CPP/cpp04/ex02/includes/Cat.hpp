#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"


class Cat  : public AAnimal
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
