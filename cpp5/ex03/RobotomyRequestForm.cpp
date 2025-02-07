#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 
                                                   72, 
                                                   45, 
                                                   "default_target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 
                                                                          72, 
                                                                          45,
                                                                          target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getGradeRequiredToExecute()) {
        throw AForm::GradeTooLowException();
    }
    if (!getSigned()) {
        throw AForm::FormNotSignedException();
    }
    std::cout << "*drilling noises*" << std::endl;
    if (rand() % 2) {
        std::cout << _target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << _target << " robotomization failed" << std::endl;
    }
}