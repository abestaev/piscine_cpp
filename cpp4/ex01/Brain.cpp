#include "Brain.hpp"
#define RESET   "\033[0m"
#define GREEN "\033[0;32m"

Brain::Brain() {
    std::cout << GREEN "Brain default constructor called" RESET << std::endl;
}

Brain::Brain(const Brain &other) {
    std::cout << GREEN "Brain copy constructor called" RESET << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other) {
    std::cout << GREEN "Brain copy assignment operator called" RESET << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << GREEN "Brain destructor called" RESET << std::endl;
}

