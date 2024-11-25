#include "ScavTrap.hpp"
#define SCAVTRAP "\033[3;32m<ScavTrap>\033[0m "

ScavTrap::ScavTrap() : ClapTrap() {
    _hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << SCAVTRAP << _name << " is born!" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name) {
    _hitpoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << SCAVTRAP << _name << " is born!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
    std::cout << SCAVTRAP << _name << " is born!" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
    _name = other._name;
    _hitpoints = other._hitpoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << SCAVTRAP << _name << " destructor called" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
    if (_hitpoints == 0) {
        std::cout << SCAVTRAP << _name << " is dead!" << std::endl;
        return ;
    }
    if (_energyPoints == 0) {
        std::cout << SCAVTRAP << _name << " is out of energy!" << std::endl;
        return ;
    }
    if (_energyPoints > 0) {
        _energyPoints -= 1;
        std::cout << SCAVTRAP << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << SCAVTRAP << _name << " has entered in Gate keeper mode." << std::endl;
}