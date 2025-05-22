#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : nbDecimal(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& autre) {
    std::cout << "Copy constructor called" << std::endl;
    *this = autre;
}

Fixed& Fixed::operator=(const Fixed& autre) {
    std::cout << "Copy assignement operator called." << std::endl;
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