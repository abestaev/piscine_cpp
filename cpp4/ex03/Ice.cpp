#include "Ice.hpp"

Ice::Ice() : AMateria() { _type = "ice"; }

Ice::Ice(std::string type) { this->_type = type; }

Ice::Ice(Ice const & src) : AMateria(src) {
    *this = src;
    _type = src.getType();
}

Ice &Ice::operator=(Ice const & src) {
    if (this != &src) {
        _type = src.getType();
    }
    return *this;
}

Ice::~Ice() {}

Ice* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}