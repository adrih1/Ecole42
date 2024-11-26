#include "../includes/Cure.hpp"

// Default constructor
Cure::Cure() : AMateria("cure") {}

// Copy constructor
Cure::Cure(const Cure &other) : AMateria(other) {}

// Destructor
Cure::~Cure() {}

// Assignment operator
Cure &Cure::operator=(const Cure &other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

// Clone method
AMateria* Cure::clone() const {
    return new Cure(*this);
}

// Use method
void Cure::use(ICharacter &target) {
    std::cout << "* heals" << target.getName() << "'s wounds *" << std::endl;
}