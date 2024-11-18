#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon& _weapon;

    public:
        HumanA(std::string name, Weapon& weapon);
        void attack(void) const;
};

#endif