#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN {
    private:
        std::stack<int> stack;
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();
        
        int checkArg(const std::string &arg);
        void evaluate(const std::string &expr);
};

#endif