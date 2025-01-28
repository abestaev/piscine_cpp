#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(std::string type);
        Cure(Cure const & src);
        Cure &operator=(Cure const & src);
        virtual ~Cure();
        
        Cure* clone() const;
        void use(ICharacter& target);
};

#endif
