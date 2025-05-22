#include "Zombie.hpp"


Zombie::Zombie() : name("Zombie") {};

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie()
{
    std::cout << this->name << " is dead" << std::endl;
}

void Zombie::announce(void) const
{
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}