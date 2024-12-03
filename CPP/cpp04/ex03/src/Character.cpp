#include "../includes/Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string &name) : _name(name) {
    for (int i = 0; i < 4; ++i) {
        _inventory[i] = NULL;
    }
}

Character::Character(const Character &other) : _name(other._name) {
    for (int i = 0; i < 4; ++i) {
        if (other._inventory[i])
           _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}


Character &Character::operator=(const Character &other) {
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; ++i) {
            if (_inventory[i])
                delete _inventory[i];
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; ++i) {
        if (_inventory[i])
            delete _inventory[i];
    }
}

const std::string &Character::getName() const {
    return this->_name;
}


void Character::equip(AMateria *m) {
    if (!m)
        return;
    for (int i = 0; i < 4; ++i) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
    }
    std::cerr << "Inventory is full, cannot equip more Materia." << std::endl;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4)
        _inventory[idx] = NULL;
    else  
        std::cerr << "Inventory is full, cannot equip more Materia." << std::endl;

}

void Character::use(int idx, ICharacter &target) {
    if (idx >= 0 && idx < 4 && _inventory[idx])
        _inventory[idx]->use(target);
    else
        std::cerr << "Inventory is full, cannot equip more Materia." << std::endl;
}