#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	AForm::execute(executor);
	std::ofstream shrubName((_target + "_shrubbery").c_str());
	if (!shrubName)
	{
		std::cerr << "Failed to create file: " << _target << "_shrubbery" << std::endl;
		return;
	}

	shrubName << "       _-_\n"
			 "    /~~   ~~\\\n"
			 " /~~         ~~\\\n"
			 "{               }\n"
			 " \\  _-     -_  /\n"
			 "   ~  \\\\ //  ~\n"
			 "_- -   | | _- _\n"
			 "  _ -  | |   -_\n"
			 "      // \\\\\n";
    shrubName.close();
}