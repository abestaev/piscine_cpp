#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const & src);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const &executor) const;
};

#endif 