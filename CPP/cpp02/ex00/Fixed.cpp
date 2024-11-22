#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : nbDecimal(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& autre) {
    std::cout << "Copy constructor called" << std::endl;
    *this = autre;
}

Fixed& Fixed::operator=(const Fixed& autre) 
{
    std::cout << "Copy assignement operator called." << std::endl;
    if (this != &autre)
        this->nbDecimal = autre.getRawBits();
    return *this;
}


// Fonction membre getRawBits
int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->nbDecimal;
}

// Fonction membre setRawBits
void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->nbDecimal = raw;
}