#include <iostream>
#include "Phonebook.hpp"
#define COLOR_PROMPT "\033[1;32m" 
#define COLOR_RESET "\033[0m" 

int main(void)
{
    Phonebook phonebook;
    std::string command;

    while (1)
    {
        std::cout << COLOR_PROMPT << "PHONEBOOK> " << COLOR_RESET;
        std::getline(std::cin, command);
        if (command == "EXIT" || std::cin.eof())
            break;  
        else if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
        {
            phonebook.searchContact();
        }
        else if (!command.empty())
            std::cout << "Invalid command" << std::endl;
    }
    return 0;
}