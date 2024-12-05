#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat constructor" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &other) {
    std::cout << "WrongCat copy constructor" << std::endl;
    *this = other;
}

WrongCat &WrongCat::operator=(WrongCat const &other) {
    std::cout << "WrongCat assignment operator" << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "cui cui" << std::endl;   
}