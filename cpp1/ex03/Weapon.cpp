#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) { return ; }

const std::string& Weapon::getType(void) const
{ return _type; }

void Weapon::setType(std::string type)
{ _type = type; }