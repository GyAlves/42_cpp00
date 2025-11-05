/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HandleSearchCommand.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:30:00 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/02 19:30:00 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "../headers/PhoneBook.hpp"

void handleSearchCommand(PhoneBook& phoneBook)
{
    if (phoneBook.getContactCount() == 0)
    {
        std::cout << "No contacts available. Please add  a contact first." << std::endl;
        return;
    }

    phoneBook.displayContacts();

    while (true)
    {
        int contactIndex;
        std::cout << "Choose a contact by it's index to see the details: ";
        std::cin >> contactIndex;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (contactIndex < 1 || contactIndex > phoneBook.getContactCount())
        {
            std::cout << "Invalid index. Please try again." << std::endl;
            continue;
        }

        phoneBook.displayContactDetails(contactIndex);
        break;
    }
}
