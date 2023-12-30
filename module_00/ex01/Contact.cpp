#include "Contact.hpp"

Contact::Contact()
{
    return ;
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, \
        std::string phoneNumber, std::string darkestSecret)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
    return ;
}

Contact::~Contact()
{
    return ;
}

std::string Contact::getContactFirstName()
{
    return (this->firstName);
}

std::string Contact::getContactLastName()
{
    return (this->lastName);
}

std::string Contact::getContactNickName()
{
    return (this->nickName);
}

std::string Contact::getContactPhoneNumber()
{
    return (this->phoneNumber);
}

std::string Contact::getContactDarkestSecret()
{
    return (this->darkestSecret);
}
