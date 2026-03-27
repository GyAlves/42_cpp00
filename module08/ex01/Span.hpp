/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 00:00:00 by gyasminalve       #+#    #+#             */
/*   Updated: 2026/03/27 00:00:00 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>
# include <algorithm>

class Span
{
private:

    unsigned int        _maxSize;
    std::vector<int>    _numbers;

    Span();

public:

    Span(unsigned int N);
    Span(Span const& other);
    ~Span();

    Span& operator=(Span const& other);

    void    addNumber(int number);
    int     shortestSpan() const;
    int     longestSpan() const;

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        while (begin != end)
        {
            if (_numbers.size() >= _maxSize)
                throw FullException();

            _numbers.push_back(*begin);
            ++begin;
        }
    }

    class FullException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Span is full";
        }
    };

    class NoSpanException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Not enough numbers to calculate span";
        }
    };
};

#endif
