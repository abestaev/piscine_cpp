#include "FragTrap.hpp"
#define FRAGTRAP "\033[3;35m<FragTrap>\033[0m "

FragTrap::FragTrap() : ClapTrap() {
    _hitpoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << FRAGTRAP << _name << " is born!" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name) {
    _hitpoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << FRAGTRAP << _name << " is born!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other) {
    std::cout << FRAGTRAP << _name << " is born!" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &other) {
    _name = other._name;
    _hitpoints = other._hitpoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << FRAGTRAP << _name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << FRAGTRAP << _name << " says: \"High five!\"" << std::endl;
}