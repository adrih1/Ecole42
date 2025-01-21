#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/Intern.hpp"

#define RESET "\033[0m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define ORANGE "\033[38;5;208m"
#define YELLOW "\033[33m"

void testSubject()
{
    std::cout << GREEN << "Test Subject" << RESET << std::endl;
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
    
    delete rrf;
}

void testInterWorks() {
    std::cout << GREEN << "\nTest: Intern Creates Forms" << RESET << std::endl;
    try {
        Intern intern;

        AForm* form1 = intern.makeForm("PresidentialPardonForm", "Target 1");
        AForm* form2 = intern.makeForm("RobotomyRequestForm", "Target 2");
        AForm* form3 = intern.makeForm("ShrubberyCreationForm", "Target 3");
        AForm* form4 = intern.makeForm("InvalidForm", "Target 4");

        delete form1;
        delete form2;
        delete form3;
        delete form4;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int main ()
{
    testSubject();
    testInterWorks();   
    return 0;
}