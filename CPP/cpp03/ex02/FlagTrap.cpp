// ScavTrap.cpp
#include "FlagTrap.hpp"


FlagTrap::FlagTrap() : ClapTrap("default")
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FlagTrap(void) constructor called for " << this->name << std::endl;
}

FlagTrap::FlagTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FlagTrap(\"" << name << "\") constructor called" << std::endl;
}
 
FlagTrap::FlagTrap(const FlagTrap &obj) : ClapTrap(obj)
{
	std::cout << "FlagTrap copy constructor called for " << obj.name << std::endl;
}

FlagTrap::~FlagTrap() {
    std::cout << "FlagTrap " << name << " destroyed!" << std::endl;
}


FlagTrap &FlagTrap::operator=(const FlagTrap &obj)
{
	if (this != &obj)
	{
		ClapTrap::operator=(obj);
		std::cout << "FlagTrap copy assignment operator called for " << obj.name << std::endl;
	}
	return (*this);
}

void highFivesGuys(void)
{
		std::cout << "FlagTrap did a high five " << std::endl;

}


