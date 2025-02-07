#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
    public:
        Intern();
        Intern(Intern const & src);
        Intern &operator=(Intern const & src);
        ~Intern();

        AForm *makeForm(std::string const &formName, std::string const &target);
};

#endif