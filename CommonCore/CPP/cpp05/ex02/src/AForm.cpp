#include "../includes/AForm.hpp"

// --- Exceptions ---
const char *AForm::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException: Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException: Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "FormNotSignedException: Form is not signed!";
}

const char *AForm::GradeTooLowToExecuteException::what() const throw()
{
    return "GradeTooLowToExecuteException: Grade is too low to execute!";
}


AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) 
    : _name(name),_signed(false),  _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}


AForm::AForm(const AForm& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {};


AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return *this;
}

AForm::~AForm() {}

//Getters
std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSigned() const
{
    return this->_signed;
}

int AForm::getGradeToSign() const
{
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;
}


//Member functions
void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign || bureaucrat.getGrade() < 1)
        throw GradeTooLowException();
    else
        _signed = true;
}

void AForm::execute(Bureaucrat const &bureaucrat) const
{
    if (!this->_signed)
		throw AForm::FormNotSignedException();
	if (bureaucrat.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << form.getName()
		<< " [Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Grade to sign: " << form.getGradeToSign()
		<< ", Grade to execute: " << form.getGradeToExecute() << "]";
	return os;
}