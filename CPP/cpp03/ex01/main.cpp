// main.cpp
#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("Clap1");
    ClapTrap clap2("Clap2");

    std::cout << "\n--- Initial State ---" << std::endl;
    clap1.attack("Enemy");
    clap2.attack("Enemy");

    std::cout << "\n--- Clap1 attacks Clap2 several times ---" << std::endl;
    for (int i = 0; i < 5; i++) {
        clap1.attack("Clap2");
        clap2.takeDamage(clap1.getAttackDamage());
    }

    std::cout << "\n--- Clap2 tries to repair itself ---" << std::endl;
    clap2.beRepaired(3);
    std::cout << clap2.getName() << " has " << clap2.getHitPoints() << " hit points" << std::endl;


    std::cout << "\n--- Clap1 continues to attack until heis exhausted ---" << std::endl;
    while (clap1.getEnergyPoints() > 0 && clap1.getHitPoints() > 0) {
        clap1.attack("Clap2");
    }

    std::cout << "\n--- Clap1 tries to repair ---" << std::endl;
    clap1.beRepaired(5);

    std::cout << "\n--- End of Test ---" << std::endl;
    return 0;
}
