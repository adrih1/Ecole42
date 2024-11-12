#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : nbDecimal(0) {
    cout << "Default constructor called" << endl;
}

Fixed::~Fixed() {
    cout << "Destructor called" << endl;
}

Fixed::Fixed(const Fixed& autre) {
    cout << "Copy constructor called" << endl;
    *this = autre;
}

Fixed& Fixed::operator=(const Fixed& autre) {
    cout << "Copy assignement operator called." << endl;
    if (this != &autre)
        this->nbDecimal = autre.nbDecimal;
    return *this;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->nbDecimal = value << Fixed::fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->nbDecimal = (int)roundf(value * (1 << Fixed::fractionalBits));
}
float Fixed::toFloat() const {
    return static_cast<float>(this->nbDecimal) / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return this->nbDecimal >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}