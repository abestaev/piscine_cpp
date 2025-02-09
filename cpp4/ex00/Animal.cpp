#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(Animal const &other) {
    std::cout << "Animal copy constructor" << std::endl;
    *this = other;
}

Animal &Animal::operator=(Animal const &other) {
    std::cout << "Animal assignment operator" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal's noise" << std::endl;
}

std::string Animal::getType() const {
    return type;
}