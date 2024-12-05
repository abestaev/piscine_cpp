#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
    private:
        Brain *brain;

    public:
        Dog();
        Dog(Dog const &other);
        Dog &operator=(Dog const &other);
        ~Dog();
        
        void makeSound() const;
        void setIdeas(int i, std::string idea);
        std::string getIdeas(int i) const;
};

#endif