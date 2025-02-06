#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 
                                                         25, 
                                                         5,
                                                         "default_target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm",
                                                                           25, 
                                                                           5,
                                                                           target) {} 
                                                                    
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getGradeRequiredToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}