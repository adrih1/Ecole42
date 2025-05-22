#include "../includes/Character.hpp"

Character::Character() : _name("default"), _equippedCount(0)
{
	for (int i = 0; i < 4; i++)
    {
        _inventory[i] = NULL;
		_deletedInventory[i] = NULL;
    }
}

Character::Character(const std::string &name) : _name(name), _equippedCount(0) 
{
   for (int i = 0; i < 4; i++)
    {
        _inventory[i] = NULL;
		_deletedInventory[i] = NULL;
    }
}

Character::Character(const Character &other) : _name(other._name), _equippedCount(other._equippedCount) {
    for (int i = 0; i < 4; ++i) 
    {
        if (other._inventory[i])
           _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
        if (other._deletedInventory[i])
            _deletedInventory[i] = other._deletedInventory[i]->clone();
        else
            _deletedInventory[i] = NULL;
    }
}

Character &Character::operator=(const Character &other) {
    if (this != &other) 
    {
        _name = other._name;
        _equippedCount = other._equippedCount;
        for (int i = 0; i < 4; i++) {
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            if (_deletedInventory[i])
            {
                delete _deletedInventory[i];
                _deletedInventory[i] = NULL;
            }
            if (other._deletedInventory[i])
                _deletedInventory[i] = other._deletedInventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character() 
{
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
            delete _inventory[i];
        if (_deletedInventory[i])
            delete _deletedInventory[i];
    }
}

const std::string &Character::getName() const {
    return this->_name;
}


void Character::equip(AMateria *m) {
    if (!m)
        return;
    bool equiped = false;
    for (int i = 0; i < 4; i++) 
    {
        if (!_inventory[i]) 
        {
            _inventory[i] = m;
            equiped = true;
            break;
        }
    }
    if (!equiped)
    {
        bool stored = false;
        for (int i = 0; i < 4; i++) 
        {
            if (!_deletedInventory[i]) 
            {
                _deletedInventory[i] = m;
                stored = true;
                break;
            }
        }
        if (!stored)
            delete m;
    }
    std::cerr << "Inventory is full, cannot equip more Materia." << std::endl;
}

void Character::unequip(int idx) 
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
    if (_deletedInventory[idx])
    {
        delete _deletedInventory[idx];
        _deletedInventory[idx] = NULL;
    }
    this->_deletedInventory[idx] = _inventory[idx];
    _inventory[idx] = NULL;

}

void Character::use(int idx, ICharacter &target) 
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	_inventory[idx]->use(target);
}