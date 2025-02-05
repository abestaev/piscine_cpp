#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        std::string const _name;
        bool _signed;
        const int _gradeRequiredToSign;
        const int _gradeRequiredToExecute;

    public:
        Form();
        Form(std::string const &name, int gradeRequiredToSign, int gradeRequiredToExecute);
        Form(Form const & src);
        Form &operator=(Form const & src);
        ~Form();

        std::string const &getName() const;
        bool getSigned() const;
        int getGradeRequiredToSign() const;
        int getGradeRequiredToExecute() const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char *what() const throw();
        };

        void beSigned(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif