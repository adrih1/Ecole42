#include "bsp.hpp"

int main() {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);
    Point p(1.0f, 1.0f);  // Un point à l'intérieur du triangle
    Point p1(2.0f, 2.0f);  // Un point à l'intérieur du triangle
    Point p2(5.0f, 5.0f); // Un point en dehors du triangle

    std::cout << "Point p est-il dans le triangle ? " << (bsp(a, b, c, p) ? "Oui" : "Non") << std::endl;
    std::cout << "Point p1 est-il dans le triangle ? " << (bsp(a, b, c, p1) ? "Oui" : "Non") << std::endl;
    std::cout << "Point p2 est-il dans le triangle ? " << (bsp(a, b, c, p2) ? "Oui" : "Non") << std::endl;

    return 0;
}
