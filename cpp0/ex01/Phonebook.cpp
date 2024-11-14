#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

Phonebook::Phonebook() : contactCount(0), oldestContactIndex(0) {}

void Phonebook::addContact()
{
    Contact New;
    std::string input;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "First name cannot be empty" << std::endl;
        return ;
    }
    New.setFirstName(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "Last name cannot be empty" << std::endl;
        return ;
    }
    New.setLastName(input);

    std::cout << "Enter login: ";
    std::getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "Login cannot be empty" << std::endl;
        return ;
    }
    New.setLogin(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    New.setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    New.setDarkestSecret(input);

    if (contactCount < 8)
        contacts[contactCount++] = New;
    else
    {
        contacts[oldestContactIndex] = New;
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
}

void Phonebook::searchContact()
{
    int index;

    if (contactCount == 0)
    {
        std::cout << "No contacts available" << std::endl;
        return;
    }

    displayAllContacts();
    std::cout << "Enter index of contact: ";

    std::string input;
    std::getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    std::istringstream iss(input);
    if (!(iss >> index))
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    if (index >= 0 && index < contactCount)
        contacts[index].displayContact();
    else
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
}

void Phonebook::displayAllContacts()
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Login" << std::endl;

    for (int i = 0; i < contactCount; i++)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncateField(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncateField(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncateField(contacts[i].getLogin()) << std::endl;
    }
}

std::string Phonebook::truncateField(const std::string& field) const
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}