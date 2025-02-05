#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    std::cout << "=== test 1 ===" << std::endl;
    try {
        Bureaucrat ramzy("Ramzy", 2);
        Form exam("Exam05", 1, 1);
        std::cout << ramzy << std::endl;
        std::cout << exam << std::endl << std::endl;
        ramzy.signForm(exam);
        ramzy.incrementGrade();
        ramzy.signForm(exam);
        ramzy.signForm(exam);
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}