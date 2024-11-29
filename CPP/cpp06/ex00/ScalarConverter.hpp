#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter &operator=(const ScalarConverter &other);
    
    ~ScalarConverter();

    // Méthodes d'aide pour les conversions spécifiques
    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);

    // Méthode utilitaire pour vérifier si une chaîne est un pseudo littéral
    static bool isPseudoLiteral(const std::string &literal);

public:
    static void convert(const std::string &literal);
    

};

#endif