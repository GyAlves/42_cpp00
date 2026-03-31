/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 00:00:00 by gyasminalve       #+#    #+#             */
/*   Updated: 2026/03/27 00:00:00 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"

int main(void)
{
    std::cout << "Test 1: Basic functionality" << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    std::cout << "\nTest 2: Exception when full" << std::endl;

    try {
        sp.addNumber(42);
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nTest 3: Exception with no span" << std::endl;

    Span sp2(2);
    sp2.addNumber(1);

    try {
        std::cout << sp2.shortestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\nTest 4: Large span with range" << std::endl;

    Span sp3(10000);
    std::vector<int> numbers;
    for (int i = 0; i < 10000; i++)
        numbers.push_back(i);

    sp3.addRange(numbers.begin(), numbers.end());
    std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp3.longestSpan() << std::endl;

    std::cout << "\nTest 5: Negative numbers" << std::endl;

    Span sp4(4);
    sp4.addNumber(-10);
    sp4.addNumber(-5);
    sp4.addNumber(0);
    sp4.addNumber(5);

    std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp4.longestSpan() << std::endl;

    return 0;
}
