#ifndef INTER_HPP
#define INTER_HPP

#include "AForm.hpp"

class Intern
{

public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &intern);
    ~Intern();

    AForm *makeForm(std::string formName, std::string target);  
};

std::ostream &operator<<(std::ostream &os, const Intern &intern);

#endif