// Zombie.cpp
#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() {
    std::cout << name << " a été détruit." << std::endl;
}

void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name) {
    return new Zombie(name);
}

void randomChump(std::string name) {
    Zombie stackZombie(name);
    stackZombie.announce();
}
