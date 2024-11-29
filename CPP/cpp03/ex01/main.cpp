// main.cpp
#include "ScavTrap.hpp"

int main() {
    ScavTrap scav1("Scav 1");
    ScavTrap scav2("Scav 2");

    std::cout << "\n--- Initial State ---" << std::endl;
    scav1.attack("Enemy");
    scav2.attack("Enemy");

    std::cout << "\n--- scav1 attacks scav2 several times ---" << std::endl;
    for (int i = 0; i < 5; i++) {
        scav1.attack("scav2");
        scav2.takeDamage(scav1.getAttackDamage());
    }

    std::cout << "\n--- scav2 tries to repair itself ---" << std::endl;
    scav2.beRepaired(3);
    std::cout << scav2.getName() << " has " << scav2.getHitPoints() << " hit points" << std::endl;


    std::cout << "\n--- scav1 continues to attack until heis exhausted ---" << std::endl;
    while (scav1.getEnergyPoints() > 0 && scav1.getHitPoints() > 0) {
        scav1.attack("scav2");
    }

    std::cout << "\n--- scav1 tries to repair ---" << std::endl;
    scav1.beRepaired(5);

    std::cout << "\n--- End of Test ---" << std::endl;
    return 0;
}
