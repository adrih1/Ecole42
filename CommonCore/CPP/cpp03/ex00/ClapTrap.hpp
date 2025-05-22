#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>


class ClapTrap {
private:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;

public:
    ClapTrap(const std::string& name); 
    ~ClapTrap();
    ClapTrap(const ClapTrap& autre);
    ClapTrap& operator=(const ClapTrap& autre);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName() const { return name; }
    int getHitPoints() const { return hitPoints; }
    int getEnergyPoints() const { return energyPoints; }
    int getAttackDamage() const { return attackDamage; }

};

#endif
