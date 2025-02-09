#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_inventory[4];
        AMateria *_lostMateria[1000];
        int _count;
        int _lostCount;

    public:
        Character();
        Character(std::string name);
        Character(Character const & src);
        Character &operator=(Character const & src);
        virtual ~Character();
        
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif