#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}

HumanB::HumanB(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon) {}

void HumanB::attack() const
{
    if (_weapon) {
        std::cout << _name << " attacks with his " << _weapon->getType() << std::endl;
    } else {
        std::cout << _name << " attacks with his bare hands" << std::endl;
    }
}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}