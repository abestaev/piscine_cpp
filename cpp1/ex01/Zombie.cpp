#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() { return ; }
Zombie::Zombie(std::string name) : _name(name) { return ; }

void Zombie::announce(void) const
{
    std::cout << "\033[35m" << this->_name << ": \033[0m" << "BraiiiiiiinnnzzzZ..." << std::endl;
    return ;
}

void Zombie::setName(std::string name)
{
    _name = name;
    return ;
}