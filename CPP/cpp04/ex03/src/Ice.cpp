#include "../includes/Ice.hpp"

// Default constructor
Ice::Ice() : AMateria("ice") {}

// Copy constructor
Ice::Ice(const Ice &other) : AMateria(other) {}

// Destructor
Ice::~Ice() {}

// Assignment operator
Ice &Ice::operator=(const Ice &other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

// Clone method
AMateria* Ice::clone() const {
    return new Ice(*this);
}

// Use method
void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}