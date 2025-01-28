#include "Character.hpp"

Character::Character() : _name("default"), _count(0) {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

Character::Character(std::string name) : _name(name), _count(0) {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

Character::Character(Character const & src) {
    *this = src;
    _name = src.getName();
    _count = src._count;
    for (int i = 0; i < 4; i++) {
        if (src._inventory[i] != NULL) {
            _inventory[i] = src._inventory[i]->clone();
        } else {
            _inventory[i] = NULL;
        }
    }
}

Character &Character::operator=(Character const & src) {
    if (this != &src) {
        for (int i = 0; i < 4; i++) {
            if (_inventory[i] != NULL) {
                delete _inventory[i];
            }
        }
        _name = src.getName();
        _count = src._count;
        for (int i = 0; i < 4; i++) {
            if (src._inventory[i] != NULL) {
                _inventory[i] = src._inventory[i]->clone();
            } else {
                _inventory[i] = NULL;
            }
        }
    }
    return *this;
    
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] != NULL) {
            delete _inventory[i];
        }
    }
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (_count < 4) {
        _inventory[_count] = m;
        _count++;
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4) {
        _inventory[idx] = NULL;
        _count--;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && _inventory[idx] != NULL) {
        _inventory[idx]->use(target);
    }
}
