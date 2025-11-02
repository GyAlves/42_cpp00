/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:07:34 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/02 18:54:54 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "headers/PhoneBook.hpp"
#include "headers/Utils.hpp"

int main(void)
{
    PhoneBook phoneBook;

    std::cout << "Welcome to your PhoneBook!! " << std::endl;
    std::cout << "Enter a command (ADD, SEARCH, EXIT) " << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    while(true)
    {
        std::string command;
        std::getline(std::cin, command);

        command = formatCommandInput(command);

        if (command == "ADD")
            handleAddCommand(phoneBook);
        else if (command == "SEARCH")
            handleSearchCommand(phoneBook);
        else if (command == "EXIT")
        {
            std::cout << "Exiting the program." << std::endl;
            break;
        }
        else
            std::cout << "Invalid command. Please try again." << std::endl;
    }

    return (0);
}