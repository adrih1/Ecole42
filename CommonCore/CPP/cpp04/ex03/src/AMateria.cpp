#include "../includes/AMateria.hpp"

// Constructor
AMateria::AMateria(std::string const & type) : _type(type) {}

// Copy constructor
AMateria::AMateria(AMateria const & other) : _type(other._type) {}

// Destructor
AMateria::~AMateria() {}

// Assignment operator
AMateria & AMateria::operator=(AMateria const & other) 
{
    if (this != &other) {
       this->_type = other._type;
    }
    return *this;
}

std::string const & AMateria::getType() const {
    return this->_type;
}

// Use the materia
void AMateria::use(ICharacter & target) {
    (void)target;
	    std::cout << " * uses " << _type << " on " << target.getName() << std::endl;
}
