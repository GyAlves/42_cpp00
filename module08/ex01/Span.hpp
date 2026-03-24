#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span(unsigned int N);
    Span(Span const& other);
    ~Span();
    Span& operator=(Span const& other);
    void addNumber(int number);
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        while (begin != end) {
            if (_numbers.size() >= _maxSize) {
                throw FullException();
            }
            _numbers.push_back(*begin);
            ++begin;
        }
    }
    int shortestSpan() const;
    int longestSpan() const;
    class FullException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Span is full";
        }
    };
    class NoSpanException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Not enough numbers to calculate span";
        }
    };

private:
    Span();
};

#endif
