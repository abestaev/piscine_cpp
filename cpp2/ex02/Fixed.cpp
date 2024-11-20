#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
    // std::cout << "Int constructor called" << std::endl;
    _rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    // std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fixed) : _rawBits(fixed._rawBits) {
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed) {
        _rawBits = fixed._rawBits;
    }
    return *this;
}

int Fixed::getRawBits() const {
    // std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void Fixed::setRawBits(int raw) {
    _rawBits = raw;
}

float Fixed::toFloat() const {
    return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _rawBits >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &fixed) const {
    return _rawBits > fixed._rawBits;
}

bool Fixed::operator<(const Fixed &fixed) const {
    return _rawBits < fixed._rawBits;
}

bool Fixed::operator>=(const Fixed &fixed) const {
    return _rawBits >= fixed._rawBits;
}

bool Fixed::operator<=(const Fixed &fixed) const {
    return _rawBits <= fixed._rawBits;
}

bool Fixed::operator==(const Fixed &fixed) const {
    return _rawBits == fixed._rawBits;
}

bool Fixed::operator!=(const Fixed &fixed) const {
    return _rawBits != fixed._rawBits;
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    return Fixed(toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++() {
    _rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--() {
    _rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return a < b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return a > b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return a > b ? a : b;
}

