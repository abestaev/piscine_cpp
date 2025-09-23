#include "RPN.hpp"
#include <limits>
#include <cctype>

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expr) {
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        if (token.size() > 1)
            throw std::invalid_argument("Invalid token: " + token);
        if (std::isdigit(static_cast<unsigned char>(token[0]))) {
            _stack.push(atoi(token.c_str()));
        } else {
            if (_stack.size() < 2)
                throw std::invalid_argument("Too many operands");
            
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            long long la = static_cast<long long>(a);
            long long lb = static_cast<long long>(b);
            
            if (token[0] == '+') {
                long long r = la + lb;
                if (r < std::numeric_limits<int>::min() || r > std::numeric_limits<int>::max())
                    throw std::overflow_error("Overflow");
                _stack.push(static_cast<int>(r));
            }
            else if (token[0] == '-') {
                long long r = la - lb;
                if (r < std::numeric_limits<int>::min() || r > std::numeric_limits<int>::max())
                    throw std::overflow_error("Overflow");
                _stack.push(static_cast<int>(r));
            }
            else if (token[0] == '*') {
                long long r = la * lb;
                if (lb != 0 && r / lb != la)
                    throw std::overflow_error("Overflow");
                if (r < std::numeric_limits<int>::min() || r > std::numeric_limits<int>::max())
                    throw std::overflow_error("Overflow");
                _stack.push(static_cast<int>(r));
            }
            else if (token[0] == '/') {
                if (b == 0)
                    throw std::invalid_argument("Division by zero");
                if (a == std::numeric_limits<int>::min() && b == -1)
                    throw std::overflow_error("Overflow");
                _stack.push(a / b);
            } else {
                throw std::invalid_argument("Invalid operator: " + token);
            }
        }
    }
    if (_stack.size() != 1)
        throw std::invalid_argument("Not enough operands");
    return _stack.top();
}