#include "DiamondTrap.hpp"
#define DIAMONDTRAP "\033[3;36m<DiamondTrap>\033[0m "

DiamondTrap::DiamondTrap() : ClapTrap("Risitas_clap_name"), ScavTrap(), FragTrap() {
    _name = "Risitas";
    _hitpoints = FragTrap::_hitpoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << DIAMONDTRAP << _name << " is born!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), _name(name) {
    _hitpoints = FragTrap::_hitpoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << DIAMONDTRAP << _name << " is born!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other), ScavTrap(other), FragTrap(other),_name(other._name) {
    std::cout << DIAMONDTRAP << _name << " is born!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
    _name = other._name;
    _hitpoints = other._hitpoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << DIAMONDTRAP << _name << " destructor called" << std::endl;
}

void DiamondTrap::attack(std::string const &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << DIAMONDTRAP << "My name is " << _name 
                             << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}