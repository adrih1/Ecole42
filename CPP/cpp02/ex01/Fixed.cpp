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
    cout << "Copy assignement operator called." << endl;
    if (this != &autre) {
        nbDecimal = autre.nbDecimal;
    }
    return *this;
}

Fixed::Fixed(int const raw) : nbDecimal(raw * (1 << fractionalBits)) {
    cout << "Int constructor called" << endl;
}

Fixed::Fixed(float const raw) : nbDecimal(std::round(raw * (1 << fractionalBits))) {
    cout << "Float constructor called" << endl;
}

float Fixed::toFloat() const {
    return static_cast<float>(nbDecimal) / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return nbDecimal / (1 << fractionalBits);
}

// Surcharge de l'opérateur << pour afficher un objet Fixed
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();  // Affiche la valeur flottante de Fixed
    return out;
}