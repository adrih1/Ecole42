#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const float xValue, const float yValue)
    : x(Fixed(xValue)), y(Fixed(yValue)) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point &Point::operator=(const Point &other) {
    if (this == &other)
        return *this;
    std::cerr << "Erreur : Les membres const ne peuvent pas être réassignés." << std::endl;
    return *this;
}

Point::~Point() {}

Fixed Point::getX() const {
    return x;
}

Fixed Point::getY() const {
    return y;
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
    out << "(" << point.getX().toFloat() << ", " << point.getY().toFloat() << ")";
    return out;
}