#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog constructor" << std::endl;
    type = "Dog";
}

Dog::Dog(Dog const &other) {
    std::cout << "Dog copy constructor" << std::endl;
    *this = other;
}

Dog &Dog::operator=(Dog const &other) {
    std::cout << "Dog assignment operator" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Waf" << std::endl;
}