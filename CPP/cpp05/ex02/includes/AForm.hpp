#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute; 

public :
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm() = 0; 

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

    class FormNotSignedException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
    
    class GradeTooLowToExecuteException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };



    //Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    
    //Member functions
    void beSigned(Bureaucrat &bureaucrat); 
    virtual void execute(const Bureaucrat &executor) const = 0;

};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif