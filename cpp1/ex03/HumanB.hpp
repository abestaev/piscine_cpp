#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon *_weapon;

    public:
        HumanB(std::string name);
        HumanB(std::string name, Weapon &weapon);
        void attack(void) const;
        void setWeapon(Weapon& weapon);
};

#endif