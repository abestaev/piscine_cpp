#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat constructor" << std::endl;
    type = "Cat";
}

Cat::Cat(Cat const &other) {
    std::cout << "Cat copy constructor" << std::endl;
    *this = other;
}

Cat &Cat::operator=(Cat const &other) {
    std::cout << "Cat assignment operator" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Miaou" << std::endl;
}