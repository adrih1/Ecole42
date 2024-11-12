#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"


class Cat  : public Animal{
private:
    std::string type;

public:
    Cat();
    Cat(std::string name); 
    Cat(const Cat& autre);
    ~Cat();
    Cat& operator=(const Cat& autre);
};

#endif
