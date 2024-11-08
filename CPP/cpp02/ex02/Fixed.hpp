#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
#include <cmath>
using namespace	std;

class Fixed
{
  private:
	int nbDecimal;
	static const int fractionalBits;

  public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &autre);
	// Operateurs arithmetiques
	Fixed &operator=(const Fixed &autre);
	Fixed operator+(const Fixed &autre) const;
	Fixed operator-(const Fixed &autre) const;
	Fixed operator*(const Fixed &autre) const;
	Fixed operator/(const Fixed &autre) const;

	//Operateurs logiques
	bool operator>(const Fixed &autre) const;
    bool operator<(const Fixed &autre) const;
    bool operator>=(const Fixed &autre) const;
    bool operator<=(const Fixed &autre) const;
    bool operator==(const Fixed &autre) const;
    bool operator!=(const Fixed &autre) const;
	
	//Inrementation
	Fixed &operator++();       
	Fixed operator++(int);     
	Fixed &operator--();       
	Fixed operator--(int);     
	



	Fixed(int const raw);
	Fixed(float const raw);

	// Methodes de classe
	static Fixed &min(Fixed &a, Fixed &b); 
	static const Fixed &min(const Fixed &a, const Fixed &b); // version const 

	static Fixed &max(Fixed &a, Fixed &b); 
	static const Fixed &max(const Fixed &a, const Fixed &b); // version const 


	float toFloat(void) const;
	int toInt(void) const;
};

// Surcharge de l'opérateur << pour afficher un objet Fixed
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
