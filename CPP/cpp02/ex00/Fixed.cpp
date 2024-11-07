#include "Fixed.hpp"

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : nbDecimal(0) {
    cout << "Default constructor called" << endl;
}

Fixed::~Fixed() {
    cout << "Destructor called" << endl;
}

Fixed::Fixed(const Fixed& autre) : nbDecimal(autre.nbDecimal) {
    cout << "Copy constructor called" << endl;
}

Fixed& Fixed::operator=(const Fixed& autre) {
    if (this != &autre) {
        nbDecimal = autre.nbDecimal;
        cout << "Copy assignement operator called." << endl;
    }
    return *this;
}


// Fonction membre getRawBits
int Fixed::getRawBits() const {
    cout << "getRawBits member function called" << endl;
    return nbDecimal;
}

// Fonction membre setRawBits
void Fixed::setRawBits(int const raw) {
    nbDecimal = raw;
    cout << "setRawBits member function called" << endl;
}