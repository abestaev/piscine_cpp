#include "Dog.hpp"
#define RESET   "\033[0m"
#define PURPLE "\033[0;35m"

Dog::Dog() {
    std::cout << PURPLE "Dog constructor" RESET << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(Dog const &other) : AAnimal(other) {
    std::cout << PURPLE "Dog copy constructor" RESET << std::endl;
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(Dog const &other) {
    std::cout << PURPLE "Dog assignment operator" RESET << std::endl;
    if (this != &other) {
        this->type = other.type;
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << PURPLE "Dog destructor" RESET << std::endl;
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "🐕‍: wouaf!" << std::endl;
}

void Dog::setIdeas(int i, std::string idea) {
    if (brain == NULL)
        return;
    brain->ideas[i] = idea;
}

std::string Dog::getIdeas(int i) const {
    if (brain == NULL)
        return "No brain";
    return brain->ideas[i];
}