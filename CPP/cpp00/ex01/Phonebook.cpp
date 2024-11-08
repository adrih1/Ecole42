#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(0), oldestContactIndex(0) {}

void PhoneBook::addContact(const Contact& newContact) {
    if (contactCount < 8) {
        contacts[contactCount] = newContact;
        contactCount++;
    } else {
        contacts[oldestContactIndex] = newContact;
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
}

void PhoneBook::displayContacts() const {
    if (contactCount <= 0)
       return; 
    else 
    {
        std::cout   << std::setw(10) << "Index" << " | "
                    << std::setw(10) << "First Name" << " | "
                    << std::setw(10) << "Last Name" << " | "
                    << std::setw(10) << "NickName" << std::endl;
        std::cout << "-------------------------------------------------" << std::endl;
    }

    for (int i = 0; i < contactCount; i++) {
        contacts[i].displayContactSummary(i + 1);
    }
}

const Contact& PhoneBook::getContact(int index) const {
    if (index < 0 || index >= contactCount) {
        throw std::out_of_range("Invalid contact index");
    }
    return contacts[index];
}
