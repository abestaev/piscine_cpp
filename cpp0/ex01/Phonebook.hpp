#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
    private:
        Contact contacts[8];
        int contactCount;
        int oldestContactIndex;
    
    public:
        Phonebook();
        void addContact();
        void searchContact();
    
    private:
        void displayContactSummary(int index);
        void displayAllContacts();
        std::string truncateField(const std::string& field) const;
};

#endif