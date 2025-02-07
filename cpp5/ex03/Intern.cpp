#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & src) {
    *this = src;
}

Intern &Intern::operator=(Intern const & src) {
    (void)src;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) {
    std::string formTypes[3] = {
        "shrubbery creation", 
        "robotomy request",
        "presidential pardon"
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            switch (i) {
                case 0:
                    return new ShrubberyCreationForm(target);
                case 1:
                    return new RobotomyRequestForm(target);
                case 2:
                    return new PresidentialPardonForm(target);
            }
        }
    }

    std::cout << "Form type not found" << std::endl;
    return NULL;
}