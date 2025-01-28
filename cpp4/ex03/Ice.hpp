#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(std::string type);
        Ice(Ice const & src);
        Ice &operator=(Ice const & src);
        virtual ~Ice();
        
        Ice* clone() const;
        void use(ICharacter& target);
};

#endif
