#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    AForm::execute(executor);
    std::cout << "Bzzzz... Drilling noises..." << std::endl;
    
    if (std::rand() % 2)
		  std::cout << _target << " has been robotomized successfully." << std::endl;
	  else
		  std::cout << "Robotomy failed on " << _target << "." << std::endl;
}