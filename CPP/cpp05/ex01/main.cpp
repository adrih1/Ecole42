#include "Bureaucrat.hpp"
#include "Form.hpp"

void testFunctionalForm() {
    std::cout << "Test 1: Functional Form\n";
    try {
        Form Form("Form", 5, 100);
        std::cout << Form << std::endl;
        std::cout << "Creating Bureaucrat who can sign" << std::endl;
        Bureaucrat Gustavo("Gustavo", 3);
        std::cout << Gustavo << std::endl;

        std::cout << "Trying to sign " << Form.getName() << std::endl;
        Gustavo.signForm(Form);

        std::cout << Form << std::endl;
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
}

void testUnauthorizedBureaucrat()
{
    std::cout << "\nTest 2: Unauthorized Bureaucrat\n";
    try {
        Form Form("Form", 5, 100);
        std::cout << Form << std::endl;
        std::cout << "Creating Bureaucrat who can't sign" << std::endl;
        Bureaucrat Walter("Walter", 134 );
        std::cout << Walter << std::endl;

        std::cout << "Trying to sign " << Form.getName() << std::endl;
        Walter.signForm(Form);

        std::cout << Form << std::endl;
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
}

void testUnauthorizedForm()
{
    std::cout << "\nTest 3: Unauthorized Form\n";
    //Grade to execute 
    try {
        Form Form("Form", 5, 151);
        std::cout << Form << std::endl;
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    
    try {
        Form Form("Form", 5, 0);
        std::cout << Form << std::endl;
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    //Grade to sign
     //Grade to execute 
    try {
        Form Form("Form", 151, 100);
        std::cout << Form << std::endl;
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    
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
