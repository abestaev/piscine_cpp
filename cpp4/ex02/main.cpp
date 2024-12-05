#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"


int main() {
    int len = 6;
    
    AAnimal *animals[len];

    for (int i = 0; i < len / 2; ++i)
        animals[i] = new Dog();
    for (int i = len / 2; i < len; ++i)
        animals[i] = new Cat();

    std::cout << "\n------------------\n" <<std::endl;

    for (int i = 0; i < len; i++) {
        animals[i]->makeSound();
    }

    std::cout << "\n------------------\n" <<std::endl;

    for (int i = 0; i < len; i++) {
        delete animals[i];
    }
    std::cout << "\n================DEEPCOPY================\n" <<std::endl;

    Dog dog1;
    dog1.setIdeas(0, "I am dog1");
    std::cout << "dog1 idea: " << dog1.getIdeas(0) << std::endl;
    
    Dog dog2(dog1);
    dog1.setIdeas(0, "barking");
    std::cout << "dog1 idea: " << dog1.getIdeas(0) << std::endl;
    std::cout << "dog2 idea: " << dog2.getIdeas(0) << std::endl;
    return 0;
}