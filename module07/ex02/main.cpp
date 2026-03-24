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
#include "headers/Array.hpp"

int main(void) {
    try {

        Array<int> empty;
        std::cout << "Empty array size: \n" << empty.size() << std::endl;

        Array<int> intArray(5);
        std::cout << "Int array size: " << intArray.size() << std::endl;

        std::cout << "Initial values:" << std::endl;
        for (unsigned int counter = 0; counter < intArray.size(); counter++) {
            std::cout << "intArray[" << counter << "] = " << intArray[counter] << std::endl;
        }

        std::cout << "\nSetting values:" << std::endl;
        for (unsigned int counter = 0; counter < intArray.size(); counter++) {
            intArray[counter] = counter * 10;
            std::cout << "intArray[" << counter << "] = " << intArray[counter] << std::endl;
        }

        Array<int> copy(intArray);
        std::cout << "\nCopy array:" << std::endl;
        for (unsigned int counter = 0; counter < copy.size(); counter++) {
            std::cout << "copy[" << counter << "] = " << copy[counter] << std::endl;
        }

        std::cout << "\nModifying original:" << std::endl;
        intArray[0] = 999;
        std::cout << "intArray[0] = " << intArray[0] << std::endl;
        std::cout << "copy[0] = " << copy[0] << std::endl;

        Array<std::string> strArray(3);
        strArray[0] = "Hello";
        strArray[1] = "42SP";
        strArray[2] = "!";

        std::cout << "\nString array:" << std::endl;
        for (unsigned int counter = 0; counter < strArray.size(); counter++) {
            std::cout << "strArray[" << counter << "] = " << strArray[counter] << std::endl;
        }
        std::cout << "\nTrying to access out of bounds index:" << std::endl;
        std::cout << intArray[10] << std::endl;

    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
