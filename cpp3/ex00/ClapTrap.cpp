#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Risitas"), 
                       _hitpoints(10),
                       _energyPoints(10),
                       _attackDamage(0) {
    std::cout << _name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name) : _name(name),
                                              _hitpoints(10),
                                              _energyPoints(10),
                                              _attackDamage(0) {
    std::cout << _name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other) : _name(other._name),
                                            _hitpoints(other._hitpoints),
                                            _energyPoints(other._energyPoints),
                                            _attackDamage(other._attackDamage) {
    std::cout << _name << " is born!" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
    _name = other._name;
    _hitpoints = other._hitpoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << _name << " destructor called" << std::endl;
}

void ClapTrap::attack(std::string const &target) {
    if (_hitpoints == 0) {
        std::cout << _name << " is dead!" << std::endl;
        return ;
    }
    if (_energyPoints == 0) {
        std::cout << _name << " is out of energy!" << std::endl;
        return ;
    }
    if (_energyPoints > 0) {
        _energyPoints -= 1;
        std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitpoints == 0) {
        std::cout << _name << " is already dead!" << std::endl;
        return ;
    }
    _hitpoints -= amount;
    if (_hitpoints <= 0) {
        std::cout << _name << " took " << amount << " points of damage and died!" << std::endl;
        _hitpoints = 0;
    } else {
        std::cout << _name << " takes " << amount << " points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitpoints == 0) {
        std::cout << _name << " is dead and cannot be repaired!" << std::endl;
        return ;
    }
    std::cout << _name << " is repaired for " << amount << " points!" << std::endl;
    _hitpoints += amount;
}