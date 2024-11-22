#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

//Constructeurs
Fixed::Fixed() : nbDecimal(0) {
    // cout << "Default constructor called" << endl;
}

Fixed::Fixed(int const raw) : nbDecimal(raw * (1 << fractionalBits)) {
    // cout << "Int constructor called" << endl;
}

Fixed::Fixed(float const raw) : nbDecimal(static_cast<int>(raw * (1 << fractionalBits) + 0.5f)) {
    // std::cout << "Float constructor called" << std::endl;
}

//Destructor
Fixed::~Fixed() {
    // cout << "Destructor called" << endl;
}

// Constructor copy
Fixed::Fixed(const Fixed& autre) {
    // cout << "Copy constructor called" << endl;
    *this = autre;
}

Fixed& Fixed::operator=(const Fixed& autre) {
    // cout << "Copy assignement operator called." << endl;
    if (this != &autre)
        this->nbDecimal = autre.nbDecimal;
    return *this;
}

// Operateurs arithmetiques
Fixed Fixed::operator+(const Fixed &autre) const {
    return Fixed(this->toFloat() + autre.toFloat());
}

Fixed Fixed::operator-(const Fixed &autre) const {
    return Fixed(this->toFloat() - autre.toFloat());
}

Fixed Fixed::operator*(const Fixed &autre) const {
    return Fixed(this->toFloat() * autre.toFloat());
}

Fixed Fixed::operator/(const Fixed &autre) const {
    if (autre.nbDecimal == 0) {
        std::cerr << "Erreur : Division par zéro." << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / autre.toFloat());
}

// Operateurs de comparaison
bool Fixed::operator>(const Fixed &autre) const {
    return this->nbDecimal > autre.nbDecimal;
}

bool Fixed::operator<(const Fixed &autre) const {
    return this->nbDecimal < autre.nbDecimal;
}

bool Fixed::operator>=(const Fixed &autre) const {
    return this->nbDecimal >= autre.nbDecimal;
}

bool Fixed::operator<=(const Fixed &autre) const {
    return this->nbDecimal <= autre.nbDecimal;
}

bool Fixed::operator==(const Fixed &autre) const {
    return this->nbDecimal == autre.nbDecimal;
}

bool Fixed::operator!=(const Fixed &autre) const {
    return this->nbDecimal != autre.nbDecimal;
}


// Operateurs d'incrementation
Fixed &Fixed::operator++() {
    this->nbDecimal += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;   
    ++(*this);           
    return temp;           
}

// Opérateurs de décrémentation
Fixed &Fixed::operator--() {
    this->nbDecimal -= 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;    
    --(*this);            
    return temp;       
}


// Methodes de fonction
float Fixed::toFloat() const {
    return static_cast<float>(nbDecimal) / (1 << fractionalBits);
}

int Fixed::toInt() const {
    return nbDecimal / (1 << fractionalBits);
}


Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a.nbDecimal < b.nbDecimal) ? a : b;
}

const Fixed &Fixed::minConst(const Fixed &a, const Fixed &b) {
    return (a.nbDecimal < b.nbDecimal) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a.nbDecimal < b.nbDecimal) ? b : a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a.nbDecimal < b.nbDecimal) ? b : a;
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}