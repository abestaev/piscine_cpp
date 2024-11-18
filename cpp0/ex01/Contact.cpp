#include "Contact.hpp"
#define COLOR_PROMPT "\033[1;34m" 
#define COLOR_RESET "\033[0m" 

Contact::Contact(){}

void Contact::setFirstName(std::string firstName)         { this->firstName = firstName; }
void Contact::setLastName(std::string lastName)           { this->lastName = lastName; }
void Contact::setLogin(std::string login)                 { this->login = login; }
void Contact::setPhoneNumber(std::string phoneNumber)     { this->phoneNumber = phoneNumber; }
void Contact::setDarkestSecret(std::string darkestSecret) { this->darkestSecret = darkestSecret; }

std::string Contact::getFirstName()     { return this->firstName; }
std::string Contact::getLastName()      { return this->lastName; }
std::string Contact::getLogin()         { return this->login; }
std::string Contact::getPhoneNumber()   { return this->phoneNumber; }
std::string Contact::getDarkestSecret() { return this->darkestSecret; }   

void Contact::displayContact()
{
    std::cout << "---CONTACT INFO---" << std::endl;
    std::cout << "First name: " << COLOR_PROMPT << this->firstName << COLOR_RESET << std::endl;
    std::cout << "Last name: " << COLOR_PROMPT << this->lastName << COLOR_RESET << std::endl;
    std::cout << "Login: " << COLOR_PROMPT << this->login << COLOR_RESET << std::endl;
    std::cout << "Phone number: " << COLOR_PROMPT << this->phoneNumber << COLOR_RESET << std::endl;
    std::cout << "Darkest secret: " << COLOR_PROMPT << this->darkestSecret << COLOR_RESET << std::endl;
    std::cout << "------------------" << std::endl;
}