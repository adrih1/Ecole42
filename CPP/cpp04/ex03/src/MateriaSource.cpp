#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() : _count(0) {
    for (int i = 0; i < 4; ++i) {
        _materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other) : _count(other._count) {
    for (int i = 0; i < 4; ++i) 
    {
        if (other._materias[i])
            this->_materias[i] = other._materias[i]->clone();
        else
            this->_materias[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++)
        {
            if (_materias[i])
            {
                delete _materias[i];
                _materias[i] = NULL;
            }
        }
        _count = other._count;
        for(int i = 0; i < 4; i++)
        {
            if(other._materias[i])
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) 
        if (this->_materias[i])
            delete this->_materias[i];
}

void MateriaSource::learnMateria(AMateria *m) {
    if (m && _count < 4) 
    {
        _materias[_count] = m->clone();
        _count++;    
    }
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < _count; i++)
    {
        if (_materias[i]->getType() == type)
        {
            return _materias[i]->clone();
        }
    }
    return NULL;
} 