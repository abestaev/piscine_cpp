#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <sstream>
# include <cstdlib>
# include <stdexcept>

class RPN {
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
        
        int evaluate(const std::string &expr);
};

#endif