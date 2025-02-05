#include "Bureaucrat.hpp"

int main(){
    std::cout << "=== increment test ===" << std::endl;
    try {
        Bureaucrat ramzy("Ramzy", 2);
        std::cout << ramzy << std::endl;
        ramzy.incrementGrade();
        std::cout << ramzy << std::endl;
        ramzy.incrementGrade();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n=== decrement test ===" << std::endl;
    try {
        Bureaucrat ayoub("Ayoub", 149);
        std::cout << ayoub << std::endl;
        ayoub.decrementGrade();
        std::cout << ayoub << std::endl;
        ayoub.decrementGrade();
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "\n=== invalid input ===" << std::endl;
    try {
        Bureaucrat test("Test", 0);
        std::cout << test << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}