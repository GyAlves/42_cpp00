/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:03:31 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/10/31 12:04:34 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../headers/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    contactCount = 0;
}

PhoneBook::~PhoneBook()
{
    
}

void PhoneBook::setContactCount(int count)
{
    contactCount = count;
}

int PhoneBook::getContactCount() const
{
    return contactCount;
}

void PhoneBook::addContact(const Contact& contact)
{
 if (contactCount < 8)
 {
    contacts[contactCount] = contact;
    contactCount++;
 }
 else if (contactCount == 8)
 {
    contacts[contactCount] = contact;
 }
}

void PhoneBook::displayContacts() const
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << " Index | First Name | Last Name  | Nickname  " << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    
    for (int index = 0; index < contactCount; index++)
    {
        std::cout << "    " << (index + 1) << "  | ";
        std::cout << "  " << contacts[index].getFirstName().substr(0, 10) << "   | ";
        std::cout << "  " << contacts[index].getLastName().substr(0, 10) << "    | ";
        std::cout << "  " << contacts[index].getNickname().substr(0, 10) << "   | " << std::endl;
    }

    std::cout << "---------------------------------------------" << std::endl;
}