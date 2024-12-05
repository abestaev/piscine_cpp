#include "AAnimal.hpp"
#define RESET   "\033[0m"
#define WHITE "\033[0;37m"

AAnimal::AAnimal() : type("Unknown") {
    std::cout << WHITE "AAnimal constructor" RESET <<std::endl;
}

AAnimal::AAnimal(AAnimal const &other) {
    std::cout << WHITE "AAnimal copy constructor" RESET << std::endl;
    *this = other;
}

AAnimal &AAnimal::operator=(AAnimal const &other) {
    std::cout << WHITE "AAnimal assignment operator" RESET << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << WHITE "AAnimal destructor" RESET << std::endl;
}

void AAnimal::makeSound() const {
    std::cout << "bien dormi... ? t'as reve de moi.. ? meme pas un peu.?" << std::endl;
}

std::string AAnimal::getType() const {
    return type;
}