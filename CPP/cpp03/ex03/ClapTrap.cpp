#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << name << " ClapTrap(void) constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap(\"" << name << "\") constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& autre) {
    std::cout << "Copy constructor called for " << name << std::endl;
    *this = autre;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& autre) 
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &autre) {
        this->name = autre.name;
        this->hitPoints = autre.hitPoints;
        this->energyPoints = autre.energyPoints;
        this->attackDamage = autre.attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(std::string const &target) 
{
    if (this->hitPoints == 0)
	{
		std::cout << name << " has no hit points left and cannot attack!" << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << name << " has no energy points left and cannot attack!" << std::endl;
		return;
	}
	this->energyPoints -= 1;
    std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is already destroyed and cannot take more damage!" << std::endl;
		return;
	}
	if (amount >= this->hitPoints)
	{
		this->hitPoints = 0;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
		std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
	}
	else
	{
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is destroyed and cannot be repaired!" << std::endl;
		return;
	}
	if (this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy points left and cannot be repaired!" << std::endl;
		return;
	}
	this->energyPoints -= 1;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points! Current hit points: " << hitPoints << std::endl;
}


std::string ClapTrap::getName() const
{
	return name;
}

unsigned int ClapTrap::getHitPoints() const
{
	return hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return attackDamage;
}