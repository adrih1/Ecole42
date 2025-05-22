#include "Bureaucrat.hpp"
#include "Form.hpp"


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define ORANGE "\033[36m"
#define YELLOW "\033[33m"

void testFunctionalForm() {
    std::cout << GREEN << "Test 1: Functional Form" << RESET << std::endl;
    try {
        Form Form("Form", 5, 100);
        std::cout << Form << std::endl;
        std::cout << YELLOW << "> Creating Bureaucrat who can sign" << RESET << std::endl;
        Bureaucrat Gustavo("Gustavo", 3);
        std::cout << Gustavo << std::endl;

        std::cout << YELLOW << "> Trying to sign" << RESET << std::endl;
        Gustavo.signForm(Form);

        std::cout << Form << std::endl;
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
}

void testUnauthorizedBureaucrat()
{
    std::cout << GREEN << "\nTest 2: Unauthorized Bureaucrat" << RESET << std::endl;
    try {
        Form Form("Form", 5, 100);
        std::cout << Form << std::endl;
        std::cout << YELLOW << "> Creating Bureaucrat who can't sign" << RESET << std::endl;
        Bureaucrat Walter("Walter", 134 );
        std::cout << Walter << std::endl;

        std::cout << YELLOW << "> Trying to sign" << RESET << std::endl;
        Walter.signForm(Form);

        std::cout << Form << std::endl;
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
}

void testUnauthorizedForm()
{
    std::cout << GREEN << "\nTest 3: Unauthorized Form" << RESET << std::endl;
    //Grade to execute 
    std::cout << YELLOW << "> Creating a Form with a grade to execute too low" << RESET << std::endl;
    try {
        Form Form("Form", 5, 151);
        std::cout << Form << std::endl;
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << YELLOW << "> Creating a Form with a grade to execute too high" << RESET << std::endl;
    try {
        Form Form("Form", 5, 0);
        std::cout << Form << std::endl;
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << YELLOW << "> Creating a Form with a grade to sign too low" << RESET << std::endl;
    try {
        Form Form("Form", 151, 100);
        std::cout << Form << std::endl;
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << YELLOW << "> Creating a Form with a grade to sign too high" << RESET << std::endl;
    try {
        Form Form("Form", 0, 100);
        std::cout << Form << std::endl;
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

}

int main() {
    testFunctionalForm();
    testUnauthorizedBureaucrat();
    testUnauthorizedForm();
    return 0;
}
