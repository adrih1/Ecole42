#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        this->_materias[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other) {
    for (int i = 0; i < 4; ++i) {
        if (other._materias[i])
            this->_materias[i] = other._materias[i]->clone();
        else
            this->_materias[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete this->_materias[i];
            if (other._materias[i])
                this->_materias[i] = other._materias[i]->clone();
            else
                this->_materias[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete this->_materias[i];
    }
}

void MateriaSource::learnMateria(AMateria *m) {
    if (!m) {
        std::cerr << "Error: Cannot learn NULL Materia." << std::endl;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (!this->_materias[i]) {
            this->_materias[i] = m;
            return;
        }
    }
    delete m;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < 4; ++i) {
        if (this->_materias[i] && this->_materias[i]->getType() == type) {
            return this->_materias[i]->clone();
        }
    }
    return NULL;
} 