#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &intern) {
    if (this != &intern) {
         *this = intern;
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string formName, std::string target) {
    const std::string formNames[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    AForm* forms[3] = {
        new PresidentialPardonForm(target),
        new RobotomyRequestForm(target),
        new ShrubberyCreationForm(target)
    };

   for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            for (int j = 0; j < 3; j++) {
                if (j != i) 
                    delete forms[j];
            }
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i];
        }
    }
    for (int i = 0; i < 3; i++) {
        delete forms[i];
    }
    std::cout << "Intern could not create " << formName << std::endl;
    return NULL;
}


