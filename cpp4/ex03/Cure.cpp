#include "Cure.hpp"

Cure::Cure() : AMateria() { _type = "cure"; }

Cure::Cure(std::string type) { this->_type = type; }

Cure::Cure(Cure const & src) : AMateria(src) {
    *this = src;
    _type = src.getType();
}

Cure &Cure::operator=(Cure const & src) {
    if (this != &src) {
        _type = src.getType();
    }
    return *this;
}

Cure::~Cure() {}

Cure* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}