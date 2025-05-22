#include "DiamondTrap.hpp"

// Codes ANSI pour les couleurs
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"

int main() {
    // Création d'un DiamondTrap
    std::cout << GREEN << "=== Création d'un DiamondTrap ===" << RESET << std::endl;
    DiamondTrap dt("Shiny");

    std::cout << CYAN << "\n=== Test des méthodes ===" << RESET << std::endl;

    // Test de whoAmI()
    std::cout << YELLOW << "\n> Appel de whoAmI() :" << RESET << std::endl;
    dt.whoAmI();

    // Test des points de vie et d'énergie
    std::cout << YELLOW << "\n> Points de vie et d'énergie :" << RESET << std::endl;
    std::cout << "Hit Points: " << dt.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << dt.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << dt.getAttackDamage() << std::endl;

    // Test d'attaque
    std::cout << YELLOW << "\n> Test de l'attaque :" << RESET << std::endl;
    dt.attack("TargetDummy");

    // Test de prise de dégâts
    std::cout << YELLOW << "\n> Test de prise de dégâts :" << RESET << std::endl;
    dt.takeDamage(20);

    // Test de réparation
    std::cout << YELLOW << "\n> Test de réparation :" << RESET << std::endl;
    dt.beRepaired(15);

    // Test des points après réparation et dégâts
    std::cout << YELLOW << "\n> Points après test :" << RESET << std::endl;
    std::cout << "Hit Points: " << dt.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << dt.getEnergyPoints() << std::endl;

    std::cout << GREEN << "\n=== Fin des tests ===" << RESET << std::endl;

    return 0;
}
