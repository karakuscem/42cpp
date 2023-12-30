#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
    private:
            std::string firstName;
            std::string lastName;
            std::string nickName;
            std::string phoneNumber;
            std::string darkestSecret;

        public:
            Contact();
            Contact(std::string firstName, std::string lastName, std::string nickName, \
            std::string phoneNumber, std::string darkestSecret);
            ~Contact(); 
            std::string getContactFirstName();
            std::string getContactLastName();
            std::string getContactNickName();
            std::string getContactPhoneNumber();
        std::string getContactDarkestSecret();
};

#endif