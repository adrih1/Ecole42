#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

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

    void incrementGrade(); 
	void decrementGrade(); 

    //Getters
    const std::string& getName() const;
    int getGrade() const;

};
std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);

#endif