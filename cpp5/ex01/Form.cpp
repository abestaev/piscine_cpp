#include "Form.hpp"

Form::Form() : _name("default"), 
               _signed(false), 
               _gradeRequiredToSign(150), 
               _gradeRequiredToExecute(150) {}

Form::Form(std::string const &name, int gradeRequiredToSign, int gradeRequiredToExecute) : 
    _name(name), 
    _signed(false), 
    _gradeRequiredToSign(gradeRequiredToSign), 
    _gradeRequiredToExecute(gradeRequiredToExecute) {
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1) {
        throw Form::GradeTooHighException();
    }
    if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150) {
        throw Form::GradeTooLowException();
    }
}

Form::Form(Form const & src) : 
    _name(src._name), 
    _signed(src._signed), 
    _gradeRequiredToSign(src._gradeRequiredToSign), 
    _gradeRequiredToExecute(src._gradeRequiredToExecute) {}

Form &Form::operator=(Form const & src) {
    if (this != &src) {
        _signed = src._signed;
    }
    return *this;
}

Form::~Form() {}

std::string const &Form::getName() const {
    return _name;
}

bool Form::getSigned() const {
    return _signed;
}

int Form::getGradeRequiredToSign() const {
    return _gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
    return _gradeRequiredToExecute;
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeRequiredToSign) {
        throw Form::GradeTooLowException();
    }
    _signed = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form) {
    out << "\033[3;36m" << form.getName() << "\033[0m"
        << ", Signed: " << (form.getSigned() ? "yes" : "no") << std::endl
        << "Required Grade to Sign: " << form.getGradeRequiredToSign() << std::endl
        << "Required Grade to Execute: " << form.getGradeRequiredToExecute() << std::endl;
    return out;
}