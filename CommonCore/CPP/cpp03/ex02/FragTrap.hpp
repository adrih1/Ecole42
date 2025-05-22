#ifndef FRAGTRAPP_HPP
#define FRAGTRAPP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap 
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &obj);
        ~FragTrap();
        FragTrap &operator=(const FragTrap &obj);

        void highFivesGuys(void);
};

#endif
