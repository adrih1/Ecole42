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
	Fixed &operator=(const Fixed &autre);

	Fixed(int const value);
	Fixed(float const value);

	float toFloat(void) const;
	int toInt(void) const;
};

// Surcharge de l'opérateur << pour afficher un objet Fixed
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
