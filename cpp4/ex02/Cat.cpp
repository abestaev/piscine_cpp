#include "Cat.hpp"
#define RESET   "\033[0m"
#define BLUE "\033[0;34m"

Cat::Cat() {
    std::cout << BLUE "Cat constructor" RESET << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(Cat const &other) : AAnimal(other) {
    std::cout << BLUE "Cat copy constructor" RESET << std::endl;
    *this = other;
    brain = new Brain(*other.brain);
}

Cat &Cat::operator=(Cat const &other) {
    std::cout << BLUE "Cat assignment operator" RESET << std::endl;
    if (this != &other) {
        this->type = other.type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << BLUE "Cat destructor" RESET << std::endl;
    delete brain;   
}

void Cat::makeSound() const {
    std::cout << "🐈: Miaou" << std::endl;
}