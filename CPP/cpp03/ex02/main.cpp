#include "FragTrap.hpp"

int main()
{
    FragTrap walter("Walter");
    FragTrap gustavo("Gustavo");
    std::cout << "\nInitial State" << std::endl;
    std::cout << "Energy Points: " << walter.getEnergyPoints() 
    << " || " << "Energy Points: " << walter.getEnergyPoints()
    << " || " << "Attack Damage: " << walter.getAttackDamage() << std::endl;

    walter.highFivesGuys();
    gustavo.attack(walter.getName());
    walter.takeDamage(gustavo.getAttackDamage());
    
    std::cout << "End of test\n" << std::endl;
    return (0);
}