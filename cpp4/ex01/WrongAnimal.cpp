#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &other) {
    std::cout << "WrongAnimal copy constructor" << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
    std::cout << "WrongAnimal assignment operator" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "mechante.." << std::endl;   
}