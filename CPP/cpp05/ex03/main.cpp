#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/Intern.hpp"

const std::string RESET   = "\033[0m";  
const std::string BLUE    = "\033[34m";
const std::string CYAN    = "\033[36m";
const std::string BOLD_CYAN    = "\033[1;36m";

void testSubject()
{
    std::cout << BLUE << "Test Subject" << RESET << std::endl;
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");
}

void testInterWorks() {
    std::cout << BLUE << "Test: Intern Creates Forms" << RESET << std::endl;
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
    testInterWorks();   
    testSubject();
    return 0;
}