#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap 
{
    public:
        FlagTrap();
        FlagTrap(std::string name);
        FlagTrap(const FlagTrap &obj);
        ~FlagTrap();
        FlagTrap &operator=(const FlagTrap &obj);

        void highFivesGuys(void);
};

#endif
