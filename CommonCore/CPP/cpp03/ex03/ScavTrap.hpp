#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap 
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &obj);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &obj);

        void attack(std::string const &target);
        void guardGate();
};

#endif
