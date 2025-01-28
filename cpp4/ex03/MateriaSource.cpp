#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _count(0) {
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource const & src) {
    *this = src;
    _count = src._count;
    for (int i = 0; i < 4; i++) {
        if (src._inventory[i] != NULL) {
            _inventory[i] = src._inventory[i]->clone();
        } else {
            _inventory[i] = NULL;
        }
    }
}

MateriaSource &MateriaSource::operator=(MateriaSource const & src) {
    if (this != &src) {
        for (int i = 0; i < 4; i++) {
            if (_inventory[i] != NULL) {
                delete _inventory[i];
            }
        }
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

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] != NULL) {
            delete _inventory[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (_count < 4) {
        _inventory[_count] = m;
        _count++;
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] != NULL && _inventory[i]->getType() == type) {
            return _inventory[i]->clone();
        }
    }
    return NULL;
}
