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


Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& form) : _name(form._name), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute)
{
    *this = form;
}

Form &Form::operator=(const Form &form)
{
    if (this != &form)
    {
        this->_signed = form._signed;
    }
    return *this;
}

Form::~Form() {}

//Getters
std::string Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign && bureaucrat.getGrade() < 1)
        throw GradeTooLowException();
    _signed = true;
}