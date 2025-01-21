#include "Bureaucrat.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define ORANGE "\033[36m"
#define YELLOW "\033[33m"

void testCreationInvalidGrade() {
    std::cout << GREEN << "Test 1: Invalid Bureaucrat Creation" << RESET << std::endl;
    try {
        Bureaucrat Alice("Alice", 0); // Devrait lancer GradeTooHighException
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat Charlie("Charlie", 151); // Devrait lancer GradeTooLowException
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testDecrementAtMinimum() {

    std::cout << GREEN << "\nTest 2: Decrementing Bureaucrat at Minimum Grade" << RESET << std::endl;
    try {
        Bureaucrat Gustavo("Gustavo", 150);
        std::cout << Gustavo << std::endl;
        std::cout << Gustavo.getName() << " gets decremented" << std::endl;
        Gustavo.decrementGrade(); // Devrait lancer GradeTooLowException
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testIncrementAtMaximum() {
    std::cout << GREEN << "\nTest 3: Incrementing Bureaucrat at Maximum Grade" << RESET << std::endl;
    try {
        Bureaucrat Skyler("Skyler", 1);
        std::cout << Skyler << std::endl;
        std::cout << Skyler.getName() << " gets incremented" << std::endl;
        Skyler.incrementGrade(); // Devrait lancer GradeTooHighException
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testfunctionalBureaucrat() {
    std::cout << GREEN << "\nTest 4: Functional Bureaucrat" << RESET << std::endl;  
    Bureaucrat Walter("Walter", 75);
    std::cout << Walter << std::endl;
    std::cout << Walter.getName() << " gets decremented" << std::endl;
    Walter.decrementGrade();
    std::cout << Walter << std::endl;
    std::cout << Walter.getName() << " gets incremented two times" << std::endl;
    Walter.incrementGrade();
    Walter.incrementGrade();
    std::cout << Walter << std::endl;
}

int main() {
    testCreationInvalidGrade();
    testDecrementAtMinimum();
    testIncrementAtMaximum();
    testfunctionalBureaucrat();
    return 0;
}
