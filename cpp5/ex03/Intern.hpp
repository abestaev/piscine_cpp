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
    private:
        static AForm *createShrubberyForm(std::string const &target) { return new ShrubberyCreationForm(target);};
        static AForm *createRobotomyForm(std::string const &target) {return new RobotomyRequestForm(target);};
        static AForm *createPresidentialForm(std::string const &target) {return new PresidentialPardonForm(target);};
};

#endif