#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp" 

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;
    int oldestContactIndex;

public:
    PhoneBook();

    void addContact(const Contact& newContact);
    void displayContacts() const;
    const Contact& getContact(int index) const;
    int getContactCount() const { return contactCount; }
};

#endif
