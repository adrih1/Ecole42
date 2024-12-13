#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"

#define RESET "\033[0m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"


void testPresidentialPardonForm() {
    std::cout << BLUE << "Test: PresidentialPardonForm Form" << RESET << std::endl;
    std::cout << YELLOW << "Valid Test" << RESET << std::endl;
    try {
        Bureaucrat Gustavo("Gustavo", 1);
        PresidentialPardonForm f1("Target 1");
        std::cout << Gustavo << std::endl;
        std::cout << f1 << std::endl;
        Gustavo.executeForm(f1);
        Gustavo.signForm(f1);
        Gustavo.executeForm(f1);
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << YELLOW << "Error Test" << RESET << std::endl;
    try {
        Bureaucrat Gustavo("Gustavo", 30);
        PresidentialPardonForm f1("Target 1");
        std::cout << Gustavo << std::endl;
        std::cout << f1 << std::endl;
        Gustavo.executeForm(f1);
        Gustavo.signForm(f1);
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

}

void testRobotomyPardonForm() {
    std::cout << BLUE << "\nTest : Robotomy Form" << RESET << std::endl;
    std::cout << YELLOW << "Valid Test" << RESET << std::endl;
    try {
        Bureaucrat Gustavo("Gustavo", 1);
        RobotomyRequestForm f1("Target 1");
        std::cout << Gustavo << std::endl;
        std::cout << f1 << std::endl;
        Gustavo.executeForm(f1);
        Gustavo.signForm(f1);
        Gustavo.executeForm(f1);
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << YELLOW << "Error Test" << RESET << std::endl;
    try {
        Bureaucrat Gustavo("Gustavo", 73);
        RobotomyRequestForm f1("Target 1");
        std::cout << Gustavo << std::endl;
        std::cout << f1 << std::endl;
        Gustavo.executeForm(f1);
        Gustavo.signForm(f1);
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
}


void testShruberryPardonForm() {
    std::cout << BLUE << "\nTest : Shruberry Form" << RESET << std::endl;
    std::cout << YELLOW << "Valid Test" << RESET << std::endl;
    try {
        Bureaucrat Gustavo("Gustavo", 1);
        ShrubberyCreationForm f1("Target 1");
        std::cout << Gustavo << std::endl;
        std::cout << f1 << std::endl;
        Gustavo.executeForm(f1);
        Gustavo.signForm(f1);
        Gustavo.executeForm(f1);
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << YELLOW << "Error Test" << RESET << std::endl;
     try {
        Bureaucrat Gustavo("Gustavo", 146);
        ShrubberyCreationForm f1("Target 1");
        std::cout << Gustavo << std::endl;
        std::cout << f1 << std::endl;
        Gustavo.executeForm(f1);
        Gustavo.signForm(f1);
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
}

int main ()
{
    testPresidentialPardonForm();   
    testRobotomyPardonForm();  
    testShruberryPardonForm();  
    return 0;
}