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
#include "headers/Serializer.hpp"

int main() {

    Data original;
    original.value = 42;
    original.name = "Test Data";

    std::cout << "Original Data:" << std::endl;
    std::cout << "  Address: " << &original << std::endl;
    std::cout << "  Value: " << original.value << std::endl;
    std::cout << "  Name: " << original.name << std::endl;
    std::cout << std::endl;

    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "Serialized: " << serialized << std::endl;
    std::cout << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "  Address: " << deserialized << std::endl;
    std::cout << "  Value: " << deserialized->value << std::endl;
    std::cout << "  Name: " << deserialized->name << std::endl;
    std::cout << std::endl;

    if (deserialized == &original) {
        std::cout << "Success: Deserialized pointer matches original!" << std::endl;
    } else {
        std::cout << "Error: Deserialized pointer does not match original!" << std::endl;
    }

    return 0;
}
