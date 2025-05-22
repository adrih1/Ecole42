#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << name << " created!" << std::endl;
}


ClapTrap::~ClapTrap() {
    std::cout << name << " destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& autre) : name(autre.name), hitPoints(autre.hitPoints), energyPoints(autre.energyPoints), attackDamage(autre.attackDamage) {
    std::cout << "Copy constructor called for " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& autre) {
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &autre) {
        this->name = autre.name;
        this->hitPoints = autre.hitPoints;
        this->energyPoints = autre.energyPoints;
        this->attackDamage = autre.attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << name << " has insufficient energy or health to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << name << " takes " << amount << " points of damage!" << std::endl;
    hitPoints -= amount;
    if (hitPoints < 0) hitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints > 0 && energyPoints > 0) {
        std::cout << name << " repairs itself, restoring " << amount << " hit points!" << std::endl;
        hitPoints += amount;
        energyPoints--;
    } else {
        std::cout << name << " has insufficient energy or health to repair itself!" << std::endl;
    }
}