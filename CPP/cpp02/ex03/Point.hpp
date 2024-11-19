#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>
# include <string>
# include <cmath>
using namespace	std;

class Point
{
  private:
    const Fixed x;
    const Fixed y;


  public:
    //Constructeurs
    Point();
    Point(const float xValue, const float yValue);
    Point(const Point &autre);
    Point &operator=(const Point &other);
	~Point();
    
    Fixed getX() const;
    Fixed getY() const;

    bool bsp(Point const a, Point const b, Point const c, Point const point);
};

std::ostream &operator<<(std::ostream &out, const Point &point);

#endif
