#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        std::string const _name;
        bool _signed;
        const int _gradeRequiredToSign;
        const int _gradeRequiredToExecute;

    protected:
        const std::string _target;
        void checkGrade(int grade) const;

    public:
        AForm();
        AForm(std::string const &name, int gradeRequiredToSign, int gradeRequiredToExecute, std::string const &target);
        AForm(AForm const & src);
        AForm &operator=(AForm const & src);
        virtual ~AForm();

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
        virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif