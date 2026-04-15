#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <stdexcept>

class RPN {
public:
    RPN();
    RPN(RPN const& other);
    ~RPN();
    RPN& operator=(RPN const& other);
    int evaluate(std::string const& expression) const;

private:
    bool isOperator(char c) const;
};

#endif
