#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const & src) {
    if (this != &src) {
        _grade = src._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string const &Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    if (_grade == 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade == 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}

void Bureaucrat::signForm(AForm &form) {
    if (form.getSigned()) {
        std::cout << _name << " cannot sign " << form.getName() << " because the form is already signed" << std::endl;
    } else if (form.getGradeRequiredToSign() < _grade) {
        std::cout << _name << " cannot sign " << form.getName() << " because the grade is too low" << std::endl;
    } else {
        form.beSigned(*this);
        std::cout << _name << " signs " << form.getName() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << _name << " executes " << form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << _name << " cannot execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}