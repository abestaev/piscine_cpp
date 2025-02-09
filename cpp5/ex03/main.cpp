#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(){
    srand(time(NULL));

    std::cout << "\033[1;3m[Creation Bureaucrat & intern]\033[0m" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat employee("Boss", 140);
        Intern intern;

        std::cout << boss << std::endl;
        std::cout << "\033[1;3m[Creation Form unknown type]\033[0m" << std::endl;

        AForm *unknown = intern.makeForm("unknown", "unknown");
        if (unknown) {
            delete unknown;
        }
        std::cout << "\033[1;3m[Creation Shrubbery Form]\033[0m" << std::endl;

        AForm *form1 = intern.makeForm("shrubbery creation", "Lilas");
        boss.signForm(*form1);
        employee.signForm(*form1);
        employee.executeForm(*form1);
        boss.executeForm(*form1);
        delete form1;

    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    } 
}