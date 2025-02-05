#include "AForm.hpp"

AForm::AForm() : _name("default"), 
               _signed(false), 
               _gradeRequiredToSign(150), 
               _gradeRequiredToExecute(150) {}

AForm::AForm(std::string const &name, int gradeRequiredToSign, int gradeRequiredToExecute) : 
    _name(name), 
    _signed(false), 
    _gradeRequiredToSign(gradeRequiredToSign), 
    _gradeRequiredToExecute(gradeRequiredToExecute) {
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1) {
        throw AForm::GradeTooHighException();
    }
    if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(AForm const & src) : 
    _name(src._name), 
    _signed(src._signed), 
    _gradeRequiredToSign(src._gradeRequiredToSign), 
    _gradeRequiredToExecute(src._gradeRequiredToExecute) {}

AForm &AForm::operator=(AForm const & src) {
    if (this != &src) {
        _signed = src._signed;
    }
    return *this;
}

AForm::~AForm() {}

std::string const &AForm::getName() const {
    return _name;
}

bool AForm::getSigned() const {
    return _signed;
}

int AForm::getGradeRequiredToSign() const {
    return _gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const {
    return _gradeRequiredToExecute;
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeRequiredToSign) {
        throw AForm::GradeTooLowException();
    }
    _signed = true;
}

std::ostream &operator<<(std::ostream &out, AForm const &form) {
    out << "\033[3;36m" << form.getName() << "\033[0m"
        << ", Signed: " << (form.getSigned() ? "yes" : "no") << std::endl
        << "Required Grade to Sign: " << form.getGradeRequiredToSign() << std::endl
        << "Required Grade to Execute: " << form.getGradeRequiredToExecute() << std::endl;
    return out;
}