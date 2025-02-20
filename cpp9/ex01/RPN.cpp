#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->stack = other.stack;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::checkArg(const std::string &arg) {

    return 0;
}

void evaluate(const std::string &expr) {


}