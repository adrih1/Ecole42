#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : nbDecimal(0) 
{
    cout << "Default constructor called" << endl;
}

Fixed::~Fixed() {
    cout << "Destructor called" << endl;
}

Fixed::Fixed(const Fixed& autre) {
    cout << "Copy constructor called" << endl;
    *this = autre;

}

Fixed& Fixed::operator=(const Fixed& autre) 
{
    cout << "Copy assignement operator called." << endl;
    if (this != &autre)
        this->nbDecimal = autre.getRawBits();
    return *this;
}


// Fonction membre getRawBits
int Fixed::getRawBits() const {
    cout << "getRawBits member function called" << endl;
    return this->nbDecimal;
}

// Fonction membre setRawBits
void Fixed::setRawBits(int const raw) {
    cout << "setRawBits member function called" << endl;
    this->nbDecimal = raw;
}