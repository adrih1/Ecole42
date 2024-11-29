#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& bureaucrat);
    Bureaucrat& operator=(const Bureaucrat& bureaucrat);
    ~Bureaucrat();

    //Exceptions personalisees
    class GradeTooHighException : public std::exception 
    {
        public:
            virtual const char *what() const throw();
	};

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char *what() const throw();
	};


    //Getters
    const std::string& getName() const;
    int getGrade() const;

    //Methods
    void incrementGrade(); 
	void decrementGrade(); 
    void signForm(AForm& form);
    void executeForm(const AForm &form) const;

};
std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);

#endif