#include "Bureaucrat.hpp"

void testCreationInvalidGrade() {
    std::cout << "Test 1: Invalid Bureaucrat Creation\n";
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
    std::cout << "\nTest 2: Decrementing Bureaucrat at Minimum Grade\n";
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
    std::cout << "\nTest 3: Incrementing Bureaucrat at Maximum Grade\n";
    try {
        Bureaucrat Skyler("Skyler", 1);
        std::cout << Skyler << std::endl;
        std::cout << Skyler.getName() << " gets decremented" << std::endl;
        Skyler.incrementGrade(); // Devrait lancer GradeTooHighException
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testfunctionalBureaucrat() {
    std::cout << "\nTest 4: Functional Bureaucrat\n";
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
