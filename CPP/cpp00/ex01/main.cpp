#include "Phonebook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <limits>

void addContact(PhoneBook& phoneBook) {
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lastName);
    std::cout << "Enter NickName: ";
    std::getline(std::cin, nickName);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);

    if (firstName.empty() || lastName.empty() || nickName.empty() ||
        phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "Error: All fields must be filled.\n";
        return;
    }

    phoneBook.addContact(Contact(firstName, lastName, nickName, phoneNumber, darkestSecret));
    std::cout << "Contact added successfully!\n";
}

void searchContacts(const PhoneBook& phoneBook) {
    
    phoneBook.displayContacts();
    if (phoneBook.getContactCount() < 1) {
        std::cout << "Please create a contact before searching for one.\n";
        return;
    }

    std::cout << "Enter the index of the contact to view details: ";
    int index;
    if (!(std::cin >> index) || index <= 0 || index > phoneBook.getContactCount()) {
        std::cout << "Error: Invalid index.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore();

    try {
        phoneBook.getContact(index - 1).displayContact(index);
    } catch (const std::out_of_range&) {
        std::cout << "Error: No contact found at that index.\n";
    }
}

int main() {
    PhoneBook phoneBook;
    std::string command;
    std::cout << "Welcome to the PhoneBook!\n";
    
    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof()) {
            std::cout << "\nExiting PhoneBook. All contacts will be lost.\n";
            break;
        }
        if (command == "ADD") {
            addContact(phoneBook);
        } 
        else if (command == "SEARCH") {
            searchContacts(phoneBook);
        } 
        else if (command == "EXIT") {
            std::cout << "Exiting PhoneBook. All contacts will be lost.\n";
            break;
        } 
        else {
            std::cout << "Unknown command. Please enter ADD, SEARCH, or EXIT.\n";
        }
    }
    return 0;
}
