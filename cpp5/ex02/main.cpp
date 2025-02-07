#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void separator(){
    std::cout << "\n======================================\n" << std::endl;
}
// Shrubbery 145 137
// Robot 72 45
// Presidential 25 5
int main(){
    srand(time(NULL));

    std::cout << "\033[1;3m[Initiate Bureaucrats & Forms]\033[0m" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 40);
        Bureaucrat employee("Employee", 140);
        Bureaucrat intern("Intern", 150);

        ShrubberyCreationForm ficus("Ficus");
        RobotomyRequestForm robotomy("Robot");
        PresidentialPardonForm pardon("Olaf");

        std::cout << boss << std::endl;
        std::cout << manager << std::endl;
        std::cout << employee << std::endl;
        std::cout << intern << std::endl;
        std::cout << ficus << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        separator();
        std::cout << "\033[1;3m[Signing Forms]\033[0m" << std::endl;
        std::cout << "\033[1;3mShrubbery\033[0m" << std::endl;
        intern.signForm(ficus);
        employee.signForm(ficus);
        manager.signForm(ficus);

        std::cout << "\n\033[1;3mRobotomy\033[0m" << std::endl;
        manager.signForm(robotomy);
        boss.signForm(robotomy);

        std::cout << "\n\033[1;3mPresidential\033[0m" << std::endl;
        manager.signForm(pardon);
        boss.signForm(pardon);

        separator();
        std::cout << "\033[1;3m[Executing Forms]\033[0m" << std::endl;
        std::cout << "\033[1;3mShrubbery\033[0m" << std::endl;
        employee.executeForm(ficus);
        manager.executeForm(ficus);

        std::cout << "\n\033[1;3mRobotomy\033[0m" << std::endl;
        employee.executeForm(robotomy);
        manager.executeForm(robotomy);

        std::cout << "\n\033[1;3mPresidential\033[0m" << std::endl;
        employee.executeForm(pardon);
        manager.executeForm(pardon);
        boss.executeForm(pardon);

    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    separator();
    std::cout << "\033[1;3m[Test Execute Unsigned Form]\033[0m" << std::endl;
    try {
        Bureaucrat boss("Boss", 1);
        PresidentialPardonForm pardon("Olaf");

        std::cout << boss << std::endl;
        std::cout << pardon << std::endl;

        boss.executeForm(pardon);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }   
}