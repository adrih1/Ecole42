#include "Fixed.hpp"

// Test de création d'objets Fixed
void testSujet ()
{
    std::cout << "Test du sujet (test les incrementations):\n";
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
}

void testCreation() {
    std::cout << "Test de création :\n";
    Fixed a(10);
    Fixed b(3.14f);
    Fixed c(a);
    std::cout << "a : " << a << " (devrait être 10)\n";
    std::cout << "b : " << b << " (devrait être environ 3.14)\n";
    std::cout << "c : " << c << " (devrait être une copie de a, soit 10)\n";
}

// Test des opérateurs de comparaison
void testComparaison() {
    std::cout << "Test des opérateurs de comparaison :\n";
    Fixed a(10);
    Fixed b(3.14f);
    Fixed c(a);

    std::cout << "a > b : " << (a > b ? "Vrai" : "Faux") << " (devrait être Vrai)\n";
    std::cout << "a < b : " << (a < b ? "Vrai" : "Faux") << " (devrait être Faux)\n";
    std::cout << "a >= c : " << (a >= c ? "Vrai" : "Faux") << " (devrait être Vrai)\n";
    std::cout << "a <= b : " << (a <= b ? "Vrai" : "Faux") << " (devrait être Faux)\n";
    std::cout << "a == c : " << (a == c ? "Vrai" : "Faux") << " (devrait être Vrai)\n";
    std::cout << "a != b : " << (a != b ? "Vrai" : "Faux") << " (devrait être Vrai)\n";
}

// Test des opérateurs arithmétiques
void testOperationsArithmetiques() {
    std::cout << "Test des opérateurs arithmétiques :\n";
    Fixed a(10);
    Fixed b(3.14f);

    Fixed d = a + b;
    Fixed e = a - b;
    Fixed f = a * b;
    Fixed g = a / b;

    std::cout << "a + b : " << d << " (devrait être environ 13.14)\n";
    std::cout << "a - b : " << e << " (devrait être environ 6.86)\n";
    std::cout << "a * b : " << f << " (devrait être environ 31.4)\n";
    std::cout << "a / b : " << g << " (devrait être environ 3.18)\n";
}

// Test de la méthode min
void testMin() {
    std::cout << "Test de la méthode min :\n";
    Fixed a(10);
    Fixed b(3.14f);

    const Fixed &minConstFixed = Fixed::min(a, b);

    std::cout << "min(a, b) : " << min(a, b) << " (devrait être environ 3.14)\n";
    std::cout << "min(a, b) pour les const : " << minConstFixed << " (devrait être environ 3.14)\n\n";
}

// Test de la méthode min
void testMax() {
    std::cout << "Test de la méthode min :\n";
    Fixed a(10);
    Fixed b(3.14f);

    const Fixed &maxConstFixed = Fixed::max(a, b);

    std::cout << "min(a, b) : " << max(a, b) << " (devrait être 10)\n";
    std::cout << "min(a, b) pour les const : " << maxConstFixed << " (devrait être environ 10)\n\n";
}

int main() {
    testSujet();
    std::cout << "\n\n";
    testCreation();
    std::cout << "\n\n";
    testComparaison();
    std::cout << "\n\n";
    testOperationsArithmetiques();
    std::cout << "\n\n";
    testMin();
    std::cout << "\n\n";
    testMax();


    return 0;
}