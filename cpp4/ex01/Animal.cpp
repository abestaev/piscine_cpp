#include "Animal.hpp"
#define RESET   "\033[0m"
#define WHITE "\033[0;37m"

Animal::Animal() : type("Animal") {
    std::cout << WHITE "Animal constructor" RESET <<std::endl;
}

Animal::Animal(Animal const &other) {
    std::cout << WHITE "Animal copy constructor" RESET << std::endl;
    *this = other;
}

Animal &Animal::operator=(Animal const &other) {
    std::cout << WHITE "Animal assignment operator" RESET << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << WHITE "Animal destructor" RESET << std::endl;
}

void Animal::makeSound() const {
    std::cout << "bien dormi... ? t'as reve de moi.. ? meme pas un peu.?" << std::endl;
}

std::string Animal::getType() const {
    return type;
}