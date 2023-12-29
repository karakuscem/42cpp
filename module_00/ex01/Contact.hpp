#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
    private: std::string firstName;
    private: std::string lastName;
    private: std::string nickName;
    private: std::string phoneNumber;
    private: std::string darkestSecret;

    public: Contact();
    public: Contact(std::string firstName, std::string lastName, std::string nickName, \
        std::string phoneNumber, std::string darkestSecret);
    public: ~Contact();
    public: std::string getFirstName();
    public: std::string getLastName();
    public: std::string getNickName();
};

#endif