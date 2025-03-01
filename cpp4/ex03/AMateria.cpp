#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(AMateria const & src) {
    *this = src;
}

AMateria & AMateria::operator=(AMateria const & src) {
    if (this != &src) {
        this->_type = src._type;
    }
    return *this;
}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    (void)target;
}