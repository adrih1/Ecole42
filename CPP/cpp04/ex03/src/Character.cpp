#include "../includes/Character.hpp"

Character::Character() : name("default")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const std::string &name) : name(name) {
    for (int i = 0; i < 4; ++i) {
        inventory[i] = NULL;
    }
}

Character::Character(const Character &other) : name(other.name) {
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
}


Character &Character::operator=(const Character &other) {
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; ++i) {
            if (inventory[i])
                delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        if (inventory[i])
            delete inventory[i];
    }
}

const std::string &Character::getName() const {
    return this->name;
}


void Character::equip(AMateria *m) {
    if (!m)
        return;
    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
    std::cerr << "Inventory is full, cannot equip more Materia." << std::endl;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4)
        inventory[idx] = NULL;
    else  
        std::cerr << "Inventory is full, cannot equip more Materia." << std::endl;

}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
    else
        std::cerr << "Inventory is full, cannot equip more Materia." << std::endl;
}