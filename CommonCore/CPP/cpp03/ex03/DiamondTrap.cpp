#include "DiamondTrap.hpp"

// Constructeur par défaut
DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScavTrap() {
    this->name = "default";
    this->hitPoints = FragTrap::hitPoints;    // HP de FragTrap
    this->energyPoints = ScavTrap::energyPoints; // EP de ScavTrap
    this->attackDamage = FragTrap::attackDamage; // AD de FragTrap
    std::cout << "DiamondTrap default constructor called for " << this->name << std::endl;
}

// Constructeur avec nom
DiamondTrap::DiamondTrap(std::string inputName) : ClapTrap(inputName + "_clap_name"), FragTrap(), ScavTrap() {
    this->name = inputName;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap constructor called for " << this->name << std::endl;
}

// Constructeur par copie
DiamondTrap::DiamondTrap(const DiamondTrap &obj) : ClapTrap(obj), FragTrap(obj), ScavTrap(obj) {
    *this = obj;
    std::cout << "DiamondTrap copy constructor called for " << obj.name << std::endl;
}

// Destructeur
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " destroyed!" << std::endl;
}

// Opérateur d'affectation
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj) {
    if (this != &obj) {
        ClapTrap::operator=(obj); // Assure que les attributs de ClapTrap sont copiés
        this->name = obj.name;
    }
    std::cout << "DiamondTrap copy assignment operator called for " << obj.name << std::endl;
    return *this;
}

// Méthode attack (version de ScavTrap)
void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target); // Appelle l'attaque de ScavTrap
}

// Méthode whoAmI
void DiamondTrap::whoAmI() {
    std::cout << "I am DiamondTrap " << this->name << " and ClapTrap name is " << ClapTrap::name << std::endl;
}
