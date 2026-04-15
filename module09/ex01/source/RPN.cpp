#include "RPN.hpp"
#include <sstream>

RPN::RPN() {}

RPN::RPN(RPN const& other) { (void)other; }

RPN::~RPN() {}

RPN& RPN::operator=(RPN const& other) {
    (void)other;
    return *this;
}

bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::evaluate(std::string const& expression) const {
    std::stack<int> stack;
    std::istringstream ss(expression);
    std::string token;
    while (ss >> token) {
        if (token.size() == 1 && isOperator(token[0])) {
            if (stack.size() < 2)
                throw std::runtime_error("Error");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            if (token[0] == '+') stack.push(a + b);
            else if (token[0] == '-') stack.push(a - b);
            else if (token[0] == '*') stack.push(a * b);
            else {
                if (b == 0)
                    throw std::runtime_error("Error");
                stack.push(a / b);
            }
        } else {
            if (token.size() != 1 || token[0] < '0' || token[0] > '9')
                throw std::runtime_error("Error");
            stack.push(token[0] - '0');
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error");
    return stack.top();
}
