/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +#+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:40:00 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/12 01:40:00 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "headers/iter.hpp"

template <typename T>
void print(T const& x) {
    std::cout << x << std::endl;
}

template <typename T>
void increment(T& x) {
    x++;
}

int main(void) {
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = 5;

    std::cout << "Original int array:" << std::endl;
    ::iter(intArray, intLength, print<int>);

    std::cout << "\nAfter increment:" << std::endl;
    ::iter(intArray, intLength, increment<int>);
    ::iter(intArray, intLength, print<int>);

    std::string strArray[] = {"Hello", "World", "Test"};
    size_t strLength = 3;
    std::cout << "\nString array:" << std::endl;
    ::iter(strArray, strLength, print<std::string>);

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    size_t doubleLength = 4;
    std::cout << "\nOriginal double array:" << std::endl;
    ::iter(doubleArray, doubleLength, print<double>);

    std::cout << "\nAfter increment:" << std::endl;
    ::iter(doubleArray, doubleLength, increment<double>);
    ::iter(doubleArray, doubleLength, print<double>);

    return 0;
}
