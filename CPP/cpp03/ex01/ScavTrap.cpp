// ScavTrap.cpp
#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap("default")
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap(void) constructor called for " << this->name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap(\"" << name << "\") constructor called" << std::endl;
}
 
ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap copy constructor called for " << obj.name << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " destroyed!" << std::endl;
}


ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	if (this != &obj)
	{
		ClapTrap::operator=(obj);
		std::cout << "ScavTrap copy assignment operator called for " << obj.name << std::endl;
	}
	return (*this);
}

void ScavTrap::attack(std::string const &target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " is destroyed and cannot attack!" << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " has no energy points left and cannot attack!" << std::endl;
		return;
	}
	this->energyPoints -= 1;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage! "
				<< "Remaining EP: " << energyPoints << std::endl;
}

void ScavTrap::guardGate() {
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " is destroyed and cannot enter Gate keeper mode!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " has entered in Gate keeper mode." << std::endl;
}
