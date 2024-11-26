#include "Bureaucrat.hpp"
#include "Form.hpp"

void testFunctionalForm() {
    std::cout << "Test 1: Functional Form\n";
    try {
        Form Form1("Form1", 5, 100);
        std::cout << Form1 << std::endl;
        std::cout << "Creating Bureaucrat who can sign" << std::endl;
        Bureaucrat Gustavo("Gustavo", 3);
        std::cout << Gustavo << std::endl;

        std::cout << "Trying to sign " << Form1.getName() << std::endl;
        Gustavo.signForm(Form1);

        std::cout << Form1 << std::endl;
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
}

void testUnauthorizedForm()
{
    std::cout << "\nTest 2: Unauthorized Form\n";
    try {
        Form Form2("Form2", 5, 100);
        std::cout << Form2 << std::endl;
        std::cout << "Creating Bureaucrat who can't sign" << std::endl;
        Bureaucrat Walter("Walter", 134 );
        std::cout << Walter << std::endl;

        std::cout << "Trying to sign " << Form2.getName() << std::endl;
        Walter.signForm(Form2);

        std::cout << Form2 << std::endl;
    } catch (const std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    testFunctionalForm();
    testUnauthorizedForm();
    return 0;
}
