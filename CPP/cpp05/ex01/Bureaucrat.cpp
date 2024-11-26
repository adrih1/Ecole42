#include "Bureaucrat.hpp"

// --- Exceptions ---
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException: Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException: Grade is too low!";
}


Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}


Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}


//Getters
const std::string& Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
} 

//Incrementations
void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 <  1)
        throw GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150)
        throw GradeTooLowException();
    this->_grade++;
}

//TODO - Implelement signForm



//Surcharge de l'operateur
std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
