#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
    std::cout << "=== test 1 - Shrubbery ===" << std::endl;
    try {
        Bureaucrat test("test", 2);
        ShrubberyCreationForm ficus;
        std::cout << test << std::endl;
        std::cout << ficus << std::endl << std::endl;
        test.signForm(ficus);
        test.incrementGrade();
        test.signForm(ficus);
        test.signForm(ficus);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}