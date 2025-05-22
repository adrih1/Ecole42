#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact() 
        : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("") {}
        
    // Constructeur avec paramètres pour initialiser tous les champs
    Contact(const std::string& firstName, const std::string& lastName,
            const std::string& nickName, const std::string& phoneNumber,
            const std::string& darkestSecret);

    // Getters
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    // Méthode d'affichage
    void displayContactSummary(int index) const; 
    void displayContact(int index) const; 

};

#endif
