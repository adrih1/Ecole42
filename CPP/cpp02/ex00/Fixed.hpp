#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
using namespace std;


class Fixed {
private:
    int nbDecimal;
    static const int fractionalBits;

public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& autre);
    Fixed& operator=(const Fixed& autre);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif
