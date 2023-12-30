#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
    private:
        int contactCount;
        int index;
    public:
        PhoneBook();
        ~PhoneBook();
        void add(Contact contactList[8]);
        void search(Contact contactList[8]);
        void exitProgram();
        int getContactCount();
        void setContactCount(int contactCount);
        int getIndex();
        void setIndex(int index);
        void loop(std::string *field, std::string prompt);
        void printContact(Contact contact);
};

#endif