#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    return ;
}

PhoneBook::~PhoneBook()
{
    return ;
}

int PhoneBook::getContactCount()
{
    return this->contactCount;
}

int PhoneBook::getIndex()
{
    return this->index;
}

void PhoneBook::setContactCount(int contactCount)
{
    this->contactCount = contactCount;
}

void PhoneBook::setIndex(int index)
{
    this->index = index;
}

static int isNumber(std::string str)
{
    int i = 0;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

void PhoneBook::loop(std::string *field, std::string prompt)
{
    while (1)
    {
        std::cout << prompt;
        std::getline(std::cin, *field);
        if (std::cin.eof())
            this->exitProgram();
        else if (field->empty())
            std::cerr << "Field cannot be empty." << std::endl;
        else if (prompt == "Phone number: " && !isNumber(*field))
            std::cerr << "Invalid phone number." << std::endl;
        else
            break ;
    }
}

void PhoneBook::add(Contact contactList[8])
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

    if (this->getContactCount() == 8 && this->getIndex() == 8)
        this->setIndex(0);
    loop(&firstName, "First name: ");
    loop(&lastName, "Last name: ");
    loop(&nickName, "Nickname: ");
    loop(&phoneNumber, "Phone number: ");
    loop(&darkestSecret, "Darkest secret: ");
    contactList[this->getIndex()] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
    if (this->getContactCount() != 8)
        this->setContactCount(this->getContactCount() + 1);
    this->setIndex(this->getIndex() + 1);
}

void PhoneBook::exitProgram()
{
    std::cout << "Exiting program..." << std::endl;
    exit(0);
}

static std::string	truncateString(std::string field)
{
	if (field.length() <= 10)
		return (field);
	return (field.substr(0, 9) + '.');
}

static void printCommands()
{
    std::cout << "\nCommands: ADD, SEARCH, EXIT" << std::endl;
}

void PhoneBook::printContact(Contact contact)
{
    std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "First name: " << contact.getContactFirstName() << std::endl;
    std::cout << "Last name: " << contact.getContactLastName() << std::endl;
    std::cout << "Nickname: " << contact.getContactNickName() << std::endl;
    std::cout << "Phone number: " << contact.getContactPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contact.getContactDarkestSecret() << std::endl;
}

void PhoneBook::search(Contact contactList[8])
{
    int i = 0;
    int indexToSearched;
    if (this->getContactCount() == 0)
    {
        std::cout << "No contacts to display." << std::endl;
        return ;
    }
    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    while (i < this->getContactCount())
    {
        std::cout << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << truncateString(contactList[i].getContactFirstName()) << "|";
        std::cout << std::setw(10) << truncateString(contactList[i].getContactLastName()) << "|";
        std::cout << std::setw(10) << truncateString(contactList[i].getContactNickName()) << std::endl;
        i++;
    }
    std::cout << "---------------------------------------------" << std::endl;
    while (1)
    {
        std::cout << "Enter index of contact to display: ";
        std::cin >> indexToSearched;
        if (std::cin.fail())
        {
            if (std::cin.eof())
                this->exitProgram();
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cerr << "Invalid input." << std::endl;
        }
        else if (indexToSearched < 0 || indexToSearched > 8)
            std::cerr << "Index out of range." << std::endl;
        else if (indexToSearched > 0 && indexToSearched <= this->getContactCount())
            break ;
        else
            std::cerr << "Index does not exist." << std::endl;
    }
    this->printContact(contactList[indexToSearched - 1]);
    std::cin.ignore(32767, '\n');
}

int main()
{
    PhoneBook phoneBook;
    Contact contactList[8];
    std::string command;
    phoneBook.setContactCount(0);
    phoneBook.setIndex(0);
    while (1)
    {
        printCommands();
        std::cout << "Enter command: ";
        std::getline(std::cin, command);
        if (command == "ADD")
            phoneBook.add(contactList);
        else if (command == "SEARCH")
            phoneBook.search(contactList);
        else if (command == "EXIT")
            phoneBook.exitProgram();
        else if (std::cin.eof())
            phoneBook.exitProgram();
        else
            std::cerr << "Invalid command." << std::endl;
    }
    return (0);
}