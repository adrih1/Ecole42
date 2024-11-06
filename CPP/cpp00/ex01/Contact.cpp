#include "Contact.hpp"
#include <iostream>
#include <iomanip>


Contact::Contact(const std::string &firstName, const std::string &lastName,
	const std::string &nickName, const std::string &phoneNumber,
	const std::string &darkestSecret) : firstName(firstName),
	lastName(lastName), nickName(nickName), phoneNumber(phoneNumber),
	darkestSecret(darkestSecret)
{
}

std::string Contact::getFirstName() const
{
	return (firstName);
}
std::string Contact::getLastName() const
{
	return (lastName);
}
std::string Contact::getNickName() const
{
	return (nickName);
}
std::string Contact::getPhoneNumber() const
{
	return (phoneNumber);
}
std::string Contact::getDarkestSecret() const
{
	return (darkestSecret);
}

void Contact::displayContactSummary(int index) const {
    std::cout << std::setw(10) << index << " | "
              << std::setw(10) << (firstName.length() > 9 ? firstName.substr(0, 9) + "." : firstName) << " | "
              << std::setw(10) << (lastName.length() > 9 ? lastName.substr(0, 9) + "." : lastName) << " | "
              << std::setw(10) << (nickName.length() > 9 ? nickName.substr(0, 9) + "." : nickName) << std::endl;
}
