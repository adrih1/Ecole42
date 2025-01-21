#include "Form.hpp"

// --- Exceptions ---
const char *Form::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException: Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException: Grade is too low!";
}


Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) 
    : _name(name),_signed(false),  _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}


Form::Form(const Form& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {};


Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return *this;
}

Form::~Form() {}

//Getters
std::string Form::getName() const
{
    return this->_name;
}

bool Form::getIsSigned() const
{
    return this->_signed;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    else
        _signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << form.getName()
		<< " [Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Grade to sign: " << form.getGradeToSign()
		<< ", Grade to execute: " << form.getGradeToExecute() << "]";
	return os;
}