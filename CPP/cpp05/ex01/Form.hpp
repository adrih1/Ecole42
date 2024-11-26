#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute; 
public :
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();


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
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    
    //Member functions
    void beSigned(Bureaucrat &bureaucrat); 

};
std::ostream &operator<<(std::ostream &os, const Form &form);

#endif