#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal *meta = new Animal();
    const Animal *Hector = new Dog();
    const Animal *Felix = new Cat();

    std::cout << std::endl;
    std::cout << "Felix is a <" << Felix->getType() << ">\n- ";
    Felix->makeSound();
    std::cout << "\nHector is a <" << Hector->getType() << ">\n- ";
    Hector->makeSound();
    std::cout << "\nmeta is a <" << meta->getType() << ">\n- ";
    meta->makeSound();
    std::cout << std::endl;

    delete meta;
    delete Hector;
    delete Felix;

    std::cout << "\n---------------------------------------------\n" << std::endl;

    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongFelix = new WrongCat();
    
    std::cout << std::endl;
    std::cout << "WrongMeta is a <" << wrongMeta->getType() << ">\n- ";
    wrongMeta->makeSound();
    std::cout << "\nWrongFelix is a <" << wrongFelix->getType() << ">\n- ";
    wrongFelix->makeSound();
    std::cout << std::endl;
    
    delete wrongMeta;
    delete wrongFelix;

    return 0;
}